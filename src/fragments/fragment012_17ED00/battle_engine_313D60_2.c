/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_313D60.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "geo_node.h"
#include "model_animation.h"
#include "text_system.h"
#include "audio_commands.h"
#include "matrix.h"
#include "memory.h"
#include "util.h"
extern unk_D_84390240 sBattleScene;
extern s32 pad_D_84390280;
extern s32 pad_D_84390290[4];

void BattleScene_UpdateCameraDefaultModeNoop(UNUSED CameraNode* arg0);
void BattleScene_UpdateCameraOwner0FramingModeNoop(UNUSED CameraNode* arg0);
void BattleScene_AvoidDegenerateCameraLookAt(CameraNode* arg0);
void BattleScene_TickCameraSubstate(CameraNode* arg0);
s32 BattleScene_Dispatch(s32 arg0, CameraNode* arg1);

void BattleScene_RunFinalPresentation(CameraNode* arg0, UNUSED ActivePokemon* arg1, UNUSED ActivePokemon* arg2);
void BattleScene_AllocateMemory(void);
void BattleScene_TickCameraSubstateDefault(CameraNode* arg0);
void BattleScene_TickCameraSubstateStripWipe(CameraNode* arg0);
void BattleScene_Update(CameraNode* arg0);

void BattleScene_UpdateCameraDefaultModeNoop(UNUSED CameraNode* arg0) {
}

void BattleScene_UpdateCameraOwner0FramingModeNoop(UNUSED CameraNode* arg0) {
}

void BattleScene_AvoidDegenerateCameraLookAt(CameraNode* arg0) {
    if (BattleAnim_Distance2D(arg0->view.targetPosition.x, arg0->view.targetPosition.z, arg0->view.eyePosition.x, arg0->view.eyePosition.z) < 0.0001f) {
        arg0->view.targetPosition.z += 0.001f;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82134560; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82134560.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821347E8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821347E8.s")
#endif

void BattleScene_TickCameraSubstate(CameraNode* arg0) {
    if (sBattleScene.scene->unk_2E == 0) {
        BattleScene_TickCameraSubstateDefault(arg0);
    } else {
        BattleScene_TickCameraSubstateStripWipe(arg0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82134ABC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82134ABC.s")
#endif

s32 BattleScene_Dispatch(s32 arg0, CameraNode* arg1) {
    switch (arg0) {
        case 0:
            BattleScene_AllocateMemory();
            break;

        case 1:
        case 2:
            BattleScene_Update(arg1);
            break;

        case 3:
            BattleScene_RunFinalPresentation(arg1, sActivePokemon[0], sActivePokemon[1]);
            break;
    }
    return sBattleScene.scene->unk_40;
}
