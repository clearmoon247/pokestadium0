/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_343BA0.c, src/fragments/ekans_game/ekans_game.c. */

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

#include "fragments/ekans_game/ekans_game.h"
#include "geo_render.h"
#include "model_animation.h"
#include "display_object_textures.h"
#include "model_renderer.h"
#include "graphics_textures.h"
#include "ui_graphics.h"
#include "text_system.h"
#include "jpeg_stream.h"
#include "audio_sound_state.h"
#include "audio_sfx.h"
#include "audio_channel.h"
#include "audio_loop_point.h"
#include "audio_commands_category2.h"
#include "audio_category_fade.h"
#include "gfx_buffer.h"
#include "gfx_rect.h"
#include "fragments/widget_toolkit/widget_toolkit.h"
#include "fragments/particle_math/particle_math.h"
#include "memory.h"
#include "stage_loader.h"
#include "geo_layout.h"
typedef struct ActiveDiglettInfo {
    /* 0x00 */ s16 diglettId;
    /* 0x02 */ s16 state;
    /* 0x04 */ s16 timer;
    /* 0x06 */ s16 unk_06; //	0
    /* 0x08 */ s16 gotHoop;
    /* 0x0A */ s16 unk_0A; //	0
    /* 0x0C */ s16 collidingActorId;
} ActiveDiglettInfo;
typedef struct ActorOriginPosition {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ char unk0C[0x6];
    /* 0x12 */ s16 unk_12;
    /* 0x12 */ s16 unk_14;
} ActorOriginPosition;
extern MiniActor miniDigletts[9];
extern MiniActor miniDiglettHoles[9];
extern MiniActor miniEkanses[4];
extern ActiveDiglettInfo activeDigletts[3];
extern s16 ekansMinigameCountdownStarted;
extern u32 redDiglettTileTexture[];
extern u32 yellowDiglettTileTexture[];
extern u32 blueDiglettTileTexture[];
extern u32 floorTexture1[];
extern u32 floorTexture2[];
extern u32 sceneDecorationTextureBlue[];
extern u32 sceneDecorationTextureGreen[];
extern u32 sceneDecorationTextureRed[];
extern u32 sceneDecorationTextureYellow[];
extern unk_D_86002F34_018 sceneTextures[];
extern Vtx sceneGeometry_1[];
extern Vtx sceneGeometry_2[];
extern Vtx sceneGeometry_3[];
extern Vtx sceneGeometry_4[];
extern Vtx sceneGeometry_5[];
extern Vtx sceneGeometry_6[];
extern Vtx sceneGeometry_7[];
extern Vtx sceneGeometry_8[];
extern Vtx sceneGeometry_9[];
extern Vtx sceneGeometry_10[];
extern Vtx sceneGeometry_11[];
extern Vtx sceneGeometry_12[];
extern Vtx sceneGeometry_13[];
extern u32 ekansShadowTexture[];
extern MiniActor* miniDiglettPtr;
extern MiniActor* miniDiglettHolePtr;
extern MiniActor* miniEkansPtr;
extern s16 miniEkansDifficulties[4][4];
extern ActorOriginPosition skansActorInfo[];
extern ActorOriginPosition diglettActorInfo[];
extern s16 playerGUIScoreXPositions[];
extern Color_RGB8 playerColors[];

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
void func_8216E0B0(void);
s32 BattleAnim_EndEffect16_CompleteImmediately(void);
void func_8216E0C0(void);
void BattleAnim_StartEffect19Radial20_Init(void);
s32 BattleAnim_StartEffect19Radial20_Update(void);
void BattleAnim_StartEffect19Radial20_Draw(void);
s32 BattleAnim_EndEffect9Radial20_Update(void);
void BattleAnim_EndEffect9Radial20_Draw(void);
void BattleAnim_StartEffect7TexturedRibbonSheet_Init(void);
s32 BattleAnim_StartEffect7TexturedRibbonSheet_Update(void);
void BattleAnim_StartEffect7TexturedRibbonSheet_Draw(void);
void BattleAnim_StartEffect33Radial20_Init(void);
s32 BattleAnim_StartEffect33Radial20_Update(void);
void BattleAnim_StartEffect33Radial20_Draw(void);
s32 BattleAnim_EndEffect32Radial20_Update(void);
void BattleAnim_EndEffect32Radial20_Draw(void);
s32 BattleAnim_EndEffect33Radial20_Update(void);
void BattleAnim_EndEffect33Radial20_Draw(void);
void BattleAnim_StartEffect98Radial20_Init(void);
s32 BattleAnim_StartEffect98Radial20_Update(void);
void BattleAnim_StartEffect98Radial20_Draw(void);
void BattleAnim_StartEffect11Trail50Alt_Init(void);
s32 BattleAnim_StartEffect11Trail50Alt_Update(void);
void BattleAnim_StartEffect11Trail50Alt_Draw(void);
void BattleAnim_StartEffect57Trail50_Init(void);
s32 BattleAnim_StartEffect57Trail50_Update(void);
void BattleAnim_StartEffect57Trail50_Draw(void);
void BattleAnim_StartEffect42Trail40_Init(void);
s32 BattleAnim_StartEffect42Trail40_Update(void);
void BattleAnim_StartEffect42Trail40_Draw(void);
void BattleAnim_StartEffect43Trail40Variant_Init(void);
s32 BattleAnim_StartEffect43Trail40Variant_Update(void);
void BattleAnim_StartEffect43Trail40Variant_Draw(void);
void BattleAnim_StartEffect44Trail40GridAlt_Init(void);
s32 BattleAnim_StartEffect44Trail40GridAlt_Update(void);
void BattleAnim_StartEffect44Trail40GridAlt_Draw(void);
void BattleAnim_StartEffect45FourStreamTrail_Init(void);
void BattleAnim_StartEffect45FourStreamTrail_Draw(void);
void BattleAnim_StartEffect62OwnerLinkedFourStream_Init(void);
s32 BattleAnim_StartEffect62OwnerLinkedFourStream_Update(void);
void BattleAnim_StartEffect62OwnerLinkedFourStream_Draw(void);
void BattleAnim_StartEffect67OwnerAnchoredFourStream_Init(void);
s32 BattleAnim_StartEffect67OwnerAnchoredFourStream_Update(void);
void BattleAnim_StartEffect67OwnerAnchoredFourStream_Draw(void);
void BattleAnim_StartEffect78Radial20_Init(void);
s32 BattleAnim_StartEffect78Radial20_Update(void);
void BattleAnim_StartEffect78Radial20_Draw(void);
void BattleAnim_StartEffect26DoubleTextureTrail_Seed(void);
void BattleAnim_StartEffect26DoubleTextureTrail_Init(void);
s32 BattleAnim_StartEffect26DoubleTextureTrail_Update(void);
void BattleAnim_StartEffect26DoubleTextureTrail_Draw(void);
void BattleAnim_StartEffect47SixSlotTrail_Seed(void);
void BattleAnim_StartEffect47SixSlotTrail_Init(void);
s32 BattleAnim_StartEffect47SixSlotTrail_Update(void);
void BattleAnim_StartEffect47SixSlotTrail_Draw(void);
void BattleAnim_StartEffect4DoubleTextureTrail_Seed(void);
void BattleAnim_StartEffect4DoubleTextureTrail_Init(void);
s32 BattleAnim_StartEffect4DoubleTextureTrail_Update(void);
void BattleAnim_StartEffect4DoubleTextureTrail_Draw(void);
void BattleAnim_StartEffect77DoubleTextureTrail_Seed(void);
void BattleAnim_StartEffect77DoubleTextureTrail_Init(void);
s32 BattleAnim_StartEffect77DoubleTextureTrail_Update(void);
void BattleAnim_StartEffect77DoubleTextureTrail_Draw(void);
void BattleAnim_StartEffect70DoubleTextureTrail_Seed(void);
void BattleAnim_StartEffect70DoubleTextureTrail_Init(void);
s32 BattleAnim_StartEffect70DoubleTextureTrail_Update(void);
void BattleAnim_StartEffect70DoubleTextureTrail_Draw(void);
void BattleAnim_StartEffect39DoubleTextureTrail_Seed(void);
void BattleAnim_StartEffect39SixSlotTrail_Seed(void);
void BattleAnim_StartEffect39CombinedTrail_Init(void);
s32 BattleAnim_StartEffect39CombinedTrail_Update(void);
void BattleAnim_StartEffect39CombinedTrail_Draw(void);

