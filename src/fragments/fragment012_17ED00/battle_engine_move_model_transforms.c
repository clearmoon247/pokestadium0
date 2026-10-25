/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_31AA30.c, src/fragments/battle_engine/battle_engine_move_model_transforms.c. */

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

#include "fragments/battle_engine/battle_engine.h"

#include "m2c_macros.h"

void BattleScene_ShowSecondaryModelsStaggeredFrame(ActivePokemon* active_pokemon);
void BattleScene_UpdateSecondaryModelTrailPosition(ActivePokemon* pokemon, s16 new_position);
void BattleScene_ResetParticipantModelFlags(ActivePokemon* active_pokemon);
void BattleAnim_WaterfallEnd(UNUSED ActivePokemon* owner, UNUSED ActivePokemon* animated_pokemon);
s32 BattleAnim_ApproachAngleAndCheckThreshold(ActivePokemon* pokemon, s16 phase, s16 camera_offset_scale);
void BattleAnim_WithdrawContinue(ActivePokemon* owner, UNUSED ActivePokemon* animated_pokemon);
void BattleAnim_DrawParticleNoop(UNUSED Particle* arg0, UNUSED CameraNode* arg1);

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_InitSwayOffset(ActivePokemon* pokemon, f32 y, s16 theta) {
    pokemon->y = y;
    pokemon->modelTransform.rotation.z = COSS(theta) * y;
    pokemon->modelTransform.rotation.y = SINS(theta) * y;
    pokemon->rotationZ = 0.01f;
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82109130.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_UpdateTransform(ActivePokemon* owner, ActivePokemon* animated_pokemon, f32 height, f32 delta_y, s32 delta_theta) {
    f32 temp_attacker_rotation_z;
    f32 temp_attacker_y1;
    f32 base_y_rotation;
    UNUSED s32 pad;
    Vec3f rotation;
    UNUSED s32 pad2;
    f32 z_rotation_factor;
    f32 y_rotation_factor;
    f32 temp_attacker_y2;

    temp_attacker_rotation_z = animated_pokemon->rotationZ;
    temp_attacker_y1 = animated_pokemon->y;
    base_y_rotation = 18.0f;
    animated_pokemon->y = Math_StepToF(temp_attacker_y1, height, delta_y, delta_y);

    temp_attacker_y2 = animated_pokemon->y;
    if (height <= temp_attacker_y2) {
        if (&animated_pokemon->modelTransform.rotation) {}
        temp_attacker_y2 = 0.0f;
    }

    rotation.z = COSS(delta_theta) * temp_attacker_y2;
    rotation.y = SINS(delta_theta) * temp_attacker_y2;

    z_rotation_factor = -temp_attacker_rotation_z * ((temp_attacker_y1 * animated_pokemon->modelTransform.rotation.z) + rotation.z);
    y_rotation_factor = -base_y_rotation - (temp_attacker_rotation_z * ((temp_attacker_y1 * animated_pokemon->modelTransform.rotation.y) + rotation.y));

    animated_pokemon->modelTransform.rotation.z = (animated_pokemon->modelTransform.rotation.z + rotation.z + (z_rotation_factor * 0.05f));
    animated_pokemon->modelTransform.rotation.y = (animated_pokemon->modelTransform.rotation.y + rotation.y + (y_rotation_factor * 0.05f));

    rotation.y = animated_pokemon->modelTransform.rotation.y;
    animated_pokemon->modelTransform.rotation.x = 0.0f;

    BattleAnim_Vec3fSetPolarXZ(&rotation, animated_pokemon->modelTransform.rotation.z, owner->displayObject.rotation.y + NINETY_DEGREES);
    Vec3f_AddInPlace(&owner->displayObject.position, &rotation);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82109188.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_UpdateSwayPhysicsToTarget(UNUSED ActivePokemon* owner, ActivePokemon* animated_object, f32 target, f32 delta, s32 theta0, s32 theta1) {
    f32 object_z;
    f32 object_y;
    f32 adjustment;
    UNUSED s32 pad;
    Vec3f rotation;
    UNUSED s32 pad2;
    f32 adjusted_z_rotation;
    f32 adjusted_y_rotation;
    f32 temp_object_y;

    object_z = animated_object->rotationZ;
    object_y = animated_object->y;
    adjustment = 20.0f;
    animated_object->y = Math_StepToF(object_y, target, delta, delta);

    temp_object_y = animated_object->y;
    if (target <= temp_object_y) {
        if (&animated_object->modelTransform.rotation) {}
        temp_object_y = 0.0f;
    }

    rotation.z = COSS(theta0) * temp_object_y;
    rotation.y = SINS(theta0) * temp_object_y;

    adjusted_z_rotation = -object_z * ((object_y * animated_object->modelTransform.rotation.z) + rotation.z);
    adjusted_y_rotation = -adjustment - (object_z * ((object_y * animated_object->modelTransform.rotation.y) + rotation.y));

    animated_object->modelTransform.rotation.z = (animated_object->modelTransform.rotation.z + rotation.z + (adjusted_z_rotation * 0.05f));
    animated_object->modelTransform.rotation.y = (animated_object->modelTransform.rotation.y + rotation.y + (adjusted_y_rotation * 0.05f));
    rotation.y = animated_object->modelTransform.rotation.y;
    animated_object->modelTransform.rotation.x = 0.0f;

    BattleAnim_Vec3fSetPolarXZ(&rotation, animated_object->modelTransform.rotation.z, theta1);
    Vec3f_AddInPlace(&animated_object->pokeBall.position, &rotation);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821092E4.s")
#endif

void BattleScene_HideParticipantSecondaryModels(ActivePokemon* active_pokemon) {
    s32 i;

    for (i = 0; i < 3; i++) {
        Vec3f_SetComponentsDuplicate(&active_pokemon->afterimages[i].displayObject.scale, 1.0f, 1.0f, 1.0f);
        active_pokemon->afterimages[i].displayObject.node.flags &= ~1;
        active_pokemon->afterimages[i].minimized = 0;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_821094C0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821094C0.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleScene_UpdateSecondaryModelOrbit(ActivePokemon* pokemon) {
    s32 i;
    f32 tmp;
    Vec3f sp5C = { 0.0f, 0.0f, 0.0f };         // D_84384610
    f32 sp4C[] = { 0.3f, -0.4f, -0.2f, 0.4f }; // D_8438461C

    for (i = 0; i < 3; i++) {
        pokemon->afterimages[i].displayObject.lodFraction = Math_StepToS32(pokemon->afterimages[i].displayObject.lodFraction, 0x3C, 5, 5);
        pokemon->afterimages[i].unk_16C = Math_StepToS32(pokemon->afterimages[i].unk_16C, 0x38E, 0x64, 0x64);
        pokemon->afterimages[i].unk_16C = Math_StepToS32(pokemon->afterimages[i].unk_16C, 0x38E, 0x64, 0x64);
        pokemon->afterimages[i].unk_16A += pokemon->afterimages[i].unk_16C;

        tmp = SINS(pokemon->afterimages[i].unk_16A) * (BattleScene_GetParticipantModelRadiusScaled(pokemon) * sp4C[i]);
        BattleAnim_Vec3fSetPolarXZ(&sp5C, tmp, pokemon->displayObject.rotation.y);

        pokemon->afterimages[i].displayObject.position.x = pokemon->displayObject.position.x + sp5C.x;
        pokemon->afterimages[i].displayObject.position.y = pokemon->displayObject.position.y + sp5C.y;
        pokemon->afterimages[i].displayObject.position.z = pokemon->displayObject.position.z + sp5C.z;

        ModelAnim_SetFrame(&pokemon->afterimages[i].displayObject, pokemon->displayObject.transformAnim.frameFixed >> 0x10);
        ModelAnim_SetAnimation(&pokemon->afterimages[i].displayObject, pokemon->displayObject.transformAnim.animationId);
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821095B4.s")
#endif

void BattleScene_ShowSecondaryModelsAtMainPose(ActivePokemon* active_pokemon) {
    s32 i;

    for (i = 0; i < 2; i++) {
        active_pokemon->afterimages[i].minimized = 0;
        active_pokemon->afterimages[i].displayObject.lodFraction = 0x3C;
        active_pokemon->afterimages[i].displayObject.node.flags |= 1;
        Vec3f_SetComponentsDuplicate(&active_pokemon->afterimages[i].displayObject.scale, 1.0f, 1.0f, 1.0f);
        BattleAnim_Vec3fCopy(&active_pokemon->afterimages[i].displayObject.position, &active_pokemon->displayObject.position);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82109824; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82109824.s")
#endif

void BattleScene_ShowSecondaryModelsStaggeredFrame(ActivePokemon* active_pokemon) {
    s32 i;

    for (i = 0; i < 2; i++) {
        active_pokemon->afterimages[i].minimized = 0;
        active_pokemon->afterimages[i].displayObject.lodFraction = 0x41 - i * 4;
        active_pokemon->afterimages[i].displayObject.node.flags |= 1;

        ModelAnim_SetFrame(&active_pokemon->afterimages[i].displayObject, active_pokemon->displayObject.transformAnim.frameFixed >> 0x10);
        ModelAnim_SetAnimation(&active_pokemon->afterimages[i].displayObject, active_pokemon->displayObject.transformAnim.animationId);
        Vec3f_SetComponentsDuplicate(&active_pokemon->afterimages[i].displayObject.scale, 1.0f, 1.0f, 1.0f);
        BattleAnim_Vec3fCopy(&active_pokemon->afterimages[i].displayObject.position, &active_pokemon->displayObject.position);
        BattleAnim_Vec3sCopy(&active_pokemon->afterimages[i].displayObject.rotation, &active_pokemon->displayObject.rotation);
        BattleAnim_Vec3fCopy(&active_pokemon->afterimages[i].displayObject.scale, &active_pokemon->displayObject.scale);
    }
}

#ifdef NON_MATCHING
// Matches the ROM, but uses data data that is not placed in this file yet.
void BattleScene_UpdateSecondaryModelTrailPosition(ActivePokemon* pokemon, s16 new_position) {
    s32 i;
    f32 distance;
    s16 angle_x;
    s16 angle_y;
    UNUSED s32 pad;
    f32 eye[3] = { 0.2f, 0.25f, 0.3f };   // D_84384638
    f32 rate[3] = { 0.98f, 0.96f, 0.95f }; // D_84384644

    for (i = 0; i < 2; i++) {
        ModelAnim_SetFrame(&pokemon->afterimages[i].displayObject, pokemon->displayObject.transformAnim.frameFixed >> 0x10);
        ModelAnim_SetAnimation(&pokemon->afterimages[i].displayObject, pokemon->displayObject.transformAnim.animationId);
        Vec3f_CalculateDistanceAngles(&pokemon->displayObject.position, &pokemon->afterimages[i].displayObject.position, &distance, &angle_x, &angle_y);
        Camera_ComputeEyeFromAngles(&pokemon->displayObject.position, &pokemon->afterimages[i].displayObject.position, eye[i] * distance, angle_x, angle_y);
        BattleAnim_StepToS16(&pokemon->afterimages[i].displayObject.rotation.y, pokemon->displayObject.rotation.y, rate[i] * new_position);
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82109AF4.s")
#endif

void BattleScene_ResetParticipantModelFlags(ActivePokemon* active_pokemon) {
    BattleScene_SetParticipantModelTransform(active_pokemon, 0, 0);
}

void func_82109CAC(UNUSED ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    animated_pokemon->pokeBall.node.flags |= 1;
    if (animated_pokemon == sActivePokemon[0]) {
        Vec3f_SetComponentsDuplicate(&animated_pokemon->pokeBall.position, 35.0f, 50.0f, -250.0f);
    } else {
        Vec3f_SetComponentsDuplicate(&animated_pokemon->pokeBall.position, -35.0f, 50.0f, -250.0f);
    }
    BattleAnim_InitSwayOffset(animated_pokemon, 20.0f, 0x1FFE);
    animated_pokemon->modelTransformTimer++;
    animated_pokemon->pokeBall.node.renderFlags &= ~0x20;
    ModelAnim_SetFrame(&animated_pokemon->pokeBall, 0);
}

void func_82109D50(ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    if (animated_pokemon == sSide1ActivePokemon) {
        BattleAnim_UpdateSwayPhysicsToTarget(owner, animated_pokemon, 0, 0, 0x1FFE, 0x4440);
    } else {
        BattleAnim_UpdateSwayPhysicsToTarget(owner, animated_pokemon, 0, 0, 0x1FFE, 0x3BB8);
    }

    animated_pokemon->pokeBall.rotation.x += 5461;
    animated_pokemon->pokeBall.rotation.z += 3640;

    if (animated_pokemon->pokeBall.position.y < 0) {
        animated_pokemon->pokeBall.node.flags &= ~1;
        animated_pokemon->pokeBall.position.y = 0.0f;
        animated_pokemon->modelTransform.rotation.y = 0.0f;
        BattleScene_ResetParticipantModelFlags(animated_pokemon);
    }
}


void func_82109E0C(s32 arg0, s8 *arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg1, s32 *, 0x614);
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_82109CAC((ActivePokemon*)arg0, (ActivePokemon*)arg1);
        /* fallthrough */
    case 1:
        func_82109D50(arg0, arg1);
        return;
    }
}

void BattleAnim_PokeBallLandStart(UNUSED ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    Vec3f_SetComponentsDuplicate(&animated_pokemon->pokeBall.position, animated_pokemon->facingDirection * -150.0f, 100.0f, 0.0f);
    animated_pokemon->modelTransformTimer++;
    BattleAnim_InitSwayOffset(animated_pokemon, 0.0f, 16380);
    animated_pokemon->pokeBall.node.flags |= 1;
    animated_pokemon->pokeBall.node.renderFlags &= ~0x20;
    ModelAnim_SetFrame(&animated_pokemon->pokeBall, 0);
}

void BattleAnim_PokeBallLandContinue(ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    animated_pokemon->pokeBall.rotation.x += 5461;
    animated_pokemon->pokeBall.rotation.z += 3640;

    BattleAnim_UpdateSwayPhysicsToTarget(owner, animated_pokemon, 0.0f, 0.0f, NINETY_DEGREES, 0);

    if (animated_pokemon->pokeBall.position.y < 0) {
        animated_pokemon->pokeBall.rotation.x = 0;
        animated_pokemon->pokeBall.rotation.z = 0;
        if (animated_pokemon == sSide1ActivePokemon) {
            animated_pokemon->pokeBall.rotation.y = NINETY_DEGREES;
        } else {
            animated_pokemon->pokeBall.rotation.y = -NINETY_DEGREES;
        }
        animated_pokemon->modelTransform.rotation.y = 0.0f;
        animated_pokemon->pokeBall.position.y = 2.5f;
        BattleScene_ResetParticipantModelFlags(animated_pokemon);
    }
}

M2C_UNK func_82109E60();                         /* extern */
M2C_UNK func_82109EF8(s32, s8 *);                 /* extern */

void func_82109FA8(s32 arg0, s8 *arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg1, s32 *, 0x614);
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_82109E60((ActivePokemon*)arg0, (ActivePokemon*)arg1);
        /* fallthrough */
    case 1:
        func_82109EF8(arg0, arg1);
        return;
    }
}

void BattleAnim_FlyStart(UNUSED ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    Vec3f_SetComponentsDuplicate(&animated_pokemon->modelTransform, 0.0f, 0.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(&animated_pokemon->modelTransform.rotation, 0.0f, 0.0f, 0.0f);
    BattleAnim_InitSwayOffset(animated_pokemon, sModelTransformConstants[0], NINETY_DEGREES);
    BattleScene_ShowSecondaryModelsStaggeredFrame(animated_pokemon);
    animated_pokemon->modelTransformTimer++;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210A084; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210A084.s")
#endif

M2C_UNK func_82109FFC(s32);                         /* extern */
M2C_UNK func_8210A084(s32, s8 *);                 /* extern */

void func_8210A120(s32 arg0, s8 *arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg1, s32 *, 0x614);
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_82109FFC(arg0);
        /* fallthrough */
    case 1:
        func_8210A084(arg0, arg1);
        return;
    }
}

void BattleAnim_WaterfallStart(UNUSED ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    Vec3f_SetComponentsDuplicate(&animated_pokemon->modelTransform, 0.0f, 0.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(&animated_pokemon->modelTransform.rotation, 0.0f, 0.0f, 0.0f);
    BattleAnim_InitSwayOffset(animated_pokemon, sModelTransformConstants[0], NINETY_DEGREES);
    animated_pokemon->modelTransformTimer++;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210A1F4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210A1F4.s")
#endif

void BattleAnim_WaterfallEnd(UNUSED ActivePokemon* owner, UNUSED ActivePokemon* animated_pokemon) {
}

void BattleAnim_Waterfall(ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    switch (animated_pokemon->modelTransformTimer) {
        case 0:
            BattleAnim_WaterfallStart(owner, animated_pokemon);

        case 1:
            BattleAnim_WaterfallContinue(owner, animated_pokemon);
            break;

        case 2:
            BattleAnim_WaterfallEnd(owner, animated_pokemon);
            break;
    }
}

void func_8210A2F4(UNUSED ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    Vec3f_SetComponentsDuplicate(&animated_pokemon->modelTransform, 0.0f, 0.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(&animated_pokemon->modelTransform.rotation, 0.0f, 0.0f, 0.0f);
    BattleAnim_InitSwayOffset(animated_pokemon, sModelTransformConstants[0], 0x2AAA);
    animated_pokemon->modelTransformTimer++;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210A374; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210A374.s")
#endif

M2C_UNK func_8210A374(s32, s8 *);                 /* extern */

void func_8210A3DC(s32 arg0, s8 *arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg1, s32 *, 0x614);
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_8210A2F4((ActivePokemon*)arg0, (ActivePokemon*)arg1);
        /* fallthrough */
    case 1:
        func_8210A374(arg0, arg1);
        return;
    }
}

s32 BattleAnim_ApproachAngleAndCheckThreshold(ActivePokemon* pokemon, s16 phase, s16 camera_offset_scale) {
    pokemon->displayObject.rotation.y -= phase;

    if (phase > 0) {
        if ((camera_offset_scale >= pokemon->displayObject.rotation.y) && ((camera_offset_scale - phase) < pokemon->displayObject.rotation.y)) {
            return 1;
        }
    } else if ((pokemon->displayObject.rotation.y >= camera_offset_scale) && (pokemon->displayObject.rotation.y < (camera_offset_scale - phase))) {
        return 1;
    }

    return 0;
}

M2C_UNK func_821099CC(s8 *);                      /* extern */

void func_8210A4AC(s32 arg0, s8 *arg1) {
    func_821099CC(arg1);
    M2C_FIELD(arg1, s16 *, 0x602) = 0;
    M2C_FIELD(arg1, s16 *, 0x600) = 0;
    M2C_FIELD(arg1, s32 *, 0x61C) = 0;
    M2C_FIELD(arg1, s32 *, 0x614) = (s32) (M2C_FIELD(arg1, s32 *, 0x614) + 1);
}

s16 func_8000F1FC(s16, M2C_UNK, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK func_82109AF4(s8 *, s16);                 /* extern */
s32 func_8210A430(s32, s16, s16);                   /* extern */

void func_8210A4F0(s32 arg0, s8 *arg1) {
    M2C_FIELD(arg1, s16 *, 0x602) = func_8000F1FC(M2C_FIELD(arg1, s16 *, 0x602), 0x3330, 0x16C, 0x16C);
    if (func_8210A430(arg0, M2C_FIELD(arg1, s16 *, 0x602), (s16) (M2C_FIELD(arg1, s32 *, 0x60C) << 0xE)) != 0) {
        M2C_FIELD(arg1, s32 *, 0x61C) = (s32) (M2C_FIELD(arg1, s32 *, 0x61C) + 1);
    }
    func_82109AF4(arg1, M2C_FIELD(arg1, s16 *, 0x602));
    if (M2C_FIELD(arg1, s32 *, 0x61C) == 3) {
        M2C_FIELD(arg1, s32 *, 0x614) = (s32) (M2C_FIELD(arg1, s32 *, 0x614) + 1);
    }
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_SubmissionEnd(ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    f32 angle_offset = NINETY_DEGREES - owner->displayObject.rotation.y;
    f32 angle_offset_fractional;
    s16 new_phase;
    s32 done;
    
    angle_offset_fractional = (131072.0 - angle_offset) / 131072.0;
    if (angle_offset_fractional >= 1.0f) {
        angle_offset_fractional -= 1.0f;
    }
    
    new_phase = (animated_pokemon->oscillationPhase * angle_offset_fractional) * 0.8;
    if (new_phase < 3640) {
        new_phase = 3640;
    }
    done = BattleAnim_ApproachAngleAndCheckThreshold(owner, new_phase, animated_pokemon->facingDirection << 14);
    BattleScene_UpdateSecondaryModelTrailPosition(animated_pokemon, new_phase);

    if (done != 0) {
        owner->displayObject.rotation.y = animated_pokemon->facingDirection << 14;
        BattleScene_ResetParticipantModelFlags(animated_pokemon);
        BattleScene_HideParticipantSecondaryModels(animated_pokemon);
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210A584.s")
#endif

void func_8210A584(UNUSED ActivePokemon* owner, UNUSED ActivePokemon* animated_pokemon);
void func_8210A694(ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    switch (animated_pokemon->modelTransformTimer) {
        case 0:
            func_8210A4AC(owner, animated_pokemon);

        case 1:
            func_8210A4F0(owner, animated_pokemon);
            break;

        case 2:
            func_8210A584(owner, animated_pokemon);
            break;
    }
}

M2C_UNK func_821099CC(s8 *);                      /* extern */

void func_8210A700(s32 arg0, s8 *arg1) {
    func_821099CC(arg1);
    M2C_FIELD(arg1, s16 *, 0x602) = 0;
    M2C_FIELD(arg1, s16 *, 0x600) = 0;
    M2C_FIELD(arg1, s32 *, 0x61C) = 0;
    M2C_FIELD(arg1, s32 *, 0x614) = (s32) (M2C_FIELD(arg1, s32 *, 0x614) + 1);
}

s16 func_8000F1FC(s16, M2C_UNK, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK func_82109AF4(s8 *, s16);                 /* extern */
s32 func_8210A430(s32, s16, s16);                   /* extern */

void func_8210A744(s32 arg0, s8 *arg1) {
    M2C_FIELD(arg1, s16 *, 0x602) = func_8000F1FC(M2C_FIELD(arg1, s16 *, 0x602), 0x3FFC, 0x16C, 0x16C);
    if (func_8210A430(arg0, M2C_FIELD(arg1, s16 *, 0x602), (s16) (M2C_FIELD(arg1, s32 *, 0x60C) << 0xE)) != 0) {
        M2C_FIELD(arg1, s32 *, 0x61C) = (s32) (M2C_FIELD(arg1, s32 *, 0x61C) + 1);
    }
    func_82109AF4(arg1, M2C_FIELD(arg1, s16 *, 0x602));
    if (M2C_FIELD(arg1, s32 *, 0x61C) >= 3) {
        M2C_FIELD(arg1, s32 *, 0x614) = (s32) (M2C_FIELD(arg1, s32 *, 0x614) + 1);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210A7D8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210A7D8.s")
#endif

void func_8210A7D8(UNUSED ActivePokemon* owner, UNUSED ActivePokemon* animated_pokemon);
void func_8210A8CC(ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    switch (animated_pokemon->modelTransformTimer) {
        case 0:
            func_8210A700(owner, animated_pokemon);

        case 1:
            func_8210A744(owner, animated_pokemon);
            break;

        case 2:
            func_8210A7D8(owner, animated_pokemon);
            break;
    }
}

M2C_UNK func_8000D700(s32, M2C_UNK, s16, M2C_UNK);  /* extern */
M2C_UNK func_82107790(s8 *);                      /* extern */
M2C_UNK func_821099CC(s8 *);                      /* extern */

void func_8210A938(s32 arg0, s8 *arg1) {
    M2C_FIELD(arg1, s16 *, 0x602) = 0;
    M2C_FIELD(arg1, s16 *, 0x600) = 0;
    M2C_FIELD(arg1, s32 *, 0x61C) = 0;
    M2C_FIELD(arg1, f32 *, 0x5FC) = 0.0f;
    func_82107790(arg1);
    func_8000D700(arg0 + 0x1E, 0, (s16) (M2C_FIELD(arg1, s32 *, 0x60C) << 0xE), 0);
    func_821099CC(arg1);
    M2C_FIELD(arg1, s32 *, 0x614) = (s32) (M2C_FIELD(arg1, s32 *, 0x614) + 1);
}

void BattleAnim_AgilityContinue(ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    f32 magnitude;
    Vec3f zero_vector = { 0.0f, 0.0f, 0.0f }; // D_84384654

    BattleAnim_ApproachF(&animated_pokemon->oscillationAmplitude, 50.0f, 0.1f);
    animated_pokemon->oscillationPhase += 0xE38;
    magnitude = SINS(animated_pokemon->oscillationPhase) * animated_pokemon->oscillationAmplitude;
    BattleAnim_Vec3fSetPolarXZ(&zero_vector, magnitude, owner->displayObject.rotation.y);
    BattleScene_PositionParticipantModel(animated_pokemon);
    Vec3f_AddInPlace(&owner->displayObject.position, &zero_vector);
    BattleScene_UpdateSecondaryModelTrailPosition(animated_pokemon, 0);

    if (animated_pokemon->oscillationAmplitude > 49.0f) {
        animated_pokemon->modelTransformTimer++;
    }
}

void BattleAnim_AgilityEnd(ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    f32 magnitude;
    Vec3f zero_vector = { 0.0f, 0.0f, 0.0f };

    BattleAnim_ApproachF(&animated_pokemon->oscillationAmplitude, 0.0f, 0.1f);
    animated_pokemon->oscillationPhase += 3640;

    magnitude = SINS(animated_pokemon->oscillationPhase) * animated_pokemon->oscillationAmplitude;
    BattleAnim_Vec3fSetPolarXZ(&zero_vector, magnitude, owner->displayObject.rotation.y);

    BattleScene_PositionParticipantModel(animated_pokemon);
    Vec3f_AddInPlace(&owner->displayObject.position, &zero_vector);
    BattleScene_UpdateSecondaryModelTrailPosition(animated_pokemon, 0);

    if (animated_pokemon->oscillationAmplitude <= 0.5f) {
        BattleScene_PositionParticipantModel(animated_pokemon);
        Vec3s_SetComponents(&owner->displayObject.rotation, 0, animated_pokemon->facingDirection << 0xE, 0);
        BattleScene_ResetParticipantModelFlags(animated_pokemon);
        BattleScene_HideParticipantSecondaryModels(animated_pokemon);
    }
}

void func_8210A9B4(ActivePokemon* owner, ActivePokemon* animated_pokemon);
void func_8210AAA4(UNUSED ActivePokemon* owner, UNUSED ActivePokemon* animated_pokemon);
void func_8210ABC4(ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    switch (animated_pokemon->modelTransformTimer) {
        case 0:
            func_8210A938(owner, animated_pokemon);

        case 1:
            func_8210A9B4(owner, animated_pokemon);
            break;

        case 2:
            func_8210AAA4(owner, animated_pokemon);
            break;
    }
}

M2C_UNK func_8000D700(s32, M2C_UNK, s16, M2C_UNK);  /* extern */
M2C_UNK func_82107790(s8 *);                      /* extern */
M2C_UNK func_821094C0(s8 *);                      /* extern */

void func_8210AC30(s32 arg0, s8 *arg1) {
    func_821094C0(arg1);
    M2C_FIELD(arg1, s32 *, 0x608) = 0;
    func_82107790(arg1);
    func_8000D700(arg0 + 0x1E, 0, (s16) (M2C_FIELD(arg1, s32 *, 0x60C) << 0xE), 0);
    M2C_FIELD(arg1, s32 *, 0x614) = (s32) (M2C_FIELD(arg1, s32 *, 0x614) + 1);
}

void BattleAnim_DoubleTeamContinue(UNUSED ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    BattleScene_UpdateSecondaryModelOrbit(animated_pokemon);
    animated_pokemon->doubleTeamTimer++;
    if (animated_pokemon->doubleTeamTimer == 60) {
        BattleScene_ResetParticipantModelFlags(animated_pokemon);
        BattleScene_HideParticipantSecondaryModels(animated_pokemon);
    }
}

void BattleAnim_PokeBallThrow(ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    switch (animated_pokemon->modelTransformTimer) {
        case 0:
            BattleAnim_PokeBallThrowStart(owner, animated_pokemon);

        case 1:
            BattleAnim_PokeBallThrowContinue(owner, animated_pokemon);
            break;
    }
}

void BattleAnim_ResetOwnerFacingAndExitStatusIdle(ActivePokemon* arg0) {
    UNUSED s32 pad;
    CameraNode* sp18 = sBattleScene.scene->camera;

    BattleScene_PositionParticipantModel(arg0);
    Vec3s_SetComponents(&arg0->displayObject.rotation, 0, arg0->facingDirection << 0xE, 0);
    Vec3f_SetComponentsDuplicate(&sp18->view.upDirection, 0.0f, 1.0f, 0.0f);
    BattleScene_ResetParticipantModelFlags(arg0);
}

M2C_UNK func_8000D700(s32, M2C_UNK, s16, M2C_UNK);  /* extern */
M2C_UNK func_82107790(s8 *);                      /* extern */

void func_8210ADBC(s32 arg0, s8 *arg1) {
    M2C_FIELD(arg1, s16 *, 0x602) = 0;
    M2C_FIELD(arg1, s16 *, 0x604) = 0;
    M2C_FIELD(arg1, s16 *, 0x600) = 0;
    M2C_FIELD(arg1, s32 *, 0x61C) = 0;
    M2C_FIELD(arg1, f32 *, 0x5FC) = 0.0f;
    func_82107790(arg1);
    func_8000D700(arg0 + 0x1E, 0, (s16) (M2C_FIELD(arg1, s32 *, 0x60C) << 0xE), 0);
    M2C_FIELD(arg1, s32 *, 0x614) = (s32) (M2C_FIELD(arg1, s32 *, 0x614) + 1);
}

void BattleAnim_SeismicTossContinue(UNUSED ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    CameraNode* camera = sBattleScene.scene->camera;
    f32 normal_x;
    f32 normal_z;
    f32 flip_angle;
    f32 x;
    f32 y;
    f32 z;
    f32 norm;
    f32 normal_y;

    BattleAnim_StepToS16(&animated_pokemon->oscillationVelocityEasePhase, 1456, 60);
    BattleAnim_StepToS16(&animated_pokemon->oscillationAngularVelocity, -32768, animated_pokemon->oscillationVelocityEasePhase);

    x = camera->view.targetPosition.x - camera->view.eyePosition.x;
    y = camera->view.targetPosition.y - camera->view.eyePosition.y;
    z = camera->view.targetPosition.z - camera->view.eyePosition.z;

    norm = sqrtf(SQ(x) + SQ(y) + SQ(z));

    normal_x = x / norm;
    normal_y = y / norm;
    normal_z = z / norm;

    flip_angle = 1.0 - COSS(animated_pokemon->oscillationAngularVelocity);

    camera->view.upDirection.x = (flip_angle * normal_x * normal_y) - (SINS(animated_pokemon->oscillationAngularVelocity) * normal_z);
    camera->view.upDirection.y = COSS(animated_pokemon->oscillationAngularVelocity) + ((flip_angle * normal_y) * normal_y);
    camera->view.upDirection.z = (SINS(animated_pokemon->oscillationAngularVelocity) * normal_x) + ((flip_angle * normal_y) * normal_z);

    if (animated_pokemon->displayObject.position.y < 0.0f) {
        animated_pokemon->displayObject.position.y = 0.0f;
    }
}

void func_8210AE34(ActivePokemon* owner, ActivePokemon* animated_pokemon);
void func_8210AFB8(ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    switch (animated_pokemon->modelTransformTimer) {
        case 0:
            func_8210ADBC(owner, animated_pokemon);

        case 1:
            func_8210AE34(owner, animated_pokemon);
            break;
    }
}

M2C_UNK func_82109764(s8 *);                      /* extern */
M2C_UNK func_82109C88(s8 *);                      /* extern */

void func_8210B00C(s8 *arg0, s8 *arg1) {
    if (M2C_FIELD(arg0, f32 *, 0x34) != 1.0f) {
        func_82109C88(arg1);
        return;
    }
    func_82109764(arg1);
    M2C_FIELD(arg1, s32 *, 0x614) = (s32) (M2C_FIELD(arg1, s32 *, 0x614) + 1);
}

M2C_UNK func_8210942C(s32);                         /* extern */
s32 func_82109824(s32);                             /* extern */
M2C_UNK func_8210C1A8(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_8210B06C(s32 arg0, s32 arg1) {
    func_8210C1A8(arg0 + 0x30, 0x3F266666, 0x3D23D70A);
    func_8210C1A8(arg0 + 0x34, 0x3F266666, 0x3D23D70A);
    func_8210C1A8(arg0 + 0x38, 0x3F266666, 0x3D23D70A);
    if (func_82109824(arg1) != 0) {
        func_82109C88(arg1);
        func_8210942C(arg1);
    }
}

void func_8210B0FC(ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    switch (animated_pokemon->modelTransformTimer) {
        case 0:
            func_8210B00C(owner, animated_pokemon);

        case 1:
            func_8210B06C(owner, animated_pokemon);
            break;
    }
}

void func_8210B150(s32 arg0, s8 *arg1) {
    M2C_FIELD(arg1, s32 *, 0x614) = (s32) (M2C_FIELD(arg1, s32 *, 0x614) + 1);
}

void BattleAnim_WithdrawContinue(ActivePokemon* owner, UNUSED ActivePokemon* animated_pokemon) {
    owner->displayObject.scale.x = Math_StepToF(owner->displayObject.scale.x, 0.0f, 0.05f, 0.05f);
    owner->displayObject.scale.y = Math_StepToF(owner->displayObject.scale.y, 0.0f, 0.05f, 0.05f);
    owner->displayObject.scale.z = Math_StepToF(owner->displayObject.scale.z, 0.0f, 0.05f, 0.05f);

    if (owner->displayObject.scale.y <= 0.1) {
        Vec3f_SetComponentsDuplicate(&owner->displayObject.scale, 0.001f, 0.001f, 0.001f);
    }
}

void func_8210B164(ActivePokemon* owner, ActivePokemon* animated_pokemon);
void func_8210B22C(ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    switch (animated_pokemon->modelTransformTimer) {
        case 0:
            func_8210B150(owner, animated_pokemon);

        case 1:
            func_8210B164(owner, animated_pokemon);
            break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210B280; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210B280.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210B2C4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210B2C4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210B3F0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210B3F0.s")
#endif

void func_8210B2C4(ActivePokemon* owner, ActivePokemon* animated_pokemon);
void func_8210B3F0(UNUSED ActivePokemon* owner, UNUSED ActivePokemon* animated_pokemon);
void func_8210B280(UNUSED ActivePokemon* owner, ActivePokemon* animated_pokemon);
void func_8210B520(ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    switch (animated_pokemon->modelTransformTimer) {
        case 0:
            func_8210B280(owner, animated_pokemon);

        case 1:
            func_8210B2C4(owner, animated_pokemon);
            break;

        case 2:
            func_8210B3F0(owner, animated_pokemon);
            break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210B58C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210B58C.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_SquishHitReactionContinue(ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    BattleMonRuntime* runtime = &animated_pokemon->state.runtime;
    s16 angular_velocity;

    animated_pokemon->oscillationAngularVelocity += 0xCCC;
    angular_velocity = animated_pokemon->oscillationAngularVelocity;

    animated_pokemon->oscillationAmplitude = Math_StepToF(animated_pokemon->oscillationAmplitude, 0.0f, 0.02f, 0.02f);

    if (angular_velocity > 0) {
        angular_velocity *= -1;
    }

    if (runtime->scaleResize == 0) {
        owner->displayObject.scale.x = 1.0f - (SINS(angular_velocity) * animated_pokemon->oscillationAmplitude);
        owner->displayObject.scale.y = (SINS(angular_velocity) * animated_pokemon->oscillationAmplitude) + 1.0f;
        owner->displayObject.scale.z = 1.0f - (SINS(angular_velocity) * animated_pokemon->oscillationAmplitude);
    } else {
        owner->displayObject.scale.x = 0.8 - (SINS(angular_velocity) * animated_pokemon->oscillationAmplitude);
        owner->displayObject.scale.y = (SINS(angular_velocity) * animated_pokemon->oscillationAmplitude) + 0.8;
        owner->displayObject.scale.z = 0.8 - (SINS(angular_velocity) * animated_pokemon->oscillationAmplitude);
    }

    if (animated_pokemon->oscillationAmplitude <= 0.01f) {
        if (runtime->scaleResize == 0) {
            Vec3f_SetComponentsDuplicate(&owner->displayObject.scale, 1.0f, 1.0f, 1.0f);
        } else {
            Vec3f_SetComponentsDuplicate(&owner->displayObject.scale, 0.8f, 0.8f, 0.8f);
        }
        BattleScene_ResetParticipantModelFlags(animated_pokemon);
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210B5C8.s")
#endif

M2C_UNK func_8210B58C(s32);                         /* extern */
M2C_UNK func_8210B5C8(s32, s8 *);                 /* extern */

void func_8210B790(s32 arg0, s8 *arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg1, s32 *, 0x614);
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_8210B58C(arg0);
        /* fallthrough */
    case 1:
        func_8210B5C8(arg0, arg1);
        return;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210B7E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210B7E4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210B824; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210B824.s")
#endif

M2C_UNK func_8210B7E4(s32);                         /* extern */
M2C_UNK func_8210B824(s32, s8 *);                 /* extern */

void func_8210B9F8(s32 arg0, s8 *arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg1, s32 *, 0x614);
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_8210B7E4(arg0);
        /* fallthrough */
    case 1:
        func_8210B824(arg0, arg1);
        return;
    }
}

void func_8210BA4C(s32 arg0, s8 *arg1) {
    M2C_FIELD(arg1, s32 *, 0x61C) = 0;
    M2C_FIELD(arg1, s32 *, 0x614) = (s32) (M2C_FIELD(arg1, s32 *, 0x614) + 1);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210BA64; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210BA64.s")
#endif

void func_8210BA64(ActivePokemon* owner, ActivePokemon* animated_pokemon);
void func_8210BB28(ActivePokemon* owner, ActivePokemon* animated_pokemon) {
    switch (animated_pokemon->modelTransformTimer) {
        case 0:
            func_8210BA4C(owner, animated_pokemon);

        case 1:
            func_8210BA64(owner, animated_pokemon);
            break;
    }
}

void BattleAnim_DrawParticleNoop(UNUSED Particle* arg0, UNUSED CameraNode* arg1) {
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_PlayTransformInducingAnimation(s32 side_index) {
    ActivePokemon* owner = sActivePokemon[side_index];
    ActivePokemon* animated_pokemon = sActivePokemon[side_index];

    // Zero renumbers the transforms, so the cases call the Zero functions by address.
    switch (sActivePokemon[side_index]->modelTransformId) {
        case 0:
            BattleAnim_DrawParticleNoop((Particle*)owner, (CameraNode*)animated_pokemon);
            break;
        case 1:
            func_82109E0C((s32)owner, (s8*)animated_pokemon);
            break;
        case 2:
            func_82109FA8((s32)owner, (s8*)animated_pokemon);
            break;
        case 3:
            func_8210A120((s32)owner, (s8*)animated_pokemon);
            break;
        case 4:
            func_8210A694(owner, animated_pokemon);
            break;
        case 5:
            func_8210A8CC(owner, animated_pokemon);
            break;
        case 6:
            func_8210ABC4(owner, animated_pokemon);
            break;
        case 7:
            BattleAnim_PokeBallThrow(owner, animated_pokemon);
            break;
        case 8:
            func_8210AFB8(owner, animated_pokemon);
            break;
        case 9:
            func_8210B0FC(owner, animated_pokemon);
            break;
        case 10:
            func_8210BB28(owner, animated_pokemon);
            break;
        case 11:
            func_8210A3DC((s32)owner, (s8*)animated_pokemon);
            break;
        case 12:
            func_8210B22C(owner, animated_pokemon);
            break;
        case 13:
            func_8210B520(owner, animated_pokemon);
            break;
        case 14:
            BattleAnim_Waterfall(owner, animated_pokemon);
            break;
        case 15:
            func_8210B790((s32)owner, (s8*)animated_pokemon);
            break;
        case 16:
            func_8210B9F8((s32)owner, (s8*)animated_pokemon);
            break;
        default:
            BattleScene_ResetParticipantModelFlags(animated_pokemon);
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210BB88.s")
#endif
