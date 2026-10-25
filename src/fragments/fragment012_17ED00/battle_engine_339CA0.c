/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_339CA0.c, src/fragments/battle_engine/battle_engine_343BA0.c. */

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

#include "m2c_macros.h"

void BattleAnim_CallbackSharedDescriptor29ScaleAnimFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect3Descriptor29DirectionalScaleFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor3DMetadataBurstChild_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect55Descriptor49RiseGravityFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect67Descriptor3DAnimatedGravityFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackOrphanDescriptor34ColorFadeDetach_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor36ScaleAlphaFade_InitParticle(Particle* arg0);
void BattleAnim_SetupUnusedGlitterVariant(Particle* arg0);
void BattleAnim_CallbackEndEffects37And38Descriptor38BurstChild_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion_InitParticle(Particle* arg0);
void BattleAnim_SetupEndEffect52DefaultBurstChild(Particle* arg0);
void BattleAnim_CallbackEndEffect23Descriptor44ScalePulse_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect43Descriptor40DelayedAnimFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffects37And38Descriptor34BurstEmitter_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect56Descriptor40AnimScaleFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect56Descriptor46AnimColorImpulseFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect73Descriptor15AnimatedColorImpulseFade_InitParticle(Particle* arg0);
void BattleAnim_RecolorParticleByQueuedMoveId(Particle* arg0);
void BattleAnim_CallbackStartEffects28And53And65And76Descriptor47AnimatedScaleMotion_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect81Descriptor3DRisingAnimFade_InitParticle(Particle* arg0);
void BattleAnim_ApplySpeciesKeyedSpawnOffset(Particle* arg0);
void BattleAnim_CallbackStartEffect101Descriptor3DMetadataBurstChild_InitParticle(Particle* arg0);
void BattleAnim_CallbackDescriptor50BurstChild_InitParticle(Particle* arg0);
void BattleAnim_EndEffect16_NoOpInit(void);
void BattleAnim_CallbackSharedDescriptor3CExpandingFadeIn_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffects29And60And104And110Descriptor44BurstChild_InitParticle(Particle* arg0);
void ParticleEffect_InitializeGroup(void);
void ParticleEffect_ConfigTexture7Palette1(void);
void ParticleEffect_ConfigTexture9Palette2(void);
void ParticleEffect_ConfigVariantMotion6(void);
void ParticleEffect_ConfigVariantMotion16(void);
void ParticleEffect_SpecialSetupBurstPalette3(void);
void ParticleEffect_SpecialSetupBurstPalette4(void);
void ParticleEffect_SpecialSetupDelayedScatterPalette1(void);
void BattleAnim_OrphanDescriptor34Emitter(void);
void ParticleEffect_AdditionalSetupDualRiseFade(void);
void ParticleEffect_AdditionalSetupBurstAndRiseFade(void);
void ParticleEffect_CombinedSetupBurst3DRandom(void);
void ParticleEffect_CombinedSetupBurstHorizontalRandom(void);
void BattleAnim_EndEffects41And83Descriptor34BurstSequence(void);
void ParticleEffect_MultiHandleSetup(void);
void BattleAnim_StartEffect137Descriptor3FRisingFade(void);
void ParticleEffect_SpecialCollisionSetup(void);
void BattleAnim_EndEffect26DelayedDescriptor29ScatterSequence(void);
void ParticleEffect_FinalSetupPortraitBurst(void);
void ParticleEffect_AdditionalNodeSingleRiseFade(void);
void BattleAnim_StartEffects87And88Descriptor3DVerticalFadeSequence(void);
void BattleAnim_SpawnDefaultDescriptorBurstEmitterSequence(s32 arg0);
void ParticleEffect_ComplexGroupSetup(void);

void BattleAnim_CallbackEndEffect3Descriptor29DirectionalScaleFade(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade(Particle* arg0);
void BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade(Particle* arg0);
void BattleAnim_CallbackOrphanDescriptor34ColorFadeDetach(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor36ScaleAlphaFade(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion(Particle* arg0);
void BattleAnim_CallbackEndEffect52Descriptor42BurstChild(Particle* arg0);
void BattleAnim_CallbackEndEffect52DefaultBurstEmitter(Particle* arg0);
void BattleAnim_CallbackSharedDescriptors42And44ScaleFall(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion(Particle* arg0);
void BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter(Particle* arg0);
s32 BattleAnim_CallbackEndEffects37And38Descriptor34BurstEmitter(Particle* arg0);
void BattleAnim_CallbackSharedAnimatedVerticalFade(Particle* arg0);
void BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter(Particle* arg0);

void BattleAnim_CallbackSharedDescriptor29ScaleAnimFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    switch (Particle_FieldCE_GetS32_0C040(arg0)) {
        case 0:
            Particle_Field94_AddX_0A578(arg0, 0x4000);
            break;

        case 1:
            Particle_Field94_AddX_0A578(arg0, -0x3000);
            Particle_Field94_AddY_0A594(arg0, 0x4000);
            Particle_Field94_AddZ_0A5B0(arg0, 0x2000);
            break;

        case 2:
            Particle_Field94_AddX_0A578(arg0, 0x2000);
            Particle_Field94_AddY_0A594(arg0, 0x2000);
            Particle_Field94_AddZ_0A5B0(arg0, 0x2000);
            break;

        case 3:
            Particle_Field94_AddX_0A578(arg0, -0x8000);
            Particle_Field94_AddY_0A594(arg0, 0x2000);
            Particle_Field94_AddZ_0A5B0(arg0, 0x6000);
            break;

        case 4:
            Particle_Field94_AddX_0A578(arg0, -0x4000);
            Particle_Field94_AddY_0A594(arg0, 0x4000);
            Particle_Field94_AddZ_0A5B0(arg0, 0x4000);
            break;
    }

    Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
    Particle_AddPositionFromRotationTemplate1(arg0, (sp26 - 1) * 10.0f);
    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140548(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8215F930(s8 *);                      /* extern */

void func_8215FAA4(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_8215F930(arg0);
        break;
    case 2:
        func_8213CCEC(arg0, 0, 7, 1, 1, 0);
        break;
    case 3:
        func_82140548(arg0, 0, 0x40);
        break;
    case 4:
        func_8213C930(arg0);
        break;
    }
    func_82140228(arg0, 0x40600000, 0x3E800000);
}

void BattleAnim_CallbackEndEffect3Descriptor29DirectionalScaleFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_FieldCF_GetS16_0C058(arg0);

    switch (sp26) {
        case 0:
            Particle_Field94_AddX_0A578(arg0, 0x5800);
            Particle_Field94_AddY_0A594(arg0, 0x5800);
            Particle_Field94_AddZ_0A5B0(arg0, -0x6000);
            break;

        case 1:
            Particle_Field94_AddX_0A578(arg0, 0x6000);
            Particle_Field94_AddY_0A594(arg0, 0);
            Particle_Field94_AddZ_0A5B0(arg0, 0x5800);
            break;

        case 2:
            Particle_Field94_AddX_0A578(arg0, 0x2000);
            Particle_Field94_AddY_0A594(arg0, 0x2000);
            Particle_Field94_AddZ_0A5B0(arg0, 0x2000);
            break;

        case 3:
            Particle_Field94_AddX_0A578(arg0, 0x6000);
            break;

        case 4:
            Particle_Field94_AddX_0A578(arg0, 0);
            Particle_Field94_AddY_0A594(arg0, 0);
            Particle_Field94_AddZ_0A5B0(arg0, 0);
            break;

        case 5:
            Particle_Field94_AddX_0A578(arg0, 0x6000);
            Particle_Field94_AddY_0A594(arg0, 0x2800);
            Particle_Field94_AddZ_0A5B0(arg0, 0x5800);
            break;
    }

    Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0xC);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 3);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect3Descriptor29DirectionalScaleFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect3Descriptor29DirectionalScaleFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            func_8213CCEC(arg0, 0, 7, 1, 1, 0);
            Particle_Field1C_Approach_0B98C(arg0, 3.5f, 0.25f);
            break;

        case 4:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x40);
            Particle_Field1C_Approach_0B98C(arg0, 3.5f, 0.25f);
            break;

        case 5:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    switch (sp26) {
        case 0:
            Particle_Field94_AddX_0A578(arg0, 0x5800);
            Particle_Field94_AddY_0A594(arg0, 0x5800);
            Particle_Field94_AddZ_0A5B0(arg0, -0x6000);
            break;

        case 1:
            Particle_Field94_AddX_0A578(arg0, 0x6000);
            Particle_Field94_AddY_0A594(arg0, 0);
            Particle_Field94_AddZ_0A5B0(arg0, 0x5800);
            break;

        case 2:
            Particle_Field94_AddX_0A578(arg0, 0x2000);
            Particle_Field94_AddY_0A594(arg0, 0x2000);
            Particle_Field94_AddZ_0A5B0(arg0, 0x2000);
            break;

        case 3:
            Particle_Field94_AddX_0A578(arg0, 0x6000);
            break;

        case 4:
            Particle_Field94_AddX_0A578(arg0, 0);
            Particle_Field94_AddY_0A594(arg0, 0);
            Particle_Field94_AddZ_0A5B0(arg0, 0);
            break;

        case 5:
            Particle_Field94_AddX_0A578(arg0, 0x6000);
            Particle_Field94_AddY_0A594(arg0, 0x2800);
            Particle_Field94_AddZ_0A5B0(arg0, 0x5800);
            break;
    }

    switch (sp24) {
        case 0:
            Particle_SetRandomVelocityXSymmetric(arg0, 0xA, 3);
            Particle_SetRandomVelocityYOffset(arg0, 0xF, 0xA);
            Particle_SetRandomVelocityZSymmetric(arg0, 0xF, 3);
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0xD);
            break;

        case 1:
            Particle_SetRandomVelocityXSymmetric(arg0, 0xA, 5);
            Particle_SetRandomVelocityYOffset(arg0, 0x14, 5);
            Particle_SetRandomVelocityZSymmetric(arg0, 0xA, 5);
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0xE);
            break;
    }

    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            func_8213CCEC(arg0, 0, 7, 2, 1, 0);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8216008C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216008C.s")
#endif

