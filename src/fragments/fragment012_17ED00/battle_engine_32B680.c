/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_304060.c, src/fragments/battle_engine/battle_engine_32B680.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "model_animation.h"
#include "geo_render.h"
#include "gfx_buffer.h"
#include "matrix.h"
#include "math_util.h"

#include "fragments/battle_engine/battle_engine.h"
#include "model_animation.h"
#include "matrix.h"
typedef struct unk_D_843859E0 {
    /* 0x00 */ u8 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ f32 unk_0C;
} unk_D_843859E0;

#include "m2c_macros.h"

void func_8211F580(void);
void BattleScene_IntroCameraRollStepNoFov(CameraNode* arg0);

void BattleScene_SelectNextIntroCameraShot(CameraNode* arg0);

void func_8211F580(void) {
}

extern f32 D_FLT_8218935C[][4];
s32 func_8211F588(void) {
    if ((D_FLT_8218935C[M2C_FIELD(sActivePokemon[0], s16*, 0x1A) - 1][1] + D_FLT_8218935C[M2C_FIELD(sActivePokemon[1], s16*, 0x1A) - 1][1] <= 85.0f) &&
        (D_FLT_8218935C[M2C_FIELD(sActivePokemon[0], s16*, 0x1A) - 1][2] == 0.0f) &&
        (D_FLT_8218935C[M2C_FIELD(sActivePokemon[1], s16*, 0x1A) - 1][2] == 0.0f) &&
        (M2C_FIELD(sActivePokemon[0], f32*, 0x28) == 0.0f) &&
        (M2C_FIELD(sActivePokemon[1], f32*, 0x28) == 0.0f)) {
        return 1;
    }
    return 0;
}

s32 BattleScene_SkipIntroIfFainted(UNUSED ActivePokemon* arg0, CameraNode* arg1) {
    ActivePokemonState* ptr = &sActivePokemon[sBattleScene.scene->unk_2C]->state;

    if ((ptr->unk_2D == 0x10) || ((ptr->flags & 0x4000) != 0)) {
        BattleScene_SelectNextIntroCameraShot(arg1);
        return 1;
    }
    return 0;
}

extern Vec3f D_8218B630;
extern Vec3f D_8218B63C;
void BattleScene_IntroCameraStep0(CameraNode* arg0) {
    BattleScene_SetCameraClipPlanes(arg0, 20.0f, 4000.0f);
    BattleScene_ResetCameraFrameCounter();
    if (BattleScene_AreBothParticipantModelsCompact() != 0) {
        BattleScene_SetCameraAtFromPosition(arg0, D_8218B63C, 0, 0, 0.0f, 0.0f);
        BattleScene_SetCameraEyeAndStoreAngles(arg0, D_8218B63C, 0x5B0, 0, 750.0f, 0.0f);
    } else {
        BattleScene_SetCameraAtFromPosition(arg0, D_8218B630, 0, 0, 0.0f, 0.0f);
        BattleScene_SetCameraEyeAndStoreAngles(arg0, D_8218B630, 0x5B0, 0, 750.0f, 0.0f);
    }
    arg0->view.eyePosition.z *= 0.6;
    sBattleScene.scene->unk_20++;
}

void BattleScene_IntroCameraStep2(CameraNode* arg0) {
    BattleScene_SetCameraClipPlanes(arg0, 20.0f, 4000.0f);
    BattleScene_ResetCameraFrameCounter();
    if (BattleScene_AreBothParticipantModelsCompact() != 0) {
        BattleScene_SetCameraAtFromPosition(arg0, D_8218B63C, 0, 0, 0.0f, 0.0f);
        BattleScene_SetCameraEyeAndStoreAngles(arg0, D_8218B63C, 0x1A4E, 0, 1000.0f, 0.0f);
    } else {
        BattleScene_SetCameraAtFromPosition(arg0, D_8218B630, 0, 0, 0.0f, 0.0f);
        BattleScene_SetCameraEyeAndStoreAngles(arg0, D_8218B630, 0x1A4E, 0, 1000.0f, 0.0f);
    }
    sBattleScene.scene->unk_20++;
}

void func_821224F4(CameraNode*);
void func_82121D78(CameraNode*, f32, f32);
void func_8212187C(s32);
void func_821351F8(CameraNode*, ActivePokemon*);
void BattleScene_InitializeBattlePresentation(CameraNode* arg0) {
    func_821224F4(arg0);
    func_82121D78(arg0, 20.0f, 4000.0f);
    func_8212187C(0);
    func_821351F8(arg0, sActivePokemon[sBattleScene.scene->unk_2C]);
    sBattleScene.scene->unk_20++;
}

