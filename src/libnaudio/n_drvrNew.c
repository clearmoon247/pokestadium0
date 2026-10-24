/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/libnaudio/n_drvrNew.c. */

#include "libnaudio/n_synthInternals.h"
#include <os.h>
#include <stdio.h>
#define SCALE 16384
#define ms *(((s32)((f32)44.1)) & ~0x7)
extern s32 SMALLROOM_PARAMS_N[26];
extern s32 BIGROOM_PARAMS_N[34];
extern s32 ECHO_PARAMS_N[10];
extern s32 CHORUS_PARAMS_N[10];
extern s32 FLANGE_PARAMS_N[10];
extern s32 NULL_PARAMS_N[10];

void alN_PVoiceNew(N_PVoice* mv, ALDMANew dmaNew, ALHeap* hp);

#ifdef NON_MATCHING
/* TODO: decompile func_80046270; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80046270.s")
#endif

void alN_PVoiceNew(N_PVoice* mv, ALDMANew dmaNew, ALHeap* hp) {
    mv->dc_state = alHeapAlloc(hp, 1, sizeof(ADPCM_STATE));
    mv->dc_lstate = alHeapAlloc(hp, 1, sizeof(ADPCM_STATE));
    mv->dc_dma = dmaNew(&mv->dc_dmaState);
    mv->dc_lastsam = 0;
    mv->dc_first = 1;
    mv->dc_memin = 0;

    mv->rs_state = alHeapAlloc(hp, 1, sizeof(RESAMPLE_STATE));
    mv->rs_delta = 0.0;
    mv->rs_first = 1;
    mv->rs_ratio = 1.0;
    mv->rs_upitch = 0;

    mv->em_state = alHeapAlloc(hp, 1, sizeof(ENVMIX_STATE));
    mv->em_first = 1;
    mv->em_motion = AL_STOPPED;
    mv->em_volume = 1;
    mv->em_ltgt = 1;
    mv->em_rtgt = 1;
    mv->em_cvolL = 1;
    mv->em_cvolR = 1;
    mv->em_dryamt = 0;
    mv->em_wetamt = 0;
    mv->em_lratm = 1;
    mv->em_lratl = 0;
    mv->em_lratm = 1;
    mv->em_lratl = 0;
    mv->em_delta = 0;
    mv->em_segEnd = 0;
    mv->em_pan = 0;
    mv->em_ctrlList = 0;
    mv->em_ctrlTail = 0;
}
