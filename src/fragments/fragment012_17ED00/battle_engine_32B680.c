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

#ifdef NON_MATCHING
/* TODO: decompile func_8211F588; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211F588.s")
#endif

s32 BattleScene_SkipIntroIfFainted(UNUSED ActivePokemon* arg0, CameraNode* arg1) {
    ActivePokemonState* ptr = &sActivePokemon[sBattleScene.scene->unk_2C]->state;

    if ((ptr->unk_2D == 0x10) || ((ptr->flags & 0x4000) != 0)) {
        BattleScene_SelectNextIntroCameraShot(arg1);
        return 1;
    }
    return 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8211F6B8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211F6B8.s")
#endif

extern Vec3f D_8218B630;
extern Vec3f D_8218B63C;

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

#ifdef NON_MATCHING
/* TODO: decompile func_8211F9C4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211F9C4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211FA34; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211FA34.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211FAC4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211FAC4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211FB54; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211FB54.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_82120418; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82120418.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212054C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212054C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212068C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212068C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821206F4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821206F4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82120A34; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82120A34.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_82120D94; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82120D94.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_8212116C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212116C.s")
#endif

s32 func_821217DC(M2C_UNK);                         /* extern */
extern s8 *D_8219A5A0;

void func_821211D4(s32 arg0) {
    if (func_821217DC(0x1B8) != 0) {
        M2C_FIELD(D_8219A5A0, s32 *, 0x20) = 0x1D;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8212120C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212120C.s")
#endif

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
