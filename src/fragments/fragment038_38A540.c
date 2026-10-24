/* Stadium Zero fragment038_38A540. */

#include "global.h"
#include "m2c_macros.h"

#ifdef NON_MATCHING
/* TODO: decompile func_8F400020; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment038_38A540/func_8F400020.s")
#endif

s32 func_8F400020(s32);                             /* extern */
extern s8 *D_8006049C;

void func_8F400088(s32 arg0, s8 *arg1) {
    if (arg0 == 2) {
        M2C_FIELD(arg1, s32 *, 0xC) = func_8F400020(M2C_FIELD(arg1, s32 *, 0xC));
        M2C_FIELD(arg1, s16 *, 0x1A) = (s16) M2C_FIELD(D_8006049C, s32 *, 0x14);
    }
}
