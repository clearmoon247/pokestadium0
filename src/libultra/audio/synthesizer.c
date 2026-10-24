/* Stadium Zero resident code. */
/* Identical to ultralib src/audio/synthesizer.c (2.0I, IDO 5.3); link libultra here once the build exists. */

#include "global.h"
#include "m2c_macros.h"

M2C_UNK func_8004D600(s32);                         /* extern */
M2C_UNK func_8004D630(s32, s32);                    /* extern */
void func_800569B0(s32 arg0, s32 arg1) {
    func_8004D600(arg1);
    func_8004D630(arg1, arg0 + 0x14);
}

M2C_UNK func_8004D600(s32);                         /* extern */
void func_800569E8(s8 *arg0) {
    s32 var_s0;

    var_s0 = M2C_FIELD(arg0, s32 *, 0x14);
    if (var_s0 != 0) {
        do {
            func_8004D600(var_s0);
            func_8004D630(var_s0, arg0 + 4);
            var_s0 = M2C_FIELD(arg0, s32 *, 0x14);
        } while (var_s0 != 0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_80056A48; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80056A48.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80056A60; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80056A60.s")
#endif
