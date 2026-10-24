/* Stadium Zero fragment032_35C390. */

#include "global.h"
#include "m2c_macros.h"

s32 func_8004D300(s32);                             /* extern */
s32 func_8F500020(s32 arg0) {
    s32 temp_a0;

    temp_a0 = func_8004D300(1);
    if (!((*(volatile s32 *)0xA4600010) & 3) && (((*(volatile s32 *)0xB0000D10) & 0xFFFF) != 0x400)) {
        arg0 = -1;
    }
    func_8004D300(temp_a0);
    return arg0;
}

extern s8 *D_80060490;

void func_8F500088(s32 arg0, s8 *arg1) {
    if (arg0 == 2) {
        M2C_FIELD(arg1, s16 *, 0x1A) = (s16) (M2C_FIELD(D_80060490, s16 *, 0x18) - 1);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8F5000AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment032_35C390/func_8F5000AC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8F50010C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment032_35C390/func_8F50010C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8F500188; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment032_35C390/func_8F500188.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8F5001C4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment032_35C390/func_8F5001C4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8F500238; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment032_35C390/func_8F500238.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8F500298; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment032_35C390/func_8F500298.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8F500358; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment032_35C390/func_8F500358.s")
#endif
