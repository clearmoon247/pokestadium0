/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/pokemon_stats.c. */

#include "pokemon_stats.h"
#include "gb_data.h"
#include "save_data.h"
#include "text_system.h"
#include "gb_tower.h"
#include "hal_libc.h"
#include "util.h"
#include "m2c_macros.h"

// Zero's per-port Game Boy save state; Stadium 1's GbSavePort is 0x58 bytes.
typedef struct GbSavePortZero {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05[0x13];
    /* 0x18 */ u8 unk_18[0x20];
    /* 0x38 */ u16 unk_38;
    /* 0x3A */ u8 unk_3A[6];
    /* 0x40 */ u8* unk_40;
    /* 0x44 */ u8* unk_44;
} GbSavePortZero; // size = 0x48
extern s8 D_800AD210;
#define sGbSavePorts ((GbSavePortZero*)&D_800AD210)
extern u8 D_8006B8C4[];
typedef struct unk_func_800228F0_sp24 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u16 unk_02;
    // Two 6-byte Game Boy names, read with Text_UntranscodeFixedName.
    /* 0x04 */ char unk_04[0xC];
} unk_func_800228F0_sp24;
extern u8 gDexToInternalIndex[];
extern u8 gInternalIndexToDex[];
extern u32 D_800AD330;
extern u8 D_800AD334;
extern u8 D_800AD335;
extern GbSaveMainData D_800AD338;

s32 GbSave_HasPlayerNameMarker(u8* arg0);
s32 GbSave_VerifyChecksum(u8* arg0, u8* arg1);
void GbSave_ComputeChecksum(u8* arg0, u8* arg1);
s32 GbSave_VerifyWriteback(u8* arg0, s32 arg1);
void GbSave_RequirePakPresent(s32 arg0);
s32 GbSave_GetBoxEntryCount(s32 arg0, s32 arg1);
void GbSave_SetBoxEntryCount(s32 arg0, s32 arg1, s32 arg2);
s32 Deck_GetCapacity(s32 arg0);
s32 Deck_GetEntrySize(s32 arg0);
s32 GbSave_GetPresentPortMask(void);
s32 GbSave_GetPortAvailability(s32 arg0);

GbSaveBoxEntry* GbSave_GetBoxEntry(s32 arg0, s32 arg1);

s32 GbSave_HasPlayerNameMarker(u8* arg0) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (*arg0++ == 'P') {
            return 1;
        }
    }

    return 0;
}

s32 GbSave_VerifyChecksum(u8* arg0, u8* arg1) {
    s32 sp1C = 0;
    s32 sp18 = 0;

    if (GbSave_HasPlayerNameMarker(arg0) != 0) {
        while (arg1 >= arg0) {
            sp18 += *arg0++;
        }
        sp1C = (sp18 & 0xFF) == 0xFF;
    }

    return sp1C;
}

void GbSave_ComputeChecksum(u8* arg0, u8* arg1) {
    s32 var_v0 = 0;

    while (arg0 < arg1) {
        var_v0 += *arg0++;
    }

    *arg1 = 0xFF - (var_v0 & 0xFF);
}

s32 GbSave_VerifyWriteback(u8* arg0, s32 arg1) {
    u8* var_v0 = D_800AD338.unk_000;

    while (arg1-- > 0) {
        if (*arg0++ != *var_v0++) {
            return 0;
        }
    }

    return 1;
}

s8 GbCart_IdentifyGame(s32 arg0) {
    // Only part of the rom header,
    // osGbpakReadId reads from 0x100 but this reads from 0x120
    typedef struct RomHeader {
        /* 0x00 */ char nintendo_chr[0x14];
        /* 0x14 */ char game_title[16];
        /* 0x24 */ u16 company_code;
        /* 0x26 */ u8 body_code;
        /* 0x27 */ u8 cart_type;
        /* 0x28 */ u8 rom_size;
        /* 0x29 */ u8 ram_size;
        /* 0x2A */ s8 country_code;
        /* 0x2B */ u8 fixed2;
        /* 0x2C */ u8 version;
        /* 0x2D */ u8 isum;
        /* 0x2E */ u16 sum;
        /* 0x30 */ char unk30[0x10];
    } RomHeader; // size = 0x40

    RomHeader sp28;
    s8 var_s0 = POKEMON_ROM_NONE;

    if (GbPak_ReadRom(arg0, &sp28, 0x120, sizeof(RomHeader)) == 0) {
        sp28.game_title[7] = '\x0';
        sp28.game_title[16] = '\x0';

        if (HAL_Strcmp(&sp28.game_title[0], "POKEMON") == 0) {
            if (HAL_Strcmp(&sp28.game_title[8], "RED") == 0) {
                var_s0 = POKEMON_ROM_RED;
            } else if (HAL_Strcmp(&sp28.game_title[8], "GREEN") == 0) {
                var_s0 = POKEMON_ROM_GREEN;
            } else if (HAL_Strcmp(&sp28.game_title[8], "BLUE") == 0) {
                var_s0 = POKEMON_ROM_BLUE;
            } else if (HAL_Strcmp(&sp28.game_title[8], "YELLOW") == 0) {
                var_s0 = POKEMON_ROM_YELLOW;
            }
        }
    }

    return var_s0;
}