void BattleAnim_CalcVectorAtToDm(f32* arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5);
void BattleAnim_StartEffect19Radial20_EmitVariantD(void);
void BattleAnim_StartEffect7TexturedRibbonSheet_Emit(void);
void BattleAnim_StartEffect33Radial20_EmitVariantC(void);
void BattleAnim_StartEffect98Radial20_EmitVariantD(void);
void BattleAnim_StartEffect78Radial20_EmitVariantA(void);

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

void func_8216E0B0(void) {
}

s32 BattleAnim_EndEffect16_CompleteImmediately(void) {
    return -1;
}

void func_8216E0C0(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_8216E0C8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216E0C8.s")
#endif

void BattleAnim_StartEffect19Radial20_Init(void) {
    D_8219CB0E = 0;
    BattleAnim_ResetSharedEffectMatrix();
    Radial20_ResetPool();
    BattleAnim_StartEffect19Radial20_EmitVariantD();
}

s32 BattleAnim_StartEffect19Radial20_Update(void) {
    D_8219CB0E++;
    if (D_8219CB0E >= 0xB5) {
        return -1;
    }

    if ((D_8219CB0E < 0x78) && ((D_8219CB0E % 7) == 0)) {
        BattleAnim_StartEffect19Radial20_EmitVariantD();
    }
    return Radial20_IsComplete();
}

void BattleAnim_StartEffect19Radial20_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Radial20_Draw(gDisplayListHead);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8216E340; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216E340.s")
#endif

s32 BattleAnim_EndEffect9Radial20_Update(void) {
    return Radial20_Update();
}

void BattleAnim_EndEffect9Radial20_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Strip400_Draw(gDisplayListHead);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8216E428; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216E428.s")
#endif

void BattleAnim_StartEffect7TexturedRibbonSheet_Init(void) {
    D_8219CB10 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    TexturedRibbonSheet_Init();
    BattleAnim_StartEffect7TexturedRibbonSheet_Emit();
}

s32 BattleAnim_StartEffect7TexturedRibbonSheet_Update(void) {
    D_8219CB10++;
    if (D_8219CB10 >= 0x709) {
        return -1;
    }

    if ((D_8219CB10 < 0x6EA) && ((D_8219CB10 % 3) == 0)) {
        BattleAnim_StartEffect7TexturedRibbonSheet_Emit();
    }

    return TexturedRibbonSheet_IsComplete();
}

void BattleAnim_StartEffect7TexturedRibbonSheet_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = TexturedRibbonSheet_Draw(gDisplayListHead);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8216E680; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216E680.s")
#endif

void BattleAnim_StartEffect33Radial20_Init(void) {
    D_8219CB12 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    Radial20_ResetPool();
    BattleAnim_StartEffect33Radial20_EmitVariantC();
}

s32 BattleAnim_StartEffect33Radial20_Update(void) {
    D_8219CB12++;
    if (D_8219CB12 >= 0xB5) {
        return -1;
    }

    if ((D_8219CB12 < 0x78) && ((D_8219CB12 % 7) == 0)) {
        BattleAnim_StartEffect33Radial20_EmitVariantC();
    }

    return Radial20_IsComplete();
}

void BattleAnim_StartEffect33Radial20_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Radial20_Draw(gDisplayListHead);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8216E930; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216E930.s")
#endif

s32 BattleAnim_EndEffect32Radial20_Update(void) {
    return Radial20_Update();
}

void BattleAnim_EndEffect32Radial20_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Strip400_Draw(gDisplayListHead);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8216EA20; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216EA20.s")
#endif

s32 BattleAnim_EndEffect33Radial20_Update(void) {
    return Radial20_Update();
}

void BattleAnim_EndEffect33Radial20_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Strip400_Draw(gDisplayListHead);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8216EB10; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216EB10.s")
#endif

void BattleAnim_StartEffect98Radial20_Init(void) {
    D_8219CB16 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    Radial20_ResetPool();
    BattleAnim_StartEffect98Radial20_EmitVariantD();
}

s32 BattleAnim_StartEffect98Radial20_Update(void) {
    D_8219CB16++;
    if (D_8219CB16 >= 0xB5) {
        return -1;
    }

    if ((D_8219CB16 < 0x78) && ((D_8219CB16 % 7) == 0)) {
        BattleAnim_StartEffect98Radial20_EmitVariantD();
    }

    return Radial20_IsComplete();
}

void BattleAnim_StartEffect98Radial20_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Radial20_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect11Trail50Alt_Init(void) {
    D_8219CB18 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    Trail50EffectAlt_Init();
}

s32 BattleAnim_StartEffect11Trail50Alt_Update(void) {
    UNUSED s32 pad[1];
    Vec3f sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    UNUSED s32 pad2[2];
    f32 var_fv0;
    f32 sp44;

    D_8219CB18++;
    if (!(D_8219CB18 & 1)) {
        sp44 = BattleAnim_EffectSecondaryOwnerModelScale();
        BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp60);
        sp5C = (((guRandom() % 50) - 0x19) * sp44) + sp60.x;
        sp58 = (((guRandom() % 60) - 0x1E) * sp44) + sp60.y;
        sp54 = (((guRandom() % 50) - 0x19) * sp44) + sp60.z;
        var_fv0 = 10.0f;
        if (sp5C > 0.0) {
            var_fv0 = -var_fv0;
        }
        Trail50EffectAlt_Start(sp5C, sp58, sp54, var_fv0, 0.0f, 0.0f, 0xFF, 0xFF, 0xFF, 0x64, 0.3f, 1.0f, 4.0f, 0x1E);
    }
    Trail50EffectAlt_IsComplete();
    return 0;
}

