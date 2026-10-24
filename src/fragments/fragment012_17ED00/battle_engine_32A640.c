/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_32A640.c, src/fragments/battle_engine/battle_engine_343BA0.c. */

#include "fragments/battle_engine/battle_engine.h"

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

#include "m2c_macros.h"

void BattleAnim_UnusedResetAppearanceAndAdvance(Particle* arg0);
void BattleAnim_SetupOrphanDescriptor2BSpinFade(Particle* arg0);
void BattleAnim_SetupEndEffect26Descriptor2CGravityScatterFall(Particle* arg0);
void BattleAnim_DefaultStartEffect_Draw(void);
void BattleAnim_OrphanDescriptor2BAnd2EEmitterSequence(void);
void RegisterParticleEffect_ComplexMovement(void);
void RegisterParticleEffect_Burst(void);

void BattleAnim_CallbackOrphanDescriptor2BSpinFade(Particle* arg0);
void BattleAnim_CallbackOrphanDescriptor2EScatterFade(Particle* arg0);
void BattleAnim_CallbackEndEffect26Descriptor2CGravityScatterFall(Particle* arg0);
void BattleAnim_CallbackEndEffects85And87GravityFallDelay(Particle* arg0);

void BattleAnim_UnusedResetAppearanceAndAdvance(Particle* arg0) {
    Particle_SetPrimColor(arg0, 0xFF, 0xFF, 0xFF);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_821516B0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821516B0.s")
#endif

void BattleAnim_SetupOrphanDescriptor2BSpinFade(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
    Particle_Field7C_SetYScaled_0AF24(arg0, 1.0f);
    Particle_Field94_SetX_0A2A4(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field94_SetZ_0A2CC(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field9A_SetY_0A3D8(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field74_SetScaled_0AD8C(arg0, 5.0f);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82151834; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82151834.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821519AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821519AC.s")
#endif

M2C_UNK func_8213C938(s8 *);                      /* extern */
M2C_UNK func_8213CA80(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
s32 func_8213CB7C(s8 *);                          /* extern */
M2C_UNK func_8213E528(s8 *);                      /* extern */
M2C_UNK func_8213EDCC(s8 *, M2C_UNK);             /* extern */
s32 func_821406B4(s8 *);                          /* extern */
M2C_UNK func_821519AC(s8 *);                      /* extern */

void func_82151A5C(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_821519AC(arg0);
        break;
    case 2:
        if (func_821406B4(arg0) != 0) {
            func_8213CB3C(arg0);
        }
        break;
    case 3:
        func_8213CA80(arg0, 0x46);
        break;
    case 4:
        func_8213C938(arg0);
        break;
    }
    if (func_8213CB7C(arg0) != 0) {
        func_8213E528(arg0);
        func_8213EDCC(arg0, 0x2000);
    }
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_SetupEndEffect26Descriptor2CGravityScatterFall(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.12f);
    Particle_Field7C_SetYScaled_0AF24(arg0, (ParticleMath_RandomRange(0x14) * 0.02f) + 0.25f);
    Particle_Field94_SetX_0A2A4(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field94_SetZ_0A2CC(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field74_SetScaled_0AD8C(arg0, 5.0f);
    Particle_FieldAE_SetS16_0BF4C(arg0, ParticleMath_RandomRange(0x800) + 0xC00);
    Particle_Field9A_SetX_0A3C4(arg0, ParticleMath_RandomSignedOffsetBySign(0x800, 0x300));
    Particle_FieldB0_SetS16_0BFEC(arg0, ParticleMath_RandomSignedOffsetBySign(0x800, 0x300));
    Particle_Field9A_SetY_0A3D8(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field9A_SetZ_0A3EC(arg0, ParticleMath_RandomSignedOffsetBySign(0x800, 0x300));
    Particle_Field38_AddYScaled_08E90(arg0, ParticleMath_RandomRange(0x1E));
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82151B20.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82151CC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82151CC8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82151F80; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82151F80.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82152230; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82152230.s")
#endif

void BattleAnim_DefaultStartEffect_Draw(void) {
}

void BattleAnim_OrphanDescriptor2BAnd2EEmitterSequence(void) {
    BattleAnim_SpawnCategory17MarkerSlot(0x80, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackOrphanDescriptor2BSpinFade, &gBattleAnimParticleDescriptors[0x2B], 0, 0x10, 0xA, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackOrphanDescriptor2BSpinFade, &gBattleAnimParticleDescriptors[0x2B], 0, 0x10, 0xA, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackOrphanDescriptor2BSpinFade, &gBattleAnimParticleDescriptors[0x2B], 0, 0x10, 0xA, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackOrphanDescriptor2BSpinFade, &gBattleAnimParticleDescriptors[0x2B], 0, 8, 0xA, 0, 0, 0);
    BattleAnim_AddSpawnDelay(0x3A);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackOrphanDescriptor2EScatterFade, &gBattleAnimParticleDescriptors[0x2E], 0, 0x10, 2, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackOrphanDescriptor2EScatterFade, &gBattleAnimParticleDescriptors[0x2E], 0, 0x10, 2, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackOrphanDescriptor2EScatterFade, &gBattleAnimParticleDescriptors[0x2E], 0, 0x10, 2, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackOrphanDescriptor2EScatterFade, &gBattleAnimParticleDescriptors[0x2E], 0, 0x10, 2, 0, 0, 0);
}

void RegisterParticleEffect_ComplexMovement(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 0x14, BattleAnim_CallbackEndEffect26Descriptor2CGravityScatterFall, &gBattleAnimParticleDescriptors[0x2C], 0, 4, 0xE, 0, 0, 0);
    BattleAnim_EndEffect26DelayedDescriptor29ScatterSequence();
}

void RegisterParticleEffect_Burst(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 5, BattleAnim_CallbackEndEffects85And87GravityFallDelay, &gBattleAnimParticleDescriptors[0x2D], 0, 1, 0xE, 0, 0, 1);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 5, BattleAnim_CallbackEndEffects85And87GravityFallDelay, &gBattleAnimParticleDescriptors[0x2D], 0, 1, 0xE, 0, 0, 1);
}
