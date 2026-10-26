/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_343BA0.c. */

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

void func_8213436C(void);

extern s32 D_8219A760;
void func_821079E8(s32);

void BattleScene_FinalPresentationFrameActiveOwner(CameraNode* arg0) {
    f32 sp3C;

    func_821079E8(0x1FFE);
    BattleScene_SetCameraClipPlanes(arg0, 20.0f, 4000.0f);
    BattleAnim_GetOwnerDefaultAnchorPosition(sActivePokemon[D_8219A760], &sBattleScene.scene->unk_D0);
    sp3C = BattleScene_ScaleCameraDistance(sActivePokemon[D_8219A760], 3.5f, 300.0f);
    BattleScene_SetCameraAtFromAnchor(sActivePokemon[D_8219A760], arg0, sBattleScene.scene->unk_D0, 0, BattleScene_GetParticipantFacingAngle(sActivePokemon[D_8219A760]),
                  0.0f, 0.0f);
    BattleScene_SetCameraEyeFromAt(arg0, 0, BattleScene_GetParticipantFacingAngle(sActivePokemon[D_8219A760]), sp3C, 0.0f);

    if (sActivePokemon[0]) {}
    sBattleScene.scene->unk_20 += 1;
    if (D_8219A760) {}
}

void func_8213436C(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_82134374; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82134374.s")
#endif

void BattleScene_AllocateMemory(void) {
    sBattleScene.scene = main_pool_alloc(sizeof(BattleScene), 0);
    bzero(sBattleScene.scene, sizeof(BattleScene));
}
