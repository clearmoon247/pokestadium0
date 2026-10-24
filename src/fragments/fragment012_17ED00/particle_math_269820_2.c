/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/particle_math/particle_math_269820.c. */

#include "fragments/particle_math/particle_math.h"
#include "geo_render.h"
extern ParticleDescriptor gDefaultParticleDescriptor;

#include "m2c_macros.h"

s32 Particle_TickDelayAndAdvanceLifecycle(Particle* arg0, s16 arg1);
void Particle_SetFlags(Particle* arg0, s32 arg1);
void Particle_ClearFlags(Particle* arg0, s32 arg1);
void Particle_ToggleFlags(Particle* arg0, s32 arg1);
s32 Particle_HasFlags(Particle* arg0, s32 arg1);
s32 Particle_LacksFlags(Particle* arg0, s32 arg1);
void Particle_EnableRendering(Particle* arg0);
void Particle_DisableRendering(Particle* arg0);
s32 Particle_IsRenderingEnabled(Particle* arg0);
void Particle_EnableFlag40(Particle* arg0);
void Particle_DisableFlag40(Particle* arg0);
void Particle_HasFlag40(Particle* arg0);
s32 Particle_AnimateFramesForwardAndAdvanceLifecycle(Particle* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
s32 Particle_AnimateFramesReverseAndAdvanceLifecycle(Particle* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
void Particle_SetPositionFromRotationTemplate1(Particle* arg0, f32 arg1);
void Particle_SetPositionFromRotationTemplate2(Particle* arg0, f32 arg1);
void Particle_AddPositionFromRotationTemplate1(Particle* arg0, f32 arg1);
void Particle_AddPositionFromRotationTemplate2(Particle* arg0, f32 arg1);
void Particle_Field50_SetXScaled_098E8(Particle* arg0, f32 arg1);
void Particle_Field50_SetYScaled_09900(Particle* arg0, f32 arg1);
void Particle_Field50_AddXScaled_099C0(Particle* arg0, f32 arg1);
void Particle_Field50_AddYScaled_099E0(Particle* arg0, f32 arg1);
void Particle_Field50_SubXScaled_09A78(Particle* arg0, f32 arg1);
void Particle_Field50_SubYScaled_09A98(Particle* arg0, f32 arg1);
s32 Particle_Field50_ApproachXToField5C_09AD8(Particle* arg0, f32 arg1);
s32 Particle_Field50_ApproachYToField5C_09B18(Particle* arg0, f32 arg1);
void Particle_Field50_AddXFromField7C_09C58(Particle* arg0);
void Particle_Field50_AddYFromField7C_09C6C(Particle* arg0);
void Particle_AddVelocityXYFromRotationZViaImpulse(Particle* arg0);
void Particle_AddVelocityFromRotationTemplate2(Particle* arg0);
void Particle_Field50_SetZScaled_09918(Particle* arg0, f32 arg1);
f32 ParticleMath_ScaleApproachStep(f32 arg0);
void Particle_SetRotationTargetXY(Particle* arg0, s16 arg1, s16 arg2);
void Particle_Field94_AddXFromField9A_0A4B4(Particle* arg0);
void Particle_Field94_SubX_0A63C(Particle* arg0, s16 arg1);
void Particle_ApproachRotationTargetXY(Particle* arg0);
void Particle_ApproachRotationTargetXYZ(Particle* arg0);
s32 Particle_Field94_DecrementXTo_0A7DC(Particle* arg0, s32 arg1, s32 arg2);
void Particle_AddRotationRandomSignedXY(Particle* arg0, s32 arg1, s32 arg2);
void Particle_AddRotationRandomSignedXYWithXHalfTurn(Particle* arg0, s32 arg1, s32 arg2);
void Particle_AddRotationRandomSignedY(Particle* arg0, s32 arg1);
void Particle_AddRotationRandomSignedYWithHalfTurn(Particle* arg0, s32 arg1);
void Particle_AddRotationRandomSignedXWithFixedYQuarterTurn(Particle* arg0);
s32 Particle_Field74_Approach_0ADBC(Particle* arg0, f32 arg1, f32 arg2);
s32 Particle_Field7C_IncrementXUntilAtLeast_0AF54(Particle* arg0, f32 arg1, f32 arg2);
s32 Particle_Field7C_IncrementYUntilAtLeast_0AFA8(Particle* arg0, f32 arg1, f32 arg2);
s32 Particle_Field7C_DecrementXUntilAtMost_0B050(Particle* arg0, f32 arg1, f32 arg2);
s32 Particle_Field7C_DecrementYUntilAtMost_0B0A4(Particle* arg0, f32 arg1, f32 arg2);
void Particle_Field1C_SetScaled_0B938(Particle* arg0, f32 arg1);
void Particle_SetScale(Particle* arg0, f32 arg1);
void Particle_SetScaleSpeed(Particle* arg0, f32 arg1);
void Particle_SetScaleTarget(Particle* arg0, f32 arg1);
s32 Particle_Field1C_Approach_0B98C(Particle* arg0, f32 arg1, f32 arg2);
s32 Particle_Field1C_ApproachAndStepState_0B9D0(Particle* arg0, f32 arg1, f32 arg2);
s32 Particle_Field1C_ApproachField24ByField20_0BA1C(Particle* arg0);
s32 Particle_Field1C_ApproachField24AndStepState_0BA48(Particle* arg0);
s32 Particle_Field20_Approach_0BA84(Particle* arg0, f32 arg1, f32 arg2);
s32 Particle_PrimAlpha_ApproachAndStepState_0BC5C(Particle* arg0, u8 arg1, u8 arg2);
s32 Particle_FieldA6_DecrementToZero_0BD08(Particle* arg0, s16 arg1);
s32 Particle_FieldA6_DecrementToZeroAndStepState_0BD34(Particle* arg0, s16 arg1);
s32 Particle_FieldA6_DecrementToStep1_0BD80(Particle* arg0, s16 arg1);
s32 Particle_FieldA6_DecrementToZeroStep1_0BDAC(Particle* arg0);
s32 Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(Particle* arg0);
s32 Particle_FieldA8_DecrementToZeroStep1_0BE6C(Particle* arg0);
s32 Particle_FieldA8_DecrementToZeroStep1AndStepState_0BE8C(Particle* arg0);
s32 Particle_FieldAE_ApproachAndStepState_0BF98(Particle* arg0, s16 arg1, s16 arg2);

void Particle_AdvanceLifecycle(Particle* arg0);
s32 Particle_TickDelayTimer(Particle* arg0, s16 arg1);
s32 Particle_AnimateFramesForward(Particle* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
s32 Particle_AnimateFramesReverse(Particle* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
void Particle_Field38_SetVecFromVec3fScaled_08C20(Particle* arg0, Vec3f arg1);
void Particle_Field38_AddVecScaledFromVec3f_08D78(Particle* arg0, Vec3f arg1);
void Particle_Field50_AddVecFromField7C_09BDC(Particle* arg0);
void Particle_Field50_AddXYFromField7C_09C34(Particle* arg0);
void Particle_FieldA0_SetX_0A400(Particle* arg0, s16 arg1);
void Particle_FieldA0_SetY_0A414(Particle* arg0, s16 arg1);
void Particle_Field94_AddX_0A578(Particle* arg0, s16 arg1);
void Particle_Field94_AddY_0A594(Particle* arg0, s16 arg1);
void Particle_ApproachRotationTargetX(Particle* arg0);
void Particle_ApproachRotationTargetY(Particle* arg0);
void Particle_ApproachRotationTargetZ(Particle* arg0);
void Particle_ComputeVectorFromRotationXYZAlt(Particle* arg0, f32 arg1, Vec3f* arg2);
void Particle_ComputeVectorFromRotationYZVariant(Particle* arg0, f32 arg1, Vec3f* arg2);
void Particle_Field7C_SetXYFromField74AngleZ_0B23C(Particle* arg0);
void Particle_Field7C_SetVecFromField74AnglesXZ_0B330(Particle* arg0);
s32 Particle_PrimAlpha_Approach_0BC2C(Particle* arg0, u8 arg1, u8 arg2);
s32 Particle_FieldA6_DecrementTo_0BCC4(Particle* arg0, s16 arg1, s16 arg2);
s32 Particle_FieldA8_DecrementTo_0BE30(Particle* arg0, s16 arg1);
s32 Particle_FieldAE_Approach_0BF60(Particle* arg0, s16 arg1, s16 arg2);

s32 Particle_TickDelayAndAdvanceLifecycle(Particle* arg0, s16 arg1) {
    s32 sp1C = Particle_TickDelayTimer(arg0, arg1);

    if (sp1C != 0) {
        Particle_AdvanceLifecycle(arg0);
    }
    return sp1C;
}

void Particle_SetFlags(Particle* arg0, s32 arg1) {
    arg0->unk_18 |= arg1;
}

void Particle_ClearFlags(Particle* arg0, s32 arg1) {
    arg0->unk_18 &= ~arg1;
}

void Particle_ToggleFlags(Particle* arg0, s32 arg1) {
    arg0->unk_18 ^= arg1;
}

s32 Particle_HasFlags(Particle* arg0, s32 arg1) {
    s32 var_v1 = 0;

    if (arg0->unk_18 & arg1) {
        var_v1 = 1;
    }
    return var_v1;
}

s32 Particle_LacksFlags(Particle* arg0, s32 arg1) {
    s32 var_v1 = 0;

    if (!(arg0->unk_18 & arg1)) {
        var_v1 = 1;
    }
    return var_v1;
}

void Particle_EnableRendering(Particle* arg0) {
    Particle_SetFlags(arg0, 4);
}

void Particle_DisableRendering(Particle* arg0) {
    Particle_ClearFlags(arg0, 4);
}

s32 Particle_IsRenderingEnabled(Particle* arg0) {
    return Particle_HasFlags(arg0, 4);
}

void Particle_EnableFlag40(Particle* arg0) {
    Particle_SetFlags(arg0, 0x40);
}

void Particle_DisableFlag40(Particle* arg0) {
    Particle_ClearFlags(arg0, 0x40);
}

void Particle_HasFlag40(Particle* arg0) {
    Particle_HasFlags(arg0, 0x40);
}

void func_8213CBFC(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s8 *, 0xC3) = (s8) arg1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213CC10; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213CC10.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213CCEC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213CCEC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213CD60; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213CD60.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213CE3C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213CE3C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213CEB0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213CEB0.s")
#endif

s32 Particle_AnimateFramesForwardAndAdvanceLifecycle(Particle* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    s32 sp24 = Particle_AnimateFramesForward(arg0, arg1, arg2, arg3, arg4, arg5);

    if (sp24 != 0) {
        Particle_AdvanceLifecycle(arg0);
    }

    return sp24;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213D080; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213D080.s")
#endif

s32 Particle_AnimateFramesReverseAndAdvanceLifecycle(Particle* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    s32 sp24 = Particle_AnimateFramesReverse(arg0, arg1, arg2, arg3, arg4, arg5);

    if (sp24 != 0) {
        Particle_AdvanceLifecycle(arg0);
    }
    return sp24;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213D238; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213D238.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213D260; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213D260.s")
#endif

void func_8213D284(s8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0xB4) = (s16) (M2C_FIELD(arg0, s16 *, 0xB4) + 1);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213D294; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213D294.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213D30C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213D30C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213D3FC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213D3FC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213D43C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213D43C.s")
#endif

void func_8213D484(s8 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    M2C_FIELD(arg0, f32 *, 0x34) = arg1;
    M2C_FIELD(arg0, f32 *, 0x38) = arg2;
    M2C_FIELD(arg0, f32 *, 0x3C) = arg3;
}

extern f32 D_FLT_8219A824;

void func_8213D4A4(s8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x34) = (f32) (arg1 * D_FLT_8219A824);
}

extern f32 D_FLT_8219A824;

void func_8213D4BC(s8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x38) = (f32) (arg1 * D_FLT_8219A824);
}

extern f32 D_FLT_8219A824;

void func_8213D4D4(s8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x3C) = (f32) (arg1 * D_FLT_8219A824);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213D4EC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213D4EC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213D54C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213D54C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213D58C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213D58C.s")
#endif

extern f32 D_FLT_8219A824;

void func_8213D5E4(s8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x34) = (f32) (M2C_FIELD(arg0, f32 *, 0x34) + (arg1 * D_FLT_8219A824));
}

extern f32 D_FLT_8219A824;

void func_8213D604(s8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x38) = (f32) (M2C_FIELD(arg0, f32 *, 0x38) + (arg1 * D_FLT_8219A824));
}

extern f32 D_FLT_8219A824;

void func_8213D624(s8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x3C) = (f32) (M2C_FIELD(arg0, f32 *, 0x3C) + (arg1 * D_FLT_8219A824));
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213D644; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213D644.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213D6AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213D6AC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213D720; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213D720.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213D790; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213D790.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213D800; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213D800.s")
#endif

void Particle_SetPositionFromRotationTemplate1(Particle* arg0, f32 arg1) {
    Vec3f sp1C;

    Particle_ComputeVectorFromRotationXYZAlt(arg0, arg1, &sp1C);
    Particle_Field38_SetVecFromVec3fScaled_08C20(arg0, sp1C);
}

void Particle_SetPositionFromRotationTemplate2(Particle* arg0, f32 arg1) {
    Vec3f sp1C;

    Particle_ComputeVectorFromRotationYZVariant(arg0, arg1, &sp1C);
    Particle_Field38_SetVecFromVec3fScaled_08C20(arg0, sp1C);
}

void Particle_AddPositionFromRotationTemplate1(Particle* arg0, f32 arg1) {
    Vec3f sp1C;

    Particle_ComputeVectorFromRotationXYZAlt(arg0, arg1, &sp1C);
    Particle_Field38_AddVecScaledFromVec3f_08D78(arg0, sp1C);
}

void Particle_AddPositionFromRotationTemplate2(Particle* arg0, f32 arg1) {
    Vec3f sp1C;

    Particle_ComputeVectorFromRotationYZVariant(arg0, arg1, &sp1C);
    Particle_Field38_AddVecScaledFromVec3f_08D78(arg0, sp1C);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213D9D0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213D9D0.s")
#endif

s32 func_82137DF4(M2C_UNK);                         /* extern */
extern f32 D_FLT_8219A824;

void func_8213DA64(s8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, f32 *, 0x34) = (f32) ((f32) func_82137DF4(arg1) * D_FLT_8219A824);
}

s32 func_82137DF4(M2C_UNK);                         /* extern */
extern f32 D_FLT_8219A824;

void func_8213DAA4(s8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, f32 *, 0x38) = (f32) ((f32) func_82137DF4(arg1) * D_FLT_8219A824);
}

s32 func_82137DF4(M2C_UNK);                         /* extern */
extern f32 D_FLT_8219A824;

void func_8213DAE4(s8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, f32 *, 0x3C) = (f32) ((f32) func_82137DF4(arg1) * D_FLT_8219A824);
}

