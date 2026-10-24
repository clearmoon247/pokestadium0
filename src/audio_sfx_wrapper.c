/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/audio_sfx_wrapper.c. */

#include "audio_sfx_wrapper.h"
#include "audio_sfx.h"

void Audio_PlaySoundEffectByIdWrapper(s32 arg0);

void Audio_PlaySoundEffectByIdWrapper(s32 arg0) {
    Audio_PlaySoundEffectById(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_80036630; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80036630.s")
#endif
