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

#ifdef NON_MATCHING
/* TODO: decompile func_81300020; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment004_15F8F0/func_81300020.s")
#endif

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
