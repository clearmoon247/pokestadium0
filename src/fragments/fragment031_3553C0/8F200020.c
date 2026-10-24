/* Stadium Zero fragment031_3553C0. */

#include "global.h"
#include "m2c_macros.h"

#ifdef NON_MATCHING
/* TODO: decompile func_8F200020; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment031_3553C0/func_8F200020.s")
#endif

s32 func_8000515C(M2C_UNK);                         /* extern */
M2C_UNK func_8F200020(s32, s32);                    /* extern */
extern u16 D_80060484;

void func_8F20010C(s32 arg0, s8 *arg1) {
    s32 temp_v0;

    if (arg0 == 2) {
        temp_v0 = func_8000515C(0x50);
        M2C_FIELD(arg1, s32 *, 0x18) = temp_v0;
        func_8F200020(temp_v0, D_80060484 & 7);
    }
}
