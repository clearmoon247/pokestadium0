/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_31AA30.c, src/fragments/battle_engine/battle_engine_32B680.c, src/fragments/battle_engine/battle_engine_move_animation.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "model_animation.h"
#include "geo_render.h"
#include "gfx_buffer.h"
#include "matrix.h"
#include "math_util.h"

#include "fragments/battle_engine/battle_engine.h"

#include "fragments/battle_engine/battle_engine.h"
#include "model_animation.h"
#include "model_animation_events.h"
#include "model_renderer.h"
#include "pokemon_stats.h"
#include "text_system.h"
#include "gb_save.h"
#include "audio_commands.h"
#include "jpeg_stream.h"
#include "audio_fade.h"
#include "audio_stored_fade.h"
#include "audio_loop_point.h"
#include "cry.h"
#include "matrix.h"
#include "memory.h"
#include "moves.h"
#include "pokemon.h"
#include "status.h"
extern PokemonBattleCues sSide1BattleCues;
extern PokemonBattleCues sSide2BattleCues;
extern SpeciesModelTransform sSide1PresentationTransform;
extern SpeciesModelTransform sSide2PresentationTransform;
extern ActivePokemon* sActivePokemon[2];
extern ActivePokemon* sSide1ActivePokemon;
extern ActivePokemon* sSide2ActivePokemon;
extern MovePresentationCue* sCurrentAnimation;
extern ModelDimensions sPokemonModelDimensions[2];
extern SwayLayoutConfig sDefaultSwayLayout;
extern BattleSceneStateTickSlot sBattleSceneStateTickSlots[7];
extern s32 sBattleSceneStateTickSlotIndex;
extern PokemonBattleCues* sSideBattleCues[];
extern SpeciesModelTransform* sSidePresentationTransform[];
extern TagTeamPartners* sPlayerTagTeam[];
extern u8 sPokemonWithAlternateSleepIdle[];
extern u8 sPokemonWithAlternateSleepHitReactions[];
extern u8 sPokemonWithNewHmInYellow[];
extern u8 sCharizardLearnsFlyInYellow[];
extern u8 sButterfreeLearnsFlashInYellow[];
extern u8 sVenonatLearnsFlashInYellow[];
extern u8 sVenomothLearnsFlashInYellow[];
extern u8 sDiglettLearnsCutInYellow[];
extern u8 sDugtrioLearnsCutInYellow[];
extern u8 sKabutopsLearnsCutInYellow[];
extern u8 sMewtwoLearnsNothingNewInYellow[];
extern u8 sMewLearnsNothingNewInYellow[];
extern u8* sPokemonYellowHmAdditions[];
extern u8 sAerodactyl;
extern u8 sFearow;
extern u8 sFarfetchD;
extern u8 sDoduoEvoLine[];
extern char** sBattleMessagesTable;
extern char** sPokemonNameTable;
extern char** sMoveNameTable;
extern char** sStatusConditionNameTable;
extern char** sBattleControllerDisconnectedMessage;
#define PARTNER_PIKACHU_CUE_BANK 152
#define DIGLETT_OB1 (DIGLETT - 1)
#define DUGTRIO_OB1 (DUGTRIO - 1)
#define ELECTRODE_OB1 (ELECTRODE - 1)
#define SQUIRTLE_OB1 (SQUIRTLE - 1)
#define WARTORTLE_OB1 (WARTORTLE - 1)
#define BLASTOISE_OB1 (BLASTOISE - 1)
#define CLOYSTER_OB1  (CLOYSTER - 1)

#include "m2c_macros.h"

void ParticleEffect_Noop(UNUSED s32 arg0, UNUSED s32 arg1);
void BattleAnim_DrawAsset76Ia8FrameWithAsset77I4OverlayPipelineA(Particle* arg0, CameraNode* arg1);
void BattleAnim_DrawAsset76Ia8FrameWithAsset77I4OverlayPipelineB(Particle* arg0, CameraNode* arg1);
void func_82142678(UNUSED ActivePokemon* active_pokemon, UNUSED s32 unused);

void BattleAnim_DrawAsset76Ia8FrameWithAsset77I4Overlay(Particle* arg0, CameraNode* arg1);

void ParticleEffect_Noop(UNUSED s32 arg0, UNUSED s32 arg1) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_8214176C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8214176C.s")
#endif

void BattleAnim_DrawAsset76Ia8FrameWithAsset77I4OverlayPipelineA(Particle* arg0, CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_821904C8);

    BattleAnim_DrawAsset76Ia8FrameWithAsset77I4Overlay(arg0, arg1);
}

void BattleAnim_DrawAsset76Ia8FrameWithAsset77I4OverlayPipelineB(Particle* arg0, CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_82190548);

    BattleAnim_DrawAsset76Ia8FrameWithAsset77I4Overlay(arg0, arg1);
}

