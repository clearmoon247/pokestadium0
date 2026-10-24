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

void Battle_GetTertiaryOwnerBonePositionUnused(Vec3f* arg0);
void BattleAnim_EffectSecondaryOwnerAnchorPosition(Vec3f* arg0);
void BattleAnim_EffectTertiaryOwnerBonePosition(Vec3f* arg0);
void BattleAnim_EffectSecondaryOwnerBonePosition(Vec3f* arg0);
f32 BattleAnim_EffectTertiaryOwnerModelScale(void);
f32 BattleAnim_EffectSecondaryOwnerModelScale(void);
void BattleAnim_ResetSharedEffectMatrix(void);
void BattleAnim_Effect5RibbonMesh_Init(void);
s32 BattleAnim_Effect5RibbonMesh_Update(void);
void BattleAnim_Effect5RibbonMesh_Draw(void);
void BattleAnim_EndEffect1RibbonMesh_Init(void);
s32 BattleAnim_EndEffect1RibbonMesh_Update(void);
void BattleAnim_EndEffect1RibbonMesh_Draw(void);
void BattleAnim_EndEffect19RibbonMesh_Init(void);
s32 BattleAnim_EndEffect19RibbonMesh_Update(void);
void BattleAnim_EndEffect19RibbonMesh_Draw(void);
void BattleAnim_Effect54RibbonMesh_Init(void);
s32 BattleAnim_Effect54RibbonMesh_Update(void);
void BattleAnim_Effect54RibbonMesh_Draw(void);
void BattleAnim_StartEffect34TerrainGrid_Init(void);
s32 BattleAnim_StartEffect34TerrainGrid_Update(void);
void BattleAnim_StartEffect34TerrainGrid_Draw(void);

void Battle_GetTertiaryOwnerBonePositionUnused(Vec3f* arg0) {
    BattleAnim_GetTertiaryOwnerBonePosition(arg0);
}

void BattleAnim_EffectSecondaryOwnerAnchorPosition(Vec3f* arg0) {
    BattleAnim_GetSecondaryOwnerAnchorPosition(arg0);
}

void BattleAnim_EffectTertiaryOwnerBonePosition(Vec3f* arg0) {
    BattleAnim_GetTertiaryOwnerBonePosition(arg0);
}

void BattleAnim_EffectSecondaryOwnerBonePosition(Vec3f* arg0) {
    BattleAnim_GetSecondaryOwnerBonePosition(arg0);
}

f32 BattleAnim_EffectTertiaryOwnerModelScale(void) {
    return BattleAnim_GetTertiaryOwnerModelScale();
}

f32 BattleAnim_EffectSecondaryOwnerModelScale(void) {
    return BattleAnim_GetSecondaryOwnerModelScale();
}

#ifdef NON_MATCHING
/* TODO: decompile func_8216DB20; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216DB20.s")
#endif

void BattleAnim_ResetSharedEffectMatrix(void) {
    guRotateRPY(&D_8219CAC8, 0.0f, 0.0f, 0.0f);
}

void BattleAnim_Effect5RibbonMesh_Init(void) {
    Vec3f sp24;
    f32 sp20;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerBonePosition(&sp24);
    sp20 = BattleAnim_EffectSecondaryOwnerModelScale();
    RibbonMesh_Init();
    RibbonMesh_Spawn(sp24.x, sp24.y, sp24.z, 40.0f, sp20, 0);
}

s32 BattleAnim_Effect5RibbonMesh_Update(void) {
    return RibbonMesh_UpdatePool();
}

void BattleAnim_Effect5RibbonMesh_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = RibbonMesh_DrawPool(gDisplayListHead);
}

void BattleAnim_EndEffect1RibbonMesh_Init(void) {
    Vec3f sp24;
    f32 sp20;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerBonePosition(&sp24);
    sp20 = BattleAnim_EffectTertiaryOwnerModelScale();
    RibbonMesh_Init();
    RibbonMesh_Spawn(sp24.x, sp24.y, sp24.z, 40.0f, sp20, 1);
}

s32 BattleAnim_EndEffect1RibbonMesh_Update(void) {
    return RibbonMesh_UpdatePool();
}

void BattleAnim_EndEffect1RibbonMesh_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = RibbonMesh_DrawPool(gDisplayListHead);
}

void BattleAnim_EndEffect19RibbonMesh_Init(void) {
    Vec3f sp24;
    f32 sp20;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerBonePosition(&sp24);
    sp20 = BattleAnim_EffectTertiaryOwnerModelScale();
    RibbonMesh_Init();
    RibbonMesh_Spawn(sp24.x, sp24.y, sp24.z, 40.0f, sp20, 0);
    RibbonMesh_Spawn(sp24.x, sp24.y, sp24.z, 38.0f, sp20, 1);
}

s32 BattleAnim_EndEffect19RibbonMesh_Update(void) {
    return RibbonMesh_UpdatePool();
}

void BattleAnim_EndEffect19RibbonMesh_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = RibbonMesh_DrawPool(gDisplayListHead);
}

void BattleAnim_Effect54RibbonMesh_Init(void) {
    Vec3f sp24;
    f32 sp20;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerBonePosition(&sp24);
    sp20 = BattleAnim_EffectSecondaryOwnerModelScale();
    RibbonMesh_Init();
    RibbonMesh_Spawn(sp24.x, sp24.y, sp24.z, 40.0f, sp20, 0);
    RibbonMesh_Spawn(sp24.x, sp24.y, sp24.z, 38.0f, sp20, 1);
}

s32 BattleAnim_Effect54RibbonMesh_Update(void) {
    return RibbonMesh_UpdatePool();
}

void BattleAnim_Effect54RibbonMesh_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = RibbonMesh_DrawPool(gDisplayListHead);
}

void BattleAnim_StartEffect34TerrainGrid_Init(void) {
    Vec3f sp1C;

    BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp1C);
    BattleAnim_ResetSharedEffectMatrix();

    if (sp1C.x < 0.0) {
        TerrainGrid_Init(1, 0, 0x4650);
    } else {
        TerrainGrid_Init(-1, 0, 0x4650);
    }
}

s32 BattleAnim_StartEffect34TerrainGrid_Update(void) {
    return TerrainGrid_Update();
}

void BattleAnim_StartEffect34TerrainGrid_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = TerrainGrid_Draw(gDisplayListHead);
}
