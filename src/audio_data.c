/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/audio_data.c. */

#include "audio_data.h"
#include "libnumus/player.h"
#include "rom_device.h"
#include "audio_cache.h"
#include "audio_category_fade.h"
#include "audio_commands.h"

void Audio_ClearWaveDataLoaded(void);

void Audio_ClearWaveDataLoaded(void) {
    D_80075C30 &= ~0x80000000;
}
