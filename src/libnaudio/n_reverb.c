/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/libnaudio/n_reverb.c. */

#include "libnaudio/n_synthInternals.h"
#include <ultraerror.h>
#include <os.h>
#include <os_internal.h>
#include <stdio.h>
#define RANGE 2.0
#define SWAP(in, out) \
    {                 \
        s16 t = out;  \
        out = in;     \
        in = t;       \
    }
Acmd* _n_loadOutputBuffer(ALFx* r, ALDelay* d, s32 buff, Acmd* p);
Acmd* _n_loadBuffer(ALFx* r, s16* curr_ptr, s32 buff, s32 count, Acmd* p);
Acmd* _n_saveBuffer(ALFx* r, s16* curr_ptr, s32 buff, Acmd* p);
Acmd* _n_filterBuffer(ALLowPass* lp, s32 buff, Acmd* p);
extern f32 _doModFunc(ALDelay* d, s32 count);
extern s32 L_INC[];

Acmd* n_alFxPull(s32 sampleOffset, Acmd* p);
Acmd* _n_loadOutputBuffer(ALFx* r, ALDelay* d, s32 buff, Acmd* p);
Acmd* _n_loadBuffer(ALFx* r, s16* curr_ptr, s32 buff, s32 count, Acmd* p);
Acmd* _n_saveBuffer(ALFx* r, s16* curr_ptr, s32 buff, Acmd* p);
Acmd* _n_filterBuffer(ALLowPass* lp, s32 buff, Acmd* p);

/***********************************************************************
 * Reverb filter public interfaces
 ***********************************************************************/
