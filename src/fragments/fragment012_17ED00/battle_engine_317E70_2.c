/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_317E70.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "geo_render.h"
#include "model_renderer.h"
#include "matrix.h"
#include "fragments/particle_math/particle_math.h"
#include "memory.h"

void BattleAnim_CleanupEffects(s32 cleanup_mode);
void BattleAnim_ResetSpawnDelay(void);
void BattleAnim_SetSpawnDelay(s32 arg0);
void BattleAnim_AddSpawnDelay(s32 arg0);
void BattleAnim_ResetSpawnDelayAlias(void);
BattleAnimEffectSlot* BattleAnim_CreateEffectSlot(s32 arg0, s32 arg1, s8 arg2, func_unk_D_8140E724 arg3, ParticleDescriptor* arg4,
                              ActivePokemon* arg5, s16 arg6, s16 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB);
BattleAnimEffectSlot* BattleAnim_CreateEffectSlotForCurrentOwner(s32 arg0, func_unk_D_8140E724 arg1, ParticleDescriptor* arg2, s16 arg3, s16 arg4, u8 arg5,
                              u8 arg6, u8 arg7, u8 arg8);
BattleAnimEffectSlot* BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(s32 arg0, s32 arg1, s8 arg2, func_unk_D_8140E724 arg3, ParticleDescriptor* arg4, s16 arg5,
                              s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA);
