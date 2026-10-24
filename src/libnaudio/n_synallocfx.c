/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/libnaudio/n_synallocfx.c. */

#include "libnaudio/n_synthInternals.h"

ALFxRef n_alSynAllocFX(s16 bus, ALSynConfig* c, ALHeap* hp);

ALFxRef n_alSynAllocFX(s16 bus, ALSynConfig* c, ALHeap* hp) {
    n_alFxNew(&n_syn->auxBus->fx_array[bus], c, hp);
    return (n_syn->auxBus->fx_array[bus]);
}