s16 func_8213C464();                                /* extern */
M2C_UNK func_8213C938(s8 *);                      /* extern */
M2C_UNK func_8213CA80(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821403B0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821403E0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821404AC(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821404DC(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8216008C(s8 *);                      /* extern */

void func_821600E0(s8 *arg0) {
    s16 sp26;
    s16 temp_v1;

    sp26 = func_8213C464();
    temp_v1 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v1) {                              /* irregular */
    case 1:
        func_8216008C(arg0);
        break;
    case 2:
        func_8213CA80(arg0, 0x14);
        break;
    case 3:
        func_8213C938(arg0);
        break;
    }
    func_82140228(arg0, 0x40C66666, 0x3F800000);
    if (sp26 == 0) {
        func_821403B0(arg0, 0, 0x18);
        func_821403E0(arg0, 0, 0x18);
        func_821404DC(arg0, 0, 0x18);
        func_821404AC(arg0, 0, 0x18);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_821601C0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821601C0.s")
#endif

s16 func_8213C464();                                /* extern */
M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213CA80(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821403B0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821403E0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821404AC(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821404DC(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821601C0(s8 *);                      /* extern */

void func_82160230(s8 *arg0) {
    s16 sp26;
    s16 temp_v1;

    sp26 = func_8213C464();
    temp_v1 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v1) {                              /* irregular */
    case 1:
        func_821601C0(arg0);
        break;
    case 2:
        func_8213CA80(arg0, 0x14);
        break;
    case 3:
        func_8213C930(arg0);
        break;
    }
    func_82140228(arg0, 0x40C00000, 0x3F800000);
    if (sp26 == 0) {
        func_821403B0(arg0, 0, 0x18);
        func_821403E0(arg0, 0, 0x18);
        func_821404DC(arg0, 0, 0x18);
        func_821404AC(arg0, 0, 0x18);
    }
    func_82140518(arg0, 0, 0x10);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8216031C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216031C.s")
#endif

M2C_UNK func_8213C938(s8 *);                      /* extern */
M2C_UNK func_8213CA80(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_8213CC10(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140548(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8216031C(s8 *);                      /* extern */

void func_821603C8(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_8216031C(arg0);
        break;
    case 2:
        func_8213CA80(arg0, 8);
        break;
    case 3:
        func_82140548(arg0, 0, 0x20);
        break;
    case 4:
        func_8213C938(arg0);
        break;
    }
    func_8213CC10(arg0, 0, 7, 1, 2, 0);
    func_82140228(arg0, 0x40A00000, 0x3ECCCCCD);
}

void BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor3DMetadataBurstChild_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_SetPrimAlpha(arg0, 0x64);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E6BC(s8 *);                      /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82160494(s8 *);                      /* extern */

void func_82160528(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82160494(arg0);
        return;
    case 2:
        if (func_8213CA80(arg0, M2C_FIELD(arg0, s16 *, 0xA2)) != 0) {
            func_8213CB3C(arg0);
            return;
        }
        return;
    case 3:
        func_8213CCEC(arg0, 0, 7, 1, 2, 0);
        func_82140518(arg0, 0x64, 6);
        func_8213E6BC(arg0);
        return;
    case 4:
        func_8213C930(arg0);
        break;
    }
}

f32 func_8000F150();                                /* extern */
s16 func_8213C47C();                                /* extern */
u16 func_8213C484(s8 *);                          /* extern */
s32 func_8213C494(s8 *);                          /* extern */
M2C_UNK func_8213C9D0(s8 *);                      /* extern */
M2C_UNK func_8213EDB0(s8 *, s16);                 /* extern */
M2C_UNK func_8213F628(s8 *, f32);                 /* extern */
M2C_UNK func_821401D4(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_8214050C(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_82143478(s8 *, u16);                 /* extern */

void func_821605F8(s8 *arg0) {
    s16 sp26;
    u16 sp24;

    sp26 = func_8213C47C();
    sp24 = func_8213C484(arg0);
    func_821401D4(arg0, 0x3E800000);
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) ((func_8000F150() * 0.5f) + 0.25f);
    func_8213EDB0(arg0, (s16) (0x1800 - ((0x3000 / func_8213C494(arg0)) * sp26)));
    func_8213F628(arg0, (2.0f * func_8000F150()) + 3.0f);
    func_82143478(arg0, sp24);
    func_8214050C(arg0, 0xB4);
    func_8213C9D0(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E1FC(s8 *, s32);                 /* extern */
M2C_UNK func_8213E4D8(s8 *);                      /* extern */
M2C_UNK func_8213F658(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140548(s8 *, M2C_UNK, M2C_UNK);    /* extern */

void func_82160704(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_821605F8(arg0);
        return;
    case 2:
        func_8213CCEC(arg0, 0, 7, 1, 2, 0);
        func_82140228(arg0, 0x3F400000, 0x3CCCCCCD);
        func_8213F658(arg0, 0x3F000000, 0x3E800000);
        func_8213E1FC(arg0, M2C_FIELD(arg0, s32 *, 0x5C));
        func_8213E4D8(arg0);
        return;
    case 3:
        func_82140548(arg0, 0, 0x20);
        return;
    case 4:
        func_8213C930(arg0);
        return;
    }
}

f32 func_8000F150();                                /* extern */
s16 func_8213C47C();                                /* extern */
u16 func_8213C484(s8 *);                          /* extern */
s32 func_8213C494(s8 *);                          /* extern */
M2C_UNK func_8213C9D0(s8 *);                      /* extern */
M2C_UNK func_8213EDB0(s8 *, s16);                 /* extern */
M2C_UNK func_8213F628(s8 *, f32);                 /* extern */
M2C_UNK func_821401D4(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_8214050C(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_82143478(s8 *, u16);                 /* extern */

void func_821607E8(s8 *arg0) {
    s16 sp26;
    u16 sp24;

    sp26 = func_8213C47C();
    sp24 = func_8213C484(arg0);
    func_821401D4(arg0, 0x3F000000);
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) ((func_8000F150() * 0.5f) + 0.25f);
    func_8213EDB0(arg0, (s16) (0x1800 - ((0x3000 / func_8213C494(arg0)) * sp26)));
    func_8213F628(arg0, (func_8000F150() * 2.5f) + 3.0f);
    func_82143478(arg0, sp24);
    func_8214050C(arg0, 0xB4);
    func_8213C9D0(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213C9D0(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E1FC(s8 *, s32);                 /* extern */
M2C_UNK func_8213E4D8(s8 *);                      /* extern */
M2C_UNK func_8213F658(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_82140518(s8 *, M2C_UNK, M2C_UNK);        /* extern */

void func_821608FC(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_821607E8(arg0);
        break;
    case 2:
        func_8213CCEC(arg0, 0, 7, 1, 3, 0);
        func_82140228(arg0, 0x3F800000, 0x3D4CCCCD);
        func_8213F658(arg0, 0x3F000000, 0x3E800000);
        func_8213E1FC(arg0, M2C_FIELD(arg0, s32 *, 0x5C));
        break;
    case 3:
        if (func_82140518(arg0, 0, 0x20) != 0) {
            func_8213C9D0(arg0);
        }
        break;
    case 4:
        func_8213C930(arg0);
        break;
    }
    func_8213E4D8(arg0);
}

void BattleAnim_CallbackStartEffect31Descriptor49TieredRiseImpulseFade_InitParticle(Particle* arg0) {
    UNUSED s16 pad;
    s16 sp24 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.25f);
    arg0->unk_5C.y = (MathUtil_Random_ZeroOne() * 0.5f) + 0.4f;
    Particle_Field94_AddY_0A594(arg0, 0x800 - ((0x1000 / func_8213C494(arg0)) * sp24));
    Particle_Field74_SetScaled_0AD8C(arg0, (2.0f * MathUtil_Random_ZeroOne()) + 5.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x32);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E1FC(s8 *, s32);                 /* extern */
M2C_UNK func_8213E4D8(s8 *);                      /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821609F0(s8 *);                      /* extern */

void func_82160AF0(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_821609F0(arg0);
        return;
    case 2:
        func_8213CCEC(arg0, 0, 7, 1, 2, 0);
        func_82140518(arg0, 0x64, 9);
        func_82140228(arg0, 0x3ECCCCCD, 0x3CCCCCCD);
        func_8213E1FC(arg0, M2C_FIELD(arg0, s32 *, 0x5C));
        func_8213E4D8(arg0);
        return;
    case 3:
        func_8213C930(arg0);
        return;
    }
}

f32 func_8000F150();                                /* extern */
s16 func_8213C47C();                                /* extern */
s32 func_8213C494(s8 *);                          /* extern */
M2C_UNK func_8213C9D0(s8 *);                      /* extern */
M2C_UNK func_8213DDB8(s8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8213EDB0(s8 *, s16);                 /* extern */
M2C_UNK func_8213F628(s8 *, f32);                 /* extern */
M2C_UNK func_821401D4(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_8214050C(s8 *, M2C_UNK);             /* extern */

void func_82160BB8(s8 *arg0) {
    s16 sp26;

    sp26 = func_8213C47C();
    func_821401D4(arg0, 0x3ECCCCCD);
    func_8213DDB8(arg0, 0, 0, 0xA);
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) ((func_8000F150() * 0.5f) + 0.25f);
    func_8213EDB0(arg0, (s16) (0x2000 - ((0x4000 / func_8213C494(arg0)) * sp26)));
    func_8213F628(arg0, func_8000F150() + 1.0f);
    func_82143478(arg0, 0xA);
    func_8214050C(arg0, 0x64);
    func_8213C9D0(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213C9D0(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E1FC(s8 *, s32);                 /* extern */
M2C_UNK func_8213E4D8(s8 *);                      /* extern */
M2C_UNK func_8213F658(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_82140518(s8 *, M2C_UNK, M2C_UNK);        /* extern */

void func_82160CCC(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82160BB8(arg0);
        return;
    case 2:
        func_8213CCEC(arg0, 0, 7, 1, 2, 0);
        func_82140228(arg0, 0x3F400000, 0x3CCCCCCD);
        func_8213F658(arg0, 0x3F000000, 0x3E4CCCCD);
        func_8213E1FC(arg0, M2C_FIELD(arg0, s32 *, 0x5C));
        func_8213E4D8(arg0);
        return;
    case 3:
        if (func_82140518(arg0, 0, 0x20) != 0) {
            func_8213C9D0(arg0);
            return;
        }
        return;
    case 4:
        func_8213C930(arg0);
        break;
    }
}

void BattleAnim_CallbackEndEffect55Descriptor49RiseGravityFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.3f);
    Particle_SetRandomVelocityXYZ(arg0, 0xA, 5, 0xA);
    Particle_Field38_AddYScaled_08E90(arg0, 15.0f);
    Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0xA) * 0.1f) + 1.5f);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x32);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213C9D0(s8 *);                      /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
M2C_UNK func_8213CC10(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
s32 func_8213E7A0(s8 *);                          /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82160DC4(s8 *);                      /* extern */

void func_82160EAC(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82160DC4(arg0);
        return;
    case 2:
        if (func_8213CA80(arg0, M2C_FIELD(arg0, s16 *, 0xA2)) != 0) {
            func_8213CB3C(arg0);
            return;
        }
        return;
    case 3:
        func_82140228(arg0, 0x3F000000, 0x3CA3D70A);
        func_8213CC10(arg0, 0, 7, 1, 2, 0);
        func_82140518(arg0, 0x64, 6);
        if (func_8213E7A0(arg0) != 0) {
            func_8213C9D0(arg0);
            return;
        }
        break;
    case 4:
        func_8213C930(arg0);
        break;
    }
}

void BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.25f);
    Particle_Field94_AddY_0A594(arg0, sp26 << 0xC);
    Particle_Field74_SetScaled_0AD8C(arg0, (2.0f * MathUtil_Random_ZeroOne()) + 6.0f);
    Particle_Field7C_SetYScaled_0AF24(arg0, (MathUtil_Random_ZeroOne() * 3.0f) + 1.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0xA);
    Particle_SetPrimAlpha(arg0, 0x64);
    Particle_FieldA6_SetS16_0BCA8(arg0, 7);
    Particle_AdvanceLifecycle(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82161074; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82161074.s")
#endif

void BattleAnim_CallbackEndEffect67Descriptor3DAnimatedGravityFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    switch (Particle_FieldCF_GetS16_0C058(arg0)) {
        case 0:
            Particle_Field1C_SetScaled_0B938(arg0, 0.75f);
            Particle_SetRandomVelocityXYZ(arg0, 0xF, 0xF, 0xF);
            Particle_Field38_AddYScaled_08E90(arg0, 15.0f);
            Particle_Field74_SetScaled_0AD8C(arg0, 1.0f);
            break;

        case 1:
            Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
            Particle_SetRandomVelocityXYZ(arg0, 3, 3, 3);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            break;
    }

    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 4);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x13);
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E7A0(s8 *);                      /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82161190(s8 *);                      /* extern */

void func_82161288(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82161190(arg0);
        return;
    case 2:
        if (func_8213CA80(arg0, M2C_FIELD(arg0, s16 *, 0xA2)) != 0) {
            func_8213CB3C(arg0);
            return;
        }
        return;
    case 3:
        func_8213CCEC(arg0, 0, 7, 1, 2, 0);
        func_82140518(arg0, 0x64, 6);
        func_8213E7A0(arg0);
        return;
    case 4:
        func_8213C930(arg0);
        break;
    }
}

void BattleAnim_CallbackOrphanDescriptor34ColorFadeDetach_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_SetRandomRotatedVelocityXY(arg0, 0xF, 0xF);
    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
    Particle_SetPrimColor(arg0, 0xFF, 0xFF, 0xFF);
    Particle_SetEnvColor(arg0, 0xFF, 0x64, 0);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C938(s8 *);                      /* extern */
s32 func_8213CA04(s8 *, M2C_UNK);                 /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E6BC(s8 *);                      /* extern */
M2C_UNK func_82140380(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8214047C(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821404AC(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821404DC(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82161358(s8 *);                      /* extern */

void func_8216140C(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82161358(arg0);
        return;
    case 2:
        if (func_8213CA80(arg0, M2C_FIELD(arg0, s16 *, 0xA2)) != 0) {
            func_8213CB3C(arg0);
            return;
        }
        return;
    case 3:
        func_8213CCEC(arg0, 0, 7, 1, 2, 0);
        func_82140380(arg0, 0x64, 9);
        func_8214047C(arg0, 0, 0x10);
        func_821404DC(arg0, 0x32, 3);
        func_821404AC(arg0, 0xFF, 0x10);
        if (func_8213CA04(arg0, 8) != 0) {
            func_82140518(arg0, 0, 0x20);
        }
        func_8213E6BC(arg0);
        return;
    case 4:
        func_8213C938(arg0);
        break;
    }
}

void BattleAnim_CallbackSharedDescriptor36ScaleAlphaFade_InitParticle(Particle* arg0) {
    Particle_Field1C_SetScaled_0B938(arg0, 0.1f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x14);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedDescriptor36ScaleAlphaFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedDescriptor36ScaleAlphaFade_InitParticle(arg0);
            break;

        case 2:
            Particle_Field1C_Approach_0B98C(arg0, 0.75f, 0.08125f);
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x20);
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_SetupUnusedGlitterVariant(Particle* arg0) {
    Vec3s sp28;

    Particle_FieldAC_GetS16_0C038(arg0);
    Particle_Field1C_SetScaled_0B938(arg0, 0.1f);
    sp28.x = MathUtil_Random16();
    sp28.y = MathUtil_Random16();
    sp28.z = 0;
    Particle_Field94_SetVecFromVec3s_0A24C(arg0, sp28);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x15);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, ParticleMath_RandomRange(5) + 8);
    Particle_Field74_SetScaled_0AD8C(arg0, 5.0f);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
s32 func_8213C9B0(s8 *);                          /* extern */
M2C_UNK func_8213C9D0(s8 *);                      /* extern */
M2C_UNK func_8213E528(s8 *);                      /* extern */
M2C_UNK func_8213F658(s8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_82140518(s8 *, M2C_UNK, M2C_UNK);        /* extern */
s32 func_82140690(s8 *);                          /* extern */
M2C_UNK func_821615F8(s8 *);                      /* extern */

void func_821616BC(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_821615F8(arg0);
        break;
    case 2:
        func_8213F658(arg0, 0x40000000, 0x3F000000);
        if ((func_82140690(arg0) != 0) && (func_82140518(arg0, 0, 0x40) != 0)) {
            func_8213C9D0(arg0);
        }
        break;
    case 3:
        func_8213C930(arg0);
        break;
    }
    if (func_8213C9B0(arg0) != 0) {
        func_8213E528(arg0);
    }
}

void BattleAnim_CallbackEndEffects37And38Descriptor38BurstChild_InitParticle(Particle* arg0) {
    Vec3s sp28;
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_FieldAC_GetS16_0C038(arg0);

    sp28.x = ParticleMath_RandomSigned(0x2000);
    sp28.y = ParticleMath_RandomSignedOffset(0x2000, 0x8000);
    sp28.z = 0;
    Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);

    switch (sp26) {
        case 0:
            Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x15);
            break;

        case 1:
            Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x1B);
            break;
    }

    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, ParticleMath_RandomRange(5) + 8);
    Particle_Field74_SetScaled_0AD8C(arg0, 6.0f);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
s32 func_8213C9B0(s8 *);                          /* extern */
M2C_UNK func_8213C9D0(s8 *);                      /* extern */
M2C_UNK func_8213E528(s8 *);                      /* extern */
M2C_UNK func_8213F658(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_82140518(s8 *, M2C_UNK, M2C_UNK);        /* extern */
s32 func_82140690(s8 *);                          /* extern */
M2C_UNK func_8216177C(s8 *);                      /* extern */

void func_82161890(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_8216177C(arg0);
        break;
    case 2:
        func_82140228(arg0, 0x3DCCCCCD, 0x3C23D70A);
        func_8213F658(arg0, 0x40400000, 0x3F400000);
        if ((func_82140690(arg0) != 0) && (func_82140518(arg0, 0, 0x40) != 0)) {
            func_8213C9D0(arg0);
        }
        break;
    case 3:
        func_8213C930(arg0);
        break;
    }
    if (func_8213C9B0(arg0) != 0) {
        func_8213E528(arg0);
    }
}

void BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion_InitParticle(Particle* arg0) {
    Vec3s sp28;
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_FieldAC_GetS16_0C038(arg0);
    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);

    switch (sp26) {
        case 0:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 8);
            Particle_SetPrimAlpha(arg0, 0x64);
            Particle_Field74_SetScaled_0AD8C(arg0, 5.0f);
            sp28.x = ParticleMath_RandomSigned(0x2000);
            sp28.y = ParticleMath_RandomSignedOffset(0x2000, 0x8000);
            sp28.z = 0;
            Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);
            break;

        case 1:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 8);
            Particle_SetPrimAlpha(arg0, 0x64);
            Particle_Field74_SetScaled_0AD8C(arg0, 5.0f);
            sp28.x = ParticleMath_RandomSigned(0x2000);
            sp28.y = ParticleMath_RandomSignedOffset(0x2000, 0x8000);
            sp28.z = 0;
            Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);
            break;

        case 2:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 8);
            Particle_SetPrimAlpha(arg0, 0x64);
            Particle_Field38_SetYScaled_08CA0(arg0, -10.0f);
            Particle_Field74_SetScaled_0AD8C(arg0, 5.0f);
            sp28.x = ParticleMath_RandomSigned(0x2000);
            sp28.y = ParticleMath_RandomSignedOffset(0x2000, 0x8000);
            sp28.z = 0;
            Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);
            break;

        case 3:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 9);
            Particle_SetPrimAlpha(arg0, 0x96);
            Particle_Field74_SetScaled_0AD8C(arg0, 3.0f);
            sp28.x = ParticleMath_RandomSigned(0x2000);
            sp28.y = ParticleMath_RandomSignedOffset(0x2000, 0x8000);
            sp28.z = 0;
            Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);
            break;

        case 4:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 5);
            Particle_SetPrimAlpha(arg0, 0x96);
            Particle_Field74_SetScaled_0AD8C(arg0, 4.0f);
            sp28.x = ParticleMath_RandomSigned(0x3000);
            sp28.y = ParticleMath_RandomSignedOffset(0x3000, 0x8000);
            sp28.z = 0;
            Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);
            break;
    }

    Particle_FieldA6_SetS16_0BCA8(arg0, ParticleMath_RandomRange(5) + 8);
    Particle_AdvanceLifecycle(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82161C4C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82161C4C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82161DA4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82161DA4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82161E78; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82161E78.s")
#endif

void BattleAnim_SetupEndEffect52DefaultBurstChild(Particle* arg0) {
    BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackEndEffect52Descriptor42BurstChild, &gBattleAnimParticleDescriptors[0x42], 0xC);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect52DefaultBurstEmitter(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupEndEffect52DefaultBurstChild(arg0);
            break;

        case 2:
            Particle_MarkInactive(arg0);
            break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8216201C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216201C.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_CallbackSharedDescriptors42And44ScaleFall(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupSharedScalePulseFallSetup(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            if (Particle_Field1C_ApproachField24AndStepState_0BA48(arg0) != 0) {
                Particle_SetScaleSpeed(arg0, 0.0f);
            }
            break;

        case 4:
            Particle_Field1C_ApproachField24AndStepState_0BA48(arg0);
            break;

        case 5:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_Field74_AdvanceAndAddNegY_CheckField2CYNonPositive_09FD8(arg0);
        if (arg0->unk_2C.y < 0.0f) {
            Particle_MarkInactive(arg0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821624FC.s")
#endif

void BattleAnim_CallbackEndEffect23Descriptor44ScalePulse_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.0f);
    Particle_SetScaleSpeed(arg0, 0.3f);
    Particle_SetScaleTarget(arg0, 0.05f);
    Particle_SetRandomVelocityXYZ(arg0, 0xA, 0x14, 0x14);
    Particle_Field38_AddXZFromField94Y_08ED0(arg0, 15.0f);
    Particle_Field38_AddYScaled_08E90(arg0, 7.0f);
    Particle_Field74_SetScaled_0AD8C(arg0, ParticleMath_RandomRange(5) + 8.0f);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_CallbackEndEffect23Descriptor44ScalePulse(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect23Descriptor44ScalePulse_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            if (Particle_Field1C_ApproachField24AndStepState_0BA48(arg0) != 0) {
                Particle_SetScaleSpeed(arg0, 0.0f);
            }
            break;

        case 4:
            Particle_Field1C_ApproachField24AndStepState_0BA48(arg0);
            break;

        case 5:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_AddVelocityXZFromRotationYPlusHalfTurn(arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821626F4.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void func_821627C0(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupSharedScalePulseFallSetup(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            if (Particle_Field1C_ApproachField24AndStepState_0BA48(arg0) != 0) {
                Particle_SetScaleSpeed(arg0, 0.0f);
            }
            break;

        case 4:
            Particle_Field1C_ApproachField24AndStepState_0BA48(arg0);
            break;

        case 5:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        func_8213E528(arg0);
        if (arg0->unk_2C.y < 0.0f) {
            Particle_MarkInactive(arg0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821627C0.s")
#endif

void BattleAnim_CallbackEndEffect43Descriptor40DelayedAnimFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.7f);
    Particle_Field38_SetYScaled_08CA0(arg0, 10.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x19);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect43Descriptor40DelayedAnimFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect43Descriptor40DelayedAnimFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A6) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            func_8213CCEC(arg0, 0, 5, 1, 1, 2);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCE_GetS32_0C040(arg0);

    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, Particle_FieldCF_GetS16_0C058(arg0));

    switch (sp24) {
        case 1:
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            break;

        case 5:
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            break;

        case 6:
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
            break;

        case 16:
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_Field1C_SetScaled_0B938(arg0, 2.0f);
            break;

        case 7:
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
            break;

        case 8:
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
            Particle_Field38_AddYScaled_08E90(arg0, -10.0f);
            break;

        case 12:
            Particle_Field1C_SetScaled_0B938(arg0, 0.75f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_SetRandomVelocityXYZ(arg0, 8, 0xA, 8);
            break;

        case 13:
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.0f);
            Particle_SetRandomVelocityX(arg0, 0x1E);
            Particle_SetRandomVelocityYOffset(arg0, 0x14, 0xA);
            Particle_SetRandomVelocityZ(arg0, 0x1E);
            break;

        case 14:
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.0f);
            Particle_SetRandomVelocityX(arg0, 0x14);
            Particle_SetRandomVelocityYOffset(arg0, 0x14, 0xA);
            Particle_SetRandomVelocityZ(arg0, 0xF);
            break;

        case 15:
            Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.3f);
            Particle_SetRandomVelocityXYZ(arg0, 0xA, 0xA, 0xA);
            break;
    }

    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821629E4.s")
#endif

void BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion_InitParticle(arg0);
            break;

        case 2:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A6) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            func_8213CCEC(arg0, 0, 3, 1, 1, 0);
            Particle_AddVelocityXZFromRotationYPlusHalfTurn(arg0);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    switch (Particle_FieldCF_GetS16_0C058(arg0)) {
        case 0:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            Particle_Field38_AddYScaled_08E90(arg0, 15.0f);
            break;

        case 1:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;

        case 2:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            Particle_Field38_AddYScaled_08E90(arg0, -10.0f);
            break;

        case 3:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 1);
            Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;

        case 4:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 2);
            Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;

        case 5:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 3);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;

        case 6:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;

        case 9:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_SetRandomVelocityXYZ(arg0, 0xF, 0xF, 0xF);
            Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;

        case 10:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_SetRandomVelocityXYZ(arg0, 0x14, 0, 0x14);
            Particle_Field38_SetYScaled_08CA0(arg0, 0.0f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;

        case 11:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_SetRandomVelocityXYZ(arg0, 0xA, 0, 0xA);
            Particle_Field38_SetYScaled_08CA0(arg0, 30.0f - (sp26 * 5.0f));
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;
    }

    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82162D1C.s")
#endif

void BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter_InitParticle(arg0);
            break;

        case 2:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A6) != 0) {
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 2);
            }
            break;

        case 3:
            func_8213CCEC(arg0, 0, 3, 1, 1, 0);
            Particle_AddVelocityXZFromRotationYPlusHalfTurn(arg0);
            if ((Particle_FieldA6_DecrementToZeroStep1_0BDAC != 0) && (arg0->unk_B8 == 0)) {
                Particle_AdvancePhase(arg0);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }

    if (arg0->unk_B8 == 1) {
        BattleAnim_EmitParticleBurstWithMetadata(arg0, BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor3DMetadataBurstChild, &gBattleAnimParticleDescriptors[0x3D], 1, 8, 0);
        Particle_AdvancePhase(arg0);
    }
}