BattleAnimEffectSlot* BattleAnim_SpawnGlobalTintColorFadeDetach(s32 arg0, s16 arg1, u8 arg2);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaFadeInHoldOut(s32 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(s32 arg0, s16 arg1, s16 arg2, u8 arg3);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldFadeOut(s32 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldFadeOutRepeating(s32 arg0, s32 arg1, s8 arg2, s16 arg3, s16 arg4, u8 arg5, u8 arg6);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaFadeInHoldFullAlpha(s32 arg0, s16 arg1, s16 arg2, u8 arg3);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaFadeInHold(s32 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaFadeInHoldRepeating(s32 arg0, s32 arg1, s8 arg2, s16 arg3, s16 arg4, u8 arg5, u8 arg6);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldDetachFullAlpha(s32 arg0, s16 arg1, u8 arg2);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldDetach(s32 arg0, s16 arg1, u8 arg2, u8 arg3);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldDetachRepeating(s32 arg0, s32 arg1, s8 arg2, s16 arg3, u8 arg4, u8 arg5);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25PaletteFadeOut(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25PaletteFadeIn(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintRampDetach(s32 arg0, u8 arg1, s16 arg2, s16 arg3, s16 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPulseDetach(s32 arg0, s16 arg1, u8 arg2, s16 arg3, s16 arg4, s16 arg5);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintHoldFadeDetach(s32 arg0, s16 arg1, u8 arg2, s16 arg3, s16 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteApproachInactive(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteApproachInactiveAlt(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteCycle(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteCycleVariant(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteFade(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintRandomPaletteCycle(s32 arg0, s16 arg1, u8 arg2);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteRotateFadeDetach(s32 arg0, s16 arg1, s16 arg2, u8 arg3);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelAlphaFade(s32 arg0, s16 arg1, s16 arg2, s16 arg3);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelAlphaFadeFullPreset(s32 arg0);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelAlphaFadeZeroStartPreset(s32 arg0);
BattleAnimEffectSlot* BattleAnim_SpawnCategory17MarkerSlot(s32 arg0, u8 arg1);
BattleAnimEffectSlot* BattleAnim_SpawnCategory19MarkerSlot(s32 arg0, u8 arg1);

BattleAnimEffectSlot* BattleAnim_AllocEffectSlot(void);
void BattleAnim_CleanupEffectsRetainingCategories47(void);
void BattleAnim_CleanupEffectsRetainingCategory4(void);
void BattleAnim_ClearEffectCallbacks(void);
s32 BattleAnim_IsEffectSpawningEnabled(void);
void BattleAnim_EnableEffectSpawning(void);

void BattleAnim_CleanupEffects(s32 cleanup_mode) {
    BattleAnim_ResetSpawnDelay();
    switch (cleanup_mode) {
        case 1:
            BattleAnim_CleanupEffectsRetainingCategories47();
            if (BattleAnim_IsEffectSpawningEnabled() != 0) {
                BattleAnim_ClearEffectCallbacks();
            }
            break;

        case 2:
            BattleAnim_CleanupEffectsRetainingCategory4();
            BattleAnim_ClearEffectCallbacks();
            BattleAnim_EnableEffectSpawning();
            BattleAnim_ReinitAuxiliaryEffects();
            break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213B3A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213B3A4.s")
#endif

void BattleAnim_ResetSpawnDelay(void) {
    gBattleAnimSpawnDelay = 0;
}

void BattleAnim_SetSpawnDelay(s32 arg0) {
    gBattleAnimSpawnDelay = arg0;
}

void BattleAnim_AddSpawnDelay(s32 arg0) {
    gBattleAnimSpawnDelay += arg0;
}

void BattleAnim_ResetSpawnDelayAlias(void) {
    BattleAnim_ResetSpawnDelay();
}

BattleAnimEffectSlot* BattleAnim_CreateEffectSlot(s32 arg0, s32 arg1, s8 arg2, func_unk_D_8140E724 arg3, ParticleDescriptor* arg4,
                              ActivePokemon* arg5, s16 arg6, s16 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB) {
    BattleAnimEffectSlot* sp1C = BattleAnim_AllocEffectSlot();

    if ((u32)sp1C != -1) {
        sp1C->unk_0E = arg0 + gBattleAnimSpawnDelay;
        sp1C->unk_0C = arg1;
        sp1C->unk_14 = arg2;
        sp1C->unk_00 = arg3;
        sp1C->unk_04 = arg4;
        sp1C->unk_08 = arg5;
        sp1C->unk_16 = arg8;
        sp1C->unk_10 = arg6;
        sp1C->unk_12 = arg7;
        sp1C->unk_19 = arg9;
        sp1C->unk_1A = argB;
        sp1C->unk_1B = argA;
        sp1C->unk_17 = BattleAnim_GetCurrentEffectList();
        sp1C->unk_18 = BattleAnim_GetQueuedResourceListId();
    }
    return sp1C;
}

BattleAnimEffectSlot* BattleAnim_CreateEffectSlotForCurrentOwner(s32 arg0, func_unk_D_8140E724 arg1, ParticleDescriptor* arg2, s16 arg3, s16 arg4, u8 arg5,
                              u8 arg6, u8 arg7, u8 arg8) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, arg1, arg2, gBattleAnimCurrentOwner, arg3, arg4, arg5, arg6, arg7, arg8);
}

BattleAnimEffectSlot* BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(s32 arg0, s32 arg1, s8 arg2, func_unk_D_8140E724 arg3, ParticleDescriptor* arg4, s16 arg5,
                              s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA) {
    return BattleAnim_CreateEffectSlot(arg0, arg1, arg2, arg3, arg4, gBattleAnimCurrentOwner, arg5, arg6, arg7, arg8, arg9, argA);
}

BattleAnimEffectSlot* BattleAnim_SpawnGlobalTintColorFadeDetach(s32 arg0, s16 arg1, u8 arg2) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackGlobalTintColorFadeDetach, &gDefaultParticleDescriptor, NULL, 0, arg1, 0x16, 0, arg2, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaFadeInHoldOut(s32 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25AlphaFadeInHoldOut, &gBattleAnimParticleDescriptors[37], NULL, arg1, arg2, 0x16, arg4, arg3, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(s32 arg0, s16 arg1, s16 arg2, u8 arg3) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25AlphaHoldFadeOut, &gBattleAnimParticleDescriptors[37], NULL, arg1, arg2, 0x16, 0xFF, arg3, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldFadeOut(s32 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25AlphaHoldFadeOut, &gBattleAnimParticleDescriptors[37], NULL, arg1, arg2, 0x16, arg4, arg3, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldFadeOutRepeating(s32 arg0, s32 arg1, s8 arg2, s16 arg3, s16 arg4, u8 arg5, u8 arg6) {
    return BattleAnim_CreateEffectSlot(arg0, arg1, arg2, BattleAnim_CallbackDescriptor25AlphaHoldFadeOut, &gBattleAnimParticleDescriptors[37], NULL, arg3, arg4, 0x16, arg6, arg5, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaFadeInHoldFullAlpha(s32 arg0, s16 arg1, s16 arg2, u8 arg3) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25AlphaFadeInHold, &gBattleAnimParticleDescriptors[37], NULL, arg1, arg2, 0x16, 0xFF, arg3, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaFadeInHold(s32 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25AlphaFadeInHold, &gBattleAnimParticleDescriptors[37], NULL, arg1, arg2, 0x16, arg4, arg3, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaFadeInHoldRepeating(s32 arg0, s32 arg1, s8 arg2, s16 arg3, s16 arg4, u8 arg5, u8 arg6) {
    return BattleAnim_CreateEffectSlot(arg0, arg1, arg2, BattleAnim_CallbackDescriptor25AlphaFadeInHold, &gBattleAnimParticleDescriptors[37], NULL, arg3, arg4, 0x16, arg6, arg5, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldDetachFullAlpha(s32 arg0, s16 arg1, u8 arg2) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25AlphaHoldDetach, &gBattleAnimParticleDescriptors[37], NULL, arg1, 0, 0x16, 0xFF, arg2, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldDetach(s32 arg0, s16 arg1, u8 arg2, u8 arg3) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25AlphaHoldDetach, &gBattleAnimParticleDescriptors[37], NULL, arg1, 0, 0x16, arg3, arg2, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldDetachRepeating(s32 arg0, s32 arg1, s8 arg2, s16 arg3, u8 arg4, u8 arg5) {
    return BattleAnim_CreateEffectSlot(arg0, arg1, arg2, BattleAnim_CallbackDescriptor25AlphaHoldDetach, &gBattleAnimParticleDescriptors[37], NULL, arg3, 0, 0x16, arg5, arg4, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25PaletteFadeOut(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25PaletteFadeOut, &gBattleAnimParticleDescriptors[37], NULL, arg1, arg2, 0x16, arg4, arg3, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25PaletteFadeIn(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25PaletteFadeIn, &gBattleAnimParticleDescriptors[37], NULL, arg1, arg2, 0x16, arg4, arg3, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintRampDetach(s32 arg0, u8 arg1, s16 arg2, s16 arg3, s16 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintRampDetach, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg2, arg4, 0x1A, arg3, arg1, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPulseDetach(s32 arg0, s16 arg1, u8 arg2, s16 arg3, s16 arg4, s16 arg5) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintPulseDetach, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg1, arg5, 0x1A, arg4, arg2, arg3);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintHoldFadeDetach(s32 arg0, s16 arg1, u8 arg2, s16 arg3, s16 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintHoldFadeDetach, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg1, arg4, 0x1A, 0, arg2, arg3);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteApproachInactive(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintPaletteApproachInactive, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg4, arg3, 0x1A, arg2, arg1, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteApproachInactiveAlt(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintPaletteApproachInactive, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg4, arg3, 0x1A, arg2, arg1, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteCycle(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintPaletteCycle, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg4, arg3, 0x1A, arg2, arg1, arg5);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteCycleVariant(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintPaletteCycle, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg4, arg3, 0x1A, arg2, arg1, arg5);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteFade(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintPaletteFade, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg4, arg3, 0x1A, arg2, arg1, arg5);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintRandomPaletteCycle(s32 arg0, s16 arg1, u8 arg2) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintRandomPaletteCycle, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, 0, arg1, 0x1A, arg2, 0, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteRotateFadeDetach(s32 arg0, s16 arg1, s16 arg2, u8 arg3) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintPaletteRotateFadeDetach, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg1, arg2, 0x1A, arg3, 0, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelAlphaFade(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelAlphaFade, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg1, arg3, 0x1A, arg2, 0, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelAlphaFadeFullPreset(s32 arg0) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelAlphaFade, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, 0xFF, 0xFF, 0x1A, 0xFF, 0, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelAlphaFadeZeroStartPreset(s32 arg0) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelAlphaFade, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, 0, 0xFF, 0x1A, 0, 0, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnCategory17MarkerSlot(s32 arg0, u8 arg1) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, NULL, NULL, 0, 0, 0, 0x17, arg1, 0, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnCategory19MarkerSlot(s32 arg0, u8 arg1) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, NULL, NULL, gBattleAnimCurrentOwner, 0, 0, 0x19, arg1, 0, 0);
}
