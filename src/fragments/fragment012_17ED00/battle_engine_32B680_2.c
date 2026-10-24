/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_32B680.c, src/fragments/battle_engine/battle_engine_343BA0.c, src/fragments/battle_engine/battle_engine_move_animation.c, src/fragments/battle_engine/battle_engine_move_model_transforms.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "model_animation.h"
#include "geo_render.h"
#include "gfx_buffer.h"
#include "matrix.h"
#include "math_util.h"

#include "fragments/battle_engine/battle_engine.h"
#include "gallery.h"
#include "gfx_buffer.h"
#include "math.h"
#include "math_util.h"
extern u8* sBattleAnimAssetPointers[256];
extern s16 sBattleAnimResourceList[0x10];
extern arg1_func_80019420* sBattleAnimResourceTablePointers[40];
extern s16 D_8219CAC0;
extern s16 D_8219CAC2;
extern Mtx D_8219CAC8;
extern s16 D_8219CB08;
extern s16 D_8219CB0A;
extern s16 D_8219CB0C;
extern s16 D_8219CB0E;
extern s16 D_8219CB10;
extern s16 D_8219CB12;
extern s16 D_8219CB14;
extern s16 D_8219CB16;
extern s16 D_8219CB18;
extern s16 D_8219CB1A;
extern const char D_821978C8[];

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

#include "fragments/battle_engine/battle_engine.h"
#include "model_animation.h"
#include "model_renderer.h"
#include "matrix.h"
#include "pokemon.h"
extern f32 sModelTransformConstants[];
#define NINETY_DEGREES 0x4000
extern s32 pad_D_8438466C;
extern s16 sChargeMoveCues[];
extern ThumbnailSettings sSideThumbnailSettings[2];
extern BattleSceneStateCallback sBattleSceneStateTickSentinel;
extern BattleSceneStateRow sBattleSceneStateRowTable[];

#include "m2c_macros.h"

void BattleAnim_SetupReflectiveCamera(void);
Gfx* BattleAnim_BuildAnimatedTileDisplayList(Gfx* arg0, u8* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9,
                   s16 argA, s16 argB);
Gfx* BattleAnim_BuildAnimatedTileDisplayListFromStruct(Gfx* arg0, arg1_func_8434E21C* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7,
                   s16 arg8, s16 arg9, s16 argA, s16 argB);