s32 func_82137DF4(M2C_UNK);                         /* extern */
extern f32 D_FLT_8219A824;

void func_8213DB24(s8 *arg0, M2C_UNK arg1, s32 arg2) {
    M2C_FIELD(arg0, f32 *, 0x34) = (f32) (((f32) func_82137DF4(arg1) * D_FLT_8219A824) + (f32) arg2);
}

s32 func_82137DF4(M2C_UNK);                         /* extern */
extern f32 D_FLT_8219A824;

void func_8213DB78(s8 *arg0, M2C_UNK arg1, s32 arg2) {
    M2C_FIELD(arg0, f32 *, 0x38) = (f32) (((f32) func_82137DF4(arg1) * D_FLT_8219A824) + (f32) arg2);
}

s32 func_82137DF4(M2C_UNK);                         /* extern */
extern f32 D_FLT_8219A824;

void func_8213DBCC(s8 *arg0, M2C_UNK arg1, s32 arg2) {
    M2C_FIELD(arg0, f32 *, 0x3C) = (f32) (((f32) func_82137DF4(arg1) * D_FLT_8219A824) + (f32) arg2);
}

s32 func_82137DF4(M2C_UNK);                         /* extern */
extern f32 D_FLT_8219A824;

void func_8213DC20(s8 *arg0, M2C_UNK arg1, s32 arg2) {
    f32 temp_f0;

    temp_f0 = (f32) func_82137DF4(arg1);
    if (temp_f0 >= 0.0f) {
        M2C_FIELD(arg0, f32 *, 0x34) = (f32) (((f32) arg2 + temp_f0) * D_FLT_8219A824);
        return;
    }
    M2C_FIELD(arg0, f32 *, 0x34) = (f32) ((temp_f0 - (f32) arg2) * D_FLT_8219A824);
}