void BattleAnim_StartEffect11Trail50Alt_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Trail50EffectAlt_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect57Trail50_Init(void) {
    D_8219CB1A = 0;
    BattleAnim_ResetSharedEffectMatrix();
    Trail50Effect_Init();
}

s32 BattleAnim_StartEffect57Trail50_Update(void) {
    UNUSED s32 pad[1];
    Vec3f sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    UNUSED s32 pad2[2];
    f32 var_fv0;
    f32 sp44;

    D_8219CB1A++;
    if (!(D_8219CB1A & 1)) {
        sp44 = BattleAnim_EffectSecondaryOwnerModelScale();
        BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp60);
        sp5C = (((guRandom() % 50) - 0x19) * sp44) + sp60.x;
        sp58 = (((guRandom() % 60) - 0x1E) * sp44) + sp60.y;
        sp54 = (((guRandom() % 50) - 0x19) * sp44) + sp60.z;
        var_fv0 = 10.0f;
        if (sp5C > 0.0) {
            var_fv0 = -var_fv0;
        }
        Trail50Effect_Start(sp5C, sp58, sp54, var_fv0, 0.0f, 0.0f, 0xFF, 0xFF, 0xFF, 0x64, 0.3f, 1.0f, 4.0f, 0x1E);
    }
    Trail50Effect_IsComplete();
    return 0;
}

