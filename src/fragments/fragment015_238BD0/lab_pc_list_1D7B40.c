/* Stadium Zero fragment015_238BD0. */
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

void func_89004708(void);
void func_89004710(void);

#ifdef NON_MATCHING
/* TODO: decompile func_89004680; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89004680.s")
#endif

void func_89004708(void) {
}

void func_89004710(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_89004718; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89004718.s")
#endif

void func_890047E4(s8 *arg0, s8 *arg1) {
    u16 *temp_v0;

    if (M2C_FIELD(arg1, s32 *, 8) == 1) {
        temp_v0 = M2C_FIELD(arg0, u16 **, 0x30);
        *temp_v0 |= 0x200;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8900480C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_8900480C.s")
#endif

void func_890048EC(s8 *arg0, s32 arg1) {
    u16 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x30) + (arg1 * 2);
    *temp_v0 |= 1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_89004908; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89004908.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89004AD4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89004AD4.s")
#endif

s32 func_8002AE6C();                                /* extern */
M2C_UNK func_8002D9B8(s8 *, s32, s32, M2C_UNK, s32); /* extern */

void func_89004B98(s8 *arg0) {
    if (func_8002AE6C() == 0) {
        func_8002D9B8(arg0 + 0x2C, M2C_FIELD(arg0, s32 *, 0) + 6, M2C_FIELD(arg0, s32 *, 4) + 0xA, 0xFFEF, 0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_89004BE0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89004BE0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89004C54; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89004C54.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89004E1C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89004E1C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89004E3C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89004E3C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89004EB0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89004EB0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89004FE4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89004FE4.s")
#endif

M2C_UNK func_8002B054(M2C_UNK, s32);                /* extern */

void func_89005068(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    func_8002B054(arg2, arg4);
}

#ifdef NON_MATCHING
/* TODO: decompile func_89005098; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89005098.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_890054D4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_890054D4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_890056A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_890056A4.s")
#endif

M2C_UNK func_8001A384(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8001A944(s32, s32, s32);               /* extern */
M2C_UNK func_8001AA9C(u8, u8, u8, u8);              /* extern */
M2C_UNK func_8001AB2C(M2C_UNK);                     /* extern */
M2C_UNK func_8001AB6C();                            /* extern */
M2C_UNK func_8001ABBC();                            /* extern */
extern M2C_UNK D_800734A8;

void func_89005958(s32 arg0, s32 arg1, s32 arg2) {
    func_8001AB6C();
    func_8001A384(0x10, 0);
    func_8001AA9C(M2C_FIELD(&D_800734A8, u8 *, 0), M2C_FIELD(&D_800734A8, u8 *, 1), M2C_FIELD(&D_800734A8, u8 *, 2), M2C_FIELD(&D_800734A8, u8 *, 3));
    func_8001AB2C(0x2C);
    func_8001A944(arg0 + 0xC, arg1 + 0x14, arg2);
    func_8001ABBC();
}

#ifdef NON_MATCHING
/* TODO: decompile func_890059D0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_890059D0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89005AE0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89005AE0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89005E14; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89005E14.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89005EA4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89005EA4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89005F2C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89005F2C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89005FD8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89005FD8.s")
#endif

M2C_UNK func_89004E1C(s8 *, s32, s8 *);         /* extern */

void func_89006054(s8 *arg0) {
    s32 temp_v0;
    s8 *temp_a0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x248);
    temp_a0 = arg0 + 0x31C;
    M2C_FIELD(temp_a0, s32 *, -0x8C) = temp_v0;
    func_89004E1C(temp_a0, M2C_FIELD(arg0, s32 *, 0x3A8) + (temp_v0 * 0x10), arg0);
    M2C_FIELD(arg0, s32 *, 0) = 4;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8900609C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_8900609C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_890067B0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_890067B0.s")
#endif

M2C_UNK func_80002620(M2C_UNK);                     /* extern */

void func_890069C0(s32 arg0) {
    func_80002620(0x4F545043);
}

#ifdef NON_MATCHING
/* TODO: decompile func_890069E8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_890069E8.s")
#endif

M2C_UNK func_80023268(s32, u8, M2C_UNK);            /* extern */
extern s32 D_89019108;

void func_89006AB4(s8 *arg0) {
    s32 var_s1;
    u8 *var_s0;

    var_s0 = M2C_FIELD(arg0, u8 **, 0);
    var_s1 = 0;
    if (M2C_FIELD(arg0, s32 *, 8) > 0) {
        do {
            func_80023268(D_89019108, *var_s0, 3);
            var_s1 += 1;
            var_s0 += 0x50;
        } while (var_s1 < M2C_FIELD(arg0, s32 *, 8));
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_89006B2C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89006B2C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89006CDC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89006CDC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_89006D60; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment015_238BD0/func_89006D60.s")
#endif
