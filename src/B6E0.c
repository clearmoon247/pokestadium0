/* Stadium Zero resident code. */

#include "global.h"
#include "m2c_macros.h"

M2C_UNK (*func_80002C80(M2C_UNK *))(s32);           /* extern */
M2C_UNK func_80004920(s32);                         /* extern */
M2C_UNK func_80004EA8(s32);                         /* extern */
M2C_UNK func_800567E0(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_800594D0(M2C_UNK);                     /* extern */
extern M2C_UNK D_800A9710;
extern s32 D_800AAF44;
extern M2C_UNK D_81106830;

void func_8000AAE0(s32 arg0) {
    M2C_UNK (*temp_s2)(s32);

    temp_s2 = func_80002C80(&D_81106830);
    func_800594D0(0x01000F00);
    func_800567E0(D_800AAF44 + 0x21C0, D_800AAF44 + 0x21B0, 1);
    func_80004EA8(D_800AAF44 + 0x21B0);
loop_1:
    func_80004920(D_800AAF44 + 0x21B0);
    if (M2C_FIELD(&D_800A9710, s16 *, 0xA38) >= 0x15) {
        goto loop_1;
    }
    temp_s2(D_800AAF44);
    goto loop_1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8000AB98; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8000AB98.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8000AC78; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8000AC78.s")
#endif

M2C_UNK func_8004D1C0(s32, s32 *, M2C_UNK);         /* extern */
extern s32 D_800AAF40;

s32 func_8000ADE8(void) {
    s32 sp1C;

    func_8004D1C0(D_800AAF40 + 0x21B4, &sp1C, 1);
    return sp1C;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8000AE1C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8000AE1C.s")
#endif
