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
/* TODO: decompile func_82109130; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82109130.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82109188; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82109188.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821092E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821092E4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210942C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210942C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821094C0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821094C0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821095B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821095B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82109764; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82109764.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_82109CAC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82109CAC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82109D50; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82109D50.s")
#endif

M2C_UNK func_82109CAC(s32);                         /* extern */
M2C_UNK func_82109D50(s32, s8 *);                 /* extern */

void func_82109E0C(s32 arg0, s8 *arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg1, s32 *, 0x614);
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_82109CAC(arg0);
        /* fallthrough */
    case 1:
        func_82109D50(arg0, arg1);
        return;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82109E60; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82109E60.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82109EF8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82109EF8.s")
#endif

M2C_UNK func_82109E60(s32);                         /* extern */
M2C_UNK func_82109EF8(s32, s8 *);                 /* extern */

void func_82109FA8(s32 arg0, s8 *arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg1, s32 *, 0x614);
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_82109E60(arg0);
        /* fallthrough */
    case 1:
        func_82109EF8(arg0, arg1);
        return;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82109FFC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82109FFC.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_8210A174; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210A174.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210A1F4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210A1F4.s")
#endif

void BattleAnim_WaterfallEnd(UNUSED ActivePokemon* owner, UNUSED ActivePokemon* animated_pokemon) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210A288; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210A288.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210A2F4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210A2F4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210A374; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210A374.s")
#endif

M2C_UNK func_8210A2F4(s32);                         /* extern */
M2C_UNK func_8210A374(s32, s8 *);                 /* extern */

void func_8210A3DC(s32 arg0, s8 *arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg1, s32 *, 0x614);
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_8210A2F4(arg0);
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
/* TODO: decompile func_8210A584; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210A584.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210A694; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210A694.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_8210A8CC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210A8CC.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_8210A9B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210A9B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210AAA4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210AAA4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210ABC4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210ABC4.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_8210AC9C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210AC9C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210ACF0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210ACF0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210AD44; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210AD44.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_8210AE34; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210AE34.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210AFB8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210AFB8.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_8210B0FC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210B0FC.s")
#endif

void func_8210B150(s32 arg0, s8 *arg1) {
    M2C_FIELD(arg1, s32 *, 0x614) = (s32) (M2C_FIELD(arg1, s32 *, 0x614) + 1);
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleAnim_WithdrawContinue(ActivePokemon* owner, UNUSED ActivePokemon* animated_pokemon) {
    owner->displayObject.scale.x = Math_StepToF(owner->displayObject.scale.x, 0.0f, 0.05f, 0.05f);
    owner->displayObject.scale.y = Math_StepToF(owner->displayObject.scale.y, 0.0f, 0.05f, 0.05f);
    owner->displayObject.scale.z = Math_StepToF(owner->displayObject.scale.z, 0.0f, 0.05f, 0.05f);

    if (owner->displayObject.scale.y <= 0.1) {
        Vec3f_SetComponentsDuplicate(&owner->displayObject.scale, 0.001f, 0.001f, 0.001f);
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210B164.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210B22C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210B22C.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_8210B520; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210B520.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210B58C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210B58C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210B5C8; signature not recovered. */
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

#ifdef NON_MATCHING
/* TODO: decompile func_8210BB28; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210BB28.s")
#endif

void BattleAnim_DrawParticleNoop(UNUSED Particle* arg0, UNUSED CameraNode* arg1) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210BB88; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210BB88.s")
#endif
