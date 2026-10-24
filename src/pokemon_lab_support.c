/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/fragments/pokemon_lab_support/pokemon_lab_support.c. */

#include "fragments/pokemon_lab_support/pokemon_lab_support.h"
#include "gb_save.h"

s32 LabPC_StatusToIconIndex(s32 arg0);

s32 LabPC_StatusToIconIndex(s32 arg0) {
    s32 v1;
    if (arg0 & 7) {
        v1 = 2;
    }
    else if (arg0 & 8) {
        v1 = 3;
    }
    else if (arg0 & 0x10) {
        v1 =  4;
    }
    else if (arg0 & 0x20) {
        v1 =  5;
    }
    else if (arg0 & 0x40) {
        v1 =  6;
    }
    else {
        v1 = 0;
    }
    return v1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8001FA8C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001FA8C.s")
#endif
