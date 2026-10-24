/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/libnaudio/n_synsetpriority.c. */

#include "libnaudio/n_synsetpriority.h"

void n_alSynSetPriority(N_ALVoice* voice, s16 priority);

void n_alSynSetPriority(N_ALVoice* voice, s16 priority) {
    voice->priority = priority;
}