void BattleAnim_CallbackEndEffects37And38Descriptor34BurstEmitter_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    switch (Particle_FieldCF_GetS16_0C058(arg0)) {
        case 3:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 1);
            Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            Particle_FieldCF_SetU8_0BEEC(arg0, 0);
            break;

        case 4:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 2);
            Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            Particle_FieldCF_SetU8_0BEEC(arg0, 1);
            break;
    }

    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

s32 BattleAnim_CallbackEndEffects37And38Descriptor34BurstEmitter(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffects37And38Descriptor34BurstEmitter_InitParticle(arg0);
            break;

        case 2:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A6) != 0) {
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 2);
            }
            break;

        case 3:
            func_8213CCEC(arg0, 0, 3, 1, 1, 0);
            Particle_AddVelocityXZFromRotationYPlusHalfTurn(arg0);
            if ((Particle_FieldA6_DecrementToZeroStep1_0BDAC != NULL) && (arg0->unk_B8 == 0)) {
                Particle_AdvancePhase(arg0);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }

    switch (arg0->unk_B8) {
        case 1:
            BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackEndEffects37And38Descriptor38BurstChild, &gBattleAnimParticleDescriptors[0x38], 8);
            Particle_AdvancePhase(arg0);
            break;

        case 2:
            if (Particle_TickPhaseTimer(arg0, 1) != 0) {
                BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackEndEffects37And38Descriptor38BurstChild, &gBattleAnimParticleDescriptors[0x38], 4);
                Particle_AdvancePhase(arg0);
            }
            break;

        case 3:
            if (Particle_TickPhaseTimer(arg0, 1) != 0) {
                BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackEndEffects37And38Descriptor38BurstChild, &gBattleAnimParticleDescriptors[0x38], 4);
                Particle_AdvancePhase(arg0);
            }
            break;
    }
}

