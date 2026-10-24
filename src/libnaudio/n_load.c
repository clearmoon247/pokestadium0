/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/libnaudio/n_load.c. */

#include "libnaudio/n_synthInternals.h"
#include <os.h>
#include <R4300.h>
#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif
#define ADPCMFBYTES 9
#define LFSAMPLES 4
Acmd* _decodeChunk(Acmd* ptr, N_PVoice* f, s32 tsam, s32 nbytes, s16 outp, s16 inp, u32 flags);

s32 n_alLoadParam(N_PVoice* filter, s32 paramID, void* param);

#ifdef NON_MATCHING
/* TODO: decompile func_80046B20; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80046B20.s")
#endif

s32 n_alLoadParam(N_PVoice* filter, s32 paramID, void* param) {
    N_PVoice* a = filter;

    switch (paramID) {
        case (AL_FILTER_SET_WAVETABLE):
            a->dc_table = (ALWaveTable*)param;
            a->dc_memin = (s32)a->dc_table->base;
            a->dc_sample = 0;
            switch (a->dc_table->type) {
                case (AL_ADPCM_WAVE):

                    a->dc_table->len = ADPCMFBYTES * ((s32)(a->dc_table->len / ADPCMFBYTES));

                    a->dc_bookSize = 2 * a->dc_table->waveInfo.adpcmWave.book->order *
                                     a->dc_table->waveInfo.adpcmWave.book->npredictors * ADPCMVSIZE;
                    if (a->dc_table->waveInfo.adpcmWave.loop) {
                        a->dc_loop.start = a->dc_table->waveInfo.adpcmWave.loop->start;
                        a->dc_loop.end = a->dc_table->waveInfo.adpcmWave.loop->end;
                        a->dc_loop.count = a->dc_table->waveInfo.adpcmWave.loop->count;
                        alCopy(a->dc_table->waveInfo.adpcmWave.loop->state, a->dc_lstate, sizeof(ADPCM_STATE));
                    } else {
                        a->dc_loop.start = a->dc_loop.end = a->dc_loop.count = 0;
                    }
                    break;

                case (AL_RAW16_WAVE):
                    if (a->dc_table->waveInfo.rawWave.loop) {
                        a->dc_loop.start = a->dc_table->waveInfo.rawWave.loop->start;
                        a->dc_loop.end = a->dc_table->waveInfo.rawWave.loop->end;
                        a->dc_loop.count = a->dc_table->waveInfo.rawWave.loop->count;
                    } else {
                        a->dc_loop.start = a->dc_loop.end = a->dc_loop.count = 0;
                    }
                    break;

                default:
                    break;
            }
            break;

        case (AL_FILTER_RESET):
            a->dc_lastsam = 0;
            a->dc_first = 1;
            a->dc_sample = 0;

            /* sct 2/14/96 - Check table since it is initialized to null and */
            /* Get loop info according to table type. */
            if (a->dc_table) {
                a->dc_memin = (s32)a->dc_table->base;
                if (a->dc_table->type == AL_ADPCM_WAVE) {
                    if (a->dc_table->waveInfo.adpcmWave.loop) {
                        a->dc_loop.count = a->dc_table->waveInfo.adpcmWave.loop->count;
                    }
                } else if (a->dc_table->type == AL_RAW16_WAVE) {
                    if (a->dc_table->waveInfo.rawWave.loop) {
                        a->dc_loop.count = a->dc_table->waveInfo.rawWave.loop->count;
                    }
                }
            }

            break;

        default:
            break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8004711C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8004711C.s")
#endif
