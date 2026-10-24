/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/libnaudio/n_syndelete.c. */

#include "libnaudio/n_synthInternals.h"

void n_alSynDelete(void);

void n_alSynDelete(void) {
    n_syn->head = 0;
}