void BattleAnim_CallbackStartEffect56Descriptor40AnimScaleFade_InitParticle(Particle* arg0) {
    Particle_FieldAC_GetS16_0C038(arg0);
    Particle_Field1C_SetScaled_0B938(arg0, 0.05f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 7);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, 0x32);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect56Descriptor40AnimScaleFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect56Descriptor40AnimScaleFade_InitParticle(arg0);
            break;

        case 2:
            func_8213CC10(arg0, 0, 5, 1, 1, -1);
            Particle_Field1C_Approach_0B98C(arg0, 0.3f, 0.01f);
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackStartEffect56Descriptor46AnimColorImpulseFade_InitParticle(Particle* arg0) {
    s16 sp2E;
    s16 sp2C;
    Vec3s sp24;

    sp2E = Particle_FieldAC_GetS16_0C038(arg0);
    sp2C = sp2E % 3;
    Particle_Field1C_SetScaled_0B938(arg0, 0.4f);
    Particle_Field74_SetScaled_0AD8C(arg0, 1.0f);

    sp24.x = MathUtil_Random16();
    sp24.y = MathUtil_Random16();
    sp24.z = 0;
    Particle_Field94_SetVecFromVec3s_0A24C(arg0, sp24);

    switch (sp2C) {
        case 0:
            Particle_SetPosition(arg0, 0.0f, -2.0f, 0.0f);
            break;

        case 1:
            Particle_SetPosition(arg0, 0.0f, 2.0f, 2.0f);
            break;

        case 2:
            Particle_SetPosition(arg0, 0.0f, 2.0f, -2.0f);
            break;
    }

    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x17);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp2E * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E4D8(s8 *);                      /* extern */