void BattleAnim_StartEffect57Trail50_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Trail50Effect_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect42Trail40_Init(void) {
    Vec3f sp1C;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp1C);
    Trail40_Init(0x708);
}

s32 BattleAnim_StartEffect42Trail40_Update(void) {
    return Trail40_IsComplete();
}

void BattleAnim_StartEffect42Trail40_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Trail40_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect43Trail40Variant_Init(void) {
    Vec3f sp1C;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp1C);
    Trail40Variant_InitPool(0x708);
}

s32 BattleAnim_StartEffect43Trail40Variant_Update(void) {
    return Trail40Variant_AdvanceTimer();
}

void BattleAnim_StartEffect43Trail40Variant_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Trail40Variant_BuildGfx(gDisplayListHead);
}

void BattleAnim_StartEffect44Trail40GridAlt_Init(void) {
    Vec3f sp1C;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp1C);
    Trail40GridAlt_Init(0x708);
}

s32 BattleAnim_StartEffect44Trail40GridAlt_Update(void) {
    return Trail40GridAlt_IsComplete();
}

void BattleAnim_StartEffect44Trail40GridAlt_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Trail40GridAlt_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect45FourStreamTrail_Init(void) {
    D_8219CAC0 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    FourStreamTrail_Init();
}

#ifdef NON_MATCHING
/* TODO: decompile func_8216F3A0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216F3A0.s")
#endif

void BattleAnim_StartEffect45FourStreamTrail_Draw(void) {
    if (D_8219CAC0 >= 2) {
        gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gDisplayListHead = FourStreamTrail_Draw(gDisplayListHead);
    }
}

void BattleAnim_StartEffect62OwnerLinkedFourStream_Init(void) {
    D_8219CAC2 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    OwnerLinkedFourStream_Init();
}

s32 BattleAnim_StartEffect62OwnerLinkedFourStream_Update(void) {
    s32 var_v1;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;

    D_8219CAC2++;
    if (((D_8219CAC2 >> 2) < 4) && !(D_8219CAC2 & 3)) {
        BattleAnim_CalcVectorAtToDm(&sp60, &sp5C, &sp58, &sp54, &sp50, &sp4C);
        sp48 = ((2 - (((D_8219CAC2 >> 2) + 2) % 3)) * 0.5235988f) + 0.34906587f;
        sp54 *= 7.0f * __cosf(sp48);
        sp50 = __sinf(sp48) * 10.0f;
        sp4C = 0.0f;
        OwnerLinkedFourStream_Start(sp60, sp5C, sp58, sp54, sp50, 0.0f, 0xD0, 0xFF, 0xFF, 0x80, 0.8f, 2.0f, 4.0f, 0x28);
    }

    if (D_8219CAC2 >= 2) {
        var_v1 = OwnerLinkedFourStream_IsComplete();
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void BattleAnim_StartEffect62OwnerLinkedFourStream_Draw(void) {
    if (D_8219CAC2 >= 2) {
        gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gDisplayListHead = OwnerLinkedFourStream_Draw(gDisplayListHead);
    }
}

void BattleAnim_StartEffect67OwnerAnchoredFourStream_Init(void) {
    Vec3f sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;

    D_8219CB08 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    OwnerAnchoredFourStream_Init();
    BattleAnim_CalcVectorAtToDm(&sp58, &sp54, &sp50, &sp4C, &sp48, &sp44);
    sp4C *= 5.0;
    sp48 *= 5.0;
    sp44 *= 5.0;
    OwnerAnchoredFourStream_Start(sp58, sp54, sp50, sp4C, sp48, sp44, 0xC0, 0xFF, 0xFF, 0xA0, 0.6f, 2.0f, 4.0f, 0x28);
    sp5C.x = sp58;
    sp5C.y = sp54;
    sp5C.z = sp50;
    BattleAnim_SpawnSecondaryOwnerParticle(sp5C, 1);
}

s32 BattleAnim_StartEffect67OwnerAnchoredFourStream_Update(void) {
    D_8219CB08++;
    if (D_8219CB08 >= 0x32) {
        return -1;
    }

    return OwnerAnchoredFourStream_IsComplete();
}

void BattleAnim_StartEffect67OwnerAnchoredFourStream_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = OwnerAnchoredFourStream_Draw(gDisplayListHead);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8216FA40; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216FA40.s")
#endif

void BattleAnim_StartEffect78Radial20_Init(void) {
    D_8219CB0A = 0;
    BattleAnim_ResetSharedEffectMatrix();
    Radial20_ResetPool();
    BattleAnim_StartEffect78Radial20_EmitVariantA();
}

s32 BattleAnim_StartEffect78Radial20_Update(void) {
    D_8219CB0A++;
    if (D_8219CB0A >= 0xB5) {
        return -1;
    }
    return Radial20_IsComplete();
}

void BattleAnim_StartEffect78Radial20_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Radial20_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect26DoubleTextureTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84387FC0 = { 2, 1, 0xE, 1, 2, 2, 3, 1 };
    static unk_D_843C2C00_024 D_84387FE0 = { 3, 5, 0, 5, 3, 7, 0, 5 };
    static unk_D_843C2C00_024 D_84388000 = { 2, 1, 0xE, 1, 2, 1, 3, 1 };
    static unk_D_843C2C00_024 D_84388020 = { 3, 5, 0, 5, 0, 7, 5, 7 };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    BattleAnim_CalcVectorAtToDm(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 10.0f;
    spA4 *= 10.0f;
    spA0 *= 10.0f;
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 2.0f, 10.0f, 0x14, 0x8F, 0x8F, 6, 0xA, 0xF, 0xE,
                  -3, 5, 0, 0xF, &D_84387FC0, &D_84387FE0, 0xFF, 0xFF, 0, 0x96, 0x64, 0xFF, 0, 0xC8, 0x32, 0xFF, 0x96,
                  0xFF, 0x78);
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x8F, 0x90, 2, 6, 0, 0xF, -4,
                  2, 0, 0, &D_84388000, &D_84388020, 0, 0xFF, 0x64, 0x96, 0x64, 0x64, 0, 0xFF, 0xC8, 0, 0, 0, 0);
}

void BattleAnim_StartEffect26DoubleTextureTrail_Init(void) {
    BattleAnim_ResetSharedEffectMatrix();
    DoubleTextureTrail_InitPool();
    BattleAnim_StartEffect26DoubleTextureTrail_Seed();
}

s32 BattleAnim_StartEffect26DoubleTextureTrail_Update(void) {
    return DoubleTextureTrail_UpdateAll();
}

void BattleAnim_StartEffect26DoubleTextureTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = DoubleTextureTrail_DrawAll(gDisplayListHead);
}

void BattleAnim_StartEffect47SixSlotTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84388040 = { 3, 5, 1, 5, 1, 7, 3, 7 };
    static unk_D_843C2C00_024 D_84388060 = { 0x1F, 0x1F, 0x1F, 0, 7, 7, 7, 0 };

    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;

    BattleAnim_CalcVectorAtToDm(&spA4, &spA0, &sp9C, &sp98, &sp94, &sp90);
    sp94 += 0.2f * __cosf((RAND(10) * M_PI_F) / 10.0f);
    sp90 += 0.2f * __cosf((RAND(10) * M_PI_F) / 10.0f);

    sp98 *= 12.0f;
    sp94 *= 12.0f;
    sp90 *= 12.0f;

    BattleAnim_SixSlotTrail_Spawn(0, spA4, spA0, sp9C, sp98, sp94, sp90, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0, 0x64, 0xFF, 0xFF, 0.4f, 2.0f,
                  20.0f, 0x3C, 0x95, 0x95, 0, 0xA, 0, 0xD, 0, 0, 0, 0, &D_84388040, &D_84388060);
}

void BattleAnim_StartEffect47SixSlotTrail_Init(void) {
    D_8219CB0C = 0;
    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_SixSlotTrail_ResetPool();
    BattleAnim_StartEffect47SixSlotTrail_Seed();
}

s32 BattleAnim_StartEffect47SixSlotTrail_Update(void) {
    D_8219CB0C++;
    if ((D_8219CB0C % 10) == 0) {
        BattleAnim_StartEffect47SixSlotTrail_Seed();
    }
    return BattleAnim_SixSlotTrail_UpdateAll();
}

void BattleAnim_StartEffect47SixSlotTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = BattleAnim_SixSlotTrail_DrawAll(gDisplayListHead);
}

void BattleAnim_StartEffect4DoubleTextureTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84388080 = { 3, 5, 1, 5, 6, 7, 2, 3 };
    static unk_D_843C2C00_024 D_843880A0 = { 0x1F, 0x1F, 0x1F, 0, 0, 7, 5, 7 };
    static unk_D_843C2C00_024 D_843880C0 = { 3, 5, 2, 5, 1, 7, 3, 7 };
    static unk_D_843C2C00_024 D_843880E0 = { 0x1F, 0x1F, 0x1F, 0, 0, 7, 5, 7 };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    BattleAnim_CalcVectorAtToDm(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 10.0f;
    spA4 *= 10.0f;
    spA0 *= 10.0f;
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 2.0f, 10.0f, 0x14, 0x93, 0x93, 5, 0xA, 0xF, 0xF,
                  -5, 5, 0xF, 0xF, &D_84388080, &D_843880A0, 0xC8, 0xC8, 0, 0x64, 0, 0, 0xC8, 0, 0xFF, 0, 0xFF, 0,
                  0x5A);
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x91, 0x91, -2, 0xA, 0xF,
                  0xF, 5, 0xF, 0xF, 0xF, &D_843880C0, &D_843880E0, 0xFF, 0x32, 0x64, 0xC8, 0, 0x64, 0x32, 0xFF, 0xFF, 0,
                  0, 0, 0);
}

void BattleAnim_StartEffect4DoubleTextureTrail_Init(void) {
    BattleAnim_ResetSharedEffectMatrix();
    DoubleTextureTrail_InitPool();
    BattleAnim_StartEffect4DoubleTextureTrail_Seed();
}

s32 BattleAnim_StartEffect4DoubleTextureTrail_Update(void) {
    return DoubleTextureTrail_UpdateAll();
}

void BattleAnim_StartEffect4DoubleTextureTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = DoubleTextureTrail_DrawAll(gDisplayListHead);
}

void BattleAnim_StartEffect77DoubleTextureTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84388100 = { 2, 1, 0xE, 1, 2, 7, 1, 3 };
    static unk_D_843C2C00_024 D_84388120 = { 3, 5, 0, 5, 0, 7, 5, 7 };
    static unk_D_843C2C00_024 D_84388140 = { 2, 1, 0xE, 1, 2, 7, 1, 3 };
    static unk_D_843C2C00_024 D_84388160 = { 3, 5, 0, 5, 0, 7, 5, 7 };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    BattleAnim_CalcVectorAtToDm(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 10.0f;
    spA4 *= 10.0f;
    spA0 *= 10.0f;
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 2.0f, 10.0f, 0x14, 0x97, 0x98, -5, 0x14, 0xF,
                  0xD, -5, 0x14, 0, 0xE, &D_84388100, &D_84388120, 0xFF, 0xFF, 0xFF, 0x32, 0x64, 0x64, 0, 0xFF, 0xFF,
                  0xC8, 0xFF, 0xFF, 0x96);
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x97, 0x98, 5, 0xF, 0xF, 0xE,
                  0, 0xF, 0xF, 0xF, &D_84388140, &D_84388160, 0xFF, 0xFF, 0xFF, 0x32, 0x64, 0x64, 0x64, 0xFF, 0xFF, 0,
                  0, 0, 0);
}

void BattleAnim_StartEffect77DoubleTextureTrail_Init(void) {
    BattleAnim_ResetSharedEffectMatrix();
    DoubleTextureTrail_InitPool();
    BattleAnim_StartEffect77DoubleTextureTrail_Seed();
}

s32 BattleAnim_StartEffect77DoubleTextureTrail_Update(void) {
    return DoubleTextureTrail_UpdateAll();
}

void BattleAnim_StartEffect77DoubleTextureTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = DoubleTextureTrail_DrawAll(gDisplayListHead);
}

void BattleAnim_StartEffect70DoubleTextureTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84388180 = { 2, 1, 0xE, 1, 2, 1, 3, 1 };
    static unk_D_843C2C00_024 D_843881A0 = { 3, 5, 0, 5, 0, 7, 5, 7 };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    BattleAnim_CalcVectorAtToDm(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 10.0f;
    spA4 *= 10.0f;
    spA0 *= 10.0f;
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x97, 0x94, 0, 0x14, 0xE,
                  0xF, 0, 0x14, 0xF, 0xE, &D_84388180, &D_843881A0, 0xFF, 0xFF, 0xFF, 0x96, 0x96, 0xFF, 0xFF, 0, 0xFF,
                  0xFF, 0xFF, 0, 0x96);
}

void BattleAnim_StartEffect70DoubleTextureTrail_Init(void) {
    BattleAnim_ResetSharedEffectMatrix();
    DoubleTextureTrail_InitPool();
    BattleAnim_StartEffect70DoubleTextureTrail_Seed();
}

s32 BattleAnim_StartEffect70DoubleTextureTrail_Update(void) {
    return DoubleTextureTrail_UpdateAll();
}

void BattleAnim_StartEffect70DoubleTextureTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = DoubleTextureTrail_DrawAll(gDisplayListHead);
}

void BattleAnim_StartEffect39DoubleTextureTrail_Seed(void) {
    static unk_D_843C2C00_024 D_843881C0 = {
        0x00000002, 0x00000001, 0x0000000E, 0x00000001, 0x00000007, 0x00000007, 0x00000007, 0x00000003,
    };
    static unk_D_843C2C00_024 D_843881E0 = {
        0x00000003, 0x00000005, 0x00000000, 0x00000005, 0x00000007, 0x00000007, 0x00000007, 0x00000000,
    };
    static unk_D_843C2C00_024 D_84388200 = {
        0x00000002, 0x00000001, 0x0000000E, 0x00000001, 0x00000002, 0x00000001, 0x00000003, 0x00000001,
    };
    static unk_D_843C2C00_024 D_84388220 = {
        0x00000003, 0x00000005, 0x00000000, 0x00000005, 0x00000000, 0x00000007, 0x00000005, 0x00000007,
    };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    BattleAnim_CalcVectorAtToDm(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 12.0f;
    spA4 *= 12.0f;
    spA0 *= 12.0f;
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 2.0f, 10.0f, 0x14, 0x91, 0x92, 5, 0x1E, 0, 0xD,
                  -5, 0x1E, 0xF, 0xD, &D_843881C0, &D_843881E0, 0xFF, 0xFF, 0, 0xFF, 0x96, 0x32, 0, 0, 0xFF, 0xFF, 0xC8,
                  0x64, 0xC8);
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x97, 0x96, 6, 0x14, 0xE,
                  0xF, -3, 0xA, 0, 0xF, &D_84388200, &D_84388220, 0xFF, 0xFF, 0x64, 0x96, 0xFF, 0xFF, 0x64, 0, 0xC8, 0,
                  0, 0, 0);
}

void BattleAnim_StartEffect39SixSlotTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84388240 = {
        0x00000002, 0x00000001, 0x0000000E, 0x00000001, 0x00000002, 0x00000001, 0x00000003, 0x00000001,
    };
    static unk_D_843C2C00_024 D_84388260 = {
        0x00000003, 0x00000005, 0x00000000, 0x00000005, 0x00000000, 0x00000007, 0x00000005, 0x00000007,
    };

    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;

    BattleAnim_CalcVectorAtToDm(&spA4, &spA0, &sp9C, &sp98, &sp94, &sp90);

    sp94 += (0.4f * __cosf((RAND(10) * M_PI_F) / 10));
    sp90 += (0.4f * __cosf((RAND(10) * M_PI_F) / 10));

    sp98 *= 12.0f;
    sp94 *= 12.0f;
    sp90 *= 12.0f;

    BattleAnim_SixSlotTrail_Spawn(0, spA4, spA0, sp9C, sp98, sp94, sp90, 0xFF, 0xFF, 0x64, 0x32, 0xC8, 0xFF, 0x32, 0, 0xFF, 0.4f, 2.0f,
                  5.0f, 0x3C, 0x95, 0x95, 0, 0x14, 0, 0xD, 0, 0x19, 0, 0xD, &D_84388240, &D_84388260);
}

void BattleAnim_StartEffect39CombinedTrail_Init(void) {
    BattleAnim_ResetSharedEffectMatrix();
    DoubleTextureTrail_InitPool();
    BattleAnim_StartEffect39DoubleTextureTrail_Seed();
    BattleAnim_SixSlotTrail_ResetPool();
    BattleAnim_StartEffect39SixSlotTrail_Seed();
}

s32 BattleAnim_StartEffect39CombinedTrail_Update(void) {
    D_8219CB14++;
    if ((D_8219CB14 % 10) == 0) {
        BattleAnim_StartEffect39SixSlotTrail_Seed();
    }
    BattleAnim_SixSlotTrail_UpdateAll();
    return DoubleTextureTrail_UpdateAll();
}

void BattleAnim_StartEffect39CombinedTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_8219CAC8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = DoubleTextureTrail_DrawAll(gDisplayListHead);
    gDisplayListHead = BattleAnim_SixSlotTrail_DrawAll(gDisplayListHead);
}