s32 func_82137DF4(M2C_UNK);                         /* extern */
extern f32 D_FLT_8219A824;

void func_8213DCA8(s8 *arg0, M2C_UNK arg1, s32 arg2) {
    f32 temp_f0;

    temp_f0 = (f32) func_82137DF4(arg1);
    if (temp_f0 >= 0.0f) {
        M2C_FIELD(arg0, f32 *, 0x38) = (f32) (((f32) arg2 + temp_f0) * D_FLT_8219A824);
        return;
    }
    M2C_FIELD(arg0, f32 *, 0x38) = (f32) ((temp_f0 - (f32) arg2) * D_FLT_8219A824);
}

s32 func_82137DF4(M2C_UNK);                         /* extern */
extern f32 D_FLT_8219A824;

void func_8213DD30(s8 *arg0, M2C_UNK arg1, s32 arg2) {
    f32 temp_f0;

    temp_f0 = (f32) func_82137DF4(arg1);
    if (temp_f0 >= 0.0f) {
        M2C_FIELD(arg0, f32 *, 0x3C) = (f32) (((f32) arg2 + temp_f0) * D_FLT_8219A824);
        return;
    }
    M2C_FIELD(arg0, f32 *, 0x3C) = (f32) ((temp_f0 - (f32) arg2) * D_FLT_8219A824);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213DDB8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213DDB8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213DE50; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213DE50.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213DF24; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213DF24.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213DFF4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213DFF4.s")
#endif

void func_8213E0A4(s8 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    M2C_FIELD(arg0, f32 *, 0x64) = arg1;
    M2C_FIELD(arg0, f32 *, 0x68) = arg2;
    M2C_FIELD(arg0, f32 *, 0x6C) = arg3;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213E0C4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E0C4.s")
#endif

extern f32 D_FLT_8219A824;

void func_8213E104(s8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x4C) = (f32) (arg1 * D_FLT_8219A824);
}

void Particle_Field50_SetXScaled_098E8(Particle* arg0, f32 arg1) {
    arg0->unk_50.x = arg1 * gParticleRenderContext.unk_00.y;
}

void Particle_Field50_SetYScaled_09900(Particle* arg0, f32 arg1) {
    arg0->unk_50.y = arg1 * gParticleRenderContext.unk_00.y;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213E14C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E14C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213E184; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E184.s")
#endif

extern f32 D_FLT_8219A824;

void func_8213E1DC(s8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x4C) = (f32) (M2C_FIELD(arg0, f32 *, 0x4C) + (arg1 * D_FLT_8219A824));
}

void Particle_Field50_AddXScaled_099C0(Particle* arg0, f32 arg1) {
    arg0->unk_50.x += arg1 * gParticleRenderContext.unk_00.y;
}

void Particle_Field50_AddYScaled_099E0(Particle* arg0, f32 arg1) {
    arg0->unk_50.y += arg1 * gParticleRenderContext.unk_00.y;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213E23C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E23C.s")
#endif

extern f32 D_FLT_8219A824;

void func_8213E294(s8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x4C) = (f32) (M2C_FIELD(arg0, f32 *, 0x4C) - (arg1 * D_FLT_8219A824));
}

void Particle_Field50_SubXScaled_09A78(Particle* arg0, f32 arg1) {
    arg0->unk_50.x -= arg1 * gParticleRenderContext.unk_00.y;
}

void Particle_Field50_SubYScaled_09A98(Particle* arg0, f32 arg1) {
    arg0->unk_50.y -= arg1 * gParticleRenderContext.unk_00.y;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213E2F4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E2F4.s")
#endif

s32 Particle_Field50_ApproachXToField5C_09AD8(Particle* arg0, f32 arg1) {
    return ParticleMath_ApproachFloat(&arg0->unk_50.x, arg1 * gParticleRenderContext.unk_00.y, arg0->unk_5C.x);
}

s32 Particle_Field50_ApproachYToField5C_09B18(Particle* arg0, f32 arg1) {
    return ParticleMath_ApproachFloat(&arg0->unk_50.y, arg1 * gParticleRenderContext.unk_00.y, arg0->unk_5C.y);
}

void func_8213E3B4(s8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x4C) = (f32) M2C_FIELD(arg0, f32 *, 0x78);
    M2C_FIELD(arg0, f32 *, 0x50) = (f32) M2C_FIELD(arg0, f32 *, 0x7C);
    M2C_FIELD(arg0, f32 *, 0x54) = (f32) M2C_FIELD(arg0, f32 *, 0x80);
}

void func_8213E3D0(s8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x4C) = (f32) M2C_FIELD(arg0, f32 *, 0x78);
    M2C_FIELD(arg0, f32 *, 0x54) = (f32) M2C_FIELD(arg0, f32 *, 0x80);
}