void BattleAnim_DrawAsset1FAnimatedI4WithAsset20DisplayList(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_PushBillboardMatrix(arg1, arg0->unk_2C, arg0->unk_1C);

    gSPDisplayList(gDisplayListHead++, D_82190548);

    ParticleGfx_LoadTextureI4WrapSTNoMirror(sBattleAnimAssetPointers[0x1F], 0x20, 0x40);
    ParticleGfx_SetAnimatedTileSize(0, 8, 0x20, 0x40);
    ParticleGfx_SetPrimEnvColorShadeCombine(0xFF, 0xFF, 0xFF, arg0->prim_a, 0xFF, 0xFF, 0xFF, 0xFF);

    gDPSetRenderMode(gDisplayListHead++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);
    gSPDisplayList(gDisplayListHead++, sBattleAnimAssetPointers[0x20]);
}

s32 BattleAnim_DrawAssetBcRgba16WithAssetBdDisplayList(Particle* arg0, UNUSED CameraNode* arg1) {
    ParticleGfx_PushTransformMatrix(arg0->unk_2C, arg0->unk_94, arg0->unk_1C);

    gSPDisplayList(gDisplayListHead++, gDL_ItemIcon);

    ParticleGfx_LoadTextureRgba16(sBattleAnimAssetPointers[0xBC], 0x20, 0x20);

    gSPDisplayList(gDisplayListHead++, sBattleAnimAssetPointers[0xBD]);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82141AC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82141AC8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82141BDC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82141BDC.s")
#endif

void BattleAnim_DrawAsset29DualI4LayeredQuad(Particle* arg0, UNUSED CameraNode* arg1) {
    ParticleGfx_Push2DTransform(arg0->unk_2C.x, arg0->unk_2C.y, arg0->unk_94.z, arg0->unk_1C);

    gSPDisplayList(gDisplayListHead++, D_821904C8);

    ParticleGfx_SetPrimEnvLodCombine(0x80, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a, arg0->env_r, arg0->env_g, arg0->env_b);
    ParticleGfx_LoadTextureMultiBlock4(sBattleAnimAssetPointers[0x29], 0, 0, 4, 0x20, 0x20, 1, 1, 5, 5, 2, 0);
    ParticleGfx_SetAnimatedTileSize(1, 1, 0x20, 0x20);
    ParticleGfx_LoadTextureMultiBlock4(sBattleAnimAssetPointers[0x29], 0x100, 1, 4, 0x20, 0x20, 1, 1, 5, 5, 1, 0xF);
    ParticleGfx_SetAnimatedAuxTileSize(-1, 1, 0x20, 0x20);
    ParticleGfx_DrawQuadVertices(gFullscreenQuadVtx);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82141E88; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82141E88.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82141F6C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82141F6C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82142048; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82142048.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82142124; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82142124.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82142254; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82142254.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82142348; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82142348.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8214243C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8214243C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82142530; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82142530.s")
#endif

/**
 * Empty function. Not referenced in C.
 */
void func_82142678(UNUSED ActivePokemon* active_pokemon, UNUSED s32 unused) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_82142684; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82142684.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821427BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821427BC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821428F8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821428F8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82142A34; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82142A34.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82142B60; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82142B60.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82142C8C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82142C8C.s")
#endif

void BattleAnim_DrawAsset1BI4TriangleA(Particle* arg0, UNUSED CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_821904C8);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_LoadTextureI4Alias(sBattleAnimAssetPointers[0x1B], 0x10, 0x100);
    ParticleGfx_SetPrimEnvColorCombine(0xFF, 0xFF, 0xFF, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a);
    ParticleGfx_DrawTransformedTriangle(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, gVtx_UI_TriangleSmall);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

extern Vtx D_82190D60[];
void func_82142EDC(Particle* arg0, UNUSED CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_821904C8);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_LoadTextureI4Alias(sBattleAnimAssetPointers[0x1B], 0x10, 0x100);
    ParticleGfx_SetPrimEnvColorCombine(0xFF, 0xFF, 0xFF, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a);
    ParticleGfx_DrawTransformedTriangle(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, D_82190D60);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void BattleAnim_DrawAsset13FrameDiv2I4Quad(Particle* arg0, UNUSED CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_821904C8);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_LoadTextureI4Alias(sBattleAnimAssetPointers[0x13] + ((gParticleFrameDiv2 & 7) * 0x600), 0x20, 0x60);
    ParticleGfx_SetPrimEnvColorCombine(0xFF, 0xFF, 0xFF, 0, 0x64, 0xC8, 0xFF);
    ParticleGfx_DrawTransformedQuad(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, gVtx_UI_ComplexQuad);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8214313C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8214313C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82143218; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82143218.s")
#endif

M2C_UNK func_8216D640(u8, u8, u8, u8);              /* extern */

void func_82143344(s8 *arg0, M2C_UNK arg1) {
    func_8216D640(M2C_FIELD(arg0, u8 *, 0xBA), M2C_FIELD(arg0, u8 *, 0xBB), M2C_FIELD(arg0, u8 *, 0xBC), M2C_FIELD(arg0, u8 *, 0xC0));
}
