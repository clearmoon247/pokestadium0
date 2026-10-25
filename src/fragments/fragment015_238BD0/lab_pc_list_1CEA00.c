/* Stadium Zero fragment015_238BD0. */
/* C ported from the Stadium 1 decomp: src/fragments/lab_pc/lab_pc_1B4EA0.c, src/fragments/lab_pc_list/lab_pc_list_1CEA00.c. */

#include "fragments/lab_pc_list/lab_pc_list.h"
#include "graphics_textures.h"
#include "input.h"
#include "gb_data.h"
#include "pokemon_stats.h"
#include "save_data.h"
#include "game_state.h"
#include "table_view.h"
#include "text_system.h"
#include "status_icons.h"
#include "gb_save.h"
#include "jpeg_stream.h"
#include "audio_sfx.h"
#include "memmap.h"
#include "memory.h"
#include "stage_loader.h"
#include "fragments/pokemon_lab_support/pokemon_lab_support.h"
extern s32 pad_D_8831A4DC[8];
typedef struct unk_D_88317298 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} unk_D_88317298;
typedef struct unk_D_883172F4 {
    /* 0x00 */ u16* unk_00;
    /* 0x04 */ s32 unk_04;
} unk_D_883172F4;

#include "fragments/lab_pc/lab_pc.h"
#include "graphics_textures.h"
#include "input.h"
#include "gb_data.h"
#include "pokemon_stats.h"
#include "save_data.h"
#include "game_state.h"
#include "table_view.h"
#include "text_system.h"
#include "gb_save.h"
#include "audio_sfx.h"
#include "hal_libc.h"
#include "memmap.h"
#include "memory.h"
#include "stage_loader.h"
typedef struct unk_D_88218060 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Color_RGBA8* unk_04;
} unk_D_88218060;
typedef struct unk_D_88218070 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8* unk_08;
    /* 0x0C */ s16 unk_0C;
    /* 0x10 */ Color_RGBA8* unk_10;
} unk_D_88218070;

#include "fragments/particle_math/particle_math.h"
#include "m2c_macros.h"
void func_8002ED18(s8*, s32, s8*);

void func_8900020C(void);
s32 LabItem_ComputeRemainingCapacity(s32 arg0, unk_func_8820BE14_06C* arg1);
s32 LabItem_ComputeMaxTransferQuantity(s32 arg0, unk_func_8820BE14_06C* arg1);
s32 LabItem_FindOrAllocateGamePakBoxSlot(unk_func_8821421C_07C* arg0, s32 arg1, char* arg2);
void LabItem_LoadGamePakBoxSlots(unk_func_8821421C_07C* arg0);
void LabItem_ReadDeckEntries(s32 arg0, s32 arg1, s32 arg2, unk_func_8820BE14_06C* arg3);

void func_89000020(unk_func_8830867C_02C_0CC* arg0, s32 (*arg1)(s32, s32)) {
    func_800274E0(arg0->unk_00, arg1, arg0->unk_08);
}

#ifdef NON_MATCHING
/* TODO: decompile func_89000048; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89000048.s")
#endif

void func_800275E4(s32, s32);
int func_800274E0();
void func_80030744(s32*, s32);

void func_890000A4(s32* arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 var_s3;
    s32 var_v0;
    s32* temp_s4;
    u8 sp3C[2];
    u8* var_s2;
    u8* temp_v1;

    temp_s4 = (s32*)arg0[0];
    temp_v1 = (u8*)temp_s4[0];
    i = 0;

    if (temp_s4[2] > 0) {
        var_s2 = temp_v1;
        do {
            if (arg1 == var_s2[0]) {
                arg2 += var_s2[1];
                func_800275E4(arg0[0], i);
                if (i < arg0[2]) {
                    arg0[2]--;
                }
            } else {
                i++;
                var_s2 += 2;
            }
        } while (i < temp_s4[2]);
    }

    sp3C[0] = arg1;
    var_s3 = arg0[2];

    while (arg2 > 0) {
        if (arg2 < 0x63) {
            var_v0 = arg2;
        } else {
            var_v0 = 0x63;
        }
        arg2 -= var_v0;
        sp3C[1] = var_v0;
        func_800274E0(temp_s4, sp3C, var_s3++);
    }

    func_80030744(arg0, arg0[2]);
}

typedef struct LabItemGrid {
    /* 0x00 */ u8* unk_00;
    /* 0x04 */ char unk04[0x8];
    /* 0x0C */ s32 unk_0C;
} LabItemGrid;