void func_8213E3E4(s8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x4C) = (f32) M2C_FIELD(arg0, f32 *, 0x78);
    M2C_FIELD(arg0, f32 *, 0x50) = (f32) M2C_FIELD(arg0, f32 *, 0x7C);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213E3F8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E3F8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213E42C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E42C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213E450; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E450.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213E474; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E474.s")
#endif

void Particle_Field50_AddXFromField7C_09C58(Particle* arg0) {
    arg0->unk_50.x += arg0->unk_7C.x;
}

void Particle_Field50_AddYFromField7C_09C6C(Particle* arg0) {
    arg0->unk_50.y += arg0->unk_7C.y;
}

void Particle_AddVelocityXYFromRotationZViaImpulse(Particle* arg0) {
    Particle_Field7C_SetXYFromField74AngleZ_0B23C(arg0);
    Particle_Field50_AddXYFromField7C_09C34(arg0);
}

M2C_UNK func_8213E42C(s32);                         /* extern */
M2C_UNK func_8213FB14();                            /* extern */

void func_8213E4D8(s32 arg0) {
    func_8213FB14();
    func_8213E42C(arg0);
}

void Particle_AddVelocityFromRotationTemplate2(Particle* arg0) {
    Particle_Field7C_SetVecFromField74AnglesXZ_0B330(arg0);
    Particle_Field50_AddVecFromField7C_09BDC(arg0);
}

M2C_UNK func_8213E3F8(s32);                         /* extern */
M2C_UNK func_8213FB50();                            /* extern */

void func_8213E528(s32 arg0) {
    func_8213FB50();
    func_8213E3F8(arg0);
}

M2C_UNK func_8213E3F8(s32);                         /* extern */
M2C_UNK func_8213FBCC();                            /* extern */

void func_8213E550(s32 arg0) {
    func_8213FBCC();
    func_8213E3F8(arg0);
}

M2C_UNK func_8213E3F8(s32);                         /* extern */
M2C_UNK func_8213FC48();                            /* extern */

void func_8213E578(s32 arg0) {
    func_8213FC48();
    func_8213E3F8(arg0);
}

