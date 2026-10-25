/* Stadium Zero resident code. */
/* Identical to ultralib src/os/setfpccsr.c (2.0I, IDO 5.3); link libultra here once the build exists. */

#include "global.h"
#include "m2c_macros.h"

#ifdef NON_MATCHING
/* TODO: decompile func_800594D0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800594D0.s")
#endif

s32 func_800594E0(void) {
    return (*(volatile s32 *)0xA4500004);
}
