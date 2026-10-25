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

#ifdef NON_MATCHING
/* TODO: decompile func_80021100; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80021100.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800211C4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800211C4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80021248; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80021248.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_800214F0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800214F0.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_80021720; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80021720.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002178C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002178C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80021894; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80021894.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80021910; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80021910.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80021A8C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80021A8C.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_80021F50; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80021F50.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80021FF4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80021FF4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002207C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002207C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80022118; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80022118.s")
#endif

void GbSave_RequirePakPresent(s32 arg0) {
    if (GbTower_CheckPakRemoved(arg0, 0) == 0) {
        Game_ShutdownAndLoadFragment(arg0, 2);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_800221BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800221BC.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_800226BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800226BC.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_80022CC4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80022CC4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80022D18; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80022D18.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_80022F90; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80022F90.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8002302C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002302C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800230C4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800230C4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800231C8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800231C8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80023268; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80023268.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_8002362C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8002362C.s")
#endif
