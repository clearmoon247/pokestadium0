/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/libnaudio/n_synthesizer.c. */

#include "libnaudio/n_synthInternals.h"
#define ONLY_ONE_PLAYER
#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif
s32 __n_nextSampleTime(ALPlayer** client);
s32 _n_timeToSamplesNoRound(s32 micros);
#ifndef ONLY_ONE_PLAYER
#endif

#include "m2c_macros.h"

void n_alSynNew(ALSynConfig* c);
ALParam* __n_allocParam(void);
void _n_freeParam(ALParam* param);
void _n_collectPVoices(void);
void _n_freePVoice(N_PVoice* pvoice);

/***********************************************************************
 * Synthesis driver public interfaces
 ***********************************************************************/
void n_alSynNew(ALSynConfig* c) {
    s32 i;
    N_ALVoice* vv;
    N_PVoice* pv;
    N_ALVoice* vvoices;
    N_PVoice* pvoices;
    ALHeap* hp = c->heap;
    ALSave* save;
    ALFilter* sources;
    N_PVoice* m_sources;
    ALParam* params;
    ALParam* paramPtr;

    n_syn->head = NULL;
    n_syn->numPVoices = c->maxPVoices;
    n_syn->curSamples = 0;
    n_syn->paramSamples = 0;
    n_syn->outputRate = c->outputRate;
    n_syn->maxOutSamples = FIXED_SAMPLE;
    n_syn->dma = (ALDMANew)c->dmaproc;

    /******* save new *******************************/
    n_syn->sv_dramout = 0;
    n_syn->sv_first = 1;

    /******* aux new *******************************/
    n_syn->auxBus = (N_ALAuxBus*)alHeapAlloc(hp, 1, sizeof(N_ALAuxBus));

    n_syn->auxBus->sourceCount = 0;
    n_syn->auxBus->maxSources = c->maxPVoices;
    n_syn->auxBus->sources = (N_PVoice**)alHeapAlloc(hp, c->maxPVoices, sizeof(N_PVoice*));

    /******* main new *******************************/
    n_syn->mainBus = (N_ALMainBus*)alHeapAlloc(hp, 1, sizeof(N_ALMainBus));

    /******* fx new *******************************/

    if (c->fxType != AL_FX_NONE) {
        n_syn->auxBus->fx = n_alSynAllocFX(0, c, hp);
        n_syn->mainBus->filter.handler = (N_ALCmdHandler)n_alFxPull;
    } else {
        n_syn->mainBus->filter.handler = (N_ALCmdHandler)n_alAuxBusPull;
    }

    n_syn->pFreeList.next = 0;
    n_syn->pFreeList.prev = 0;
    n_syn->pLameList.next = 0;
    n_syn->pLameList.prev = 0;
    n_syn->pAllocList.next = 0;
    n_syn->pAllocList.prev = 0;

    pvoices = alHeapAlloc(hp, c->maxPVoices, sizeof(N_PVoice));
    for (i = 0; i < c->maxPVoices; i++) {
        pv = &pvoices[i];
        alLink((ALLink*)pv, &n_syn->pFreeList);
        pv->vvoice = 0;
        alN_PVoiceNew(pv, n_syn->dma, hp);
        n_syn->auxBus->sources[n_syn->auxBus->sourceCount++] = pv;
    }

    params = alHeapAlloc(hp, c->maxUpdates, sizeof(ALParam));
    n_syn->paramList = 0;
    for (i = 0; i < c->maxUpdates; i++) {
        paramPtr = &params[i];
        paramPtr->next = n_syn->paramList;
        n_syn->paramList = paramPtr;
    }
    n_syn->heap = hp;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80044790; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80044790.s")
#endif

ALParam* __n_allocParam(void) {
    ALParam* update = 0;

    if (n_syn->paramList) {
        update = n_syn->paramList;
        n_syn->paramList = n_syn->paramList->next;
        update->next = 0;
    }
    return update;
}

void _n_freeParam(ALParam* param) {
    param->next = n_syn->paramList;
    n_syn->paramList = param;
}

void _n_collectPVoices(void) {
    ALLink* dl;
    N_PVoice* pv;

    while ((dl = n_syn->pLameList.next) != 0) {
        pv = (N_PVoice*)dl;

        /* ### remove from mixer */

        alUnlink(dl);
        alLink(dl, &n_syn->pFreeList);
    }
}

void _n_freePVoice(N_PVoice* pvoice) {
    /*
     * move the voice from the allocated list to the lame list
     */
    alUnlink((ALLink*)pvoice);
    alLink((ALLink*)pvoice, &n_syn->pLameList);
}

#ifdef NON_MATCHING
/* TODO: decompile func_800449E0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800449E0.s")
#endif

s32 func_800449E0();                                /* extern */

s32 func_80044A34(void) {
    return func_800449E0() & ~0xF;
}
