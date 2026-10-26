/* Stadium Zero resident code. */

#include "global.h"

s32 func_8005C9B0(void) {
    register s32 status = IO_READ(AI_STATUS_REG);

    if (status & AI_STATUS_FIFO_FULL) {
        return 1;
    } else {
        return 0;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8005C9E0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8005C9E0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8005CBA4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8005CBA4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8005CC30; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8005CC30.s")
#endif