s32 GbSave_CheckMainDataUnchanged(s32 arg0) {
    UNUSED s32 pad;
    s32 sp18 = 0;

    if ((GbPak_MbcRead(arg0, &D_800AD338, 0x2580, 0x1020) == 0) &&
        (GbSave_VerifyChecksum(&D_800AD338.unk_018, (u8*)&D_800AD338 + 0x1014) != 0)) {
        sp18 = ((u8*)&D_800AD338)[0x1014] == sGbSavePorts[arg0].unk_04;
    }
    return sp18;
}

s32 GbSave_ReadMainData(s32 arg0) {
    s32 i;
    s32 sp30;
    u8* temp_s4 = sGbSavePorts[arg0].unk_40;

    sp30 = NULL;

    if (GbPak_MbcRead(arg0, temp_s4, 0x2580, 0x1020) == 0) {
        for (i = 0; i < 3; i++) {
            sp30 = GbSave_VerifyChecksum(temp_s4 + 0x18, temp_s4 + 0x1014);
            if (sp30 != 0) {
                if (sGbSavePorts[arg0].unk_00 & 0x20) {
                    sGbSavePorts[arg0].unk_04 = temp_s4[0x1014];
                    sGbSavePorts[arg0].unk_00 = sGbSavePorts[arg0].unk_00 & ~0x20;
                } else {
                    sp30 = temp_s4[0x1014] == sGbSavePorts[arg0].unk_04;
                }
                return sp30;
            }
        }
    }

    return sp30;
}

