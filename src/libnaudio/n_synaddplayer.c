/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/libnaudio/n_synaddplayer.c. */

#include <os_internal.h>
#include "libnaudio/n_synthInternals.h"

void n_alSynAddPlayer(ALPlayer* client);

void n_alSynAddPlayer(ALPlayer* client) {
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    client->samplesLeft = n_syn->curSamples;
    client->next = n_syn->head;
    n_syn->head = client;

    osSetIntMask(mask);
}
