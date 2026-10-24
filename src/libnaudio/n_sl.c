/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/libnaudio/n_sl.c. */

#include "libnaudio/n_synthInternals.h"
extern N_ALGlobals* n_alGlobals;
extern N_ALSynth* n_syn;

void n_alInit(N_ALGlobals* g, ALSynConfig* c);
void n_alClose(void);

void n_alInit(N_ALGlobals* g, ALSynConfig* c) {
    if (!n_alGlobals) { /* already initialized? */
        n_alGlobals = g;
        if (!n_syn) {
            n_syn = &n_alGlobals->drvr;
            n_alSynNew(c);
        }
    }
}

void n_alClose(void) {
    if (n_alGlobals) {
        n_alSynDelete();
        n_alGlobals = 0;
        n_syn = 0;
    }
}