M2C_UNK func_8213E3F8(s32);                         /* extern */
M2C_UNK func_8213FCC8();                            /* extern */

void func_8213E5A0(s32 arg0) {
    func_8213FCC8();
    func_8213E3F8(arg0);
}

M2C_UNK func_8213E3F8(s32);                         /* extern */
M2C_UNK func_8213FE04();                            /* extern */

void func_8213E5C8(s32 arg0) {
    func_8213FE04();
    func_8213E3F8(arg0);
}

M2C_UNK func_8213E3F8(s32);                         /* extern */
M2C_UNK func_8213FD3C();                            /* extern */

void func_8213E5F0(s32 arg0) {
    func_8213FD3C();
    func_8213E3F8(arg0);
}

M2C_UNK func_8213E3F8(s32);                         /* extern */
M2C_UNK func_8213FED4();                            /* extern */

void func_8213E618(s32 arg0) {
    func_8213FED4();
    func_8213E3F8(arg0);
}

M2C_UNK func_8213E3F8(s32);                         /* extern */
M2C_UNK func_8213FED4();                            /* extern */

void func_8213E640(s32 arg0) {
    func_8213FED4();
    func_8213E3F8(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213E668; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E668.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213E6BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E6BC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213E71C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E71C.s")
#endif

M2C_UNK func_8213E488();                            /* extern */

void func_8213E77C(s8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x7C) = (f32) M2C_FIELD(arg0, f32 *, 0x70);
    func_8213E488();
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213E7A0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E7A0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213E7F4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E7F4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213E858; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E858.s")
#endif

void Particle_Field50_SetZScaled_09918(Particle* arg0, f32 arg1) {
    arg0->unk_50.z = arg1 * gParticleRenderContext.unk_00.y;
}

extern f32 D_FLT_8219A824;

void func_8213E8B0(s8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) (arg1 * D_FLT_8219A824);
}

extern f32 D_FLT_8219A824;

void func_8213E8C8(s8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x60) = (f32) (arg1 * D_FLT_8219A824);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213E8E0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E8E0.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
f32 ParticleMath_ScaleApproachStep(f32 arg0) {
    return arg0 * 0.4f;
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E924.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213E938; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213E938.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213EA68; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213EA68.s")
#endif

void func_8213EA8C(s8 *arg0, s16 arg1, s16 arg2, s16 arg3) {
    M2C_FIELD(arg0, s16 *, 0x90) = arg1;
    M2C_FIELD(arg0, s16 *, 0x92) = arg2;
    M2C_FIELD(arg0, s16 *, 0x94) = arg3;
}

void func_8213EAC0(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x90) = arg1;
}

void func_8213EAD4(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x92) = arg1;
}

void func_8213EAE8(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x94) = arg1;
}

void func_8213EAFC(s8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x90) = (s16) (M2C_FIELD(arg0, s16 *, 0x90) + 0x8000);
    M2C_FIELD(arg0, s16 *, 0x92) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000);
    M2C_FIELD(arg0, s16 *, 0x94) = (s16) (M2C_FIELD(arg0, s16 *, 0x94) + 0x8000);
}

void func_8213EB28(s8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x90) = (s16) (M2C_FIELD(arg0, s16 *, 0x90) + 0x8000);
}

void func_8213EB3C(s8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x92) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000);
}

void func_8213EB50(s8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x94) = (s16) (M2C_FIELD(arg0, s16 *, 0x94) + 0x8000);
}

void func_8213EB64(s8 *arg0, s16 arg1, s16 arg2, s16 arg3) {
    M2C_FIELD(arg0, s16 *, 0x96) = arg1;
    M2C_FIELD(arg0, s16 *, 0x98) = arg2;
    M2C_FIELD(arg0, s16 *, 0x9A) = arg3;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213EB98; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213EB98.s")
#endif

void func_8213EBBC(s8 *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x96) = arg1;
    M2C_FIELD(arg0, s16 *, 0x98) = arg2;
}

void func_8213EBE0(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x96) = arg1;
}

void func_8213EBF4(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x98) = arg1;
}

void func_8213EC08(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x9A) = arg1;
}

void func_8213EC1C(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x9C) = arg1;
}

void func_8213EC30(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x9E) = arg1;
}

void Particle_SetRotationTargetXY(Particle* arg0, s16 arg1, s16 arg2) {
    Particle_FieldA0_SetX_0A400(arg0, arg1);
    Particle_FieldA0_SetY_0A414(arg0, arg2);
}

void func_8213EC80(s8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x9C) = (s16) M2C_FIELD(arg0, s16 *, 0x90);
    M2C_FIELD(arg0, s16 *, 0x9E) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
    M2C_FIELD(arg0, s16 *, 0xA0) = (s16) M2C_FIELD(arg0, s16 *, 0x94);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213EC9C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213EC9C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213ECD0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213ECD0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213ECE4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213ECE4.s")
#endif

void Particle_Field94_AddXFromField9A_0A4B4(Particle* arg0) {
    arg0->unk_94.x += arg0->unk_9A.x;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213ED0C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213ED0C.s")
#endif

void func_8213ED48(s8 *arg0, s16 arg1, s16 arg2, s16 arg3) {
    M2C_FIELD(arg0, s16 *, 0x90) = (s16) (M2C_FIELD(arg0, s16 *, 0x90) + arg1);
    M2C_FIELD(arg0, s16 *, 0x92) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) + arg2);
    M2C_FIELD(arg0, s16 *, 0x94) = (s16) (M2C_FIELD(arg0, s16 *, 0x94) + arg3);
}

void func_8213ED94(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x90) = (s16) (M2C_FIELD(arg0, s16 *, 0x90) + arg1);
}

void func_8213EDB0(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x92) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) + arg1);
}

void func_8213EDCC(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x94) = (s16) (M2C_FIELD(arg0, s16 *, 0x94) + arg1);
}

