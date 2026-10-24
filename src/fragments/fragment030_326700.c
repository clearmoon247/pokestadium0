/* Stadium Zero fragment030_326700. */

#include "global.h"
#include "m2c_macros.h"

#ifdef NON_MATCHING
/* TODO: decompile func_8F100020; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment030_326700/func_8F100020.s")
#endif

s32 func_8000515C(M2C_UNK);                         /* extern */
M2C_UNK func_8F100020(s32);                         /* extern */

void func_8F100118(s32 arg0, s8 *arg1) {
    s32 temp_v0;

    if (arg0 == 2) {
        temp_v0 = func_8000515C(0x20);
        M2C_FIELD(arg1, s32 *, 0x18) = temp_v0;
        func_8F100020(temp_v0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8F100154; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment030_326700/func_8F100154.s")
#endif

s32 func_8000515C(M2C_UNK);                         /* extern */
M2C_UNK func_8F100154(s32);                         /* extern */

void func_8F100214(s32 arg0, s8 *arg1) {
    s32 temp_v0;

    if (arg0 == 2) {
        temp_v0 = func_8000515C(0x18);
        M2C_FIELD(arg1, s32 *, 0x18) = temp_v0;
        func_8F100154(temp_v0);
    }
}
