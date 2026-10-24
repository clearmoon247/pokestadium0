/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_31AA30.c, src/fragments/battle_engine/battle_engine_32B680.c, src/fragments/battle_engine/battle_engine_343BA0.c, src/fragments/battle_engine/battle_engine_move_animation.c, src/fragments/particle_math/particle_math_26E6D0.c. */

#include "fragments/particle_math/particle_math.h"
extern u8 gParticlePalette[][3];
extern u8 gParticlePaletteSetA[];
extern u8 gParticlePaletteSetB[];
extern u8 gParticleRandomPaletteIndices[];
extern u8 gParticlePalettePairs[][2];

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

void ParticleGfx_LoadTextureCallbackIa8_32x32(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4_32x32(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4FrameMod4_32x32(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod4_32x32(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4FrameDiv4Mod4_32x32(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_32x32(UNUSED Particle* arg0, u8* texture);
void func_82140D50(void);
void ParticleGfx_LoadTextureCallbackI4FrameMod10_32x64(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4_64x64(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4FrameMod8_64x64(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_64x64(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4WrapST_64x64(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackIa8WrapST_64x64(UNUSED Particle* arg0, u8* texture);
void ParticleEffect_Noop(UNUSED s32 arg0, UNUSED s32 arg1);
void BattleAnim_DrawAsset76Ia8FrameWithAsset77I4OverlayPipelineA(Particle* arg0, CameraNode* arg1);
void BattleAnim_DrawAsset76Ia8FrameWithAsset77I4OverlayPipelineB(Particle* arg0, CameraNode* arg1);
void func_82142678(UNUSED ActivePokemon* active_pokemon, UNUSED s32 unused);

void BattleAnim_DrawAsset76Ia8FrameWithAsset77I4Overlay(Particle* arg0, CameraNode* arg1);

M2C_UNK func_8216BBF8(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_82140B70(s8 *arg0, s32 arg1) {
    func_8216BBF8((M2C_FIELD(arg0, s8 *, 0xC3) << 0xA) + arg1, 0x20, 0x20);
}

void ParticleGfx_LoadTextureCallbackIa8_32x32(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureIa8(texture, 32, 32);
}

M2C_UNK func_8216BBF8(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_82140BD0(s8 *arg0, s32 arg1) {
    func_8216BBF8((M2C_FIELD(arg0, s8 *, 0xC3) << 0xB) + arg1, 0x20, 0x40);
}

void ParticleGfx_LoadTextureCallbackI4_32x32(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(texture, 32, 32);
}

M2C_UNK func_8216BFE8(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_82140C30(s8 *arg0, s32 arg1) {
    func_8216BFE8((M2C_FIELD(arg0, s8 *, 0xC3) << 9) + arg1, 0x20, 0x20);
}

void ParticleGfx_LoadTextureCallbackI4FrameMod4_32x32(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[gParticleFrameMod4 * (32 * 32 / 2)], 32, 32);
}

void ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod4_32x32(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[(gParticleFrameDiv2 & 3) * (32 * 32 / 2)], 32, 32);
}

void ParticleGfx_LoadTextureCallbackI4FrameDiv4Mod4_32x32(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[(gParticleFrameDiv4 & 3) * (32 * 32 / 2)], 32, 32);
}

void ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_32x32(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[(gParticleFrameDiv2 & 7) * (32 * 32 / 2)], 32, 32);
}

void func_82140D50(void) {
}

M2C_UNK func_8216C008(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_82140D58(s8 *arg0, s32 arg1) {
    func_8216C008((M2C_FIELD(arg0, s8 *, 0xC3) * 0x120) + arg1, 0x18, 0x18);
}

void ParticleGfx_LoadTextureCallbackI4FrameMod10_32x64(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[(gParticleFrameCounter % 10) * (32 * 64 / 2)], 32, 64);
}

M2C_UNK func_8216BFE8(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_82140DD8(s8 *arg0, s32 arg1) {
    func_8216BFE8((M2C_FIELD(arg0, s8 *, 0xC3) << 0xA) + arg1, 0x20, 0x40);
}

void ParticleGfx_LoadTextureCallbackI4_64x64(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(texture, 64, 64);
}

void ParticleGfx_LoadTextureCallbackI4FrameMod8_64x64(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[gParticleFrameMod8 * (64 * 64 / 2)], 64, 64);
}

void ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_64x64(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[(gParticleFrameDiv2 & 7) * (64 * 64 / 2)], 64, 64);
}

M2C_UNK func_8216BFE8(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_82140EAC(s8 *arg0, s32 arg1) {
    func_8216BFE8((M2C_FIELD(arg0, s8 *, 0xC3) << 0xB) + arg1, 0x40, 0x40);
}

void ParticleGfx_LoadTextureCallbackI4WrapST_64x64(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4WrapST(texture, 64, 64);
}

void ParticleGfx_LoadTextureCallbackIa8WrapST_64x64(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureIa8WrapST(texture, 64, 64);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82140F38; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82140F38.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82140FAC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82140FAC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82141038; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82141038.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82141128; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82141128.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821411B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821411B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82141220; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82141220.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8214127C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8214127C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82141308; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82141308.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8214139C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8214139C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82141428; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82141428.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821414B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821414B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82141540; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82141540.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821415CC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821415CC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821416BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821416BC.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_821418DC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821418DC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82141A00; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82141A00.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_82141CF0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82141CF0.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_82142DB8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82142DB8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82142EDC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82142EDC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82143000; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82143000.s")
#endif

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