void func_8213EDE8(s8 *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x9C) = (s16) (M2C_FIELD(arg0, s16 *, 0x9C) + arg1);
    M2C_FIELD(arg0, s16 *, 0x9E) = (s16) (M2C_FIELD(arg0, s16 *, 0x9E) + arg2);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213EE1C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213EE1C.s")
#endif

void func_8213EE58(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x90) = (s16) (M2C_FIELD(arg0, s16 *, 0x90) - arg1);
}

void func_8213EE74(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x92) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) - arg1);
}

void Particle_Field94_SubX_0A63C(Particle* arg0, s16 arg1) {
    arg0->unk_94.x -= arg1;
}

M2C_UNK func_82137940(s8 *, s16, s16, s8 *);    /* extern */

void func_8213EEAC(s8 *arg0) {
    func_82137940(arg0 + 0x90, M2C_FIELD(arg0, s16 *, 0x9C), M2C_FIELD(arg0, s16 *, 0x96), arg0);
}

M2C_UNK func_82137940(s8 *, s16, s16, s8 *);    /* extern */

void func_8213EED8(s8 *arg0) {
    func_82137940(arg0 + 0x92, M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0x98), arg0);
}

M2C_UNK func_82137940(s8 *, s16, s16, s8 *);    /* extern */

void func_8213EF04(s8 *arg0) {
    func_82137940(arg0 + 0x94, M2C_FIELD(arg0, s16 *, 0xA0), M2C_FIELD(arg0, s16 *, 0x9A), arg0);
}

void Particle_ApproachRotationTargetXY(Particle* arg0) {
    Particle_ApproachRotationTargetX(arg0);
    Particle_ApproachRotationTargetY(arg0);
}