M2C_UNK func_8213F658(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821403B0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821403E0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821404DC(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821635E4(s8 *);                      /* extern */

void func_8216374C(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_821635E4(arg0);
        return;
    case 2:
        if (func_8213CA80(arg0, M2C_FIELD(arg0, s16 *, 0xA2)) != 0) {
            func_8213CB3C(arg0);
            return;
        }
        return;
    case 3:
        func_8213CCEC(arg0, 0, 7, 1, 1, 0);
        func_8213F658(arg0, 0x3E4CCCCD, 0x3E800000);
        func_82140228(arg0, 0x3F000000, 0x3CA3D70A);
        func_821403E0(arg0, 0, 0x20);
        func_821404DC(arg0, 0, 0x20);
        if (M2C_FIELD(arg0, s8 *, 0xC3) >= 6) {
            func_821403B0(arg0, 0, 0x20);
            func_82140518(arg0, 0x64, 0x4E);
        }
        func_8213E4D8(arg0);
        return;
    case 4:
        func_8213C930(arg0);
        break;
    }
}

void BattleAnim_CallbackStartEffect73Descriptor15AnimatedColorImpulseFade_InitParticle(Particle* arg0) {
    s16 sp2E = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp2C = sp2E % 3;
    Vec3s sp24;

    Particle_Field1C_SetScaled_0B938(arg0, 0.4f);
    Particle_Field74_SetScaled_0AD8C(arg0, 1.0f);

    sp24.x = MathUtil_Random16();
    sp24.y = MathUtil_Random16();
    sp24.z = 0;
    Particle_Field94_SetVecFromVec3s_0A24C(arg0, sp24);

    switch (sp2C) {
        case 0:
            Particle_SetPosition(arg0, 0.0f, -2.0f, 0.0f);
            break;

        case 1:
            Particle_SetPosition(arg0, 0.0f, 2.0f, 2.0f);
            break;

        case 2:
            Particle_SetPosition(arg0, 0.0f, 2.0f, -2.0f);
            break;
    }

    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x17);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp2E * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E4D8(s8 *);                      /* extern */
M2C_UNK func_8213F658(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821403B0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821403E0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821404DC(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82163884(s8 *);                      /* extern */

void func_821639EC(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82163884(arg0);
        return;
    case 2:
        if (func_8213CA80(arg0, M2C_FIELD(arg0, s16 *, 0xA2)) != 0) {
            func_8213CB3C(arg0);
            return;
        }
        return;
    case 3:
        func_8213CCEC(arg0, 0, 7, 1, 1, 0);
        func_8213F658(arg0, 0x3E4CCCCD, 0x3E800000);
        func_82140228(arg0, 0x3F000000, 0x3CA3D70A);
        func_821403E0(arg0, 0, 0x20);
        func_821404DC(arg0, 0, 0x20);
        if (M2C_FIELD(arg0, s8 *, 0xC3) >= 6) {
            func_821403B0(arg0, 0, 0x20);
            func_82140518(arg0, 0x64, 0x4E);
        }
        func_8213E4D8(arg0);
        return;
    case 4:
        func_8213C930(arg0);
        break;
    }
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_RecolorParticleByQueuedMoveId(Particle* arg0) {
    s16 sp1E;

    switch (BattleAnim_GetQueuedMoveId()) {
        case 0x4D:
            sp1E = 0x43;
            break;
        case 0x4E:
            sp1E = 5;
            break;
        case 0x4F:
            sp1E = 0xC;
            break;
        case 0x93:
            sp1E = 5;
            break;
        case 0x1C:
            sp1E = 0x31;
            break;
        case 0x6C:
            sp1E = 0x1C;
            break;
        case 0x7B:
            sp1E = 0x1E;
            break;
        case 0x36:
            sp1E = 0x1D;
            break;
        case 0x72:
            sp1E = 0x1E;
            break;
        case 0x8B:
            sp1E = 0x1E;
            break;
    }
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp1E);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82163B24.s")
#endif

void BattleAnim_CallbackStartEffects28And53And65And76Descriptor47AnimatedScaleMotion_InitParticle(Particle* arg0) {
    Vec3s sp28;
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    sp28.x = MathUtil_Random16();
    sp28.y = MathUtil_Random16();
    sp28.z = 0;
    Particle_Field94_SetVecFromVec3s_0A24C(arg0, sp28);

    switch (sp24) {
        case 0:
            Particle_SetRandomVelocityXYZ(arg0, 0xF, 0xF, 0xF);
            Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
            Particle_Field74_SetScaled_0AD8C(arg0, 1.0f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;

        case 1:
            Particle_SetRandomVelocityXYZ(arg0, 0xA, 0xA, 0xA);
            Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.0f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;
    }

    BattleAnim_RecolorParticleByQueuedMoveId(arg0);
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E528(s8 *);                      /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82163C28(s8 *);                      /* extern */

void func_82163D7C(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82163C28(arg0);
        return;
    case 2:
        if (func_8213CA80(arg0, M2C_FIELD(arg0, s16 *, 0xA2)) != 0) {
            func_8213CB3C(arg0);
            return;
        }
        return;
    case 3:
        func_8213CCEC(arg0, 0, 7, 1, 2, 0);
        func_82140518(arg0, 0x64, 6);
        func_82140228(arg0, 0x40000000, 0x3D99999A);
        func_8213E528(arg0);
        return;
    case 4:
        func_8213C930(arg0);
        break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82163E60; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82163E60.s")
#endif

M2C_UNK func_82137AB4(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_82140228(s8 *, M2C_UNK, s32);        /* extern */
M2C_UNK func_821404DC(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140548(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821406B4(s8 *);                      /* extern */
M2C_UNK func_82163E60(s8 *);                      /* extern */

void func_82163ED0(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82163E60(arg0);
        return;
    case 2:
        func_82140228(arg0, 0x40000000, 0x3CA3D70A);
        func_821404DC(arg0, 0xC8, 2);
        func_821406B4(arg0);
        return;
    case 3:
        func_82137AB4(arg0 + 0x70, 0x3C03126F, 0x3A83126F);
        func_82140228(arg0, 0x40000000, M2C_FIELD(arg0, s32 *, 0x70));
        func_821404DC(arg0, 0xC8, 2);
        func_82140548(arg0, 0, 0xC);
        return;
    case 4:
        func_8213C930(arg0);
        return;
    }
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_CallbackStartEffect81Descriptor3DRisingAnimFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    Particle_SetRandomVelocityXYZ(arg0, 0xF, 0xF, 0xF);
    Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0x32) * 0.02f) + 0.5f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_SetPrimAlpha(arg0, 0x64);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82163FC0.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_CallbackStartEffect81Descriptor3DRisingAnimFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect81Descriptor3DRisingAnimFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_FieldA6_SetS16_0BCA8(arg0, ParticleMath_RandomRange(4) + 4);
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            Particle_AddVelocityYFromFieldOffset74(arg0);
            break;

        case 4:
            func_8213CCEC(arg0, 0, 7, 1, 2, 0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x40, 4);
            Particle_AddVelocityYFromFieldOffset74(arg0);
            break;

        case 5:
            Particle_MarkInactive(arg0);
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821640A0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82164198; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82164198.s")
#endif

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E77C(s8 *);                      /* extern */
s32 func_821406B4(s8 *);                          /* extern */
M2C_UNK func_82164198(s8 *);                      /* extern */

void func_82164AD0(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82164198(arg0);
        return;
    case 2:
        if (func_821406B4(arg0) != 0) {
            func_8213CB3C(arg0);
            return;
        }
        return;
    case 3:
        func_8213CCEC(arg0, 0, 7, 1, (s32) M2C_FIELD(arg0, s16 *, 0xAC), 0);
        func_82140518(arg0, 0x40, M2C_FIELD(arg0, u8 *, 0xAB));
        func_8213E77C(arg0);
        return;
    case 4:
        func_8213C930(arg0);
        break;
    }
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_ApplySpeciesKeyedSpawnOffset(Particle* arg0) {
    f32 sp1C = 50.0f;
    f32 sp18 = 30.0f;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 3:
            sp1C = 40.0f;
            break;

        case 0x5F:
            sp1C = 25.0f;
            break;

        case 0x67:
            sp1C = 35.0f;
            break;

        case 0x71:
            sp18 = 35.0f;
            break;

        case 0x73:
            sp1C = 40.0f;
            break;

        case 0x82:
            sp1C = 20.0f;
            break;

        case 0x83:
            sp1C = 30.0f;
            break;
    }

    Particle_Field38_AddXZFromField94Y_08ED0(arg0, sp1C);
    Particle_Field38_AddYScaled_08E90(arg0, sp18);
    Particle_Field78_SetScaled_0ADA4(arg0, 0.4f);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82164B9C.s")
#endif

M2C_UNK func_8213C930(s8 *);                      /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
M2C_UNK func_8213CC10(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213D238(s8 *);                      /* extern */
M2C_UNK func_8213D284(s8 *);                      /* extern */
s32 func_8213D294(s8 *, M2C_UNK);                 /* extern */
M2C_UNK func_8213E71C(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_8213E7F4(s8 *);                      /* extern */
M2C_UNK func_8213F640(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_8213F6DC(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_82140594(s8 *, M2C_UNK);             /* extern */
s32 func_821406B4(s8 *);                          /* extern */
M2C_UNK func_82164198(s8 *);                      /* extern */
M2C_UNK func_82164B9C(s8 *);                      /* extern */

void func_82164CA4(s8 *arg0) {
    s16 temp_v0;
    s16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        func_82164198(arg0);
        func_82164B9C(arg0);
        break;
    case 2:                                         /* switch 1 */
        if (func_821406B4(arg0) != 0) {
            func_8213CB3C(arg0);
            func_8213D238(arg0);
            func_82140594(arg0, 0x14);
        }
        break;
    case 3:                                         /* switch 1 */
        func_8213CC10(arg0, 0, 7, 1, 2, 0);
        func_82140518(arg0, 0x40, 2);
        func_8213E7F4(arg0);
        func_8213E71C(arg0, 0x41200000);
        func_821406B4(arg0);
        break;
    case 4:                                         /* switch 1 */
        func_8213C930(arg0);
        break;
    }
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0xB4);
    switch (temp_v0_2) {                            /* switch 2; irregular */
    case 1:                                         /* switch 2 */
        func_8213F6DC(arg0, 0x3F800000, 0x3DCCCCCD);
        if (func_8213D294(arg0, 4) != 0) {
            func_8213D284(arg0);
            func_8213F640(arg0, 0x3E4CCCCD);
            return;
        }
        return;
    case 2:                                         /* switch 2 */
        func_8213F6DC(arg0, 0xBF000000, 0x3E4CCCCD);
        break;
    }
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
s32 func_8213C9B0(s8 *);                          /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E3F8(s8 *);                      /* extern */
M2C_UNK func_8213F940(s8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_821406B4(s8 *);                          /* extern */
M2C_UNK func_82164198(s8 *);                      /* extern */

void func_82164E18(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82164198(arg0);
        break;
    case 2:
        if (func_821406B4(arg0) != 0) {
            func_8213CB3C(arg0);
        }
        break;
    case 3:
        func_8213CCEC(arg0, 0, 7, 1, (s32) M2C_FIELD(arg0, s16 *, 0xAC), 0);
        func_82140518(arg0, 0x40, M2C_FIELD(arg0, u8 *, 0xAB));
        break;
    case 4:
        func_8213C930(arg0);
        break;
    }
    if (func_8213C9B0(arg0) != 0) {
        func_8213F940(arg0, 0xC0000000, 0x3E99999A);
        func_8213E3F8(arg0);
    }
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
s32 func_8213C9B0(s8 *);                          /* extern */
M2C_UNK func_8213CB3C(s8 *);                      /* extern */
M2C_UNK func_8213E3F8(s8 *);                      /* extern */
M2C_UNK func_8213F940(s8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_821406B4(s8 *);                          /* extern */
M2C_UNK func_82164198(s8 *);                      /* extern */

void func_82164F04(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82164198(arg0);
        break;
    case 2:
        if (func_821406B4(arg0) != 0) {
            func_8213CB3C(arg0);
        }
        break;
    case 3:
        if (M2C_FIELD(arg0, f32 *, 0x2C) < 0.0f) {
            func_8213C930(arg0);
        }
        break;
    }
    if (func_8213C9B0(arg0) != 0) {
        func_8213F940(arg0, 0xC1200000, 0x3F4CCCCD);
        func_8213E3F8(arg0);
    }
}

void BattleAnim_CallbackStartEffect101Descriptor3DMetadataBurstChild_InitParticle(Particle* arg0) {
    UNUSED s32 pad;

    Particle_FieldAC_GetS16_0C038(arg0);
    Particle_FieldCD_GetU8_0C048(arg0);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
    Particle_Field94_AddVec_0A52C(arg0, ParticleMath_RandomRange(0x10000), ParticleMath_RandomRange(0x10000), 0);
    Particle_Field74_SetScaled_0AD8C(arg0, 0.75f);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect101Descriptor3DMetadataBurstChild(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect101Descriptor3DMetadataBurstChild_InitParticle(arg0);
            break;

        case 2:
            func_8213CCEC(arg0, 0, 7, 1, 2, 0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x80, 8);
            Particle_AddVelocityFromRotationTemplate1(arg0);
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackDescriptor50BurstChild_InitParticle(Particle* arg0) {
    Vec3s sp28;
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_FieldAC_GetS16_0C038(arg0);
    sp28.x = ParticleMath_RandomSignedOffset(0x1000, -0x2000);
    sp28.y = ParticleMath_RandomSignedOffset(0x1000, 0x8000);
    sp28.z = 0;
    Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);
    Particle_Field1C_SetScaled_0B938(arg0, 0.05f);
    Particle_SetScaleSpeed(arg0, 0.25f);
    Particle_SetScaleTarget(arg0, 0.02f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp26);
    Particle_FieldA6_SetS16_0BCA8(arg0, 8);
    Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(8) * 0.25f) + 2.0f);
    Particle_Field7C_SetVecFromField74AnglesXY_0B2B4(arg0);
    Particle_AdvanceLifecycle(arg0);
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
s32 func_8213C9B0(s8 *);                          /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E3F8(s8 *);                      /* extern */
M2C_UNK func_8213F940(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821402B8(s8 *);                      /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_82140690(s8 *);                          /* extern */
M2C_UNK func_82165100(s8 *);                      /* extern */

void func_82165224(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82165100(arg0);
        break;
    case 2:
        func_8213CCEC(arg0, 1, 7, 1, 2, 0);
        if (func_82140690(arg0) != 0) {
            func_82140518(arg0, 0x64, 0x10);
        }
        break;
    case 3:
        func_8213C930(arg0);
        break;
    }
    if (func_8213C9B0(arg0) != 0) {
        func_821402B8(arg0);
        func_8213F940(arg0, 0xBFC00000, 0x3DCCCCCD);
        func_8213E3F8(arg0);
    }
}

void BattleAnim_CallbackDescriptor50BurstEmitter_InitParticle(Particle* arg0) {
    switch (arg0->unk_A6) {
        case 0:
            Particle_SetPosition(arg0, 0.0f, -5.0f, -10.0f);
            break;

        case 1:
            Particle_SetPosition(arg0, 0.0f, 8.0f, 8.0f);
            break;

        case 2:
            Particle_SetPosition(arg0, 0.0f, 3.0f, 0.0f);
            break;

        case 3:
            Particle_SetPosition(arg0, 0.0f, -3.0f, 5.0f);
            break;
    }

    Particle_FieldA6_SetS16_0BCA8(arg0, 6);
    Particle_AdvanceLifecycle(arg0);
}

extern ParticleDescriptor D_8218E580[86];
void BattleAnim_CallbackDescriptor50BurstEmitter(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackDescriptor50BurstEmitter_InitParticle(arg0);
            break;

        case 2:
            BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackDescriptor50BurstChild, &D_8218E580[0x50], 1);
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_EndEffect16_NoOpInit(void) {
}

M2C_UNK func_8213C930(s8 *);                      /* extern */
s32 func_8213C9B0(s8 *);                          /* extern */
M2C_UNK func_8213CCEC(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8213E3F8(s8 *);                      /* extern */
M2C_UNK func_8213F940(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821402B8(s8 *);                      /* extern */
M2C_UNK func_82140518(s8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_82140690(s8 *);                          /* extern */
M2C_UNK func_82164198(s8 *);                      /* extern */

void func_8216547C(s8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82164198(arg0);
        break;
    case 2:
        func_8213CCEC(arg0, 1, 7, 1, 2, 0);
        if (func_82140690(arg0) != 0) {
            func_82140518(arg0, 0x64, 0x10);
        }
        break;
    case 3:
        func_8213C930(arg0);
        break;
    }
    if (func_8213C9B0(arg0) != 0) {
        func_821402B8(arg0);
        func_8213F940(arg0, 0xBFC00000, 0x3E4CCCCD);
        func_8213E3F8(arg0);
    }
}

void BattleAnim_CallbackSharedDescriptor3CExpandingFadeIn_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
    Particle_Field38_AddYScaled_08E90(arg0, 5.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp26);
    Particle_SetPrimAlpha(arg0, 0x40);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedDescriptor3CExpandingFadeIn(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedDescriptor3CExpandingFadeIn_InitParticle(arg0);
            break;

        case 2:
            Particle_Field1C_Approach_0B98C(arg0, 8.0f, 0.1f);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0xFF, 4);
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_CallbackStartEffects29And60And104And110Descriptor44BurstChild_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_Field74_SetScaled_0AD8C(arg0, 100.0f);
    Particle_Field78_SetScaled_0ADA4(arg0, 3.0f);
    Particle_Field5C_SetYScaled_0A094(arg0, 2.0f);
    Particle_Field9A_SetY_0A3D8(arg0, 0x400);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_Field1C_SetScaled_0B938(arg0, 0.5f - (sp26 * 0.04f));
    Particle_SetPrimAlpha(arg0, (0xFF - (sp26 * 0x10)) & 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 + 1);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82165644.s")
#endif

s32 func_8213E334(Particle* arg0, f32 arg1);
void func_8213E4B0(Particle* arg0);
void BattleAnim_CallbackStartEffects29And60And104And110Descriptor44BurstChild(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffects29And60And104And110Descriptor44BurstChild_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 0x18);
            }
            break;

        case 3:
            if ((Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) && (Particle_Field1C_Approach_0B98C(arg0, 0.0f, 0.05f) != 0)) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_Field74_ApproachUsingField78_0AE00(arg0, 0.0f);
        Particle_Field94_AddYFromField9A_0A4C8(arg0);
        func_8213E4B0(arg0);
        func_8213E334(arg0, 0.0f);
        Particle_EnvB_Approach_0BBC0(arg0, 0xFF, 4);
        Particle_EnvG_Approach_0BBF0(arg0, 0xFF, 4);
    }
}

void func_8213E11C(Particle* arg0, f32 arg1);
extern ParticleDescriptor D_8218E580[86];
void BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter_InitParticle(Particle* arg0) {
    Particle_FieldAC_GetS16_0C038(arg0);
    Particle_Field94_SetY_0A2B8(arg0, ParticleMath_RandomRange(0x10000));
    func_8213E11C(arg0, ParticleMath_RandomSignedOffsetBySign(0x28, 0x28));
    BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackStartEffects29And60And104And110Descriptor44BurstChild, &D_8218E580[0x44], 5);
    Particle_AdvanceLifecycle(arg0);
}

void func_82165854(Particle* arg0);
void func_821658DC(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_82165854(arg0);
            break;

        case 2:
            func_8213C938(arg0);
            break;
    }
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_CallbackDescriptor26BurstChild_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_SetPrimColor(arg0, 0xDC, 0xFF, 0xFF);
    ParticleGfx_RecolorEnv(arg0, 0x33);
    arg0->unk_1C = (sp26 * 0.05f) + 0.5f;
    Particle_Field74_SetScaled_0AD8C(arg0, 2.0f);
    Particle_SetPrimAlpha(arg0, (0xFF - (sp26 << 5)) & 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 + 1);
    Particle_SetTextureFrame(arg0, 0xF);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216592C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821659FC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821659FC.s")
#endif

s16 func_8213C47C();                                /* extern */
M2C_UNK func_8213E14C(s32, M2C_UNK);                /* extern */
M2C_UNK func_82143408(s32, M2C_UNK);                /* extern */

void func_82165BC8(s32 arg0) {
    s16 sp26;

    sp26 = func_8213C47C();
    func_821401D4(arg0, 0x3F000000);
    func_8213E14C(arg0, 0x42C80000);
    func_82140594(arg0, (s16) (sp26 + 1));
    func_82143408(arg0, 8);
    func_82143440(arg0, 0x33);
    func_8213CB5C(arg0);
    func_8213C9D0(arg0);
}

void BattleAnim_CallbackDescriptor26BurstEmitter(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackDescriptor26BurstEmitter_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            if (func_8213CCEC(arg0, 0, 0xF, 2, 1, 0) != 0) {
                BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackDescriptor26BurstChild, &gBattleAnimParticleDescriptors[0x26], 5);
            }
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_SetupUnusedGrowingSparkVariant(Particle* arg0) {
    f32 sp24;
    s16 sp22 = Particle_FieldAC_GetS16_0C038(arg0);

    sp24 = (sp22 + 15.0f) / 20.0f;
    if (sp24 >= 1.0f) {
        sp24 = 1.0f;
    }

    Particle_Field1C_SetScaled_0B938(arg0, sp24);
    Particle_SetScaleSpeed(arg0, 8.0f * sp24);
    Particle_SetScaleTarget(arg0, 0.35f * sp24);
    Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
    Particle_SetTextureFrame(arg0, 0xF);
    ParticleGfx_RecolorPrim(arg0, 0x8);
    ParticleGfx_RecolorEnv(arg0, 0x33);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp22 * 8);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82165D14.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_CallbackUnusedGrowingSparkVariant(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupUnusedGrowingSparkVariant(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 0xC);
            break;

        case 4:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0x20, 0x20);
            break;

        case 5:
            Particle_DisableAndDetach(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_Field1C_ApproachField24ByField20_0BA1C(arg0);
        Particle_EnvG_Approach_0BBF0(arg0, 0, 0x10);
        Particle_EnvB_Approach_0BBC0(arg0, 0, 8);
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82165E30.s")
#endif

void ParticleEffect_InitializeGroup(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 7, 0, 7);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0x11, 7, 1, 0);
}

void ParticleEffect_ConfigTexture7Palette1(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 7, 0, 6);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0x11, 7, 1, 0);
}

void ParticleEffect_ConfigTexture9Palette2(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 0, 8);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0x11, 9, 2, 0);
}

void ParticleEffect_ConfigVariantMotion6(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 0, 6);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0x11, 9, 0, 0);
}

void ParticleEffect_ConfigVariantMotion16(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 0, 0x10);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0x11, 9, 0, 0);
}

