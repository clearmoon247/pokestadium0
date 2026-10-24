/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/libnaudio/n_synsetpitch.c. */

#include <os_internal.h>
#include <ultraerror.h>
#include "libnaudio/n_synthInternals.h"

void n_alSynSetPitch(N_ALVoice* v, f32 pitch);

void n_alSynSetPitch(N_ALVoice* v, f32 pitch) {
    ALParam* update;

    if (v->pvoice) {
        /*
         * get new update struct from the free list
         */

        update = __n_allocParam();
        ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);

        /*
         * set offset and pitch data
         */
#ifdef SAMPLE_ROUND
        update->delta = SAMPLE184(n_syn->paramSamples + v->pvoice->offset);
#else
        update->delta = n_syn->paramSamples + v->pvoice->offset;
#endif
        update->type = AL_FILTER_SET_PITCH;
        update->data.f = pitch;
        update->next = 0;

        n_alEnvmixerParam(v->pvoice, AL_FILTER_ADD_UPDATE, update);
    }
}