void Particle_ApproachRotationTargetXYZ(Particle* arg0) {
    Particle_ApproachRotationTargetX(arg0);
    Particle_ApproachRotationTargetY(arg0);
    Particle_ApproachRotationTargetZ(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213EF88; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213EF88.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213EFC0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213EFC0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213EFF8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213EFF8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213F02C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213F02C.s")
#endif

s32 Particle_Field94_DecrementXTo_0A7DC(Particle* arg0, s32 arg1, s32 arg2) {
    s32 var_v1 = 0;
    s32 var_v0 = arg0->unk_94.x;

    if (arg1 < var_v0) {
        var_v0 -= arg2;
        if (arg1 >= var_v0) {
            var_v0 = arg1;
            var_v1 = 1;
        }
        arg0->unk_94.x = var_v0;
    }

    return var_v1;
}

void Particle_AddRotationRandomSignedXY(Particle* arg0, s32 arg1, s32 arg2) {
    Particle_Field94_AddX_0A578(arg0, ParticleMath_RandomSigned(arg1));
    Particle_Field94_AddY_0A594(arg0, ParticleMath_RandomSigned(arg2));
}

void Particle_AddRotationRandomSignedXYWithXHalfTurn(Particle* arg0, s32 arg1, s32 arg2) {
    Particle_Field94_AddX_0A578(arg0, ParticleMath_RandomSignedOffset(arg1, 0x8000));
    Particle_Field94_AddY_0A594(arg0, ParticleMath_RandomSigned(arg2));
}

void Particle_AddRotationRandomSignedY(Particle* arg0, s32 arg1) {
    Particle_Field94_AddY_0A594(arg0, ParticleMath_RandomSigned(arg1));
}

void Particle_AddRotationRandomSignedYWithHalfTurn(Particle* arg0, s32 arg1) {
    Particle_Field94_AddY_0A594(arg0, ParticleMath_RandomSignedOffset(arg1, 0x8000));
}

void Particle_AddRotationRandomSignedXWithFixedYQuarterTurn(Particle* arg0) {
    Particle_Field94_AddX_0A578(arg0, ParticleMath_RandomSigned(0x10000));
    Particle_Field94_AddY_0A594(arg0, 0x4000);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213F1E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213F1E4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213F264; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213F264.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213F2B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213F2B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213F354; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213F354.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213F3F4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213F3F4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213F50C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213F50C.s")
#endif

extern f32 D_FLT_8219A824;

void func_8213F628(s8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x70) = (f32) (arg1 * D_FLT_8219A824);
}

extern f32 D_FLT_8219A824;

void func_8213F640(s8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x74) = (f32) (arg1 * D_FLT_8219A824);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213F658; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213F658.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213F69C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213F69C.s")
#endif

s32 Particle_Field74_Approach_0ADBC(Particle* arg0, f32 arg1, f32 arg2) {
    return ParticleMath_ApproachFloat(&arg0->unk_74, arg1 * gParticleRenderContext.unk_00.y, arg2 * gParticleRenderContext.unk_00.y);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213F720; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213F720.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213F768; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213F768.s")
#endif

extern f32 D_FLT_8219A824;

void func_8213F7A8(s8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x78) = (f32) (arg1 * D_FLT_8219A824);
}

extern f32 D_FLT_8219A824;

void func_8213F7C0(s8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x7C) = (f32) (arg1 * D_FLT_8219A824);
}

extern f32 D_FLT_8219A824;

void func_8213F7D8(s8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x80) = (f32) (arg1 * D_FLT_8219A824);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213F7F0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213F7F0.s")
#endif

s32 Particle_Field7C_IncrementXUntilAtLeast_0AF54(Particle* arg0, f32 arg1, f32 arg2) {
    f32 temp_fv0;
    s32 var_v1 = 0;

    arg0->unk_7C.x += arg2 * gParticleRenderContext.unk_00.y;

    temp_fv0 = arg1 * gParticleRenderContext.unk_00.y;
    if (temp_fv0 <= arg0->unk_7C.x) {
        arg0->unk_7C.x = temp_fv0;
        var_v1 = 1;
    }
    return var_v1;
}

s32 Particle_Field7C_IncrementYUntilAtLeast_0AFA8(Particle* arg0, f32 arg1, f32 arg2) {
    f32 temp_fv0;
    s32 var_v1 = 0;

    arg0->unk_7C.y += arg2 * gParticleRenderContext.unk_00.y;

    temp_fv0 = arg1 * gParticleRenderContext.unk_00.y;
    if (temp_fv0 <= arg0->unk_7C.y) {
        arg0->unk_7C.y = temp_fv0;
        var_v1 = 1;
    }
    return var_v1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213F8EC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213F8EC.s")
#endif

s32 Particle_Field7C_DecrementXUntilAtMost_0B050(Particle* arg0, f32 arg1, f32 arg2) {
    f32 temp_fv0;
    s32 var_v1 = 0;

    arg0->unk_7C.x -= arg2 * gParticleRenderContext.unk_00.y;

    temp_fv0 = arg1 * gParticleRenderContext.unk_00.y;
    if (arg0->unk_7C.x <= temp_fv0) {
        arg0->unk_7C.x = temp_fv0;
        var_v1 = 1;
    }
    return var_v1;
}

s32 Particle_Field7C_DecrementYUntilAtMost_0B0A4(Particle* arg0, f32 arg1, f32 arg2) {
    s32 var_v1 = 0;
    f32 temp_fv0;

    arg0->unk_7C.y -= arg2 * gParticleRenderContext.unk_00.y;

    temp_fv0 = arg1 * gParticleRenderContext.unk_00.y;
    if (arg0->unk_7C.y <= temp_fv0) {
        arg0->unk_7C.y = temp_fv0;
        var_v1 = 1;
    }
    return var_v1;
}

void func_8213F9E8(s8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x78) = (f32) (M2C_FIELD(arg0, f32 *, 0x78) * arg1);
    M2C_FIELD(arg0, f32 *, 0x7C) = (f32) (M2C_FIELD(arg0, f32 *, 0x7C) * arg1);
    M2C_FIELD(arg0, f32 *, 0x80) = (f32) (M2C_FIELD(arg0, f32 *, 0x80) * arg1);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8213FA1C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213FA1C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213FA60; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213FA60.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213FA88; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213FA88.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213FAB0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213FAB0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213FAD8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213FAD8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213FB14; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213FB14.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213FB50; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213FB50.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213FBCC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213FBCC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213FC48; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213FC48.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213FCC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213FCC8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213FD3C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213FD3C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213FE04; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213FE04.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213FED4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213FED4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8213FF9C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8213FF9C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82140064; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82140064.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821400F0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821400F0.s")
#endif

void Particle_Field1C_SetScaled_0B938(Particle* arg0, f32 arg1) {
    arg0->unk_1C = arg1 * gParticleRenderContext.unk_00.y;
}

void Particle_SetScale(Particle* arg0, f32 arg1) {
    arg0->unk_1C = arg1;
}

void Particle_SetScaleSpeed(Particle* arg0, f32 arg1) {
    arg0->unk_20 = arg1 * gParticleRenderContext.unk_00.y;
}

void Particle_SetScaleTarget(Particle* arg0, f32 arg1) {
    arg0->unk_24 = arg1 * gParticleRenderContext.unk_00.y;
}

s32 Particle_Field1C_Approach_0B98C(Particle* arg0, f32 arg1, f32 arg2) {
    return ParticleMath_ApproachFloat(&arg0->unk_1C, arg1 * gParticleRenderContext.unk_00.y, arg2 * gParticleRenderContext.unk_00.y);
}

s32 Particle_Field1C_ApproachAndStepState_0B9D0(Particle* arg0, f32 arg1, f32 arg2) {
    s32 sp1C = Particle_Field1C_Approach_0B98C(arg0, arg1, arg2);

    if (sp1C != 0) {
        Particle_AdvanceLifecycle(arg0);
    }
    return sp1C;
}

s32 Particle_Field1C_ApproachField24ByField20_0BA1C(Particle* arg0) {
    return ParticleMath_ApproachFloat(&arg0->unk_1C, arg0->unk_20, arg0->unk_24);
}

s32 Particle_Field1C_ApproachField24AndStepState_0BA48(Particle* arg0) {
    s32 sp1C = Particle_Field1C_ApproachField24ByField20_0BA1C(arg0);

    if (sp1C != 0) {
        Particle_AdvanceLifecycle(arg0);
    }
    return sp1C;
}

s32 Particle_Field20_Approach_0BA84(Particle* arg0, f32 arg1, f32 arg2) {
    return ParticleMath_ApproachFloat(&arg0->unk_20, arg1 * gParticleRenderContext.unk_00.y, arg2 * gParticleRenderContext.unk_00.y);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82140364; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82140364.s")
#endif

M2C_UNK func_82137804(s32, s32, s32);               /* extern */

void func_82140380(s32 arg0, s32 arg1, s32 arg2) {
    func_82137804(arg0 + 0xBA, arg1 & 0xFF, arg2 & 0xFF);
}

M2C_UNK func_82137804(s32, s32, s32);               /* extern */

void func_821403B0(s32 arg0, s32 arg1, s32 arg2) {
    func_82137804(arg0 + 0xBB, arg1 & 0xFF, arg2 & 0xFF);
}

M2C_UNK func_82137804(s32, s32, s32);               /* extern */

void func_821403E0(s32 arg0, s32 arg1, s32 arg2) {
    func_82137804(arg0 + 0xBC, arg1 & 0xFF, arg2 & 0xFF);
}

extern s16 D_8219A8B2;
extern s16 D_8219A8B4;
extern s16 D_8219A8B6;

void func_82140410(s8 *arg0) {
    D_8219A8B2 = (s16) M2C_FIELD(arg0, u8 *, 0xBA);
    D_8219A8B4 = (s16) M2C_FIELD(arg0, u8 *, 0xBB);
    D_8219A8B6 = (s16) M2C_FIELD(arg0, u8 *, 0xBC);
}

extern s16 D_8219A8B2;
extern s16 D_8219A8B4;
extern s16 D_8219A8B6;

void func_82140438(s8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0xBA) = (s8) D_8219A8B2;
    M2C_FIELD(arg0, s8 *, 0xBB) = (s8) D_8219A8B4;
    M2C_FIELD(arg0, s8 *, 0xBC) = (s8) D_8219A8B6;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82140460; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82140460.s")
#endif

M2C_UNK func_82137804(s32, s32, s32);               /* extern */

void func_8214047C(s32 arg0, s32 arg1, s32 arg2) {
    func_82137804(arg0 + 0xBD, arg1 & 0xFF, arg2 & 0xFF);
}

M2C_UNK func_82137804(s32, s32, s32);               /* extern */

void func_821404AC(s32 arg0, s32 arg1, s32 arg2) {
    func_82137804(arg0 + 0xBF, arg1 & 0xFF, arg2 & 0xFF);
}

M2C_UNK func_82137804(s32, s32, s32);               /* extern */

void func_821404DC(s32 arg0, s32 arg1, s32 arg2) {
    func_82137804(arg0 + 0xBE, arg1 & 0xFF, arg2 & 0xFF);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8214050C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8214050C.s")
#endif

M2C_UNK func_82137804(s32, s32, s32);               /* extern */

void func_82140518(s32 arg0, s32 arg1, s32 arg2) {
    func_82137804(arg0 + 0xC0, arg1 & 0xFF, arg2 & 0xFF);
}

s32 Particle_PrimAlpha_ApproachAndStepState_0BC5C(Particle* arg0, u8 arg1, u8 arg2) {
    s32 sp1C = Particle_PrimAlpha_Approach_0BC2C(arg0, arg1, arg2);

    if (sp1C != 0) {
        Particle_AdvanceLifecycle(arg0);
    }
    return sp1C;
}

void func_82140594(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0xA2) = arg1;
}

s32 func_821405A8(s8 *arg0, s16 arg1, s16 arg2) {
    s32 var_v1;

    M2C_FIELD(arg0, s16 *, 0xA2) = (s16) (M2C_FIELD(arg0, s16 *, 0xA2) - arg2);
    var_v1 = 0;
    if (arg1 >= M2C_FIELD(arg0, s16 *, 0xA2)) {
        M2C_FIELD(arg0, s16 *, 0xA2) = arg1;
        var_v1 = 1;
    }
    return var_v1;
}

s32 Particle_FieldA6_DecrementToZero_0BD08(Particle* arg0, s16 arg1) {
    return Particle_FieldA6_DecrementTo_0BCC4(arg0, 0, arg1);
}

s32 Particle_FieldA6_DecrementToZeroAndStepState_0BD34(Particle* arg0, s16 arg1) {
    s32 sp1C = Particle_FieldA6_DecrementTo_0BCC4(arg0, 0, arg1);

    if (sp1C != 0) {
        Particle_AdvanceLifecycle(arg0);
    }
    return sp1C;
}

s32 Particle_FieldA6_DecrementToStep1_0BD80(Particle* arg0, s16 arg1) {
    return Particle_FieldA6_DecrementTo_0BCC4(arg0, arg1, 1);
}

s32 Particle_FieldA6_DecrementToZeroStep1_0BDAC(Particle* arg0) {
    return Particle_FieldA6_DecrementTo_0BCC4(arg0, 0, 1);
}

s32 Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(Particle* arg0) {
    s32 sp1C = Particle_FieldA6_DecrementTo_0BCC4(arg0, 0, 1);

    if (sp1C != 0) {
        Particle_AdvanceLifecycle(arg0);
    }
    return sp1C;
}

void func_821406F8(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0xA4) = arg1;
}

s32 func_8214070C(s8 *arg0, s16 arg1) {
    s32 var_v1;

    M2C_FIELD(arg0, s16 *, 0xA4) = (s16) (M2C_FIELD(arg0, s16 *, 0xA4) - 1);
    var_v1 = 0;
    if (arg1 >= M2C_FIELD(arg0, s16 *, 0xA4)) {
        M2C_FIELD(arg0, s16 *, 0xA4) = arg1;
        var_v1 = 1;
    }
    return var_v1;
}

s32 Particle_FieldA8_DecrementToZeroStep1_0BE6C(Particle* arg0) {
    return Particle_FieldA8_DecrementTo_0BE30(arg0, 0);
}

s32 Particle_FieldA8_DecrementToZeroStep1AndStepState_0BE8C(Particle* arg0) {
    s32 sp1C = Particle_FieldA8_DecrementTo_0BE30(arg0, 0);

    if (sp1C != 0) {
        Particle_AdvanceLifecycle(arg0);
    }
    return sp1C;
}

#ifdef NON_MATCHING
/* TODO: decompile func_821407A8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821407A8.s")
#endif

void func_821407B4(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0xA8) = arg1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_821407C8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821407C8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821407D4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821407D4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821407E0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821407E0.s")
#endif

void func_821407EC(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0xA6) = arg1;
}

void func_82140800(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s8 *, 0xCA) = (s8) arg1;
}

void func_82140814(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s8 *, 0xC9) = (s8) arg1;
}

void func_82140828(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0xAA) = arg1;
}

M2C_UNK func_82137898(s32, s16, s16);               /* extern */

void func_8214083C(s32 arg0, s16 arg1, s16 arg2) {
    func_82137898(arg0 + 0xAA, arg1, arg2);
}

s32 Particle_FieldAE_ApproachAndStepState_0BF98(Particle* arg0, s16 arg1, s16 arg2) {
    s32 sp1C = Particle_FieldAE_Approach_0BF60(arg0, arg1, arg2);

    if (sp1C != 0) {
        Particle_AdvanceLifecycle(arg0);
    }
    return sp1C;
}

void func_821408C8(s8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0xAC) = arg1;
}

M2C_UNK func_82137898(s32, s16, s16);               /* extern */

void func_821408DC(s32 arg0, s16 arg1, s16 arg2) {
    func_82137898(arg0 + 0xAC, arg1, arg2);
}
