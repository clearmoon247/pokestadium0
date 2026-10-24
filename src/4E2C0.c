/* Stadium Zero resident code (next to libultra audio/sl.c). */

#include "global.h"
#include "m2c_macros.h"

#ifdef NON_MATCHING
/* TODO: decompile func_8004D6C0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8004D6C0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8004D7DC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8004D7DC.s")
#endif

s32 func_80057120();                                /* extern */
M2C_UNK func_8005BD60(M2C_UNK);                     /* extern */
void func_8004D96C(s32 arg0) {
    if (func_80057120() != 0) {
        do {

        } while (func_80057120() != 0);
    }
    func_8005BD60(0x125);
}
