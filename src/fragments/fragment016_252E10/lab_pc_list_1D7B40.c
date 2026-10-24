/* Stadium Zero fragment016_252E10. */
/* C ported from the Stadium 1 decomp: src/fragments/lab_pc_list/lab_pc_list_1D7B40.c. */

#include "fragments/lab_pc_list/lab_pc_list.h"
#include "graphics_textures.h"
#include "input.h"
#include "gb_data.h"
#include "game_state.h"
#include "table_view.h"
#include "text_system.h"
#include "gb_save.h"
#include "audio_sfx.h"
#include "hal_libc.h"
#include "memmap.h"
#include "memory.h"
#include "pokemon_stats.h"
extern u8 D_8910D7D0[];
typedef struct unk_func_88309614 {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ s32 unk_08;
} unk_func_88309614;
typedef struct unk_func_88313894 {
    /* 0x00 */ char unk00[0xC];
    /* 0x0C */ unk_func_8830867C_02C_0CC_000_000* unk_0C;
    /* 0x10 */ char unk10[0xC];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ unk_func_88313894_020 unk_20;
    /* 0x40 */ unk_func_88313894_020 unk_40;
} unk_func_88313894;

#include "m2c_macros.h"

void func_891053E0(void);
void func_89108F0C(void);

#ifdef NON_MATCHING
/* TODO: decompile func_89104C70; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89104C70.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89104D14; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89104D14.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89104E38; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89104E38.s")
#endif

M2C_UNK func_8002DC04(s32);                         /* extern */

void func_89104E94(s32 arg0) {
    func_8002DC04(arg0 + 0x2C);
}

#ifdef NON_MATCHING
/* TODO: decompile func_89104EB4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89104EB4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89104FC0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89104FC0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89105144; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89105144.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_891051A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_891051A4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89105200; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89105200.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89105340; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89105340.s")
#endif

M2C_UNK func_8002DC04(s32);                         /* extern */

void func_89105390(s32 arg0) {
    func_8002DC04(arg0 + 0x2C);
}

s32 func_891053B0(s8 *arg0) {
    s32 var_v1;

    var_v1 = 0x100;
    if (M2C_FIELD(arg0, s32 *, 0xC) != 0) {
        var_v1 = 0x108;
    }
    if (M2C_FIELD(arg0, s32 *, 0x1C) > 0) {
        var_v1 &= ~0x100;
    }
    return var_v1;
}