s32 func_8000C1B4(s32, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
s32 func_8000C238(s32, s8 *, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8002107C(s32, s32);                    /* extern */
s32 func_800210AC(s8 *, M2C_UNK);                 /* extern */
extern s8 D_800AD210;
s32 func_80021334(s32 arg0) {
    s32 var_s0;
    s8 *temp_s1;
    s8 *temp_s3;

    temp_s3 = (arg0 * 0x48) + &D_800AD210;
    temp_s1 = M2C_FIELD(temp_s3, s8 **, 0x40);
    func_8002107C(temp_s1 + 0x18, temp_s1 + 0x1014);
    var_s0 = 0;
    M2C_FIELD(temp_s3, u8 *, 4) = (u8) M2C_FIELD(temp_s1, u8 *, 0x1014);
loop_1:
    if ((func_8000C238(arg0, temp_s1, 0x2580, 0x1020) == 0) && (func_8000C1B4(arg0, &D_800AD338, 0x2580, 0x1020) == 0) && (func_800210AC(temp_s1, 0x1020) != 0)) {
        return 1;
    }
    var_s0 += 1;
    if (var_s0 == 4) {
        return 0;
    }
    goto loop_1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80021410; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80021410.s")
#endif

extern GbSavePort D_800AC910[4];
s32 GbSave_ReadBoxBank(s32 arg0, s32 arg1) {
    UNUSED s32 pad[2];
    u8* sp1C = sGbSavePorts[arg0].unk_44 + arg1 * 0x15A0;

    return GbPak_MbcRead(arg0, sp1C, (arg1 == 0) ? 0x4000 : 0x6000, 0x15A0) == 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80021570; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80021570.s")
#endif

extern s8 D_800AD210;
void func_80021678(s32 arg0, u32 arg1) {
    s8 *temp_v0;
    s8 *temp_v0_2;

    if ((arg1 >= 0x44415430U) && (arg1 < 0x44415434U)) {
        temp_v0 = ((arg1 - 0x44415430) * 0x48) + &D_800AD210;
        M2C_FIELD(temp_v0, s32 *, 0x40) = 0;
        M2C_FIELD(temp_v0, u16 *, 0) = (u16) (M2C_FIELD(temp_v0, u16 *, 0) & 0xFFF6);
        return;
    }
    if ((arg1 >= 0x424F5830U) && (arg1 < 0x424F5834U)) {
        temp_v0_2 = ((arg1 - 0x424F5830) * 0x48) + &D_800AD210;
        M2C_FIELD(temp_v0_2, s32 *, 0x44) = 0;
        M2C_FIELD(temp_v0_2, u16 *, 0) = (u16) (M2C_FIELD(temp_v0_2, u16 *, 0) & 0xFFED);
    }
}

void GbSave_CheckLocationFlag(s32 arg0) {
    extern u8 D_8006BB90[12];

    s32 i;
    s32 temp_t1 = sGbSavePorts[arg0].unk_40[0x80];

    sGbSavePorts[arg0].unk_00 &= ~0x4000;

    for (i = 0; i < 12; i++) {
        if (D_8006BB90[i] == temp_t1) {
            sGbSavePorts[arg0].unk_00 |= 0x4000;
            break;
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8002178C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002178C.s")
#endif

s32 GbSave_EnsureMainDataLoaded(s32 arg0) {
    s32 sp1C = 0;

    if (((1 << arg0) & D_800AD330) && (sGbSavePorts[arg0].unk_03 == 0)) {
        sp1C = GbSave_OpenMainData(arg0);
        if (sp1C == 0) {
            Game_ShutdownAndLoadFragment(arg0, 2);
        }
    }

    return sp1C;
}

s32 func_80021910(s32 arg0) {
    u8 sp37;
    s32 i;
    s32 sp2C;

    sp2C = 0;

    if (!(sGbSavePorts[arg0].unk_00 & 1)) {
        return 0;
    }

    if (sGbSavePorts[arg0].unk_00 & 2) {
        return 1;
    }

    sGbSavePorts[arg0].unk_44 = main_pool_alloc_with_func(0x2B40, 0, arg0 + 'BOX0', GbSave_ReleasePortBuffers);

    if (sGbSavePorts[arg0].unk_44 != NULL) {
        sGbSavePorts[arg0].unk_00 |= 2;
        if (GbSave_GetBoxCount(arg0) > 0) {
            if (GbTower_ProbePak(arg0, &sp37, sGbSavePorts[arg0].unk_18) == 0) {
                Game_ShutdownAndLoadFragment(arg0, 2);
            }

            if (GbSave_ReadBoxBank(arg0, 0) != 0) {
                sp2C = GbSave_ReadBoxBank(arg0, 1);
            }

            if (GbTower_CheckPakRemoved(arg0, sp37) == 0) {
                Game_ShutdownAndLoadFragment(arg0, 2);
            }

            if (sp2C == 0) {
                main_pool_try_free(sGbSavePorts[arg0].unk_44);
            }
        } else {
            HAL_Memset(sGbSavePorts[arg0].unk_44, 0xFF, 0x2B40);

            for (i = 0; i < 4; i++) {
                sGbSavePorts[arg0].unk_44[i * 0x566] = 0;
                sGbSavePorts[arg0].unk_44[0x15A0 + i * 0x566] = 0;
            }

            sp2C = 1;
        }
    }
    return sp2C;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80021A8C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80021A8C.s")
#endif

extern GbSavePort D_800AC910[4];
#ifdef NON_MATCHING
/* TODO: decompile func_80021B30; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80021B30.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80021C6C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80021C6C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80021CF4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80021CF4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80021E64; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80021E64.s")
#endif

s32 GbSave_WriteBoxBanks(s32 arg0) {
    u8 sp2F;
    s32 sp28 = 0;

    if (sGbSavePorts[arg0].unk_00 & 2) {
        if (GbTower_ProbePak(arg0, &sp2F, sGbSavePorts[arg0].unk_18) == 0) {
            Game_ShutdownAndLoadFragment(arg0, 2);
        }

        sp28 = GbSave_WriteBoxBank(arg0, 0);

        if (sp28 != 0) {
            sp28 = GbSave_WriteBoxBank(arg0, 1);
        }
        sp28 &= GbTower_CheckPakRemoved(arg0, sp2F);
    }
    return sp28;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80021FF4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80021FF4.s")
#endif

s32 GbSave_RebuildAndWriteSave(s32 arg0) {
    u8 sp2F;
    s32 sp28;

    if (GbTower_ProbePak(arg0, &sp2F, sGbSavePorts[arg0].unk_18) == 0) {
        Game_ShutdownAndLoadFragment(arg0, 2);
    }

    sp28 = GbSave_InvalidateMainDataChecksum(arg0);

    if (sp28 != 0) {
        sp28 = GbSave_WriteBoxBanks(arg0);
        if (sp28 != 0) {
            sp28 = GbSave_CommitMainData(arg0);
        }
    }

    sp28 &= GbTower_CheckPakRemoved(arg0, sp2F);
    return sp28;
}

void GbSave_ValidateBeforeWrite(s32 arg0) {
    u8 sp27;

    if (GbTower_ProbePak(arg0, &sp27, sGbSavePorts[arg0].unk_18) == 0) {
        Game_ShutdownAndLoadFragment(arg0, 2);
    }

    if (GbSave_CheckMainDataUnchanged(arg0) == 0) {
        Game_ShutdownAndLoadFragment(arg0, 1);
    }
}

void GbSave_RequirePakPresent(s32 arg0) {
    if (GbTower_CheckPakRemoved(arg0, 0) == 0) {
        Game_ShutdownAndLoadFragment(arg0, 2);
    }
}

GbSaveBoxEntry* GbSave_GetBoxEntry(s32 arg0, s32 arg1) {
    GbSaveBoxEntry* sp1C = NULL;
    s32 temp_v0 = GbSave_GetBoxCount(arg0);

    if (temp_v0 > 0) {
        if (arg1 == (temp_v0 - 1)) {
            sp1C = (GbSaveBoxEntry*)(sGbSavePorts[arg0].unk_40 + 0xAAD);
        } else if (arg1 < 4) {
            sp1C = (GbSaveBoxEntry*)(sGbSavePorts[arg0].unk_44 + arg1 * 0x566);
        } else {
            sp1C = (GbSaveBoxEntry*)(sGbSavePorts[arg0].unk_44 + arg1 * 0x566 + 8);
        }
    }
    return sp1C;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80022284; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80022284.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002234C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002234C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80022424; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80022424.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800224E8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800224E8.s")
#endif

s32 GbSave_GetBoxEntryCount(s32 arg0, s32 arg1) {
    s32 sp1C = 0;
    GbSaveBoxEntry* temp_v0 = GbSave_GetBoxEntry(arg0, arg1);

    if (temp_v0 != NULL) {
        sp1C = temp_v0->unk_000;
    }
    return sp1C;
}

void GbSave_SetBoxEntryCount(s32 arg0, s32 arg1, s32 arg2) {
    GbSaveBoxEntry* temp_v0 = GbSave_GetBoxEntry(arg0, arg1);

    if (temp_v0 != NULL) {
        temp_v0->unk_000 = arg2;
        temp_v0->unk_001[arg2] = 0xFF;
    }
}

s32 Deck_GetCapacity(s32 arg0) {
    s32 ret = 0;

    switch (arg0) {
        case 32:
            ret = 6;
            break;

        case 33:
            ret = 0x1E;
            break;

        case 34:
            ret = 0x32;
            break;

        case 35:
            ret = 0x14;
            break;
    }

    return ret;
}

s32 Deck_GetEntrySize(s32 arg0) {
    s32 ret = 0;

    switch (arg0) {
        case 32:
            ret = 0x50;
            break;
        case 33:
            ret = 0x50;
            break;
        case 34:
            ret = 2;
            break;
        case 35:
            ret = 2;
            break;
    }
    return ret;
}

s32 Deck_GetCount(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_v1 = 0;
    u8* ptr = sGbSavePorts[arg1].unk_40;

    switch (arg0) {
        case 32:
            var_v1 = ptr[0x955];
            break;

        case 33:
            var_v1 = GbSave_GetBoxEntryCount(arg1, arg2);
            break;

        case 34:
            var_v1 = ptr[0x25C];
            break;

        case 35:
            var_v1 = ptr[0x44];
            break;
    }
    return var_v1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8002274C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002274C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80022828; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80022828.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002290C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002290C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80022A00; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80022A00.s")
#endif

s32 GbSave_GetPresentPortMask(void) {
    return D_800AD330;
}

extern s8 D_800AD213;
u8 func_80022B4C(s32 arg0) {
    return *(&D_800AD213 + (arg0 * 0x48));
}

s32 GbSave_GetPortAvailability(s32 arg0) {
    s32 temp_v0 = 1 << arg0;

    if (!(D_800AD334 & temp_v0)) {
        return 1;
    }

    if (!(D_800AD335 & temp_v0)) {
        return 2;
    }

    return 0;
}

extern s8 D_800AD212;
u8 func_80022BAC(s32 arg0) {
    return *(&D_800AD212 + (arg0 * 0x48));
}

#ifdef NON_MATCHING
/* TODO: decompile func_80022BC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80022BC8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80022C40; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80022C40.s")
#endif

s32 func_8001FAB0(s32);                             /* extern */
extern s8 D_800AD210;
s32 func_80022C70(s32 arg0) {
    s8 *temp_v0;

    temp_v0 = (arg0 * 0x48) + &D_800AD210;
    if (!(M2C_FIELD(temp_v0, u16 *, 0) & 1)) {
        return -1;
    }
    return func_8001FAB0(M2C_FIELD(temp_v0, s32 *, 0x40) + 0x7B);
}

void GbSave_SetTrainerId(s32 arg0, u16 arg1) {
    if (sGbSavePorts[arg0].unk_00 & 1) {
        GbData_WriteU16BE(sGbSavePorts[arg0].unk_40 + 0x7B, arg1);
    }
}

s32 GbSave_GetBoxCount(s32 arg0) {
    s32 temp_a0;
    s32 phi_v1 = -1;

    if (sGbSavePorts[arg0].unk_00 & 1) {
        temp_a0 = GbData_ReadU16BE(sGbSavePorts[arg0].unk_40 + 0x2C2) >> 8;
        if (temp_a0 & 0x80) {
            phi_v1 = (temp_a0 & 0x7F) + 1;
        } else {
            phi_v1 = 0;
        }
    }
    return phi_v1;
}

s32 func_8001FCC0(M2C_UNK, s32, M2C_UNK);           /* extern */
extern s8 D_800AD210;
s32 func_80022D84(s32 arg0, M2C_UNK arg1)
{
  s8 *temp_v0;
  temp_v0 = (arg0 * 0x48) + (&D_800AD210);
  if (!((*((u16 *) (((s8 *) temp_v0) + 0))) & 1))
  {
    return 0;
  }
  return func_8001FCC0(arg1 & 0xFFFFFFFFFFFFFFFF, (*((s32 *) (((s8 *) temp_v0) + 0x40))) + 0x18, arg1);
}

s32 func_8001FBE4(s32);                             /* extern */
extern s8 D_800AD210;
s32 func_80022DDC(s32 arg0) {
    s8 *temp_v0;

    temp_v0 = (arg0 * 0x48) + &D_800AD210;
    if (!(M2C_FIELD(temp_v0, u16 *, 0) & 1)) {
        return 0;
    }
    return func_8001FBE4(M2C_FIELD(temp_v0, s32 *, 0x40) + 0x18);
}

s32 func_8001FCC0(M2C_UNK, s32, M2C_UNK);           /* extern */
extern s8 D_800AD210;
s32 func_80022E30(s32 arg0, M2C_UNK arg1)
{
  s8 *temp_v0;
  temp_v0 = (arg0 * 0x48) + (&D_800AD210);
  if (!((*((u16 *) (((s8 *) temp_v0) + 0))) & 1))
  {
    return 0;
  }
  return func_8001FCC0(arg1 ^ 0, (*((s32 *) (((s8 *) temp_v0) + 0x40))) + 0x71, arg1);
}

s32 func_8001FBE4(s32);                             /* extern */
extern s8 D_800AD210;
s32 func_80022E88(s32 arg0) {
    s8 *temp_v0;

    temp_v0 = (arg0 * 0x48) + &D_800AD210;
    if (!(M2C_FIELD(temp_v0, u16 *, 0) & 1)) {
        return 0;
    }
    return func_8001FBE4(M2C_FIELD(temp_v0, s32 *, 0x40) + 0x71);
}

#ifdef NON_MATCHING
/* TODO: decompile func_80022EDC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80022EDC.s")
#endif

extern s8 D_800AD210;
s32 func_80022F00(s32 arg0) {
    s32 var_v1;
    s8 *temp_v0;

    var_v1 = 0;
    if (arg0 >= 0) {
        temp_v0 = (arg0 * 0x48) + &D_800AD210;
        if (M2C_FIELD(temp_v0, u16 *, 0) & 1) {
            var_v1 = (M2C_FIELD(M2C_FIELD(temp_v0, s8 **, 0x40), s8 *, 0x46D) & 0x20) != 0;
        }
    }
    return var_v1;
}

extern s8 D_800AD210;
s32 func_80022F48(s32 arg0) {
    s32 var_v1;
    s8 *temp_v0;

    var_v1 = 0;
    if (arg0 >= 0) {
        temp_v0 = (arg0 * 0x48) + &D_800AD210;
        if (M2C_FIELD(temp_v0, u16 *, 0) & 1) {
            var_v1 = (M2C_FIELD(M2C_FIELD(temp_v0, s8 **, 0x40), s8 *, 0x513) & 1) != 0;
        }
    }
    return var_v1;
}

s32 GbSave_CopyPortSnapshot(s32 arg0, GbSavePortSnapshot* arg1) {
    s32 temp_v1 = (sGbSavePorts[arg0].unk_00 & 1) != 0;

    if (temp_v1 != 0) {
        arg1->unk_000 = sGbSavePorts[arg0].unk_02;
        arg1->unk_001 = sGbSavePorts[arg0].unk_04;
        arg1->unk_002 = sGbSavePorts[arg0].unk_38;

        _bcopy(sGbSavePorts[arg0].unk_3A, arg1->unk_004, 6);
        _bcopy(sGbSavePorts[arg0].unk_40 + 0x955, (u8*)arg1 + 0xA, 0x158);
    }
    return temp_v1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8002302C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002302C.s")
#endif

void GbSave_RebuildSeenBitfield(s32 arg0) {
    GbSavePortZero* ptr = &sGbSavePorts[arg0];
    u8* temp_s0 = ptr->unk_40;
    u8* ptr6 = ptr->unk_05;
    u8* ptr541 = ptr->unk_44;
    u8* ptr542 = ptr->unk_44 + 0x15A0;
    s32 i;

    for (i = 0; i < 19; i++) {
        ptr6[i] = 0;
    }

    GbSave_MarkSeenBits(ptr6, temp_s0[0x955], temp_s0 + 0x956);
    GbSave_MarkSeenBits(ptr6, temp_s0[0xAAD], temp_s0 + 0xAAE);

    for (i = 0; i < 4; i++) {
        GbSave_MarkSeenBits(ptr6, ptr541[i * 0x566], ptr541 + i * 0x566 + 1);
        GbSave_MarkSeenBits(ptr6, ptr542[i * 0x566], ptr542 + i * 0x566 + 1);
    }
}

s32 GbSave_GetSpeciesProgressLevel(s32 arg0, s32 arg1) {
    s32 temp_t1;
    s32 temp_t2;
    u8* ptr23;
    u8* ptr36;

    if ((arg1 > 0) && (arg1 < 0x98)) {
        ptr23 = sGbSavePorts[arg0].unk_40 + 0x1E;
        ptr36 = sGbSavePorts[arg0].unk_40 + 0x31;

        temp_t1 = (arg1 - 1) / 8;
        temp_t2 = (arg1 - 1) % 8;

        return ((ptr23[temp_t1] >> temp_t2) & 1) + ((ptr36[temp_t1] >> temp_t2) & 1) +
               ((sGbSavePorts[arg0].unk_05[temp_t1] >> temp_t2) & 1);
    }
    return 0;
}

void func_80023268(s32 arg0, s32 arg1, s32 arg2) {
    u8* temp_a3;
    u8* temp_v0;
    s32 var_a2;
    s32 var_a3;
    u8* temp_v1;

    if ((arg1 > 0) && (arg1 < 0x98)) {
        temp_v0 = (sGbSavePorts[arg0].unk_40 + 0x1E);
        temp_a3 = (sGbSavePorts[arg0].unk_40 + 0x31);
        temp_v1 = sGbSavePorts[arg0].unk_05;

        var_a2 = (arg1 - 1) / 8;
        var_a3 = (arg1 - 1) % 8;

        if (arg2 > 0) {
            temp_a3[var_a2] |= (1 << var_a3);
        } else {
            temp_a3[var_a2] &= ~(1 << var_a3);
        }

        if (arg2 >= 2) {
            temp_v0[var_a2] |= (1 << var_a3);
        } else {
            temp_v0[var_a2] &= ~(1 << var_a3);
        }

        if (arg2 >= 3) {
            temp_v1[var_a2] |= (1 << var_a3);
        } else {
            temp_v1[var_a2] &= ~(1 << var_a3);
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_800233AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800233AC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800234EC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800234EC.s")
#endif

s32 func_8002362C(s32 arg0) {
    s32 i;
    s32 temp_v1 = 0;

    for (i = 0; i < 0x97; i++) {
        temp_v1 += (sGbSavePorts[arg0].unk_05[i / 8] >> (i % 8)) & 1;
    }

    return temp_v1;
}
