/* Stadium Zero fragment004_15F8F0. */
/* C ported from the Stadium 1 decomp: src/fragments/gb_tower_team_prep/gb_tower_team_prep.c. */

#include "fragments/gb_tower_team_prep/gb_tower_team_prep.h"
#include "display_object_textures.h"
#include "poke_icon.h"
#include "pokemon_stats.h"
#include "save_data.h"
#include "jpeg_stream.h"
#include "gfx_buffer.h"
#include "gfx_rect.h"
#include "controller.h"
#include "memory.h"
#include "stage_loader.h"
extern unk_func_8001A024* D_81300384;
extern BattleMon D_81300388[6];
extern s32 D_81300370;

s32 GbTower_TeamPrepFrameCallback(u8 arg0);

void GbTower_LoadPartyFromDeck(s32 arg0) {
    s32 i;
    DeckHandle* temp_v0;

    if (GbSave_EnsureMainDataLoaded(arg0) != 0) {
        temp_v0 = Deck_Open(0x20, arg0, 0, 0);
        D_81300370 = Deck_ReadEntries(D_81300388, 6, temp_v0);
        Deck_CloseAndFlush(temp_v0);
    }

    for (i = 0; i < D_81300370; i++) {
        func_8001833C(D_81300384, i, &D_81300388[i], 1);
    }
}

s32 GbTower_TeamPrepFrameCallback(u8 arg0) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    PokeIcon_ProcessAllSlots(D_81300384, 0);
    BgStage_DrawFrame();
    GfxImage_FillCurrent(&gDisplayListHead, 1);
    return 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_81300144; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment004_15F8F0/func_81300144.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81300228; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment004_15F8F0/func_81300228.s")
#endif