void func_891053E0(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_891053E8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_891053E8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8910548C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_8910548C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89105504; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89105504.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89105560; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89105560.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8910576C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_8910576C.s")
#endif

M2C_UNK func_800295E8(s32, s32, s32, s32, M2C_UNK *); /* extern */
M2C_UNK func_8002A8E0(s8 *);                      /* extern */
M2C_UNK func_8002DAD8(s8 *, s32, s32, s32, s8 *); /* extern */
extern M2C_UNK D_80073554;

void func_891057FC(s8 *arg0, s32 arg1) {
    func_800295E8(M2C_FIELD(arg0, s32 *, 0) - 6, M2C_FIELD(arg0, s32 *, 4) - 6, M2C_FIELD(arg0, s32 *, 8) + 0xC, M2C_FIELD(arg0, s32 *, 0xC) + 0xC, &D_80073554);
    func_8002A8E0(arg0);
    func_8002DAD8(arg0 + 0x20, M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 4) + 4, arg1 | 0xFFED, arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8910587C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_8910587C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89105924; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89105924.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8910597C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_8910597C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_891059FC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_891059FC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89105A98; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89105A98.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89105AD4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89105AD4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89105C54; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89105C54.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89105E70; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89105E70.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_891060BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_891060BC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89106254; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89106254.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89106384; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89106384.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89106424; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89106424.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89106570; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89106570.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8910666C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_8910666C.s")
#endif

M2C_UNK func_8002DC04(s32);                         /* extern */

void func_891066C0(s32 arg0) {
    func_8002DC04(arg0 + 0x40);
}

#ifdef NON_MATCHING
/* TODO: decompile func_891066E0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_891066E0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89106864; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89106864.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89106B54; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89106B54.s")
#endif

s32 func_8000B30C();                                /* extern */
M2C_UNK func_8002B204(s8 *, s32, s8 *);         /* extern */
M2C_UNK func_8002B2E4(s32, s32, s8 *);            /* extern */
M2C_UNK func_8002B4B4(s8 *, s32, s8 *);         /* extern */
s32 func_8002BC14(s32, s32, s8 *);                /* extern */
M2C_UNK func_8003F6AC(M2C_UNK);                     /* extern */
extern s32 D_800603C0;

s32 func_89106C98(s8 *arg0) {
    s32 sp1C;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;

    sp1C = 0;
    temp_v1 = func_8000B30C() & 0xFFFF;
    if (temp_v1 & 0x300) {
        func_8002B2E4(arg0 + 0xD8, temp_v1, arg0);
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 0xDC);
        if (temp_v1_2 < 3) {
            M2C_FIELD(arg0, s32 *, 0xE4) = 0;
            M2C_FIELD(arg0, s32 *, 0xB4) = (s32) (2 - temp_v1_2);
        } else if (temp_v1_2 < 6) {
            M2C_FIELD(arg0, s32 *, 0xE4) = 1;
            M2C_FIELD(arg0, s32 *, 0xC8) = (s32) (5 - temp_v1_2);
        } else {
            M2C_FIELD(arg0, s32 *, 0xE4) = 2;
            M2C_FIELD(arg0, s32 *, 0xD0) = 0;
        }
    } else if (temp_v1 & 0xC00) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0xE4);
        switch (temp_v0) {                          /* irregular */
        case 0:
            func_8002B4B4(arg0 + 0xA4, temp_v1, arg0);
            break;
        case 1:
            func_8002B4B4(arg0 + 0xB8, temp_v1, arg0);
            break;
        case 2:
            func_8002B204(arg0 + 0xCC, temp_v1, arg0);
            break;
        }
    } else if (temp_v1 == 0) {
        temp_v0_2 = func_8002BC14(D_800603C0, temp_v1, arg0);
        if (temp_v0_2 == -1) {
            func_8003F6AC(3);
            sp1C = -1;
        } else if ((temp_v0_2 == 1) && (M2C_FIELD(arg0, s32 *, 0xE4) == 2)) {
            if (M2C_FIELD(arg0, s32 *, 0xD0) == 0) {
                func_8003F6AC(2);
                sp1C = 1;
            } else if (!(M2C_FIELD(arg0, s32 *, 0x3C) & 1)) {
                func_8003F6AC(2);
                sp1C = 2;
            } else {
                func_8003F6AC(8);
            }
        }
    }
    return sp1C;
}

#ifdef NON_MATCHING
/* TODO: decompile func_89106E34; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89106E34.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89106E64; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89106E64.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89106F74; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89106F74.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89106FD8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89106FD8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8910713C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_8910713C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89107170; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89107170.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_891071A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_891071A4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_891074CC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_891074CC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89107614; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89107614.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89107850; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89107850.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_891078E0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_891078E0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89107A60; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89107A60.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89107D7C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89107D7C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89107EC4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89107EC4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89108108; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89108108.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_891081A8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_891081A8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89108450; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89108450.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_891084B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_891084B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89108650; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89108650.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_891089BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_891089BC.s")
#endif

void func_89108F0C(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_89108F14; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89108F14.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89108F94; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment016_252E10/func_89108F94.s")
#endif

M2C_UNK func_8003F6AC(M2C_UNK);                     /* extern */

s32 func_89109174(s32 arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (M2C_FIELD(D_800603C0, u16 *, 8) & 0xC000) {
        func_8003F6AC(3);
        var_v1 = 1;
    }
    return var_v1;
}