Acmd* n_alFxPull(s32 sampleOffset, Acmd* p) {
    Acmd* ptr = p;
    ALFx* r = (ALFx*)n_syn->auxBus->fx;
    s16 i, buff1, buff2, input, output;
    s16 *in_ptr, *out_ptr, gain, *prev_out_ptr = 0;
    ALDelay *d, *pd;


    /*
     * pull channels going into this effect first
     */
    ptr = n_alAuxBusPull(sampleOffset, p);

    input = N_AL_AUX_L_OUT;
    output = N_AL_AUX_R_OUT;
    buff1 = N_AL_TEMP_0;
    buff2 = N_AL_TEMP_1;

    aMix(ptr++, 0, 0xda83, N_AL_AUX_L_OUT, input);
    aMix(ptr++, 0, 0x5a82, N_AL_AUX_R_OUT, input);

    /* and write the mixed value to the delay line at r->input */
    ptr = _n_saveBuffer(r, r->input, input, ptr);

    aClearBuffer(ptr++, output, FIXED_SAMPLE << 1); /* clear the AL_AUX_R_OUT */

    for (i = 0; i < r->section_count; i++) {
        d = &r->delay[i]; /* get the ALDelay structure */
        in_ptr = &r->input[-d->input];
        out_ptr = &r->input[-d->output];

        if (in_ptr == prev_out_ptr) {
            SWAP(buff1, buff2);
        } else { /* load data at in_ptr into buff1 */
            ptr = _n_loadBuffer(r, in_ptr, buff1, FIXED_SAMPLE, ptr);
        }
        ptr = _n_loadOutputBuffer(r, d, buff2, ptr);

        if (d->ffcoef) {
            aMix(ptr++, 0, (u16)d->ffcoef, buff1, buff2);
            if (!d->rs && !d->lp) {
                ptr = _n_saveBuffer(r, out_ptr, buff2, ptr);
            }
        }

        if (d->fbcoef) {
            aMix(ptr++, 0, (u16)d->fbcoef, buff2, buff1);
            ptr = _n_saveBuffer(r, in_ptr, buff1, ptr);
        }

        if (d->lp)
            ptr = _n_filterBuffer(d->lp, buff2, ptr);

        if (!d->rs)
            ptr = _n_saveBuffer(r, out_ptr, buff2, ptr);

        if (d->gain)
            aMix(ptr++, 0, (u16)d->gain, buff2, output);

        prev_out_ptr = &r->input[d->output];
    }

    /*
     * bump the master delay line input pointer
     * modulo the length
     */
    r->input += FIXED_SAMPLE;
    if (r->input > &r->base[r->length]) {
        r->input -= r->length;
    }

    /*
     * output already in AL_AUX_R_OUT
     *      just copy to AL_AUX_L_OUT
     */
    aDMEMMove(ptr++, output, N_AL_AUX_L_OUT, FIXED_SAMPLE << 1);

    return ptr;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80047810; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80047810.s")
#endif

Acmd* _n_loadOutputBuffer(ALFx* r, ALDelay* d, s32 buff, Acmd* p) {
    Acmd* ptr = p;
    s32 ratio, count, rbuff = N_AL_TEMP_2;
    s16* out_ptr;
    f32 fincount, fratio, delta;
    s32 ramalign = 0, length;
    static f32 val = 0.0, lastval = -10.0;
    static f32 blob = 0;
    s32 incount = FIXED_SAMPLE;

    if (d->rs) {
        length = d->output - d->input;
        delta = _doModFunc(d, incount);
        delta /= length;
        delta = (s32)(delta * UNITY_PITCH);
        delta = delta / UNITY_PITCH;
        fratio = 1.0 - delta;
        fincount = d->rs->delta + (fratio * (f32)incount);
        count = (s32)fincount;
        d->rs->delta = fincount - (f32)count;
        out_ptr = &r->input[-(d->output - d->rsdelta)];
        ramalign = ((s32)out_ptr & 0x7) >> 1;
        ptr = _n_loadBuffer(r, out_ptr - ramalign, rbuff, count + ramalign, ptr);

        ratio = (s32)(fratio * UNITY_PITCH);
        {
            s16 tmp;

            tmp = buff >> 8;
            n_aResample(ptr++, osVirtualToPhysical(d->rs->state), d->rs->first, ratio, rbuff + (ramalign << 1), tmp);
        }
        d->rs->first = 0;
        d->rsdelta += count - incount;
    } else {
        out_ptr = &r->input[-d->output];
        ptr = _n_loadBuffer(r, out_ptr, buff, FIXED_SAMPLE, ptr);
    }

    return ptr;
}

Acmd* _n_loadBuffer(ALFx* r, s16* curr_ptr, s32 buff, s32 count, Acmd* p) {
    Acmd* ptr = p;
    s32 after_end, before_end;
    s16 *updated_ptr, *delay_end;


    delay_end = &r->base[r->length];


    if (curr_ptr < r->base)
        curr_ptr += r->length;
    updated_ptr = curr_ptr + count;

    if (updated_ptr > delay_end) {
        after_end = updated_ptr - delay_end;
        before_end = delay_end - curr_ptr;

        n_aLoadBuffer(ptr++, before_end << 1, buff, osVirtualToPhysical(curr_ptr));
        n_aLoadBuffer(ptr++, after_end << 1, buff + (before_end << 1), osVirtualToPhysical(r->base));
    } else {
        n_aLoadBuffer(ptr++, count << 1, buff, osVirtualToPhysical(curr_ptr));
    }

    return ptr;
}

Acmd* _n_saveBuffer(ALFx* r, s16* curr_ptr, s32 buff, Acmd* p) {
    Acmd* ptr = p;
    s32 after_end, before_end;
    s16 *updated_ptr, *delay_end;

    delay_end = &r->base[r->length];
    if (curr_ptr < r->base)    /* probably just security */
        curr_ptr += r->length; /* shouldn't occur */
    updated_ptr = curr_ptr + FIXED_SAMPLE;

    if (updated_ptr > delay_end) { /* if the data wraps past end of r->base */
        after_end = updated_ptr - delay_end;
        before_end = delay_end - curr_ptr;

        n_aSaveBuffer(ptr++, before_end << 1, buff, osVirtualToPhysical(curr_ptr));
        n_aSaveBuffer(ptr++, after_end << 1, buff + (before_end << 1), osVirtualToPhysical(r->base));
    } else {
        n_aSaveBuffer(ptr++, FIXED_SAMPLE << 1, buff, osVirtualToPhysical(curr_ptr));
    }

    return ptr;
}

Acmd* _n_filterBuffer(ALLowPass* lp, s32 buff, Acmd* p) {
    Acmd* ptr = p;
    {
        s16 tmp;

        tmp = buff >> 8;
        n_aLoadADPCM(ptr++, 32, osVirtualToPhysical(lp->fcvec.fccoef));
        n_aPoleFilter(ptr++, lp->first, lp->fgain, tmp, osVirtualToPhysical(lp->fstate));
    }

    lp->first = 0;

    return ptr;
}