typedef struct LabItemCursor {
    /* 0x00 */ LabItemGrid* unk_00;
    /* 0x04 */ char unk04[0x4];
    /* 0x08 */ s32 unk_08;
} LabItemCursor;

void func_89000048(LabItemCursor* arg0);

void func_890001B4(LabItemCursor* arg0, s32 arg1) {
    u8* temp_v1 = &arg0->unk_00->unk_00[arg0->unk_00->unk_0C * arg0->unk_08];

    if (arg1 >= temp_v1[1]) {
        func_89000048(arg0);
        return;
    }
    temp_v1[1] -= arg1;
}

void func_8900020C(void) {
}

s32 LabItem_ComputeRemainingCapacity(s32 arg0, unk_func_8820BE14_06C* arg1) {
    s32 i;
    s32 var_v1 = 0;
    u8* var_v0 = arg1->unk_00;

    for (i = 0; i < arg1->unk_08; i++, var_v0 += 2) {
        if (arg0 == var_v0[0]) {
            var_v1 = (var_v1 - var_v0[1]) + 0x63;
        }
    }

    return var_v1;
}

s32 LabItem_ComputeMaxTransferQuantity(s32 arg0, unk_func_8820BE14_06C* arg1) {
    s32 var_v1;

    if (LabItem_IsQuantitylessItemForOperation(arg0) != 0) {
        if (arg1->unk_08 < arg1->unk_04) {
            var_v1 = 1;
        } else {
            var_v1 = 0;
        }
    } else if (arg1->unk_08 < arg1->unk_04) {
        var_v1 = 0x63;
    } else {
        var_v1 = LabItem_ComputeRemainingCapacity(arg0, arg1);
    }
    return var_v1;
}

s32 LabItem_FindOrAllocateGamePakBoxSlot(unk_func_8821421C_07C* arg0, s32 arg1, char* arg2) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if ((arg0[i].unk_00 != 0) && (arg1 == arg0[i].unk_04) && (HAL_Strcmp(arg0[i].unk_08, arg2) == 0)) {
            return i;
        }
    }

    for (i = 0; i < 4; i++) {
        if (arg0[i].unk_00 == 0) {
            return i;
        }
    }

    return -1;
}

void LabItem_LoadGamePakBoxSlots(unk_func_8821421C_07C* arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        arg0[i].unk_00 = Deck_IsSaveEntryPresent(0x12, i);
        if (arg0[i].unk_00 != 0) {
            arg0[i].unk_04 = Deck_GetSaveEntryTrainerId(0x12, i) & 0xFFFF;
            Deck_GetSaveEntryName(0x12, i, arg0[i].unk_08);
        }
    }
}

void LabItem_ReadDeckEntries(s32 arg0, s32 arg1, s32 arg2, unk_func_8820BE14_06C* arg3) {
    DeckHandle* sp1C = Deck_Open(arg0, arg1, arg2, 0);

    arg3->unk_08 = Deck_ReadEntries(arg3->unk_00, arg3->unk_04, sp1C);
    Deck_CloseAndFlush(sp1C);
}

void LabItem_WriteDeckBack(s32 arg0, s32 arg1, s32 arg2, unk_func_8820BE14_06C* arg3, s32 arg4, char* arg5, s32 arg6) {
    DeckHandle* sp2C;

    if (arg6 != -1) {
        if (1) {}
        sp2C = Deck_OpenAndSetName(arg0, arg1, arg2, arg4, arg5, arg6);
    } else {
        sp2C = Deck_Open(arg0, arg1, arg2, 1);
    }

    Deck_WriteEntries(arg3->unk_00, arg3->unk_08, sp2C);

    if ((arg0 == 0x10) || (arg0 == 0x11) || (arg0 == 0x12) || (arg0 == 0x13)) {
        Deck_CloseAndFlushBox(sp2C);
    } else {
        Deck_CloseAndFlush(sp2C);
    }
}

M2C_UNK func_8002C064(M2C_UNK, M2C_UNK, u8, u8, s32); /* extern */
extern M2C_UNK D_8900A5B8;