void ParticleEffect_AllocateGfxIfNeeded(s32 arg0, arg1_func_84344CE8* arg1);
void ParticleEffect_AllocateGfxAndDraw(s32 arg0, arg1_func_84344CE8* arg1);
void ParticleEffect_RegisterExplosion(void);
void BattleAnim_SetupEffect1Descriptor2F(Particle* arg0);
void BattleAnim_InitModelAnimationSlot(Particle* arg0, s16 arg1);
void BattleAnim_StartEffect12DelayedModelAnim(void);
void BattleAnim_BuildReflectiveTextureDisplayList(Gfx* arg0, s32 arg1, u16 arg2);
void BattleAnim_AllocateReflectiveTextureDisplayList(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_BuildEffect125DisplayList(Gfx* arg0, u16 arg1);
void BattleAnim_AllocateEffect125DisplayList(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_InitEffect28Overlay(Particle* arg0);
void BattleAnim_InitEffect8Descriptor4A(Particle* arg0);
void BattleAnim_InitEffect8ModelBurst(Particle* arg0);
void ParticleEffect_RegisterMultiple(void);
void ParticleEffect_RegisterSpecific(void);
void ParticleEffect_DrawSimple(Gfx* arg0, u8* arg1);
void ParticleEffect_CreateSimpleDL(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_CallbackStartEffect34SpecialModelFadeIn_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect23Descriptor4AAnimatedFade_InitParticle(Particle* arg0);
void ParticleEffect_CreateNodeDL(s32 arg0, arg1_func_84344CE8* arg1);
void ParticleEffect_DrawNodeVariant(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void ParticleEffect_CreateNodeVariantDL(s32 arg0, arg1_func_84344CE8* arg1);
void ParticleEffect_DrawSimpleOffsetTileNoCamera(Gfx* arg0, u8* arg1, UNUSED u16 arg2);
void ParticleEffect_CreateSimpleOffsetTileNoCameraDL(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_DefaultEndEffect_Draw(void);
void ParticleEffect_RegisterPaletteVariants(void);
void BattleAnim_InitEffect49Model(Particle* arg0);
void BattleAnim_AllocateEffect49DisplayList(s32 arg0, arg1_func_84344CE8* arg1);
void ParticleEffect_RegisterColorAnim(void);
void BattleAnim_InitEffect40Model(Particle* arg0);
void ParticleEffect_RegisterLargeExplosionAndEffects(void);
void BattleAnim_AllocateEffect63DisplayList(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_AllocateEffect75DisplayList(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_InitEffects63And75Model(Particle* arg0);
void BattleAnim_InitEffects10And50Model(Particle* arg0);
void BattleAnim_ApplyEffects63And75SpeciesScaleOffset(Particle* arg0);
void BattleAnim_InitEffects63And75Model38(Particle* arg0);
void Particle_CreateDisplayList_Alpha(s32 arg0, arg1_func_84344CE8* arg1);
void Particle_CreateDisplayList_Texture4b(s32 arg0, arg1_func_84344CE8* arg1);
void Particle_CreateDisplayList_GreenPrim(s32 arg0, arg1_func_84344CE8* arg1);
void ParticleEffect_RegisterHandlers_Default(void);
void ParticleEffect_RegisterAnimationCallbacks(void);
void ParticleEffect_RegisterHandlers_Alternate(void);
void ParticleEffect_RegisterHandler_WithParticleData(void);
void BattleAnim_StartEffect64ModelAnimWait(void);
void BattleAnim_CallbackStartEffect10Model60AlphaFadeIn_InitParticle(Particle* arg0);
void Gfx_DrawParticleCyanEnv(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void Particle_CreateDisplayList_CyanEnv(s32 arg0, arg1_func_84344CE8* arg1);
void Particle_CreateDisplayList_BluePrim(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_StartEffect10Model60AndModelAnimWait(void);
void BattleAnim_StartEffect72ModelAnimWait(void);
void BattleAnim_CallbackStartEffects50And82Descriptor4AAnimatedVerticalFade_InitParticle(Particle* arg0);
void Particle_CreateDisplayList_CustomColors(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_CallbackEndEffects81And82Descriptor4FAnimatedPaletteFade_InitParticle(Particle* arg0);
void func_821597B8(UNUSED ActivePokemon* active_pokemon, UNUSED s32 unused);
void BattleAnim_TransformNop(UNUSED ActivePokemon* owner, UNUSED ActivePokemon* animated_pokemon);
void BattleAnim_CallbackStartEffects71And74And111SpecialModelColorCycle_InitParticle(Particle* arg0);
void Particle_CreateDisplayList_TempColors(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_StartEffect71SpecialModelColorCycle(void);
void BattleAnim_StartEffect111GlobalTintAndSpecialModelColorCycle(void);
void BattleAnim_StartEffect74SpecialModelColorCycle(void);
void BattleAnim_EndEffect41Descriptor34Burst(void);
void Gfx_DrawParticleDualTileDiagonal4(Gfx* arg0, u8* arg1, UNUSED u16 arg2);
void Particle_CreateDisplayList_DualTileDiagonal4(s32 arg0, arg1_func_84344CE8* arg1);
void Gfx_DrawParticleDualTileAntiDiagonal1(Gfx* arg0, u8* arg1, UNUSED u16 arg2);
void Particle_CreateDisplayList_DualTileAntiDiagonal1(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_StartEffect68ModelAnimWaitAndDescriptor42ScaleFall(void);
f32 BattleAnim_GetSpeciesScaleAdjust(Particle* arg0);
void BattleAnim_StartEffect52ModelAnim(void);
void BattleAnim_StartEffect55ModelAnimWaitMarkerSlotAndScaleFall(void);
void ParticleEffect_RegisterDefaultTexture(void);
void BattleAnim_CallbackStartEffect17ModelAnimFinish_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect7ModelScaleAlphaFade_InitParticle(Particle* arg0);
void Gfx_DrawParticlePaletteBased(Gfx* arg0, u8* arg1, UNUSED u16 arg2);
void Gfx_ParticlePaletteCallback(s32 arg0, arg1_func_84344CE8* arg1);
void Gfx_ParticlePaletteDL(Gfx* arg0, UNUSED arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void Gfx_ParticlePaletteColorOnlyCallback(s32 arg0, arg1_func_84344CE8* arg1);
s16 BattleAnim_GetMoveKeyedModelVariantIndex(void);
s16 BattleAnim_GetMoveKeyedTrailVariantParam(void);
void BattleAnim_StartEffect17ModelAnimFinish(void);
void ParticleEffect_PaletteMultiBurst(void);
void Gfx_ParticleTextureTileCallback(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void Gfx_ParticleTextureTileAllocCallback(s32 arg0, arg1_func_84344CE8* arg1);
void Gfx_ParticleRedPrimAllocCallback(s32 arg0, arg1_func_84344CE8* arg1);
void ParticleEffect_SimpleBurst(void);
void BattleAnim_StartEffect39Descriptor26ModelAnimWaitSequence(void);
void BattleAnim_EndEffect58ModelAnimAndDescriptorSequence(void);
void ParticleEffect_MultiNodeAEntry(void);
void Gfx_PokemonPortraitCallback(Gfx* arg0, u8 arg1, UNUSED u16 arg2);
void Gfx_PokemonPortraitAllocCallback(s32 arg0, arg1_func_84344CE8* arg1);
void ParticleEffect_PortraitBurst(void);
void ParticleEffect_PortraitBurstNode(void);
void Gfx_PaletteParticleDLCallback(s32 arg0, arg1_func_84344CE8* arg1);
void ParticleEffect_PaletteMultiBurstNoCleanupNoTintFade(void);
void ParticleEffect_PaletteBurstVariant4Model8D(void);
void BattleAnim_CallbackStartEffects21And93ModelAlphaAnchorFollow_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect60Model42AnimC2RotationYFollow_InitParticle(Particle* arg0);
void Gfx_WaterAnimPrimEnvDLCallback(s32 arg0, arg1_func_84344CE8* arg1);
void ParticleEffect_WaterAnimBurst(void);
void Gfx_WaterAnimDLCallback(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_CallbackStartEffect101EndEffect65Descriptor4ABurstChild_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect101ModelBurstEmitter_InitParticle(Particle* arg0);
void ParticleEffect_RotationEntry(void);
void BattleAnim_CallbackMove140EndEffect65EmitDescriptor4A_InitParticle(Particle* arg0);
void ParticleEffect_FireworkEntry(void);
void BattleAnim_CallbackStartEffect49EndEffect66ModelFadeIn_InitParticle(Particle* arg0);
void Gfx_SimpleNodeDLCallback(s32 arg0, arg1_func_84344CE8* arg1);
void ParticleEffect_SimpleNodeEntry(void);
void BattleAnim_EndEffect85TintAndDescriptorMode2Sequence(void);
void ParticleEffect_PlaySoundAndReset(void);
void ParticleEffect_AllocateDisplayList(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_EndEffect72Descriptor20ModelAnimWaitSequence(void);
void ParticleEffect_TriggerDefaultPalette1B(void);
void ParticleEffect_TriggerDefaultPalette1C(void);
void ParticleEffect_TriggerDefaultPalette1BWithTintFade(void);
void ParticleEffect_CreateColorVariant(void);
void BattleAnim_CallbackStartEffects127And128Descriptor39ScaleFade_InitParticle(Particle* arg0);
void BattleAnim_StartEffect127Descriptor39ScaleFade(void);
void BattleAnim_StartEffect128Descriptor39ScaleFade(void);
void ParticleEffect_CreateTypeX(void);
void ParticleEffect_CreateSmoke(void);
void ParticleEffect_CreateSmokeHighPriority(void);
void BattleAnim_CallbackStartEffect132Descriptor39DelayedRiseFade_InitParticle(Particle* arg0);
void ParticleEffect_CreateDual(void);

void BattleAnim_CallbackInitModelAnimWait(Particle* arg0);
void BattleAnim_CallbackInitModelAnim(Particle* arg0);
void BattleAnim_CallbackStartEffects83And103ModelAlphaFadeIn(Particle* arg0);
void BattleAnim_CallbackInitModelAnimMode2Update(Particle* arg0);
void Gfx_SetParticlePrimEnvColors(Gfx* arg0);
void Gfx_DrawParticleTextureWithParams(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void BattleAnim_CallbackMove86StartDescriptor24(Particle* arg0);
void BattleAnim_ApplyEffect1SpeciesMotion(Particle* arg0);
void BattleAnim_ApplyModelSpeciesOffset(Particle* arg0);
void BattleAnim_CallbackStartEffects12And129DelayedModelAnimWait(Particle* arg0);
void BattleAnim_CallbackMove73EndEffect31SpawnDescriptor42(Particle* arg0);
void ParticleEffect_DrawNode(Gfx* arg0, s32 arg1, u16 arg2);
void BattleAnim_CallbackMove146EndEffect6ModelAnimWait(Particle* arg0);
void BattleAnim_CallbackEndEffect49Model33Anim34WaitCleanup(Particle* arg0);
void BattleAnim_BuildEffect49DisplayList(Gfx* arg0, UNUSED s32 arg1, UNUSED u16 arg2);
void BattleAnim_CallbackStartEffect86ModelFadeCycle(Particle* arg0);
void BattleAnim_BuildEffect63DisplayList(Gfx* arg0, s32 arg1, u16 arg2);
void BattleAnim_BuildEffect75DisplayList(Gfx* arg0, UNUSED s32 arg1, UNUSED u16 arg2);
void BattleAnim_CallbackStartEffects63And75ModelAnimWait(Particle* arg0);
void BattleAnim_CallbackEndEffects10And50ModelAnimColorFade(Particle* arg0);
void BattleAnim_CallbackStartEffects63And75Model38FadeIn(Particle* arg0);
void Gfx_DrawParticleAlpha(Gfx* arg0, s32 arg1, u16 arg2);
void Gfx_DrawParticleTexture4b(Gfx* arg0, u8* arg1, UNUSED u16 arg2);
void Gfx_DrawParticleGreenPrim(Gfx* arg0, u8* arg1, UNUSED u16 arg2);
void BattleAnim_CallbackStartEffect10Model60AlphaFadeIn(Particle* arg0);
void Gfx_DrawParticleBluePrim(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void Gfx_DrawParticleCustomColors(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void BattleAnim_CallbackStartEffects71And74And111SpecialModelColorCycle(Particle* arg0);
void Gfx_DrawParticleFromTempColors(Gfx* arg0, s32 arg1, u16 arg2);
void BattleAnim_CallbackStartEffect17ModelAnimFinish(Particle* arg0);
void BattleAnim_CallbackEndEffect7ModelScaleAlphaFade(Particle* arg0);
s16 BattleAnim_GetMoveKeyedTintRampParam(void);
void Gfx_ParticleRedPrimCallback(Gfx* arg0, UNUSED arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void BattleAnim_CallbackStartEffects95To97EndEffects62And63ModelFadeIn(Particle* arg0);
void Gfx_PaletteParticleDL(Gfx* arg0, u8* arg1, UNUSED u16 arg2);
void BattleAnim_CallbackStartEffects21And93ModelAlphaAnchorFollow(Particle* arg0);
void Gfx_WaterAnimPrimEnvDL(Gfx* arg0, u8 arg1, UNUSED u16 arg2);
void Gfx_WaterAnimDL(Gfx* arg0, u8* arg1, UNUSED u16 arg2);
void BattleAnim_CallbackStartEffect101ModelBurstEmitter(Particle* arg0);
void BattleAnim_CallbackMove140EndEffect65EmitDescriptor4A(Particle* arg0);
void BattleAnim_CallbackStartEffect49EndEffect66ModelFadeIn(Particle* arg0);
void Gfx_SimpleNodeDL(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void ParticleEffect_DrawQuad(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void BattleAnim_CallbackEndEffect79DefaultDescriptorPaletteFade(Particle* arg0);
void BattleAnim_CallbackStartEffects127And128Descriptor39ScaleFade(Particle* arg0);
void BattleAnim_CallbackStartEffect132Descriptor39DelayedRiseFade(Particle* arg0);

void BattleAnim_SetupReflectiveCamera(void) {
    Mtx* sp3C = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    LookAt* sp38 = Gfx_AllocDisplayList(sizeof(LookAt) * 1);
    CameraNode* temp_v0 = BattleAnim_GetCameraContext();

    guLookAtReflect(sp3C, sp38, temp_v0->view.eyePosition.x, temp_v0->view.eyePosition.y, temp_v0->view.eyePosition.z,
                    temp_v0->view.targetPosition.x, temp_v0->view.targetPosition.y, temp_v0->view.targetPosition.z, temp_v0->view.upDirection.x,
                    temp_v0->view.upDirection.y, temp_v0->view.upDirection.z);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82152730; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82152730.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82152F44; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82152F44.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82152FB0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82152FB0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82152FE0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82152FE0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82153040; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82153040.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821530C4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821530C4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821530F4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821530F4.s")
#endif

Gfx* BattleAnim_BuildAnimatedTileDisplayList(Gfx* arg0, u8* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9,
                   s16 argA, s16 argB) {
    gDPLoadTextureTile_4b(arg0++, arg1, G_IM_FMT_I, arg2, 0, 0, 0, arg2 - 1, arg2 - 1, 0, G_TX_NOMIRROR | G_TX_WRAP,
                          G_TX_NOMIRROR | G_TX_WRAP, arg3, arg3, arg6, arg7);

    ParticleGfx_SetAnimatedTileSizeOnList(arg0++, arg4, arg5, arg2, arg2);

    gDPLoadMultiTile_4b(arg0++, arg1, 0x0100, 1, G_IM_FMT_I, arg2, 0, 0, 0, arg2 - 1, arg2 - 1, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, arg3, arg3, argA, argB);

    ParticleGfx_SetAnimatedAuxTileSizeOnList(arg0++, arg8, arg9, arg2, arg2);
    return arg0;
}

Gfx* BattleAnim_BuildAnimatedTileDisplayListFromStruct(Gfx* arg0, arg1_func_8434E21C* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7,
                   s16 arg8, s16 arg9, s16 argA, s16 argB) {
    gDPLoadTextureTile_4b(arg0++, arg1->unk_00, G_IM_FMT_I, arg2, arg2, 0, 0, arg2 - 1, arg2 - 1, 0,
                          G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, arg3, arg3, arg6, arg7);

    ParticleGfx_SetAnimatedTileSizeOnList(arg0++, arg4, arg5, arg2, arg2);

    gDPLoadMultiTile_4b(arg0++, arg1->unk_04, 0x0100, 1, G_IM_FMT_I, arg2, arg2, 0, 0, arg2 - 1, arg2 - 1, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, arg3, arg3, argA, argB);
    ParticleGfx_SetAnimatedAuxTileSizeOnList(arg0++, arg8, arg9, arg2, arg2);
    return arg0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_821536E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821536E4.s")
#endif

void ParticleEffect_AllocateGfxIfNeeded(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_SetParticlePrimEnvColors(arg1->unk_18);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_821537D8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821537D8.s")
#endif

void ParticleEffect_AllocateGfxAndDraw(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_DrawParticleTextureWithParams(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82153BE0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82153BE0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82153C50; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82153C50.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82153D00; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82153D00.s")
#endif

M2C_UNK func_8213C938(s8 *);                      /* extern */
M2C_UNK func_8213E4D8(s8 *);                      /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140548(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821406B4(s8 *);                      /* extern */
M2C_UNK func_82153D00(s8 *);                      /* extern */

void func_82153E28(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82153D00(arg0);
        break;
    case 2:
        func_821406B4(arg0);
        break;
    case 3:
        func_82140548(arg0, 0, 0x20);
        break;
    case 4:
        func_8213C938(arg0);
        break;
    }
    func_82140228(arg0, 0x41200000, 0x3D4CCCCD);
    func_8213E4D8(arg0);
}

void ParticleEffect_RegisterExplosion(void) {
    BattleAnim_SpawnCategory17MarkerSlot(0x55, 1);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 8, 0xC, BattleAnim_CallbackMove86StartDescriptor24, &gBattleAnimParticleDescriptors[0x24], 0xA, 1, 4, 0, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 8, 0xC, BattleAnim_CallbackMove86StartDescriptor24, &gBattleAnimParticleDescriptors[0x24], 0xA, 1, 4, 1, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 8, 0xC, BattleAnim_CallbackMove86StartDescriptor24, &gBattleAnimParticleDescriptors[0x24], 0xA, 1, 4, 2, 0, 0);
}

M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
extern M2C_UNK D_8218E6A8;
extern s16 D_8219A80A;
extern M2C_UNK func_82153C50;

void func_82153FD8(void) {
    func_8213B644(0x30, 0x20, 8);
    func_8213B5D8(0, 0xC, 0xA, &func_82153C50, &D_8218E6A8, 0x14, 1, 4, (s32) D_8219A80A, 0, 0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82154050; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82154050.s")
#endif

void BattleAnim_SetupEffect1Descriptor2F(Particle* arg0) {
    BattleAnim_ApplyEffect1SpeciesMotion(arg0);
    Particle_AdvanceLifecycle(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82154248; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82154248.s")
#endif

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_8218E700;
extern M2C_UNK func_82154248;

void func_821542BC(void) {
    func_8213B560(0, &func_82154248, &D_8218E700, 0, 1, 0x10, 7, 0, 0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82154310; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82154310.s")
#endif

void BattleAnim_InitModelAnimationSlot(Particle* arg0, s16 arg1) {
    Vec3f sp24;

    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);

    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModelWithAnim(arg0->unk_14, 0x21, 0x22);
        Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
        BattleAnim_ApplyModelSpeciesOffset(arg0);
        Vec3f_SetComponentsDuplicate(&sp24, (arg1 * 5.0f * 2) + -10.0f, 5.0f, 10.0f);
        Particle_AddPositionRotatedVectorByYaw(arg0, sp24);

        switch (arg1) {
            case 0:
                Particle_Field94_SetZ_0A2CC(arg0, 0x1400);
                break;

            case 1:
                Particle_Field38_AddYScaled_08E90(arg0, 2.0f);
                Particle_Field94_SetZ_0A2CC(arg0, 0);
                break;

            case 2:
                Particle_Field94_SetZ_0A2CC(arg0, -0x1400);
                break;
        }

        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_821545D0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821545D0.s")
#endif

void BattleAnim_StartEffect12DelayedModelAnim(void) {
    BattleAnim_SpawnCategory17MarkerSlot(0x55, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects12And129DelayedModelAnimWait, &gDefaultParticleDescriptor, 0x1E, 3, 6, 0, 0, 0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82154704; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82154704.s")
#endif

s32 func_8213646C();                                /* extern */
M2C_UNK func_8213B464(M2C_UNK);                     /* extern */
M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8213B6AC(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_8213BC7C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK D_8218E7A0;
extern M2C_UNK func_82152FB0;
extern M2C_UNK func_821624FC;

void func_821548B8(void) {
    s32 temp_v0;

    func_8213B560(0, &func_82152FB0, &D_8218E580, 0x1E, 1, 0xB, 0, 0x1E, 0);
    func_8213B464(0xF);
    temp_v0 = func_8213646C();
    switch (temp_v0) {                              /* irregular */
    case 0x70:
        func_8213B5D8(0, 0x10, 8, &func_821624FC, &D_8218E7A0, 0, 4, 0xB, 0, 0x18, 5);
        return;
    case 0x71:
        func_8213B644(0, 0x10, 0x1E);
        func_8213BC7C(0, 0, 8, 0, 0xFF, 0x30);
        func_8213B5D8(0, 0x10, 8, &func_821624FC, &D_8218E7A0, 0, 8, 0xB, 0, 0x17, 5);
        func_8213B6AC(0, 1, 0x20, 8, 0xFF);
        return;
    case 0x73:
        func_8213B644(0, 0x10, 0x1E);
        func_8213BC7C(0, 0, 8, 0, 0xFF, 0x30);
        func_8213B5D8(0, 0x10, 8, &func_821624FC, &D_8218E7A0, 0, 8, 0xB, 0, 0, 5);
        func_8213B6AC(0, 1, 0x20, 8, 0xFF);
        return;
    }
}

void BattleAnim_BuildReflectiveTextureDisplayList(Gfx* arg0, s32 arg1, u16 arg2) {
    BattleAnim_SetupReflectiveCamera();

    switch (BattleAnim_GetQueuedMoveId()) {
        case 0x70:
            gDPPipeSync(arg0++);
            gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 255, 255);
            gDPSetEnvColor(arg0++, 155, 255, 255, 255);
            break;

        case 0x71:
            gDPPipeSync(arg0++);
            gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 255, 255);
            gDPSetEnvColor(arg0++, 255, 255, 100, 255);
            break;

        case 0x73:
            gDPPipeSync(arg0++);
            gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 100, 255);
            gDPSetEnvColor(arg0++, 255, 100, 0, 255);
            break;
    }

    arg0 = BattleAnim_BuildAnimatedTileDisplayList(arg0, arg1, 0x20, 5, 0, 2, 0, 0, 0, 1, 0, 0);

    gSPEndDisplayList(arg0++);
}

void BattleAnim_AllocateReflectiveTextureDisplayList(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        BattleAnim_BuildReflectiveTextureDisplayList(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82154C9C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82154C9C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82154E28; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82154E28.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82154EA4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82154EA4.s")
#endif

void BattleAnim_BuildEffect125DisplayList(Gfx* arg0, u16 arg1) {
    DisplayObject* tmp = D_8006049C;

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 255, tmp->lodFraction);

    ParticleGfx_SetAnimatedTileSizeOnList(arg0++, 1, 1, 0x20, 0x20);
    ParticleGfx_SetAnimatedAuxTileSizeOnList(arg0++, 2, 2, 0x20, 0x20);

    gSPEndDisplayList(arg0++);
}

void BattleAnim_AllocateEffect125DisplayList(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 10);
        BattleAnim_BuildEffect125DisplayList(arg1->unk_18, D_80060484);
    }
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK func_82144750;
extern M2C_UNK func_82154EA4;

void func_82155084(void) {
    func_8213B560(0, &func_82154EA4, &D_8218E580, 0x1E, 1, 7, 0, 0, 0);
    func_8213B560(0x14, &func_82144750, &D_8218E580, 0x50, 1, 0, 0, 0x33, 0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215510C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215510C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821551E8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821551E8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82155238; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82155238.s")
#endif

void BattleAnim_InitEffect28Overlay(Particle* arg0) {
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_FieldCA_SetU8_0BECC(arg0, 7);
    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    Particle_SetPosition(arg0, 160.0f, 120.0f, 0.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp26);
    Particle_SetPrimAlpha(arg0, 0);
    Particle_AdvanceLifecycle(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82155380; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82155380.s")
#endif

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_8218E720;
extern M2C_UNK D_8218E7B8;
extern s16 D_8219A80A;
extern M2C_UNK func_82155380;
extern M2C_UNK func_82163D7C;

void func_821553D0(void) {
    func_8213B560(8, &func_82155380, &D_8218E720, 0, 1, 0x18, 0, 0x1C, 0);
    func_8213B560(0, &func_82163D7C, &D_8218E7B8, 0, 0xF, 0x11, (s32) D_8219A80A, 0, 0);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_8218E720;
extern M2C_UNK D_8218E7B8;
extern s16 D_8219A80A;
extern M2C_UNK func_82155380;
extern M2C_UNK func_82163D7C;

void func_82155464(void) {
    func_8213B560(8, &func_82155380, &D_8218E720, 0, 1, 0x18, 0, 0x1E, 0);
    func_8213B560(0, &func_82163D7C, &D_8218E7B8, 0, 0xF, 0x11, (s32) D_8219A80A, 0, 0);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_8218E720;
extern M2C_UNK D_8218E7B8;
extern s16 D_8219A80A;
extern M2C_UNK func_82155380;
extern M2C_UNK func_82163D7C;

void func_821554F8(void) {
    func_8213B560(8, &func_82155380, &D_8218E720, 0, 1, 0x18, 0, 0x1D, 0);
    func_8213B560(0, &func_82163D7C, &D_8218E7B8, 0, 0xF, 0x11, (s32) D_8219A80A, 0, 0);
}

void BattleAnim_InitEffect8Descriptor4A(Particle* arg0) {
    Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0xD);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C938(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8215558C(s8 *);                      /* extern */

void func_821555D4(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_8215558C(arg0);
        break;
    case 2:
        func_8213CCEC(arg0, 0, 7, 1, 2, 0);
        func_82140518(arg0, 0x20, 0x18);
        break;
    case 3:
        func_8213C938(arg0);
        break;
    }
    func_82140228(arg0, 0x3DCCCCCD, 0x3C23D70A);
}

void BattleAnim_InitEffect8ModelBurst(Particle* arg0) {
    s16 sp2E = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
    Particle_Field74_SetScaled_0AD8C(arg0, 4.5f);
    Particle_Field94_AddVec_0A52C(arg0, ParticleMath_RandomSignedOffset(0x800, -0x3800), ParticleMath_RandomSigned(0x1400), 0);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp2E * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82155724; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82155724.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82155878; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82155878.s")
#endif

s32 func_8001104C(s32);                             /* extern */
s16 func_82137D74(M2C_UNK);                         /* extern */
M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213C9D0(s8 *);                      /* extern */
M2C_UNK func_82140594(s8 *, s16);                 /* extern */
s32 func_82140690(s8 *);                          /* extern */
M2C_UNK func_82155878(s8 *);                      /* extern */
extern M2C_UNK D_8218E798;
extern M2C_UNK func_821624FC;

void func_821558F4(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82140594(arg0, func_82137D74(0x18));
        func_8213C9D0(arg0);
        return;
    case 2:
        if (func_82140690(arg0) != 0) {
            func_82155878(arg0);
            func_8213B560(0, &func_821624FC, &D_8218E798, 0, 1, 0x10, (s32) M2C_FIELD(arg0, u8 *, 0xC9), 0x17, 4);
            return;
        }
        return;
    case 3:
        if (func_8001104C(M2C_FIELD(arg0, s32 *, 0x14)) != 0) {
            func_8213C9D0(arg0);
        }
        break;
    }
}

M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK D_8218E7D0;
extern s16 D_8219A80A;
extern M2C_UNK func_82155724;
extern M2C_UNK func_82164AD0;

void func_821559E4(void) {
    func_8213B5D8(0, 4, 5, &func_82155724, &D_8218E580, 0, 2, 0x11, (s32) D_8219A80A, 0, 0);
    func_8213B5D8(0, 8, 3, &func_82164AD0, &D_8218E7D0, 0, 1, 0x11, (s32) D_8219A80A, 0x33, 6);
}

void ParticleEffect_RegisterMultiple(void) {
    s32 i;
    s32 var_s2 = 0;
    s32 tmp;
    s32 end = gBattleAnimCurrentOwner->displayObject.anchorCount;

    if (end != 0) {
        for (i = 0; i < end; i++) {
            tmp = gBattleAnimCurrentOwner->displayObject.anchors[i].id;
            BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackMove73EndEffect31SpawnDescriptor42, &gDefaultParticleDescriptor, 0, 1, 0x10, tmp, 0, 0);
            var_s2++;
            if (var_s2 >= 8) {
                break;
            }
        }
    }
}

void ParticleEffect_RegisterSpecific(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnim, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0x22, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 2, 4, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 4, 9, 0, 0x17, 1);
}

void ParticleEffect_DrawSimple(Gfx* arg0, u8* arg1) {
    BattleAnim_SetupReflectiveCamera();
    arg0 = BattleAnim_BuildAnimatedTileDisplayList(arg0, arg1, 0x20, 5, 2, 0, 0, 0, 1, 0, 0, 0);
    gSPEndDisplayList(arg0++);
}

void ParticleEffect_CreateSimpleDL(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        ParticleEffect_DrawSimple(arg1->unk_18, arg1->unk_14);
    }
}

void BattleAnim_CallbackStartEffect34SpecialModelFadeIn_InitParticle(Particle* arg0) {
    arg0->unk_14 = BattleAnim_AllocParticleDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModel(arg0->unk_14, 0x30);
        Particle_SetFlags(arg0, 0x200);
        Particle_SetScale(arg0, 5.3f);
        Particle_SetPrimAlpha(arg0, 0);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

M2C_UNK func_8213831C(s8 *, M2C_UNK);             /* extern */
s32 func_8213C9B0(s8 *);                          /* extern */
M2C_UNK func_82140548(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82155CC0(s8 *);                      /* extern */

void func_82155D3C(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82155CC0(arg0);
        break;
    case 2:
        func_82140548(arg0, 0xFF, 0x20);
        break;
    }
    if (func_8213C9B0(arg0) != 0) {
        func_8213831C(arg0 + 0x4C, 0x45674000);
    }
}

void BattleAnim_CallbackEndEffect23Descriptor4AAnimatedFade_InitParticle(Particle* arg0) {
    UNUSED s32 pad[2];
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    UNUSED s16 pad2;
    s16 sp22;

    Particle_FieldCE_GetS32_0C040(arg0);
    sp22 = Particle_FieldCF_GetS16_0C058(arg0);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_Field1C_SetScaled_0B938(arg0, 1.2f);
    Particle_SetScaleSpeed(arg0, 1.0f);
    Particle_SetScaleTarget(arg0, 0.02f);
    Particle_SetRandomVelocityXYZ(arg0, 5, 0xF, 0xF);
    Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
    Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0xA) * 0.5f) + 8.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp22);
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_FieldAE_SetS16_0BF4C(arg0, 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E6BC(s8 *);                      /* extern */
M2C_UNK func_821402B8(s8 *);                      /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_821406B4(s8 *);                          /* extern */
M2C_UNK func_82155DB8(s8 *);                      /* extern */

void func_82155EF0(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82155DB8(arg0);
        return;
    case 2:
        if (func_821406B4(arg0) != 0) {
            func_8213CB3C(arg0);
            func_82140594(arg0, 4);
            return;
        }
        return;
    case 3:
        func_821402B8(arg0);
        func_8213CCEC(arg0, 1, 7, 1, 2, 0);
        func_8213E6BC(arg0);
        func_82140518(arg0, 0x40, 8);
        return;
    case 4:
        func_8213C930(arg0);
        break;
    }
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8213B8EC(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK D_8218E580;

void func_82155FD0(void) {
    func_8213B644(0, 0x10, 0x33);
    func_8213B8EC(0, 0xFF, 0x10, 8, 0x96);
    func_8213B560(0, &func_82155D3C, &D_8218E580, 0x1E, 1, 0x14, 0, 0, 0);
}

M2C_UNK func_8213B458(M2C_UNK);                     /* extern */
M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8213BE70(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK D_8218E650;
extern M2C_UNK D_8218E7A0;
extern M2C_UNK D_8218E7D0;
extern s16 D_8219A80A;
extern M2C_UNK func_8214BA3C;
extern M2C_UNK func_82152F44;
extern M2C_UNK func_821626F4;

void func_8215604C(void) {
    func_8213B5D8(0, 8, 3, &func_82152F44, &D_8218E580, 0, 1, 0xC, 0, 0x2A, 0);
    func_8213BE70(4, 8, 0x33, 8, 0xC8, 0x18);
    func_8213B458(4);
    func_8213B5D8(0, 4, 6, &func_82155EF0, &D_8218E7D0, 0, 4, 0xB, 9, 0x13, 0);
    func_8213B5D8(0, 2, 0xC, &func_821626F4, &D_8218E7A0, 0, 4, 0xB, 9, 0x18, 0xB);
    func_8213B5D8(0, 5, 4, &func_8214BA3C, &D_8218E650, 0, 6, 0x10, (s32) D_8219A80A, 0x26, 0);
    func_8213B644(0x32, 0x20, 8);
}

#ifdef NON_MATCHING
/* TODO: decompile func_821561D4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821561D4.s")
#endif

void ParticleEffect_CreateNodeDL(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        ParticleEffect_DrawNode(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

void ParticleEffect_DrawNodeVariant(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    arg0 = BattleAnim_BuildAnimatedTileDisplayListFromStruct(arg0, arg1, 0x40, 6, -4, 0xF, 0, 0, -5, 5, 0, 0);

    gSPEndDisplayList(arg0++);
}

void ParticleEffect_CreateNodeVariantDL(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        ParticleEffect_DrawNodeVariant(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

void ParticleEffect_DrawSimpleOffsetTileNoCamera(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    arg0 = BattleAnim_BuildAnimatedTileDisplayList(arg0, arg1, 0x20, 5, -8, -0x1E, 0, 0, -0xB, -0xA, 0, 0);

    gSPEndDisplayList(arg0++);
}

void ParticleEffect_CreateSimpleOffsetTileNoCameraDL(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        ParticleEffect_DrawSimpleOffsetTileNoCamera(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

void BattleAnim_DefaultEndEffect_Draw(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_82156430; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82156430.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821564F8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821564F8.s")
#endif

void ParticleEffect_RegisterPaletteVariants(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackMove146EndEffect6ModelAnimWait, &gDefaultParticleDescriptor, 0x1E, 1, 6, gBattleAnimCurrentAnchor, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackMove146EndEffect6ModelAnimWait, &gDefaultParticleDescriptor, 0x1E, 1, 6, gBattleAnimCurrentAnchor, 1, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackMove146EndEffect6ModelAnimWait, &gDefaultParticleDescriptor, 0x1E, 1, 6, gBattleAnimCurrentAnchor, 2, 0);
}

void BattleAnim_InitEffect49Model(Particle* arg0) {
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);
    u16 sp24;

    switch (BattleAnim_GetQueuedMoveId()) {
        case 0x47:
            sp24 = 0x18;
            break;

        case 0x48:
            sp24 = 0x1F;
            break;

        case 0x8D:
            sp24 = 0x21;
            break;
    }

    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);

    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModel(arg0->unk_14, 0x33);
        if (sp26 == 0) {
            BattleAnim_BindModelAnim(arg0->unk_14, 0x34);
        } else {
            BattleAnim_BindModelAnimReversed(arg0->unk_14, 0x34);
        }
        Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215673C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215673C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821567BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821567BC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8215683C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215683C.s")
#endif

void BattleAnim_AllocateEffect49DisplayList(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        BattleAnim_BuildEffect49DisplayList(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

void ParticleEffect_RegisterColorAnim(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffect49Model33Anim34WaitCleanup, &gDefaultParticleDescriptor, 0, 1, 2, gBattleAnimCurrentAnchor, 1, 0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_821569A0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821569A0.s")
#endif

void BattleAnim_InitEffect40Model(Particle* arg0) {
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModel(arg0->unk_14, 0x35);
        Particle_Field1C_SetScaled_0B938(arg0, 5.0f);
        Particle_Field38_AddYScaled_08E90(arg0, -100.0f);
        Particle_SetPrimAlpha(arg0, 0);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82156B0C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82156B0C.s")
#endif

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK func_82156B0C;

void func_82156B90(void) {
    func_8213B560(0, &func_82156B0C, &D_8218E580, 0xA, 1, 0xA, 0, 0, 0);
}

void ParticleEffect_RegisterLargeExplosionAndEffects(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect86ModelFadeCycle, &gDefaultParticleDescriptor, 0x40, 1, 0xA, 0, 0, 0);
    BattleAnim_SpawnOwnerModelAlphaFade(0, 0xFF, 0, 0x10);
    BattleAnim_SpawnOwnerModelAlphaFade(0x2D, 0, 0xFF, 0x20);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82156C58; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82156C58.s")
#endif

void BattleAnim_AllocateEffect63DisplayList(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        BattleAnim_BuildEffect63DisplayList(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82156D7C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82156D7C.s")
#endif

void BattleAnim_AllocateEffect75DisplayList(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        BattleAnim_BuildEffect75DisplayList(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

void BattleAnim_InitEffects63And75Model(Particle* arg0) {
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        if (sp26 == 0) {
            BattleAnim_InitModelWithAnim(arg0->unk_14, 0x36, 0x37);
            Particle_Field1C_SetScaled_0B938(arg0, 0.75f);
        } else {
            BattleAnim_InitModelWithAnim(arg0->unk_14, 0x61, 0x62);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
        }
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82156EF0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82156EF0.s")
#endif

void BattleAnim_InitEffects10And50Model(Particle* arg0) {
    u16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModelWithAnim(arg0->unk_14, 0x39, 0x3A);
        Particle_Field1C_SetScaled_0B938(arg0, 0.5f);

        switch (sp26) {
            case 0:
                break;

            case 1:
                Particle_Field38_AddVecScaled_08E18(arg0, -10.0f, 0.0f, 20.0f);
                break;

            case 2:
                Particle_Field38_AddVecScaled_08E18(arg0, 10.0f, 0.0f, -20.0f);
                break;

            case 3:
                Particle_Field38_AddVecScaled_08E18(arg0, 20.0f, 0.0f, -20.0f);
                break;

            case 4:
                Particle_Field38_AddVecScaled_08E18(arg0, -20.0f, 0.0f, 20.0f);
                break;

            case 5:
                Particle_Field38_AddVecScaled_08E18(arg0, 15.0f, 0.0f, -25.0f);
                break;

            case 6:
                Particle_Field38_AddVecScaled_08E18(arg0, 20.0f, 0.0f, 30.0f);
                break;

            case 7:
                Particle_Field38_AddVecScaled_08E18(arg0, 15.0f, 0.0f, -10.0f);
                break;

            case 8:
                Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
                break;
        }
        Particle_SetPrimColor(arg0, 0xFF, 0xFF, 0xFF);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

s32 func_8001104C(s32);                             /* extern */
M2C_UNK func_8213C938(s8 *);                      /* extern */
M2C_UNK func_8213C9D0(s8 *);                      /* extern */
M2C_UNK func_8213CA80(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_82140380(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821403B0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82156F70(s8 *);                      /* extern */

void func_821570E8(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82156F70(arg0);
        return;
    case 2:
        func_8213CA80(arg0, 0xA);
        return;
    case 3:
        func_82140380(arg0, 0, 0x10);
        func_821403B0(arg0, 0, 0x20);
        if (func_8001104C(M2C_FIELD(arg0, s32 *, 0x14)) != 0) {
            func_8213C9D0(arg0);
            return;
        }
        return;
    case 4:
        func_8213C938(arg0);
        break;
    }
}

void BattleAnim_ApplyEffects63And75SpeciesScaleOffset(Particle* arg0) {
    f32 sp1C = 0.6f;
    f32 sp18 = 0.0f;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 0x3:
            sp1C = 1.0f;
            sp18 = 5.0f;
            break;

        case 0x22:
            sp1C = 1.0f;
            sp18 = 5.0f;
            break;

        case 0x4C:
            sp1C = 0.8f;
            sp18 = 5.0f;
            break;

        case 0x5E:
            sp1C = 0.8f;
            sp18 = 5.0f;
            break;

        case 0x80:
            sp1C = 0.8f;
            sp18 = 10.0f;
            break;

        case 0x82:
            sp18 = 20.0f;
            break;

        case 0x88:
            sp1C = 1.2f;
            sp18 = 10.0f;
            break;

        case 0x8E:
            sp1C = 1.2f;
            sp18 = 20.0f;
            break;

        case 0x91:
            sp1C = 1.2f;
            sp18 = 15.0f;
            break;

        case 0x95:
            sp18 = 10.0f;
            break;
    }

    Particle_Field1C_SetScaled_0B938(arg0, sp1C);
    Particle_Field38_AddXZFromField94YOffset180_08F38(arg0, sp18);
}

void BattleAnim_InitEffects63And75Model38(Particle* arg0) {
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModel(arg0->unk_14, 0x38);
        BattleAnim_ApplyEffects63And75SpeciesScaleOffset(arg0);
        Particle_SetPrimAlpha(arg0, 0);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_821573BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821573BC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8215740C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215740C.s")
#endif

void Particle_CreateDisplayList_Alpha(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_DrawParticleAlpha(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82157518; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82157518.s")
#endif

void Particle_CreateDisplayList_Texture4b(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_DrawParticleTexture4b(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_821576C8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821576C8.s")
#endif

void Particle_CreateDisplayList_GreenPrim(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_DrawParticleGreenPrim(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

void ParticleEffect_RegisterHandlers_Default(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects63And75ModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects63And75Model38FadeIn, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0, 0);
}

void ParticleEffect_RegisterAnimationCallbacks(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects10And50ModelAnimColorFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 1, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackEndEffects10And50ModelAnimColorFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 2, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(5, BattleAnim_CallbackEndEffects10And50ModelAnimColorFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 3, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackEndEffects10And50ModelAnimColorFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(9, BattleAnim_CallbackEndEffects10And50ModelAnimColorFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 5, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xA, BattleAnim_CallbackEndEffects10And50ModelAnimColorFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 6, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xD, BattleAnim_CallbackEndEffects10And50ModelAnimColorFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 7, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xA, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void ParticleEffect_RegisterHandlers_Alternate(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects63And75ModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 1, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects63And75Model38FadeIn, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0, 0);
}

void ParticleEffect_RegisterHandler_WithParticleData(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects10And50ModelAnimColorFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 8, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xA, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3E], 0, 0x10, 0xA, 0, 0x11, 0);
}

void BattleAnim_StartEffect64ModelAnimWait(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0x23, 0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82157C60; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82157C60.s")
#endif

void BattleAnim_CallbackStartEffect10Model60AlphaFadeIn_InitParticle(Particle* arg0) {
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModel(arg0->unk_14, 0x60);
        Particle_FieldCA_SetU8_0BECC(arg0, 7);
        Particle_SetFlags(arg0, 0x200);
        Particle_SetScale(arg0, 3.3f);
        Particle_SetPrimAlpha(arg0, 0);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

M2C_UNK func_8213831C(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_8213C930(s8 *);                      /* extern */
s32 func_8213C9B0(s8 *);                          /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82157DA0(s8 *);                      /* extern */

void func_82157E28(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82157DA0(arg0);
        break;
    case 2:
        func_82140518(arg0, 0x9B, 8);
        break;
    case 3:
        func_8213C930(arg0);
        break;
    }
    if (func_8213C9B0(arg0) != 0) {
        func_8213831C(arg0 + 0x4C, 0x43480000);
    }
}

void Gfx_DrawParticleCyanEnv(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    BattleAnim_GetOwnerContextParticle(D_8006049C);

    gDPPipeSync(arg0++);
    gDPSetEnvColor(arg0++, 155, 255, 255, 255);

    arg0 = BattleAnim_BuildAnimatedTileDisplayListFromStruct(arg0, arg1, 0x20, 5, 2, 1, 0xE, 0xF, 0, 4, 0xC, 5);

    gSPEndDisplayList(arg0++);
}

void Particle_CreateDisplayList_CyanEnv(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_DrawParticleCyanEnv(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82157FBC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82157FBC.s")
#endif

void Particle_CreateDisplayList_BluePrim(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_DrawParticleBluePrim(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

void BattleAnim_StartEffect10Model60AndModelAnimWait(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xE, 0, 0x25, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect10Model60AlphaFadeIn, &gDefaultParticleDescriptor, 0, 1, 0x14, 0, 0, 0);
}

void BattleAnim_StartEffect72ModelAnimWait(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xE, 0, 0x25, 0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_821581BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821581BC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82158224; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82158224.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821582A8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821582A8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82158344; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82158344.s")
#endif

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213D604(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_8213E528(s8 *);                      /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821403B0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8214047C(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_82140690(s8 *);                          /* extern */
s32 func_821406B4(s8 *);                          /* extern */
M2C_UNK func_82158344(s8 *);                      /* extern */

void func_82158450(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82158344(arg0);
        return;
    case 2:
        if (func_821406B4(arg0) != 0) {
            func_82140594(arg0, 0xA);
            func_8213CB3C(arg0);
            return;
        }
        return;
    case 3:
        func_8213CCEC(arg0, 0, 7, 1, 2, 0);
        func_82140228(arg0, 0x40200000, 0x3E800000);
        func_8213E528(arg0);
        func_8213D604(arg0, 0x3F000000);
        if (func_82140690(arg0) != 0) {
            func_82140518(arg0, 0x20, 0x10);
            func_821403B0(arg0, 0, 0x14);
            func_8214047C(arg0, 0, 0x14);
            return;
        }
        break;
    case 4:
        func_8213C930(arg0);
        break;
    }
}

void BattleAnim_CallbackStartEffects50And82Descriptor4AAnimatedVerticalFade_InitParticle(Particle* arg0) {
    UNUSED s32 pad[2];
    UNUSED s16 pad2;
    s16 sp24;

    Particle_FieldAC_GetS16_0C038(arg0);
    sp24 = Particle_FieldCF_GetS16_0C058(arg0);
    Particle_FieldCE_GetS32_0C040(arg0);
    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    Particle_SetRandomVelocityXYZ(arg0, 0xF, 0xF, 0x14);
    Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0x32) * 0.02f) + 1.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_SetPrimAlpha(arg0, 0x80);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E77C(s8 *);                      /* extern */
M2C_UNK func_821403B0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8214047C(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_82140690(s8 *);                          /* extern */
s32 func_821406B4(s8 *);                          /* extern */
M2C_UNK func_8215856C(s8 *);                      /* extern */

void func_8215863C(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_8215856C(arg0);
        return;
    case 2:
        if (func_821406B4(arg0) != 0) {
            func_8213CB3C(arg0);
            func_82140594(arg0, 5);
            return;
        }
        return;
    case 3:
        func_8213CCEC(arg0, 0, 7, 1, 2, 0);
        func_8213E77C(arg0);
        if (func_82140690(arg0) != 0) {
            func_821403B0(arg0, 0, 0x14);
            func_8214047C(arg0, 0, 0x14);
            func_82140518(arg0, 0x20, 4);
            return;
        }
        break;
    case 4:
        func_8213C930(arg0);
        break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82158740; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82158740.s")
#endif

void Particle_CreateDisplayList_CustomColors(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_DrawParticleCustomColors(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

M2C_UNK func_8213C464();                            /* extern */
M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_821401D4(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140548(s8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_82140690(s8 *);                          /* extern */
s32 func_821406B4(s8 *);                          /* extern */
M2C_UNK func_821408C8(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_821408DC(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82143478(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_821437E0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82152730(s8 *, M2C_UNK);             /* extern */

void func_821588C0(s8 *arg0) {
    s16 temp_v1;

    func_8213C464();
    temp_v1 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v1) {                              /* irregular */
    case 1:
        func_82152730(arg0, 2);
        func_821401D4(arg0, 0x3F000000);
        func_821408C8(arg0, 0x64);
        func_82143478(arg0, 0x17);
        func_82140594(arg0, 5);
        return;
    case 2:
        func_82140228(arg0, 0x40E00000, 0x3E800000);
        if (func_821406B4(arg0) != 0) {
            func_82140594(arg0, 5);
            return;
        }
        return;
    case 3:
        func_82140228(arg0, 0x40E00000, 0x3E800000);
        func_821437E0(arg0, 0x1A, 0x19);
        if (func_82140690(arg0) != 0) {
            func_821408DC(arg0, 0, 8);
            func_82140548(arg0, 0, 0x10);
            return;
        }
        break;
    case 4:
        func_8213C930(arg0);
        break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_821589E8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821589E8.s")
#endif

M2C_UNK func_8213C464();                            /* extern */
M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213D644(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_821401D4(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140548(s8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_82140690(s8 *);                          /* extern */
s32 func_821406B4(s8 *);                          /* extern */
M2C_UNK func_821408C8(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_821408DC(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82143478(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_821437E0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82152730(s8 *, M2C_UNK);             /* extern */

void func_82158BA4(s8 *arg0) {
    s16 temp_v1;

    func_8213C464();
    temp_v1 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v1) {                              /* irregular */
    case 1:
        func_82152730(arg0, 2);
        func_821401D4(arg0, 0x3E800000);
        func_821408C8(arg0, 0x64);
        func_82143478(arg0, 0x17);
        func_82140594(arg0, 5);
        func_8213D644(arg0, 0x41F00000);
        return;
    case 2:
        func_82140228(arg0, 0x40A00000, 0x3E99999A);
        if (func_821406B4(arg0) != 0) {
            func_82140594(arg0, 5);
            return;
        }
        return;
    case 3:
        func_82140228(arg0, 0x40A00000, 0x3E99999A);
        func_821437E0(arg0, 0x1A, 0x19);
        if (func_82140690(arg0) != 0) {
            func_821408DC(arg0, 0, 8);
            func_82140548(arg0, 0, 0x10);
            return;
        }
        break;
    case 4:
        func_8213C930(arg0);
        break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82158CE0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82158CE0.s")
#endif

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E6BC(s8 *);                      /* extern */
M2C_UNK func_821402B8(s8 *);                      /* extern */
M2C_UNK func_821403B0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821404DC(s8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_82140690(s8 *);                          /* extern */
s32 func_821406B4(s8 *);                          /* extern */
M2C_UNK func_82158CE0(s8 *);                      /* extern */

void func_82158E20(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82158CE0(arg0);
        return;
    case 2:
        if (func_821406B4(arg0) != 0) {
            func_8213CB3C(arg0);
            func_82140594(arg0, 4);
            return;
        }
        return;
    case 3:
        func_821402B8(arg0);
        func_8213CCEC(arg0, 1, 7, 1, 2, 0);
        func_8213E6BC(arg0);
        func_821403B0(arg0, 0, 0x20);
        func_821404DC(arg0, 0, 0x20);
        if (func_82140690(arg0) != 0) {
            return;
        }
        break;
    case 4:
        func_8213C930(arg0);
        break;
    }
}

void BattleAnim_CallbackEndEffects81And82Descriptor4FAnimatedPaletteFade_InitParticle(Particle* arg0) {
    UNUSED s32 pad[2];
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    UNUSED s16 pad2;
    s16 sp22;

    Particle_FieldCE_GetS32_0C040(arg0);
    sp22 = Particle_FieldCF_GetS16_0C058(arg0);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    Particle_SetScaleSpeed(arg0, 0.5f);
    Particle_SetScaleTarget(arg0, 0.01f);
    Particle_SetRandomVelocityXYZ(arg0, 0xA, 0, 0xF);
    Particle_Field38_AddXZFromField94Y_08ED0(arg0, 10.0f);
    Particle_Field38_AddYScaled_08E90(arg0, 5.0f);
    Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0xA) * 0.5f) + 8.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp22);
    Particle_SetPrimAlpha(arg0, 0xB4);
    Particle_FieldAE_SetS16_0BF4C(arg0, 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
s32 func_8213CB7C(s8 *);                          /* extern */
M2C_UNK func_8213CC10(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E6BC(s8 *);                      /* extern */
M2C_UNK func_8213F658(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821402B8(s8 *);                      /* extern */
M2C_UNK func_82140548(s8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_82140690(s8 *);                          /* extern */
s32 func_821406B4(s8 *);                          /* extern */
M2C_UNK func_821437E0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82158F20(s8 *);                      /* extern */

void func_82159060(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82158F20(arg0);
        break;
    case 2:
        if (func_821406B4(arg0) != 0) {
            func_8213CB3C(arg0);
            func_82140594(arg0, 4);
        }
        break;
    case 3:
        func_82140548(arg0, 0x40, 0x10);
        if (func_82140690(arg0) != 0) {
            func_821437E0(arg0, 0x16, 0x20);
        }
        func_8213F658(arg0, 0x40800000, 0x3F000000);
        func_8213E6BC(arg0);
        break;
    case 4:
        func_8213C930(arg0);
        break;
    }
    if (func_8213CB7C(arg0) != 0) {
        func_821402B8(arg0);
        func_8213CC10(arg0, 0, 7, 1, 2, 0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215917C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215917C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82159548; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82159548.s")
#endif

/**
 * Empty function. Not referenced in C.
 */
void func_821597B8(UNUSED ActivePokemon* active_pokemon, UNUSED s32 unused) {
}

void BattleAnim_TransformNop(UNUSED ActivePokemon* owner, UNUSED ActivePokemon* animated_pokemon) {
}

void BattleAnim_CallbackStartEffects71And74And111SpecialModelColorCycle_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    arg0->unk_14 = BattleAnim_AllocParticleDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        if (sp26 == 0) {
            BattleAnim_InitModel(arg0->unk_14, 0x55);
        } else {
            BattleAnim_InitModel(arg0->unk_14, 0x63);
        }
        BattleAnim_BindModelAnim(arg0->unk_14, 0x56);
        Particle_SetFlags(arg0, 0x200);
        Particle_FieldCA_SetU8_0BECC(arg0, 7);
        Particle_SetScale(arg0, 1.0f);
        ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x24);
        Particle_SetPrimAlpha(arg0, 0);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

s32 func_8001104C(s32);                             /* extern */
M2C_UNK func_8213831C(s8 *, M2C_UNK);             /* extern */
s16 func_8213C484();                                /* extern */
M2C_UNK func_8213C930(s8 *);                      /* extern */
s32 func_8213C9B0(s8 *);                          /* extern */
M2C_UNK func_8213CA80(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_821403B0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821403E0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821404DC(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821597D0(s8 *);                      /* extern */

void func_82159898(s8 *arg0) {
    s16 sp26;
    s16 temp_v1;

    sp26 = func_8213C484();
    temp_v1 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v1) {                              /* irregular */
    case 1:
        func_821597D0(arg0);
        break;
    case 2:
        func_8213CA80(arg0, 0xE);
        func_821403B0(arg0, 0xFF, 7);
        func_821403E0(arg0, 0xFF, 0x13);
        func_821404DC(arg0, 0xFF, 0x13);
        func_82140518(arg0, 0xFF, 0x13);
        break;
    case 3:
        func_8213CA80(arg0, 0x10);
        func_821403E0(arg0, 0, 0x11);
        func_821404DC(arg0, 0, 0x11);
        func_82140518(arg0, 0, 0x11);
        break;
    case 4:
        if (func_8001104C(M2C_FIELD(arg0, s32 *, 0x14)) != 0) {
            func_8213C930(arg0);
        }
        break;
    }
    if (func_8213C9B0(arg0) != 0) {
        if (sp26 == 0) {
            func_8213831C(arg0 + 0x4C, 0x432A0000);
            return;
        }
        func_8213831C(arg0 + 0x4C, 0x430C0000);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_821599E8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821599E8.s")
#endif

void Particle_CreateDisplayList_TempColors(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_DrawParticleFromTempColors(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

void BattleAnim_StartEffect71SpecialModelColorCycle(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects71And74And111SpecialModelColorCycle, &gDefaultParticleDescriptor, 0, 1, 0x14, 0, 0, 0);
}

void BattleAnim_StartEffect111GlobalTintAndSpecialModelColorCycle(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x20, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects71And74And111SpecialModelColorCycle, &gDefaultParticleDescriptor, 0, 1, 0x14, 0, 0, 0);
}

void BattleAnim_StartEffect74SpecialModelColorCycle(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects71And74And111SpecialModelColorCycle, &gDefaultParticleDescriptor, 0, 1, 0x14, 0, 1, 0);
}

void BattleAnim_EndEffect41Descriptor34Burst(void) {
    BattleAnim_EndEffects41And83Descriptor34BurstSequence();
}

M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_82166B34();                            /* extern */

void func_82159C40(void) {
    func_8213BC00(0, 0xA, 0, 0xFF, 0x40);
    func_82166B34();
    func_8213BC00(0x30, 0xA, 0xFF, 0, 2);
}

void Gfx_DrawParticleDualTileDiagonal4(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    BattleAnim_GetOwnerContextParticle(D_8006049C);
    arg0 = BattleAnim_BuildAnimatedTileDisplayList(arg0, arg1, 0x20, 5, -4, -4, 0xD, 6, 4, 4, 0xF, 1);

    gSPEndDisplayList(arg0++);
}

void Particle_CreateDisplayList_DualTileDiagonal4(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_DrawParticleDualTileDiagonal4(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

void Gfx_DrawParticleDualTileAntiDiagonal1(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    BattleAnim_GetOwnerContextParticle(D_8006049C);
    arg0 = BattleAnim_BuildAnimatedTileDisplayList(arg0, arg1, 0x20, 5, 1, -1, 0xE, 0xE, -1, 1, 2, 2);

    gSPEndDisplayList(arg0++);
}

void Particle_CreateDisplayList_DualTileAntiDiagonal1(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_DrawParticleDualTileAntiDiagonal1(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

void BattleAnim_StartEffect68ModelAnimWaitAndDescriptor42ScaleFall(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 2, 0, 0x28, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 8, 0xC, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 8, 9, 0, 0x22, 6);
}

f32 BattleAnim_GetSpeciesScaleAdjust(Particle* arg0) {
    f32 sp1C = 1.0f;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 0x3B:
            sp1C = 1.45f;
            break;

        case 0x5F:
            Particle_Field38_AddXZFromField94YOffsetMinus90_0901C(arg0, 20.0f);
            sp1C = 0.9f;
            break;

        case 0x82:
            sp1C = 0.9f;
            break;
    }
    return sp1C;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82159F70; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82159F70.s")
#endif

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK D_8218E708;
extern M2C_UNK D_8218E7D0;
extern M2C_UNK func_82159F70;
extern M2C_UNK func_82164E18;
extern M2C_UNK func_82164F04;

void func_82159FC8(void) {
    func_8213B560(0, &func_82159F70, &D_8218E580, 0, 1, 0xA, 0, 0x29, 0);
    func_8213B5D8(5, 2, 0xA, &func_82164E18, &D_8218E7D0, 0, 2, 0xA, 0, 0x44, 9);
    func_8213B5D8(0xA, 5, 6, &func_82164F04, &D_8218E708, 0, 3, 0xA, 0, 0x44, 0xB);
}

void BattleAnim_StartEffect52ModelAnim(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnim, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0x16, 0);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK D_8218E708;
extern M2C_UNK D_8218E728;
extern M2C_UNK D_8218E7D0;
extern M2C_UNK func_82152FB0;
extern M2C_UNK func_82162C68;
extern M2C_UNK func_82164E18;
extern M2C_UNK func_82164F04;

void func_8215A108(void) {
    func_8213B560(0, &func_82152FB0, &D_8218E580, 0, 1, 0xA, 0, 0x1D, 0);
    func_8213B5D8(0, 3, 3, &func_82162C68, &D_8218E728, 0, 1, 0xE, 9, 0, 0xF);
    func_8213B5D8(4, 1, 4, &func_82164E18, &D_8218E7D0, 0, 8, 0x1B, 0, 0x44, 0xA);
    func_8213B560(4, &func_82164F04, &D_8218E708, 0, 0xC, 0x1B, 0, 0x44, 0xB);
}

void BattleAnim_StartEffect55ModelAnimWaitMarkerSlotAndScaleFall(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xB, 0, 0, 0);
    BattleAnim_SpawnCategory19MarkerSlot(0x28, 1);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 4, 3, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 4, 0xB, 0, 0x17, 0xA);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B720(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK func_82152F44;

void func_8215A2DC(void) {
    func_8213B560(0, &func_82152F44, &D_8218E580, 0, 1, 4, 0, 1, 0);
    func_8213B720(0x1D, 2, 0x20, 0x12);
}

void ParticleEffect_RegisterDefaultTexture(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xB, gBattleAnimCurrentAnchor, 2, 0);
}

void BattleAnim_CallbackStartEffect17ModelAnimFinish_InitParticle(Particle* arg0) {
    Particle_FieldCD_GetU8_0C048(arg0);
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModelWithAnim(arg0->unk_14, 0x71, 0x72);
        Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
        Particle_FieldA6_SetS16_0BCA8(arg0, 0x1E);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215A418; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215A418.s")
#endif

void BattleAnim_CallbackEndEffect7ModelScaleAlphaFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldCD_GetU8_0C048(arg0);

    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        switch (sp26) {
            case 0:
                Particle_SetPosition(arg0, 8.0f, 0.0f, -10.0f);
                break;

            case 1:
                Particle_SetPosition(arg0, -10.0f, 0.0f, 12.0f);
                break;

            case 2:
                Particle_SetPosition(arg0, 0.0f, 0.0f, -2.0f);
                break;

            case 3:
                Particle_SetPosition(arg0, 15.0f, 0.0f, 3.0f);
                break;
        }

        BattleAnim_InitModelWithAnim(arg0->unk_14, 0x6E, 0x6F);
        Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
        Particle_FieldA6_SetS16_0BCA8(arg0, 0x1E);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215A5A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215A5A4.s")
#endif

void Gfx_DrawParticlePaletteBased(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    UNUSED s32 pad[2];
    s16 sp2E = Particle_FieldCF_GetS16_0C058(BattleAnim_GetOwnerContextParticle(D_8006049C));
    u8 sp2D;
    u8 sp2C;
    u8 sp2B;
    u8 sp2A;
    u8 sp29;
    u8 sp28;

    gDPLoadTextureBlock(arg0++, arg1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    ParticleGfx_SetAnimatedTileSizeOnList(arg0++, 5, 0, 0x20, 0x20);

    switch (sp2E) {
        case 0:
            sp2D = 0x96;
            sp2C = 0x32;
            sp2B = 0x32;
            sp2A = 0;
            sp29 = 0;
            sp28 = 0;
            break;

        case 1:
            sp2D = 0x78;
            sp2C = 0x96;
            sp2B = 0;
            sp2A = 0x64;
            sp29 = 0x78;
            sp28 = 0;
            break;

        case 2:
            sp2D = 0x46;
            sp2C = 0;
            sp2B = 0x78;
            sp2A = 0x64;
            sp29 = 0;
            sp28 = 0x96;
            break;

        case 3:
            sp2D = 0x64;
            sp2C = 0x96;
            sp2B = 0x96;
            sp2A = 0x64;
            sp29 = 0x96;
            sp28 = 0x96;
            break;
    }

    gDPSetPrimColor(arg0++, 0, 0xFF, sp2D, sp2C, sp2B, 255);
    gDPSetEnvColor(arg0++, sp2A, sp29, sp28, 255);

    gSPEndDisplayList(arg0++);
}

void Gfx_ParticlePaletteCallback(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_DrawParticlePaletteBased(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

void Gfx_ParticlePaletteDL(Gfx* arg0, UNUSED arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    DisplayObject* sp24 = D_8006049C;
    s32 tmp = BattleAnim_GetOwnerContextParticle(D_8006049C);
    UNUSED u8 sp1F;
    UNUSED u8 sp1E;
    u8 sp1D;
    u8 sp1C;
    u8 sp1B;
    u8 sp1A;
    u8 sp19;
    u8 sp18;

    switch (Particle_FieldCF_GetS16_0C058(tmp)) {
        case 0:
            sp1D = 0xFF;
            sp1C = 0x96;
            sp1B = 0x32;
            sp1A = 0;
            sp19 = 0;
            sp18 = 0;
            break;

        case 1:
            sp1D = 0xFF;
            sp1C = 0xFF;
            sp1B = 0xFF;
            sp1A = 0x96;
            sp19 = 0xB4;
            sp18 = 0;
            break;

        case 2:
            sp1D = 0xFF;
            sp1C = 0xFF;
            sp1B = 0xFF;
            sp1A = 0x96;
            sp19 = 0;
            sp18 = 0xC8;
            break;

        case 3:
            sp1D = 0x64;
            sp1C = 0xFF;
            sp1B = 0xFF;
            sp1A = 0xC8;
            sp19 = 0xFF;
            sp18 = 0xFF;
            break;
    }

    gDPSetCombineLERP(arg0++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED,
                      0, 0, 0, COMBINED);
    gDPSetPrimColor(arg0++, 0, 0xFF, sp1D, sp1C, sp1B, sp24->lodFraction);
    gDPSetEnvColor(arg0++, sp1A, sp19, sp18, 255);

    gSPEndDisplayList(arg0++);
}

void Gfx_ParticlePaletteColorOnlyCallback(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_ParticlePaletteDL(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

s16 BattleAnim_GetMoveKeyedModelVariantIndex(void) {
    s16 sp1E;

    switch (BattleAnim_GetQueuedMoveId()) {
        case 0x7C:
            sp1E = 0;
            break;

        case 0x33:
            sp1E = 1;
            break;

        case 0x5C:
            sp1E = 2;
            break;

        case 0x7A:
            sp1E = 3;
            break;
    }

    return sp1E;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215AB74; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215AB74.s")
#endif

s16 BattleAnim_GetMoveKeyedTrailVariantParam(void) {
    s16 sp1E;

    switch (BattleAnim_GetQueuedMoveId()) {
        case 0x7C:
            sp1E = 8;
            break;

        case 0x33:
            sp1E = 0x33;
            break;

        case 0x5C:
            sp1E = 0x33;
            break;

        case 0x7A:
            sp1E = 0x33;
            break;
    }

    return sp1E;
}

void BattleAnim_StartEffect17ModelAnimFinish(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect17ModelAnimFinish, &gDefaultParticleDescriptor, 0, 1, 0x11, gBattleAnimCurrentAnchor, BattleAnim_GetMoveKeyedModelVariantIndex(), 0);
}

void ParticleEffect_PaletteMultiBurst(void) {
    s16 sp4E;
    s16 sp44;
    s16 sp4A;

    sp4E = BattleAnim_GetMoveKeyedModelVariantIndex();
    sp44 = BattleAnim_GetMoveKeyedTintRampParam();
    sp4A = BattleAnim_GetMoveKeyedTrailVariantParam();

    BattleAnim_SpawnOwnerModelTintRampDetach(4, sp44, 0, 0xFF, 0x10);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffect7ModelScaleAlphaFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, sp4E, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackEndEffect7ModelScaleAlphaFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 1, sp4E, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackEndEffect7ModelScaleAlphaFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 2, sp4E, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xC, BattleAnim_CallbackEndEffect7ModelScaleAlphaFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 3, sp4E, 0);
    BattleAnim_SpawnOwnerModelTintRampDetach(0x28, sp44, 0xFF, 0, 0x10);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(6, 4, 0xA, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 9, 0, sp4A, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(7, 8, 5, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 9, 0, sp4A, 0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215AEA4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215AEA4.s")
#endif

void Gfx_ParticleTextureTileCallback(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    BattleAnim_GetOwnerContextParticle(D_8006049C);
    arg0 = BattleAnim_BuildAnimatedTileDisplayListFromStruct(arg0, arg1, 0x20, 5, 0, 0, 1, 1, 0, -3, 1, 1);

    gSPEndDisplayList(arg0++);
}

void Gfx_ParticleTextureTileAllocCallback(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_ParticleTextureTileCallback(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215AFEC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215AFEC.s")
#endif

void Gfx_ParticleRedPrimAllocCallback(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_ParticleRedPrimCallback(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

void ParticleEffect_SimpleBurst(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x10, 6);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects83And103ModelAlphaFadeIn, &gDefaultParticleDescriptor, 0x64, 1, 0xB, 0, 3, 6);
}

void BattleAnim_StartEffect39Descriptor26ModelAnimWaitSequence(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0x26, 0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215B164; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215B164.s")
#endif

void BattleAnim_EndEffect58ModelAnimAndDescriptorSequence(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(6, BattleAnim_CallbackInitModelAnim, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 4, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 5, 0);
    BattleAnim_EndEffect58Descriptor4AAnd51Sequence();
}

void ParticleEffect_MultiNodeAEntry(void) {
    BattleAnim_EndEffect58ModelAnimAndDescriptorSequence();
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_8213C1BC(M2C_UNK);                     /* extern */
M2C_UNK func_82168504();                            /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK func_82152FB0;

void func_8215B2B8(void) {
    func_8213BC00(4, 8, 0, 0xFF, 0x40);
    func_8213C1BC(8);
    func_8213B560(0xC, &func_82152FB0, &D_8218E580, 0, 1, 0xE, 0, 6, 0);
    func_82168504();
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_8213C1BC(M2C_UNK);                     /* extern */
M2C_UNK func_82168504();                            /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK func_82152FB0;

void func_8215B338(void) {
    func_8213BC00(6, 8, 0, 0xFF, 0x40);
    func_8213C1BC(0xA);
    func_8213B560(0xC, &func_82152FB0, &D_8218E580, 0, 1, 0xA, 0, 7, 0);
    func_82168504();
}

void Gfx_PokemonPortraitCallback(Gfx* arg0, u8 arg1, UNUSED u16 arg2) {
    u8* var_a3;
    s32 idx = arg1 * 0xB48;

    if (BattleScene_GetParticipantSideIndex(BattleAnim_GetOwnerContextParticle(D_8006049C)->unk_10) == 0) {
        var_a3 = sSide1PokemonThumbnailImage + idx;
    } else {
        var_a3 = sSide2PokemonThumbnailImage + idx;
    }

    gDPLoadTextureTile(arg0++, var_a3, G_IM_FMT_RGBA, G_IM_SIZ_16b, 76, 0, 0, 0, 75, 18, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                       G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPEndDisplayList(arg0++);
}

void Gfx_PokemonPortraitAllocCallback(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_PokemonPortraitCallback(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

void ParticleEffect_PortraitBurst(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 8, 6, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 0, 8, 0);
}

M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8215B558();                            /* extern */

void func_8215B5B8(void) {
    func_8213B644(0, 0x20, 0xE);
    func_8215B558();
}

void ParticleEffect_PortraitBurstNode(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnim, &gDefaultParticleDescriptor, 0, 1, 0xE, 0, 9, 0);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
s32 func_8213C4D0(M2C_UNK);                         /* extern */
extern M2C_UNK D_8218E580;
extern s16 D_8219A80A;
extern M2C_UNK func_82152F44;

void func_8215B63C(void) {
    if (func_8213C4D0(0x5E) == 0) {
        func_8213B560(0, &func_82152F44, &D_8218E580, 0, 1, 0x10, (s32) D_8219A80A, 0xA, 0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215B6A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215B6A4.s")
#endif

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK func_82152F44;

void func_8215B764(void) {
    func_8213B560(0, &func_82152F44, &D_8218E580, 0, 1, 0xB, 0, 0xB, 0);
    func_8213B644(0x2A, 0x10, 0x15);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213BC7C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK func_82152F44;

void func_8215B7C8(void) {
    func_8213BC7C(0, 1, 0x16, 0xFF, 0, 8);
    func_8213B560(0, &func_82152F44, &D_8218E580, 0, 1, 9, 0, 0xC, 0);
}

s32 func_82136AC0(s8 *);                          /* extern */
M2C_UNK func_82136D58(s32, M2C_UNK);                /* extern */
s16 func_8213C46C();                                /* extern */
M2C_UNK func_8213C938(s8 *);                      /* extern */
M2C_UNK func_8213C9D0(s8 *);                      /* extern */
M2C_UNK func_821401D4(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_8214050C(s8 *, M2C_UNK);             /* extern */

void func_8215B83C(s8 *arg0) {
    s16 sp26;
    s32 temp_v0;

    sp26 = func_8213C46C();
    temp_v0 = func_82136AC0(arg0);
    M2C_FIELD(arg0, s32 *, 0x14) = temp_v0;
    if (temp_v0 != 0) {
        if ((sp26 == 0) || (sp26 == 1)) {
            func_82136D58(M2C_FIELD(arg0, s32 *, 0x14), 0x8C);
        } else if ((sp26 == 2) || (sp26 == 3)) {
            func_82136D58(M2C_FIELD(arg0, s32 *, 0x14), 0x8E);
        } else {
            func_82136D58(M2C_FIELD(arg0, s32 *, 0x14), 0x8D);
        }
        func_821401D4(arg0, 0x3F800000);
        func_8214050C(arg0, 0);
        func_8213C9D0(arg0);
        return;
    }
    func_8213C938(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215B904; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215B904.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8215B9A0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215B9A0.s")
#endif

void Gfx_PaletteParticleDLCallback(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_PaletteParticleDL(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK func_82153040;
extern M2C_UNK func_8215B904;

void func_8215C158(void) {
    func_8213B560(0, &func_8215B904, &D_8218E580, 0, 1, 0xC, 0, 0, 0);
    func_8213B560(0, &func_82153040, &D_8218E580, 0, 1, 9, 0, 0xD, 0);
    func_8213B560(4, &func_82153040, &D_8218E580, 0, 1, 9, 1, 0xD, 0);
    func_8213B560(8, &func_82153040, &D_8218E580, 0, 1, 9, 2, 0xD, 0);
    func_8213B560(0xC, &func_82153040, &D_8218E580, 0, 1, 9, 0, 0xD, 0);
    func_8213B560(0x10, &func_82153040, &D_8218E580, 0, 1, 9, 1, 0xD, 0);
    func_8213B560(0x14, &func_82153040, &D_8218E580, 0, 1, 9, 2, 0xD, 0);
    func_8213B560(0x18, &func_82153040, &D_8218E580, 0, 1, 9, 0, 0xD, 0);
    func_8213B560(0x1C, &func_82153040, &D_8218E580, 0, 1, 9, 1, 0xD, 0);
    func_8213B560(0x20, &func_82153040, &D_8218E580, 0, 1, 9, 2, 0xD, 0);
    func_8213B644(0, 8, 0x33);
}

void ParticleEffect_PaletteMultiBurstNoCleanupNoTintFade(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects95To97EndEffects62And63ModelFadeIn, &gDefaultParticleDescriptor, 0, 1, 0xC, 1, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 1, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 2, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xC, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x10, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 1, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x14, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 2, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x18, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x1C, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 1, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x20, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 2, 0xD, 0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215C614; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215C614.s")
#endif

void ParticleEffect_PaletteBurstVariant4Model8D(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects95To97EndEffects62And63ModelFadeIn, &gDefaultParticleDescriptor, 0, 1, 0xC, 4, 0, 0);
}

M2C_UNK func_8213B464(M2C_UNK);                     /* extern */
M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8213B720(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK func_8215B904;

void func_8215C7AC(void) {
    func_8213B560(0, &func_8215B904, &D_8218E580, 0, 1, 0xC, 2, 0, 0);
    func_8213B644(0, 8, 0);
    func_8213B464(0x40);
    func_8213B720(0, 2, 0x10, 8);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B720(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK D_8218E728;
extern M2C_UNK func_8215B904;
extern M2C_UNK func_82162C68;

void func_8215C82C(void) {
    func_8213B720(0, 2, 0x10, 8);
    func_8213BC00(4, 8, 0xFF, 0, 8);
    func_8213B560(0, &func_8215B904, &D_8218E580, 0, 1, 0xC, 3, 0, 0);
    func_8213B5D8(4, 4, 4, &func_82162C68, &D_8218E728, 0, 3, 9, 0, 0x18, 0xD);
}

void BattleAnim_CallbackStartEffects21And93ModelAlphaAnchorFollow_InitParticle(Particle* arg0) {
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModelWithAnim(arg0->unk_14, 0x42, 0xC2);
        Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
        ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x23);
        Particle_SetPrimAlpha(arg0, 0);
        Particle_FieldAE_SetS16_0BF4C(arg0, 0);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

s32 func_821385C0();                                /* extern */
M2C_UNK func_8213EAD4(s8 *, s16);                 /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8214083C(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8215C8FC(s8 *);                      /* extern */

void func_8215C984(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_8215C8FC(arg0);
        break;
    case 2:
        func_82140518(arg0, 0xFF, 8);
        func_8214083C(arg0, 0xC8, 6);
        break;
    }
    func_8213EAD4(arg0, (s16) (func_821385C0() + 0x8000));
}

void BattleAnim_CallbackEndEffect60Model42AnimC2RotationYFollow_InitParticle(Particle* arg0) {
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModelWithAnim(arg0->unk_14, 0x42, 0xC2);
        BattleAnim_SetModelAnimFrame(arg0->unk_14, 0x28);
        Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
        ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x23);
        Particle_FieldAE_SetS16_0BF4C(arg0, 0xFF);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

s32 func_821385C0();                                /* extern */
M2C_UNK func_8213EAD4(s8 *, s16);                 /* extern */
M2C_UNK func_8215CA14();                            /* extern */

void func_8215CA9C(s8 *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0xAE) == 1) {
        func_8215CA14();
    }
    func_8213EAD4(arg0, (s16) (func_821385C0() + 0x8000));
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215CAF0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215CAF0.s")
#endif

void Gfx_WaterAnimPrimEnvDLCallback(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_WaterAnimPrimEnvDL(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

void ParticleEffect_WaterAnimBurst(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 3);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects21And93ModelAlphaAnchorFollow, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0, 0);
}

M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */

void func_8215CCF0(void) {
    func_8213B644(0x10, 0x10, 8);
}

M2C_UNK func_8213B464(M2C_UNK);                     /* extern */
M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8213B720(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8213B878(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK D_8218E728;
extern M2C_UNK func_82162C68;

void func_8215CD18(void) {
    func_8213B560(0, &func_8215C984, &D_8218E580, 0, 1, 0xA, 0, 0, 0);
    func_8213B644(0, 0x20, 3);
    func_8213BC00(8, 8, 0, 0xFF, 0x40);
    func_8213B878(0xC, 5, 0x10, 8);
    func_8213B560(0xC, &func_82162C68, &D_8218E728, 0, 4, 9, 0, 0x18, 0xD);
    func_8213B464(0x21);
    func_8213B720(0, 0, 0x10, 8);
    func_8213BC00(0, 8, 0xFF, 0, 0x10);
}

M2C_UNK func_8213B464(M2C_UNK);                     /* extern */
M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8213B720(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK D_8218E728;
extern M2C_UNK func_82162C68;

void func_8215CE20(void) {
    func_8213B560(0, &func_8215CA9C, &D_8218E580, 0, 1, 0xA, 0, 0, 0);
    func_8213B720(0, 0, 0x10, 8);
    func_8213B644(0, 0x20, 3);
    func_8213BC00(8, 8, 0, 0xFF, 0x40);
    func_8213B560(0xC, &func_82162C68, &D_8218E728, 0, 4, 9, 0, 0x18, 0xD);
    func_8213B464(0x21);
    func_8213BC00(0, 8, 0xFF, 0, 0x10);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215CF14; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215CF14.s")
#endif

void Gfx_WaterAnimDLCallback(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_WaterAnimDL(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215D18C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215D18C.s")
#endif

M2C_UNK func_8213B464(M2C_UNK);                     /* extern */
M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8214DA90();                            /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK D_8218E5D8;
extern M2C_UNK func_821530F4;
extern M2C_UNK func_82164AD0;

void func_8215D31C(void) {
    func_8213B560(0, &func_821530F4, &D_8218E580, 0xFF, 1, 0xC, 0, 0xF, 0x40);
    func_8214DA90();
    func_8213B464(0x10);
    func_8213B5D8(0, 4, 5, &func_82164AD0, &D_8218E5D8, 0, 1, 0xE, 0, 0xC, 4);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215D3D0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215D3D0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8215D520; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215D520.s")
#endif

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B720(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_8218E580;
extern s16 D_8219A80A;
extern M2C_UNK func_82152F44;

void func_8215D6B4(void) {
    func_8213B560(0, &func_82152F44, &D_8218E580, 0, 1, 0x13, (s32) D_8219A80A, 0x10, 0);
    func_8213B720(0x22, 0, 0x10, 8);
}

void BattleAnim_CallbackStartEffect101EndEffect65Descriptor4ABurstChild_InitParticle(Particle* arg0) {
    Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x33);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C938(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8215D724(s8 *);                      /* extern */

void func_8215D76C(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_8215D724(arg0);
        break;
    case 2:
        func_8213CCEC(arg0, 0, 7, 1, 2, 0);
        func_82140518(arg0, 0x20, 0x40);
        break;
    case 3:
        func_8213C938(arg0);
        break;
    }
    func_82140228(arg0, 0x3F000000, 0x3DCCCCCD);
}

void BattleAnim_CallbackStartEffect101ModelBurstEmitter_InitParticle(Particle* arg0) {
    Particle_FieldAC_GetS16_0C038(arg0);
    Particle_Field1C_SetScaled_0B938(arg0, 0.3f);
    Particle_Field94_AddVec_0A52C(arg0, -0x1000, 0, 0);
    Particle_FieldA0_SetY_0A414(arg0, BattleAnim_GetParticleAngleYToTertiaryOwner(arg0));
    Particle_Field9A_SetY_0A3D8(arg0, 0x80);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215D89C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215D89C.s")
#endif

void ParticleEffect_RotationEntry(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect101ModelBurstEmitter, &gDefaultParticleDescriptor, 0, 1, 0x11, gBattleAnimCurrentAnchor, 0, 0);
}

void BattleAnim_CallbackMove140EndEffect65EmitDescriptor4A_InitParticle(Particle* arg0) {
    Particle_FieldAC_GetS16_0C038(arg0);
    Particle_Field1C_SetScaled_0B938(arg0, 0.4f);
    Particle_Field38_SetYScaled_08CA0(arg0, 15.0f);
    Particle_Field38_AddXZFromField94Y_08ED0(arg0, 50.0f);
    Particle_Field94_AddVec_0A52C(arg0, 0x800, -0x8000, 0);
    Particle_Field74_SetScaled_0AD8C(arg0, 8.0f);
    Particle_AdvanceLifecycle(arg0);
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    BattleAnim_InitModel(arg0->unk_14, 0xA0);
}

M2C_UNK func_82139E5C(s8 *, M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_8213C938(s8 *);                      /* extern */
M2C_UNK func_8213CA80(s8 *, M2C_UNK);             /* extern */
s32 func_8213CB7C(s8 *);                          /* extern */
M2C_UNK func_8213E528(s8 *);                      /* extern */
M2C_UNK func_8213EF88(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8215DA5C(s8 *);                      /* extern */
extern M2C_UNK D_8218E7D0;

void func_8215DAEC(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_8215DA5C(arg0);
        break;
    case 2:
        func_82139E5C(arg0, &func_8215D76C, &D_8218E7D0, 1);
        func_8213EF88(arg0, 0x1000, 0x80);
        func_8213CA80(arg0, 7);
        break;
    case 3:
        func_8213C938(arg0);
        break;
    }
    if (func_8213CB7C(arg0) != 0) {
        func_8213E528(arg0);
    }
}

void ParticleEffect_FireworkEntry(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackMove140EndEffect65EmitDescriptor4A, &gDefaultParticleDescriptor, 0, 1, 0x11, gBattleAnimCurrentAnchor, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(5, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 0, 6);
    BattleAnim_CreateEffectSlotForCurrentOwner(7, BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0x11, 9, 0, 0);
}

void BattleAnim_CallbackStartEffect49EndEffect66ModelFadeIn_InitParticle(Particle* arg0) {
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModel(arg0->unk_14, 0xA2);
        Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
        Particle_SetPrimAlpha(arg0, 0);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215DCE8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215DCE8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8215DD38; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215DD38.s")
#endif

void Gfx_SimpleNodeDLCallback(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        Gfx_SimpleNodeDL(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

void ParticleEffect_SimpleNodeEntry(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x10, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect49EndEffect66ModelFadeIn, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0, 0);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213BC7C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK D_8218E728;
extern M2C_UNK func_8215DCE8;
extern M2C_UNK func_82162C68;

void func_8215DEF4(void) {
    func_8213BC7C(0, 2, 8, 0xFF, 0, 0x10);
    func_8213B560(0, &func_8215DCE8, &D_8218E580, 0, 1, 9, 0, 1, 0);
    func_8213B5D8(4, 4, 4, &func_82162C68, &D_8218E728, 0, 3, 9, 0, 0x18, 0xD);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215DFB4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215DFB4.s")
#endif

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8213B6AC(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_8213BC7C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK func_821530F4;

void func_8215E050(void) {
    func_8213B644(0, 5, 0);
    func_8213B560(0, &func_821530F4, &D_8218E580, 0xFF, 1, 0xC, 8, 0x18, 5);
    func_8213BC7C(0x32, 1, 8, 0, 0xFF, 0x20);
    func_8213B6AC(0x32, 1, 0x20, 8, 0xFF);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8213B6AC(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_8213BC7C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK func_821530F4;

void func_8215E0FC(void) {
    func_8213B644(0, 6, 0);
    func_8213B560(0, &func_821530F4, &D_8218E580, 0xFF, 1, 0xC, 7, 0x17, 6);
    func_8213B6AC(0x32, 1, 0x20, 8, 0xFF);
    func_8213BC7C(0x32, 1, 8, 0, 0xFF, 0x20);
}

M2C_UNK func_8213B464(M2C_UNK);                     /* extern */
M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8213B720(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK D_8218E728;
extern M2C_UNK func_8215DFB4;
extern M2C_UNK func_82162C68;

void func_8215E1A8(void) {
    func_8213B644(0, 0x40, 0);
    func_8213B560(0, &func_8215DFB4, &D_8218E580, 0xFF, 1, 0xC, 8, 0x18, 0x20);
    func_8213B5D8(4, 4, 4, &func_82162C68, &D_8218E728, 0, 3, 9, 0, 0x18, 0xD);
    func_8213BC00(8, 8, 0, 0xFF, 0x40);
    func_8213B720(0, 0, 0x10, 8);
    func_8213B464(0x21);
    func_8213BC00(0, 8, 0xFF, 0, 4);
    func_8213B644(8, 4, 8);
}

M2C_UNK func_8213B464(M2C_UNK);                     /* extern */
M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8213B720(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK D_8218E728;
extern M2C_UNK func_8215DFB4;
extern M2C_UNK func_82162C68;

void func_8215E2C4(void) {
    func_8213B644(0, 0x40, 0);
    func_8213B560(0, &func_8215DFB4, &D_8218E580, 0xFF, 1, 0xC, 7, 0x17, 0x20);
    func_8213B5D8(4, 4, 4, &func_82162C68, &D_8218E728, 0, 3, 9, 0, 0x18, 0xD);
    func_8213BC00(8, 8, 0, 0xFF, 0x40);
    func_8213B720(0, 0, 0x10, 8);
    func_8213B464(0x21);
    func_8213BC00(0, 8, 0xFF, 0, 4);
    func_8213B644(8, 4, 8);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215E3E0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215E3E0.s")
#endif

void BattleAnim_EndEffect85TintAndDescriptorMode2Sequence(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x20, 6);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimMode2Update, &gDefaultParticleDescriptor, 0x80, 1, 0xC, 0xA, 0x1A, 0x20);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_8213BD78(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_82168844(M2C_UNK);                     /* extern */
extern M2C_UNK D_8218E7F8;
extern M2C_UNK func_82145CC4;

void func_8215E57C(void) {
    func_82168844(0xE);
    func_8213B644(0, 2, 0xE);
    func_8213BC00(0, 0xA, 0, 0xC8, 4);
    func_8213BD78(0x32, 0xA, 0x17, 2, 0xC8);
    func_8213B560(0x40, &func_82145CC4, &D_8218E7F8, 0, 0x20, 7, 0, 0, 0);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_8213C0D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK D_8218E770;
extern s16 D_8219A80A;
extern M2C_UNK func_82152FE0;
extern M2C_UNK func_82164AD0;

void func_8215E61C(void) {
    func_8213B644(0, 0x20, 6);
    func_8213BC00(0, 0x12, 0, 0x80, 0x10);
    func_8213C0D8(0, 0xFF, 0, 0x10);
    func_8213B560(0, &func_82152FE0, &D_8218E580, 0xFF, 1, 9, (s32) D_8219A80A, 0x12, 0x20);
    func_8213B5D8(0, 1, 0xC, &func_82164AD0, &D_8218E770, 0, 1, 9, 0, 0x16, 5);
}

void ParticleEffect_PlaySoundAndReset(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0x13, 0);
    BattleAnim_SetSpawnDelay(4);
    BattleAnim_EndEffect25Descriptor13DelegateSequence();
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215E76C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215E76C.s")
#endif

void ParticleEffect_AllocateDisplayList(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        ParticleEffect_DrawQuad(arg1->unk_18, arg1->unk_14, D_80060484);
    }
}

void BattleAnim_EndEffect72Descriptor20ModelAnimWaitSequence(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xE, 5, 0x14, 0);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_82168A50();                            /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK func_821530F4;

void func_8215EC9C(void) {
    func_8213B560(0, &func_821530F4, &D_8218E580, 0xBE, 1, 9, 6, 0x15, 2);
    func_8213BC00(8, 8, 0, 0xFF, 4);
    func_82168A50();
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215ED1C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215ED1C.s")
#endif

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK func_8215ED1C;

void func_8215EDC0(void) {
    func_8213BC00(4, 8, 0xFF, 0, 0x20);
    func_8213B560(4, &func_8215ED1C, &D_8218E580, 0, 1, 9, 0, 0x19, 0);
}

void ParticleEffect_TriggerDefaultPalette1B(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0x11, gBattleAnimCurrentAnchor, 0x1B, 1);
}

void ParticleEffect_TriggerDefaultPalette1C(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0x11, gBattleAnimCurrentAnchor, 0x1C, 1);
}

void ParticleEffect_TriggerDefaultPalette1BWithTintFade(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x20, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0x11, gBattleAnimCurrentAnchor, 0x1B, 1);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK D_8218E580;
extern s16 D_8219A80A;
extern M2C_UNK func_82152F44;

void func_8215EF60(void) {
    func_8213BC00(0, 0xA, 0, 0xFF, 0x40);
    func_8213B560(0, &func_82152F44, &D_8218E580, 0, 1, 0x11, (s32) D_8219A80A, 0x1C, 1);
    func_8213BC00(0x30, 0xA, 0xFF, 0, 2);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215EFF8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215EFF8.s")
#endif

M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK func_8215EFF8;

void func_8215F0F0(void) {
    func_8213B5D8(0, 2, 3, &func_8215EFF8, &D_8218E580, 0, 1, 0x11, 7, 0x20, 0);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_8218E580;
extern M2C_UNK func_8215EFF8;

void func_8215F154(void) {
    func_8213B560(0, &func_8215EFF8, &D_8218E580, 0, 1, 0x11, 7, 0x20, 1);
}

s32 func_8001104C(s32);                             /* extern */
M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821437E0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82152730(s8 *, M2C_UNK);             /* extern */

void func_8215F1B0(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82152730(arg0, 0);
        return;
    case 2:
        func_821437E0(arg0, 0x33, 0x24);
        func_82140518(arg0, 0xFF, 0x1D);
        if (func_8001104C(M2C_FIELD(arg0, s32 *, 0x14)) != 0) {
            func_8213C930(arg0);
        }
        return;
    }
}

void ParticleEffect_CreateColorVariant(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffect79DefaultDescriptorPaletteFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0x1F, 0);
}

M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */

void func_8215F290(void) {
    func_8213B644(0, 8, 0x20);
}

void BattleAnim_CallbackStartEffects127And128Descriptor39ScaleFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_FieldCE_GetS32_0C040(arg0);

    switch (sp26) {
        case 0:
            Particle_SetPosition(arg0, 0.0f, 0.0f, 0.0f);
            break;

        case 1:
            Particle_SetPosition(arg0, 0.0f, 10.0f, 10.0f);
            break;

        case 2:
            Particle_SetPosition(arg0, 0.0f, 15.0f, -15.0f);
            break;
    }

    Particle_Field1C_SetScaled_0B938(arg0, 0.1f);
    Particle_SetScaleSpeed(arg0, 2.0f);
    Particle_SetScaleTarget(arg0, 0.0625f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 8);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
M2C_UNK func_821402B8(s8 *);                      /* extern */
M2C_UNK func_82140548(s8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_82140690(s8 *);                          /* extern */
s32 func_821406B4(s8 *);                          /* extern */
M2C_UNK func_8215F2B8(s8 *);                      /* extern */

void func_8215F3EC(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_8215F2B8(arg0);
        return;
    case 2:
        if (func_821406B4(arg0) != 0) {
            func_8213CB3C(arg0);
            func_82140594(arg0, 0xA);
            return;
        }
        return;
    case 3:
        func_821402B8(arg0);
        if (func_82140690(arg0) != 0) {
            func_82140548(arg0, 0, 0x10);
            return;
        }
        break;
    case 4:
        func_8213C930(arg0);
        break;
    }
}

void BattleAnim_StartEffect127Descriptor39ScaleFade(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects127And128Descriptor39ScaleFade, &gBattleAnimParticleDescriptors[0x39], 8, 3, 2, 0, 0x45, 0);
}

void BattleAnim_StartEffect128Descriptor39ScaleFade(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects127And128Descriptor39ScaleFade, &gBattleAnimParticleDescriptors[0x39], 8, 3, 2, 0, 0x47, 0);
}

void ParticleEffect_CreateTypeX(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects12And129DelayedModelAnimWait, &gDefaultParticleDescriptor, 0x1E, 3, 6, 0, 0, 0);
}

void ParticleEffect_CreateSmoke(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 0, 6);
}

void ParticleEffect_CreateSmokeHighPriority(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0x10, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 0, 6);
}

void BattleAnim_CallbackStartEffect132Descriptor39DelayedRiseFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_FieldCE_GetS32_0C040(arg0);

    switch (sp26) {
        case 0:
            Particle_SetPosition(arg0, 0.0f, 0.0f, 0.0f);
            break;

        case 1:
            Particle_SetPosition(arg0, 0.0f, 10.0f, 10.0f);
            break;

        case 2:
            Particle_SetPosition(arg0, 0.0f, 15.0f, -15.0f);
            break;
    }

    Particle_Field1C_SetScaled_0B938(arg0, 0.01f);
    Particle_SetScaleSpeed(arg0, 0.5f);
    Particle_SetScaleTarget(arg0, 0.05f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 8);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8215F790; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8215F790.s")
#endif

void ParticleEffect_CreateDual(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect132Descriptor39DelayedRiseFade, &gBattleAnimParticleDescriptors[0x39], 8, 3, 2, 0, 0x46, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x10, BattleAnim_CallbackStartEffect132Descriptor39DelayedRiseFade, &gBattleAnimParticleDescriptors[0x39], 8, 3, 2, 0, 0x46, 0);
}