void ParticleEffect_SpecialSetupBurstPalette3(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects37And38Descriptor34BurstEmitter, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 3, 0);
}

void ParticleEffect_SpecialSetupBurstPalette4(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects37And38Descriptor34BurstEmitter, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 4, 0);
}

void ParticleEffect_SpecialSetupDelayedScatterPalette1(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 7, 0x11, 9, 1, 0xC);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82166314; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82166314.s")
#endif

void ParticleEffect_ModeSetup(void) {
    UNUSED s32 pad;

    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 3, 5);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackEndEffect67Descriptor3DAnimatedGravityFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0x10, 0x64, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackEndEffect67Descriptor3DAnimatedGravityFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0x10, 0x64, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 8, 9, 0, 0x18, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 4, 9, 0, 0x18, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xC, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 4, 9, 0, 0x18, 0);
    BattleAnim_SpawnOwnerModelTintRampDetach(0, 0x33, 0xE0, 0, 0x20);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B794(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK D_8218E610;
extern M2C_UNK D_8218E728;
extern M2C_UNK D_8218E788;
extern M2C_UNK func_8214E67C;
extern M2C_UNK func_82162938;
extern M2C_UNK func_82162C68;

void func_8216669C(void) {
    func_8213B560(0, &func_82162C68, &D_8218E728, 0, 1, 0x11, 9, 3, 5);
    func_8213B560(4, &func_82162938, &D_8218E788, 0, 1, 0x10, 0x64, 0, 0);
    func_8213B5D8(0, 4, 5, &func_8214E67C, &D_8218E610, 8, 4, 2, 0, 0, 0);
    func_8213B794(0, 0, 0x40, 8, 0xC8);
    func_8213BC00(0, 0x17, 0xE1, 0, 0x40);
}

void BattleAnim_OrphanDescriptor34Emitter(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackOrphanDescriptor34ColorFadeDetach, &gBattleAnimParticleDescriptors[0x34], 0, 5, 0x11, gBattleAnimCurrentAnchor, 0, 0);
}