void func_8900054C(void) {
    func_8002C064(0x38, 0x1E0, M2C_FIELD(&D_8900A5B8, u8 *, 0), M2C_FIELD(&D_8900A5B8, u8 *, 1), (s32) M2C_FIELD(&D_8900A5B8, u8 *, 2));
}

#ifdef NON_MATCHING
/* TODO: decompile func_89000588; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89000588.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89000694; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89000694.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89000828; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89000828.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_890008C8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_890008C8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89000960; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89000960.s")
#endif

s32 func_8002B638(s8 *);                          /* extern */
s32 func_8002BC14(s32);                             /* extern */
M2C_UNK func_8002CEEC(s8 *, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_8002D138(s8 *);                          /* extern */
M2C_UNK func_8003F6AC(M2C_UNK);                     /* extern */
extern s32 D_800603C0;
extern M2C_UNK D_89018474;

s32 func_89000BEC(s8 *arg0) {
    s32 sp2C;
    s32 temp_v0;
    s32 temp_v0_2;

    sp2C = 0;
    temp_v0 = M2C_FIELD(arg0, s32 *, 0);
    switch (temp_v0) {                              /* irregular */
    case 0:
        if (func_8002B638(arg0 + 0x34) == 0) {
            temp_v0_2 = func_8002BC14(D_800603C0);
            if (temp_v0_2 == -1) {
                func_8003F6AC(3);
                sp2C = -1;
            } else if (temp_v0_2 == 1) {
                if (M2C_FIELD(arg0, s32 *, 0x30) < M2C_FIELD(arg0, s32 *, 0x34)) {
                    func_8003F6AC(8);
                    func_8002CEEC(arg0 + 0x48, &D_89018474, 0, 1, 0);
                    M2C_FIELD(arg0, s32 *, 0) = 1;
                } else {
                    func_8003F6AC(2);
                    sp2C = 1;
                }
            }
        }
        break;
    case 1:
        if (func_8002D138(arg0 + 0x48) == 1) {
            M2C_FIELD(arg0, s32 *, 0) = 0;
            M2C_FIELD(arg0, s32 *, 0x34) = (s32) M2C_FIELD(arg0, s32 *, 0x30);
        }
        break;
    }
    return sp2C;
}

void func_89000CF0(s8 *arg0, s8 *arg1)
{
  s32 var_v0;
  u16 *temp_a1;
  s8 *var_v1;
  s8 *new_var;
  var_v0 = 0;
  new_var = ((s8 *) arg0) + 0x30;
  var_v1 = arg1;
  do
  {
    if ((*((s32 *) (((s8 *) var_v1) + 8))) == 0)
    {
      temp_a1 = (*((s32 *) new_var)) + (var_v0 * 2);
      *temp_a1 |= 0x100;
    }
    var_v0 += 1;
    var_v1 += 0x10;
  }
  while (var_v0 != 3);
}

void func_89000D34(s8 *arg0, s32 arg1) {
    u16 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x30) + (arg1 * 2);
    *temp_v0 |= 1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_89000D50; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89000D50.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89000E98; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89000E98.s")
#endif

s32 func_8002AE6C();                                /* extern */
M2C_UNK func_8002D9B8(s8 *, s32, s32, M2C_UNK, s32); /* extern */

void func_89000F5C(s8 *arg0) {
    if (func_8002AE6C() == 0) {
        func_8002D9B8(arg0 + 0x2C, M2C_FIELD(arg0, s32 *, 0) + 6, M2C_FIELD(arg0, s32 *, 4) + 0xA, 0xFFEF, 0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_89000FA4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89000FA4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89001018; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89001018.s")
#endif

void func_89001230(s8* arg0, s32 arg1) {
    func_8002ED18(arg0, arg1, arg0 + 0x44);
}

#ifdef NON_MATCHING
/* TODO: decompile func_89001250; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89001250.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_890012C4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_890012C4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_890013F8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_890013F8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8900147C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_8900147C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_890017FC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_890017FC.s")
#endif

M2C_UNK func_8001A384(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8001A944(s32, s32, s32);               /* extern */
M2C_UNK func_8001AA9C(u8, u8, u8, u8);              /* extern */
M2C_UNK func_8001AAE4(u8, u8, u8, u8);              /* extern */
M2C_UNK func_8001AB6C();                            /* extern */
M2C_UNK func_8001ABBC();                            /* extern */
M2C_UNK func_8001ABE8();                            /* extern */
M2C_UNK func_8001AC3C();                            /* extern */
u32 func_800566BC(s32);                             /* extern */

void func_890019C8(s32 arg0, s32 arg1, s32 arg2, s8 *arg3) {
    func_8001AB6C();
    func_8001A384(0x20, 0);
    func_8001AA9C(M2C_FIELD(arg3, u8 *, 0), M2C_FIELD(arg3, u8 *, 1), M2C_FIELD(arg3, u8 *, 2), M2C_FIELD(arg3, u8 *, 3));
    func_8001ABE8();
    func_8001AAE4(M2C_FIELD(arg3, u8 *, 4), M2C_FIELD(arg3, u8 *, 5), M2C_FIELD(arg3, u8 *, 6), M2C_FIELD(arg3, u8 *, 7));
    func_8001A944(((u32) (0x178 - ((func_800566BC(arg2) >> 1) << 5)) >> 1) + arg0, arg1 + 0xC, arg2);
    func_8001AC3C();
    func_8001ABBC();
}

#ifdef NON_MATCHING
/* TODO: decompile func_89001A7C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89001A7C.s")
#endif

M2C_UNK func_8001A384(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8001A944(s32, s32, s32);               /* extern */
M2C_UNK func_8001AA9C(u8, u8, u8, u8);              /* extern */
M2C_UNK func_8001AB2C(M2C_UNK);                     /* extern */
M2C_UNK func_8001AB6C();                            /* extern */
M2C_UNK func_8001ABBC();                            /* extern */
extern M2C_UNK D_800734A8;

void func_89001B10(s32 arg0, s32 arg1, s32 arg2) {
    func_8001AB6C();
    func_8001A384(8, 0);
    func_8001AA9C(M2C_FIELD(&D_800734A8, u8 *, 0), M2C_FIELD(&D_800734A8, u8 *, 1), M2C_FIELD(&D_800734A8, u8 *, 2), M2C_FIELD(&D_800734A8, u8 *, 3));
    func_8001AB2C(0x1C);
    func_8001A944(arg0 + 8, arg1 + 4, arg2);
    func_8001ABBC();
}

#ifdef NON_MATCHING
/* TODO: decompile func_89001B88; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89001B88.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89001CB0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89001CB0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_890020C0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_890020C0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8900219C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_8900219C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89002248; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89002248.s")
#endif


void func_890022D0(s8 *arg0) {
    s32 temp_v0;
    s8 *temp_a0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1A4);
    temp_a0 = arg0 + 0x2F8;
    M2C_FIELD(temp_a0, s32 *, -0x120) = temp_v0;
    func_89001230(temp_a0, M2C_FIELD(arg0, s32 *, 0x490) + (temp_v0 * 0x10));
    M2C_FIELD(arg0, s32 *, 0) = 4;
}

#ifdef NON_MATCHING
/* TODO: decompile func_89002318; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89002318.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89002A80; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89002A80.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89002C10; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89002C10.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89002D14; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89002D14.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89002DE4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89002DE4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89002E58; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89002E58.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_890030C8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_890030C8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8900323C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_8900323C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_890032E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_890032E4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8900352C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_8900352C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89003650; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89003650.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8900379C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_8900379C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89003880; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89003880.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89003A50; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89003A50.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89003A88; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89003A88.s")
#endif

extern Color_RGBA8 D_8900A6E8;
extern Color_RGBA8 D_80073520;
void func_8002A354(s32, s32, s32, s32, Color_RGBA8);
void func_80029A64(s32, s32, s32, s32, Color_RGBA8);
void func_80027F20(s32);
void func_89003D40(s32 arg0, s32 arg1, char* arg2, s32 arg3, s32 arg4, s32* arg5) {
    s32 temp_v0 = *arg5;

    if (arg4 & 8) {
        func_8002A354(arg0 + 3, arg1 + 3, temp_v0 - 6, 0x1A, D_8900A6E8);
    } else if (arg4 & 2) {
        func_80029A64(arg0 + 2, arg1 + 2, temp_v0 - 4, 0x1C, D_80073520);
    }
    Font_BeginTranslucentTextRendering();
    func_80027F20(arg4);
    Font_SetActive(0x10, 0);
    Font_Printf(arg0 + 8, arg1 + 4, arg2);
    Font_EndTexturedTextRendering();
}

#ifdef NON_MATCHING
/* TODO: decompile func_89003E2C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89003E2C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89003ECC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89003ECC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8900408C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_8900408C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89004120; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89004120.s")
#endif

M2C_UNK func_800069CC();                            /* extern */
M2C_UNK func_80028060(M2C_UNK, M2C_UNK *, M2C_UNK *, s32); /* extern */
M2C_UNK func_89003ECC(s32);                         /* extern */
extern M2C_UNK D_89018900;
extern s32 D_89019108;
extern M2C_UNK D_89019110;

void func_89004184(s32 arg0) {
    M2C_UNK *var_a1;

    func_800069CC();
    if (D_89019108 == -1) {
        var_a1 = NULL;
    } else {
        var_a1 = &D_89019110;
    }
    func_80028060(0, var_a1, &D_89018900, D_89019108);
    func_8900054C();
    func_89003ECC(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_890041E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_890041E4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89004244; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89004244.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8900429C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_8900429C.s")
#endif

M2C_UNK func_8000B1FC();                            /* extern */
M2C_UNK func_8000B220();                            /* extern */
M2C_UNK func_89003650(M2C_UNK *);                   /* extern */
M2C_UNK func_8900379C(M2C_UNK *);                   /* extern */
s32 func_89003A88(M2C_UNK *);                       /* extern */
s32 func_890041E4(M2C_UNK *);                       /* extern */
M2C_UNK func_890067B0(M2C_UNK *, M2C_UNK *);        /* extern */
M2C_UNK func_890069C0(M2C_UNK *);                   /* extern */
M2C_UNK func_890069E8(M2C_UNK *);                   /* extern */
s32 func_89006D60(M2C_UNK *);                       /* extern */
M2C_UNK func_8900A014(M2C_UNK *);                   /* extern */
M2C_UNK func_8900A1A4(M2C_UNK *);                   /* extern */
M2C_UNK func_8900A1CC(M2C_UNK *);                   /* extern */
s32 func_8900A324(M2C_UNK *);                       /* extern */
extern M2C_UNK D_89018918;
extern M2C_UNK D_89019128;
extern M2C_UNK D_89019B98;
extern M2C_UNK D_89021428;
extern M2C_UNK D_89028950;
extern s32 D_890289D4;

s32 func_890043BC(s32 arg0) {
    s32 sp1C;
    s32 temp_v0;

    sp1C = 0;
    func_8000B1FC();
    func_8000B220();
    switch (D_890289D4) {                           /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        func_89004184(&D_89028950);
        temp_v0 = func_890041E4(&D_89028950);
        if (temp_v0 == -1) {
            sp1C = 1;
        } else if (temp_v0 > 0) {
            D_890289D4 = temp_v0 + 1;
            switch (D_890289D4) {                   /* switch 2; irregular */
            case 2:                                 /* switch 2 */
                func_890067B0(&D_89019B98, &D_89018918);
                break;
            case 3:                                 /* switch 2 */
                func_89003650(&D_89019128);
                break;
            case 4:                                 /* switch 2 */
                func_8900A014(&D_89021428);
                break;
            }
        }
        break;
    case 3:                                         /* switch 1 */
        func_8900379C(&D_89019128);
        if (func_89003A88(&D_89019128) != 0) {
            D_890289D4 = 1;
        }
        break;
    case 2:                                         /* switch 1 */
        func_890069E8(&D_89019B98);
        if (func_89006D60(&D_89019B98) != 0) {
            D_890289D4 = 1;
            func_890069C0(&D_89019B98);
        }
        break;
    case 4:                                         /* switch 1 */
        func_8900A1CC(&D_89021428);
        if (func_8900A324(&D_89021428) != 0) {
            D_890289D4 = 1;
            func_8900A1A4(&D_89021428);
        }
        break;
    }
    return sp1C;
}

extern FontContext* D_86A06200;
#ifdef NON_MATCHING
/* TODO: decompile func_89004560; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89004560.s")
#endif