s32 func_8211F644(ActivePokemon*, CameraNode*);
void func_82104C68(ActivePokemon*, s32);
void func_8211FA34(CameraNode* arg0) {
    ActivePokemon* pokemon;

    func_821224F4(arg0);
    func_82121D78(arg0, 20.0f, 4000.0f);
    func_8212187C(0);
    pokemon = sActivePokemon[sBattleScene.scene->unk_2C];
    if (func_8211F644(pokemon, arg0) == 0) {
        func_821351F8(arg0, pokemon);
        func_82104C68(pokemon, 0x10);
        sBattleScene.scene->unk_20++;
    }
}

void func_8211FAC4(CameraNode* arg0) {
    ActivePokemon* pokemon;

    func_821224F4(arg0);
    func_82121D78(arg0, 20.0f, 4000.0f);
    func_8212187C(1);
    pokemon = sActivePokemon[sBattleScene.scene->unk_2C];
    if (func_8211F644(pokemon, arg0) == 0) {
        func_821351F8(arg0, pokemon);
        func_82104C68(pokemon, 0x10);
        sBattleScene.scene->unk_20++;
    }
}

f32 func_82107EC8(ActivePokemon*);
void func_8212239C(ActivePokemon*, CameraNode*);
void func_8211FB54(CameraNode* arg0) {
    UNUSED s32 pad;
    f32 dist;
    UNUSED s32 pad2;
    s16 angle;
    ActivePokemon* pokemon;

    func_821224F4(arg0);
    func_82121D78(arg0, 20.0f, 4000.0f);
    func_8212187C(0);
    pokemon = sActivePokemon[sBattleScene.scene->unk_2C];
    if (func_8211F644(pokemon, arg0) == 0) {
        func_82104C68(pokemon, 0x10);
        BattleAnim_GetOwnerDefaultAnchorPosition(pokemon, &sBattleScene.scene->unk_D0);
        dist = BattleScene_ScaleCameraDistance(pokemon, 3.5f, 300.0f);
        angle = BattleScene_GetParticipantFacingAngle(pokemon);
        BattleScene_SetCameraAtFromPosition(arg0, sBattleScene.scene->unk_D0, 0, angle, 0.0f, func_82107EC8(pokemon) * 1.5f);
        BattleScene_SetCameraEyeFromPosition(arg0, sBattleScene.scene->unk_D0, 0, BattleScene_GetParticipantFacingAngle(pokemon), dist, 0.0f);
        func_8212239C(pokemon, arg0);
        sBattleScene.scene->unk_20++;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8211FCC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211FCC8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211FF08; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211FF08.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82120134; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82120134.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821202AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821202AC.s")
#endif

void func_82120418(CameraNode* arg0) {
    ActivePokemon* ap;

    BattleScene_ClearCameraOffsetVectors();
    ap = sActivePokemon[sBattleScene.scene->unk_2C];
    if (BattleScene_SkipIntroIfFainted(ap, arg0) == 0) {
        BattleScene_EnterStateRow(ap, 0x10);
        BattleAnim_GetOwnerDefaultAnchorPosition(ap, &sBattleScene.scene->unk_D0);
        sBattleScene.scene->unk_74 = BattleScene_ScaleCameraDistance(ap, 8.0f, 300.0f);
        BattleScene_SetCameraAtFromAnchor(ap, arg0, sBattleScene.scene->unk_D0, 0, BattleScene_GetParticipantFacingAngle(ap), 0.0f, 0);
        BattleScene_SetCameraEyeFromPosition(arg0, sBattleScene.scene->unk_D0, 0, BattleScene_GetParticipantFacingAngle(ap), sBattleScene.scene->unk_74, 0.0f);
        sBattleScene.scene->unk_20 += 1;
    }
}

void func_8212239C(ActivePokemon*, CameraNode*);
void func_8212054C(CameraNode* arg0) {
    ActivePokemon* ap;

    BattleScene_ClearCameraOffsetVectors();
    ap = sActivePokemon[sBattleScene.scene->unk_2C];
    if (BattleScene_SkipIntroIfFainted(ap, arg0) == 0) {
        BattleScene_EnterStateRow(ap, 0x10);
        BattleAnim_GetOwnerDefaultAnchorPosition(ap, &sBattleScene.scene->unk_D0);
        sBattleScene.scene->unk_74 = BattleScene_ScaleCameraDistance(ap, 3.5f, 300.0f);
        BattleScene_SetCameraAtFromAnchor(ap, arg0, sBattleScene.scene->unk_D0, 0, BattleScene_GetParticipantFacingAngle(ap), 0.0f, 0);
        BattleScene_SetCameraEyeFromPosition(arg0, sBattleScene.scene->unk_D0, 0, BattleScene_GetParticipantFacingAngle(ap), sBattleScene.scene->unk_74, 0.0f);
        func_8212239C(ap, arg0);
        sBattleScene.scene->unk_20 += 1;
    }
}

void func_8212054C(CameraNode*);
s32 func_8212068C(UNUSED s32 arg0, CameraNode* arg1) {
    ActivePokemon* p = sActivePokemon[sBattleScene.scene->unk_2C];

    if ((p->displayObject.objectType == 0x71) || (p->displayObject.objectType == 0x79)) {
        sBattleScene.scene->unk_20 = 0x16;
        func_8212054C(arg1);
        return 1;
    }
    return 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_821206F4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821206F4.s")
#endif

extern const f64 D_DBL_821960A0;
void BattleScene_IntroCameraRollStep(CameraNode* arg0) {
    if (BattleScene_ApproachCameraRoll(arg0, 0xB6, 0x78DC) != 0) {
        BattleScene_SelectNextIntroCameraShot(arg0);
    } else {
        arg0->view.eyePosition.z *= D_DBL_821960A0;
    }
}

void BattleScene_IntroCameraRollStepNoFov(CameraNode* arg0) {
    if (BattleScene_ApproachCameraRoll(arg0, 0xB6, 0x78DC) != 0) {
        BattleScene_SelectNextIntroCameraShot(arg0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82120AC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82120AC8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82120BB8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82120BB8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82120C44; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82120C44.s")
#endif

void func_821206F4(CameraNode*);
s32 func_82135734(CameraNode*, ActivePokemon*);
s32 func_821217DC(M2C_UNK);
void func_82120D94(CameraNode* arg0) {
    ActivePokemonState* st = &sActivePokemon[sBattleScene.scene->unk_2C]->state;

    if ((st->unk_2D == 0x10) || (st->flags & 0x4000)) {
        func_821206F4(arg0);
    } else if (sBattleScene.scene->unk_1C == 9) {
        if (func_82135734(arg0, sActivePokemon[sBattleScene.scene->unk_2C]) != 0) {
            func_821206F4(arg0);
        }
    } else if ((func_821217DC(0x5A) != 0) || (func_82135734(arg0, sActivePokemon[sBattleScene.scene->unk_2C]) != 0)) {
        func_821206F4(arg0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82120E70; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82120E70.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82120FB0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82120FB0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821210E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821210E4.s")
#endif

s32 func_82135734(CameraNode*, ActivePokemon*);
void func_8212188C(void);
void func_8212116C(CameraNode* arg0) {
    func_82135734(arg0, sActivePokemon[sBattleScene.scene->unk_2C]);
    if (M2C_FIELD(sBattleScene.scene, s8*, 1) == 0x10) {
        func_8212188C();
        sBattleScene.scene->unk_20 = 0x1B;
    }
}

s32 func_821217DC(M2C_UNK);                         /* extern */
extern s8 *D_8219A5A0;

void func_821211D4(s32 arg0) {
    if (func_821217DC(0x1B8) != 0) {
        M2C_FIELD(D_8219A5A0, s32 *, 0x20) = 0x1D;
    }
}

/*
 * func_8212120C
 *
 * Sets the camera's clip planes to 20.0f (near) and 4000.0f (far), the same
 * call that BattleScene_InitializeBattlePresentation makes.  Then, if any of
 * the bits in 0xE03F is set in the halfword at offset 8 of the structure that
 * D_800603C0 points to, calls func_800387BC(1) and stores 3 at offset 0x40 of
 * the structure that D_8219A5A0 points to.  What those two structures are is
 * not established from this function alone.
 */
extern u8* D_800603C0;
void func_800387BC(s32 arg0);

void func_8212120C(CameraNode* arg0) {
    func_82121D78(arg0, 20.0f, 4000.0f);
    if (*(u16*)(D_800603C0 + 8) & 0xE03F) {
        func_800387BC(1);
        M2C_FIELD(D_8219A5A0, s32 *, 0x40) = 3;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82121260; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82121260.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82121434; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82121434.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82121604; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82121604.s")
#endif