void ParticleEffect_AdditionalSetupDualRiseFade(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x28, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void ParticleEffect_AdditionalSetupBurstAndRiseFade(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor36ScaleAlphaFade, &gBattleAnimParticleDescriptors[0x36], 0, 1, 0xA, 0, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void ParticleEffect_CombinedSetupBurst3DRandom(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter, &gBattleAnimParticleDescriptors[0x34], 0, 5, 0x11, 0x64, 9, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackSharedDescriptor36ScaleAlphaFade, &gBattleAnimParticleDescriptors[0x36], 0, 1, 0xA, 0, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xC, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void ParticleEffect_CombinedSetupBurstHorizontalRandom(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter, &gBattleAnimParticleDescriptors[0x34], 0, 5, 0xA, 0, 0xA, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackSharedDescriptor36ScaleAlphaFade, &gBattleAnimParticleDescriptors[0x36], 0, 1, 0xA, 0, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xC, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void BattleAnim_EndEffects41And83Descriptor34BurstSequence(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter, &gBattleAnimParticleDescriptors[0x34], 0, 7, 0xA, 0, 0xB, 0);
}

M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */

void func_82166B88(void) {
    func_8213B644(0, 8, 0x20);
}

void ParticleEffect_MultiHandleSetup(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0xC, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 8, 9, 0, 0x17, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x12, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 0xA, 9, 0, 0x17, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x20, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 5, 9, 0, 0x17, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffect52DefaultBurstEmitter, &gDefaultParticleDescriptor, 0, 2, 9, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackEndEffect52DefaultBurstEmitter, &gDefaultParticleDescriptor, 0, 2, 9, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(5, BattleAnim_CallbackEndEffect52DefaultBurstEmitter, &gDefaultParticleDescriptor, 0, 2, 9, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackEndEffect52DefaultBurstEmitter, &gDefaultParticleDescriptor, 0, 2, 9, 0, 0, 0);
}

void BattleAnim_StartEffect137Descriptor3FRisingFade(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_8218E7D0;
extern s16 D_8219A80A;

void func_82166DC4(void) {
    func_8213B5D8(0, 3, 2, &func_82160704, &D_8218E7D0, 0, 6, 0x11, (s32) D_8219A80A, 0x11, 0);
    func_8213B5D8(0, 4, 2, &func_821608FC, &D_8218E7D0, 0, 4, 0x11, (s32) D_8219A80A, 0x11, 0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82166E7C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82166E7C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82166FD8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82166FD8.s")
#endif

void ParticleEffect_HandleStateSetup(void) {
    UNUSED s32 pad;

    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0xB, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0xB, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xA, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0xB, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x1E, BattleAnim_CallbackSharedOwnerKeyedGrowColorFade, &gBattleAnimParticleDescriptors[0x41], 0, 1, 0x18, 0, 0xF, 0);
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(0x23, 0, 0x10, 0x12);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B794(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK D_8218E6D8;
extern M2C_UNK D_8218E790;
extern s16 D_8219A80A;

void func_82167274(void) {
    func_8213B794(0, 2, 0x10, 0x12, 0xFF);
    func_8213B560(3, &func_821603C8, &D_8218E6D8, 0, 1, 0x10, (s32) D_8219A80A, 0x10, 2);
    func_8213B560(3, &func_82160230, &D_8218E790, 0, 1, 0x18, 0, 0xF, 0);
}

void ParticleEffect_StateCollisionSetupDesc29ScaleAnimFade(void) {
    UNUSED s32 pad;

    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0xD, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xA, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0xD, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x1E, BattleAnim_CallbackSharedOwnerKeyedGrowColorFade, &gBattleAnimParticleDescriptors[0x41], 0, 1, 0x18, 0, 0xD, 1);
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(0x23, 0, 0x10, 0x27);
}

void ParticleEffect_StateCollisionSetupDesc2BGravityFall(void) {
    UNUSED s32 pad;

    BattleAnim_SpawnDescriptor25AlphaHoldFadeOut(0, 2, 0x10, 0x27, 0xFF);
    BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackSharedOwnerKeyedAnimGrowFade, &gBattleAnimParticleDescriptors[0x2A], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0xD, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackSharedOwnerKeyedGrowColorAlphaFade, &gBattleAnimParticleDescriptors[0x41], 0, 1, 0x18, 0, 0xD, 1);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 1, 5, BattleAnim_CallbackEndEffects85And87GravityFallDelay, &gBattleAnimParticleDescriptors[0x2B], 0, 2, 0xE, 0, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 1, 5, BattleAnim_CallbackEndEffects85And87GravityFallDelay, &gBattleAnimParticleDescriptors[0x2B], 0, 2, 0xE, 0, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 0xF, BattleAnim_CallbackEndEffects85And87GravityFallDelay, &gBattleAnimParticleDescriptors[0x2B], 0, 1, 0xE, 0, 0, 0);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_8218E788;
extern M2C_UNK D_8218E7B0;
extern s16 D_8219A80A;
extern M2C_UNK func_82163540;

void func_821675EC(void) {
    func_8213B5D8(0, 1, 0x24, &func_8216374C, &D_8218E7B0, 0, 1, 0x11, (s32) D_8219A80A, 0, 0);
    func_8213B560(0, &func_82163540, &D_8218E788, 0, 1, 0x10, (s32) D_8219A80A, 0, 0);
}

void ParticleEffect_SpecialCollisionSetup(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffect3Descriptor29DirectionalScaleFade, &gBattleAnimParticleDescriptors[0x29], 0, 6, 0x10, 0x64, 0, 0);
}

M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */

void func_821676E4(void) {
    func_8213B644(0, 8, 0x26);
}

void ParticleEffect_MultiTextureSetup(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade, &gBattleAnimParticleDescriptors[0x29], 0, 8, 0x10, 9, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x10, BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade, &gBattleAnimParticleDescriptors[0x29], 0, 0xA, 0x10, 9, 0, 0);
    BattleAnim_SpawnGlobalTintColorFadeDetach(0x46, 4, 0x8);
}

M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */

void func_821677AC(void) {
    func_8213B644(0, 8, 0x15);
}

void BattleAnim_EndEffect26DelayedDescriptor29ScatterSequence(void) {
    BattleAnim_AddSpawnDelay(0x10);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade, &gBattleAnimParticleDescriptors[0x29], 0, 8, 0x10, 9, 1, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x10, BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade, &gBattleAnimParticleDescriptors[0x29], 0, 8, 0x10, 9, 1, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x20, BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade, &gBattleAnimParticleDescriptors[0x29], 0, 8, 0x10, 9, 1, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x30, BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade, &gBattleAnimParticleDescriptors[0x29], 0, 8, 0x10, 9, 1, 0);
}

s32 func_8213646C();                                /* extern */
M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213BC7C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
extern M2C_UNK D_8218E7B8;

void func_821678F4(void) {
    s32 temp_v0;

    temp_v0 = func_8213646C();
    switch (temp_v0) {                              /* irregular */
    case 0x4D:
        func_8213BC7C(0, 0x64, 0x3B, 0, 0xA0, 4);
        break;
    case 0x4E:
        func_8213BC7C(0, 0x64, 0x17, 0, 0xA0, 4);
        break;
    case 0x4F:
        func_8213BC7C(0, 0x64, 0x2D, 0, 0xA0, 4);
        break;
    case 0x93:
        func_8213BC7C(0, 0x64, 0x17, 0, 0xA0, 4);
        break;
    case 0x7B:
        func_8213BC7C(0, 0x64, 0x3B, 0, 0xA0, 4);
        break;
    case 0x8B:
        func_8213BC7C(0, 0x64, 0x3B, 0, 0xA0, 4);
        break;
    }
    func_8213B560(0, &func_82163D7C, &D_8218E7B8, 0, 7, 0x10, 0x64, 1, 0);
}

M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_8218E7B8;
extern M2C_UNK D_8218E7C8;
extern s16 D_8219A80A;

void func_82167A8C(void) {
    func_8213B5D8(0, 2, 3, &func_82160AF0, &D_8218E7C8, 0, 8, 0x11, (s32) D_8219A80A, 0, 0);
    func_8213B5D8(0, 3, 2, &func_82160704, &D_8218E7B8, 0, 6, 0x11, (s32) D_8219A80A, 0x31, 0);
    func_8213B5D8(0, 4, 2, &func_821608FC, &D_8218E7B8, 0, 4, 0x11, (s32) D_8219A80A, 0x31, 0);
}

extern ParticleDescriptor D_8218E580[86];
void ParticleEffect_SimpleNodeSetup(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffect55Descriptor49RiseGravityFade, &D_8218E580[0x49], 0, 5, 0x10, 0x64, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackEndEffect55Descriptor49RiseGravityFade, &D_8218E580[0x49], 0, 5, 0x10, 0x64, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects28And53And65And76Descriptor47AnimatedScaleMotion, &D_8218E580[0x47], 0, 7, 0x10, 0x64, 1, 0);
}

M2C_UNK func_8213B464(M2C_UNK);                     /* extern */
M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_8213C0D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_8218E770;
extern M2C_UNK D_8218E7D8;
extern M2C_UNK func_821640A0;

void func_82167C60(void) {
    func_8213C0D8(0, 0xFF, 0x30, 6);
    func_8213C0D8(0x24, 0, 0, 0xFF);
    func_8213BC00(0, 0x21, 0, 0xFF, 8);
    func_8213B464(6);
    func_8213B560(2, &func_82163ED0, &D_8218E7D8, 0, 1, 0xA, 0, 0x2F, 0);
    func_8213B5D8(0, 8, 4, &func_821640A0, &D_8218E770, 0, 3, 9, 0, 0x30, 0);
}

M2C_UNK func_8213B464(M2C_UNK);                     /* extern */
M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8213B720(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8213B878(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK D_8218E728;
extern M2C_UNK func_82162C68;

void func_82167D48(void) {
    func_8213B644(0, 0x20, 6);
    func_8213BC00(8, 8, 0, 0xFF, 0x40);
    func_8213B878(0xC, 5, 0x10, 8);
    func_8213B560(0xC, &func_82162C68, &D_8218E728, 0, 4, 9, 0, 0x18, 0xD);
    func_8213B464(0x21);
    func_8213B720(0, 0, 0x10, 8);
    func_8213B644(0, 0x10, 8);
    func_8213BC00(0, 8, 0xFF, 0, 0x10);
}

M2C_UNK func_8213B464(M2C_UNK);                     /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8213B720(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */

void func_82167E28(void) {
    func_8213B644(0, 0x20, 6);
    func_8213BC00(8, 8, 0, 0xFF, 0x40);
    func_8213B720(0, 0, 0x10, 8);
    func_8213B464(0x21);
    func_8213B644(0, 0x10, 8);
    func_8213BC00(0, 8, 0xFF, 0, 0x10);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213BC7C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_8215E510();                            /* extern */
extern M2C_UNK D_8218E770;
extern M2C_UNK D_8218E7F8;
extern M2C_UNK func_82145CC4;
void func_82167EB4(void) {
    M2C_UNK *sp38;

    func_8213BC7C(0, 1, 0xA, 0, 0xC8, 0x10);
    sp38 = &func_82164AD0;
    func_8213B5D8(6, 4, 0xE, &func_82164AD0, &D_8218E770, 0, 1, 0x11, 7, 0x1A, 0);
    func_8213B5D8(7, 8, 7, &func_82164AD0, &D_8218E770, 0, 1, 0x11, 7, 0x1A, 0);
    func_8213B560(0, &func_82145CC4, &D_8218E7F8, 0, 0x20, 7, 0, 0, 0);
    func_8215E510();
}

void ParticleEffect_FinalSetupRiseAndVerticalFade(void) {
    BattleAnim_SpawnOwnerModelTintPulseDetach(0, 1, 0xA, 0, 0xC8, 4);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(6, 4, 0xE, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 0x11, 7, 0x33, 7);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(7, 8, 7, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 0x11, 7, 0x33, 7);
}

void ParticleEffect_FinalSetupPortraitBurst(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x20, 6);
    ParticleEffect_PortraitBurst();
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(8, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void ParticleEffect_AdditionalNodeSingleRiseFade(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

extern ParticleDescriptor D_8218E580[86];
void BattleAnim_EndEffect58Descriptor4AAnd51Sequence(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedAnimatedVerticalFade, &D_8218E580[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(5, BattleAnim_CallbackSharedAnimatedVerticalFade, &D_8218E580[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(6, BattleAnim_CallbackSharedAnimatedVerticalFade, &D_8218E580[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(7, BattleAnim_CallbackSharedAnimatedVerticalFade, &D_8218E580[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &D_8218E580[0x51], 0, 5, 0x11, 9, 0x17, 0xE);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x10, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &D_8218E580[0x51], 0, 5, 0x11, 9, 0x17, 0xE);
}

extern ParticleDescriptor D_8218E580[86];
void func_82168364(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedAnimatedVerticalFade, &D_8218E580[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(5, BattleAnim_CallbackSharedAnimatedVerticalFade, &D_8218E580[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(6, BattleAnim_CallbackSharedAnimatedVerticalFade, &D_8218E580[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(7, BattleAnim_CallbackSharedAnimatedVerticalFade, &D_8218E580[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &D_8218E580[0x51], 0, 5, 0x11, 9, 0x17, 0xE);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x10, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &D_8218E580[0x51], 0, 5, 0x11, 9, 0x17, 0xE);
}

void BattleAnim_StartEffects87And88Descriptor3DVerticalFadeSequence(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 2, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 2, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 2, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
}

void ParticleEffect_MultiNodeD(void) {
    BattleAnim_SpawnOwnerModelTintRampDetach(4, 0x8, 0, 0xFF, 0x40);
    BattleAnim_SpawnOwnerModelTintRampDetach(9, 0x8, 0xFF, 0, 0x40);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(1, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
}

void BattleAnim_SpawnDefaultDescriptorBurstEmitterSequence(s32 arg0) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 1, 4, BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter, &gDefaultParticleDescriptor, 0, 1, 2, 0, arg0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(8, 1, 4, BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter, &gDefaultParticleDescriptor, 0, 1, 2, 0, arg0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x10, 1, 8, BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter, &gDefaultParticleDescriptor, 0, 1, 2, 0, arg0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x18, 1, 8, BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter, &gDefaultParticleDescriptor, 0, 1, 2, 0, arg0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x20, 1, 8, BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter, &gDefaultParticleDescriptor, 0, 1, 2, 0, arg0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x30, 1, 8, BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter, &gDefaultParticleDescriptor, 0, 1, 2, 0, arg0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x3C, 1, 8, BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter, &gDefaultParticleDescriptor, 0, 1, 2, 0, arg0, 0);
}

M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_82168844(M2C_UNK);                     /* extern */

void func_82168A10(void) {
    func_8213B644(0, 8, 6);
    func_82168844(0xE);
    func_8213B644(0x64, 0x20, 8);
}

M2C_UNK func_8213B560(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213B644(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_82168844(M2C_UNK);                     /* extern */
extern M2C_UNK D_8218E768;
extern M2C_UNK func_821655C0;

void func_82168A50(void) {
    func_8213B644(0, 8, 6);
    func_82168844(0x17);
    func_8213B560(0xA, &func_821655C0, &D_8218E768, 0x1A, 1, 5, 0, 0x33, 0);
    func_8213B644(0x64, 0x20, 8);
}

M2C_UNK func_8213BC7C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */

void func_82168ACC(void) {
    func_8213BC7C(0xA, 1, 8, 0, 0xFF, 0x20);
}

void ParticleEffect_ComplexGroupSetup(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 6);
    BattleAnim_SpawnDefaultDescriptorBurstEmitterSequence(0xC);
    BattleAnim_SpawnOwnerModelTintPaletteRotateFadeDetach(4, 0x32, 0x20, 0xA0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 8, 5, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 8, 9, 0, 0xC, 9);
}

M2C_UNK func_8213B5D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8213BC00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK D_8218E798;
extern M2C_UNK func_821624FC;

void func_82168B98(void) {
    func_8213BC00(0, 8, 0xFF, 0, 0x20);
    func_8213B5D8(4, 2, 2, &func_821624FC, &D_8218E798, 0, 8, 9, 0, 0x17, 1);
}
