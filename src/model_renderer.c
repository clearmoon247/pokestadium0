/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/model_renderer.c. */

#include "global.h"
#include "model_renderer.h"
#include "geo_node.h"
#include "model_animation.h"
#include "matrix.h"
#include "model_animation_events.h"
#include "battle_hud.h"
#include "gb_data.h"
#include "display_object_textures.h"
#include "game_state.h"
#include "dp_intro.h"
#include "hal_libc.h"
#include "geo_render.h"
extern struct DisplayNodeHeader D_800AD1D0;
extern struct DisplayNodeHeader D_800AD1E8;

void ModelRenderer_InitDisplayRoots(void);
void ModelRenderer_AttachDisplayObject(DisplayObject* display_object);
void ModelRenderer_AttachSecondaryDisplayObject(DisplayObject* arg0);
void ModelRenderer_ClearDisplayObject(DisplayObject* arg0);
s32 ModelAnim_SetAnimation(DisplayObject* display_object, s32 id);
s32 ModelAnim_SetEventTrack(DisplayObject* display_object, s32 track_id);
void Model_SetMaterialColor(DisplayObject* display_object, u8 r, u8 g, u8 b, u8 alpha);
void Model_SetMaterialAlpha(DisplayObject* arg0, u8 arg1);
void Model_SetMaterialTextureMode(DisplayObject* display_object, u8 texture_mode);
ModelAnimationBank* ModelAnim_GetAnimationRecord(DisplayObject* arg0, s32 arg1);

void ModelRenderer_InitDisplayRoots(void) {
    GeoNode_CreateContainer(0, &D_800AD1D0);
    GeoNode_CreateContainer(0, &D_800AD1E8);
}

void ModelRenderer_AttachDisplayObject(DisplayObject* display_object) {
    GeoNode_CreateModelPart(NULL, display_object, 0, &D_80060450, &D_8006045C, &D_80060464);
    GraphNode_AppendChild(&D_800AD1D0, &display_object->node);
    display_object->effectSlot = 0;
    display_object->node.flags &= ~1;
}

void ModelRenderer_AttachSecondaryDisplayObject(DisplayObject* arg0) {
    GeoNode_CreateModelPart(NULL, arg0, 0, &D_80060450, &D_8006045C, &D_80060464);
    GraphNode_AppendChild(&D_800AD1E8, &arg0->node);
    arg0->node.flags &= ~1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80019924; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80019924.s")
#endif

void ModelRenderer_ClearDisplayObject(DisplayObject* arg0) {
    arg0->node.children = NULL;
    arg0->node.flags &= ~1;
}

s32 ModelAnim_SetAnimation(DisplayObject* display_object, s32 id) {
    ModelAssetNode* asset_node = display_object->node.children;
    ModelAnimationBank* animation_bank = asset_node->getAnimationBank(0, 0);

    if (id == -1) {
        ModelAnim_ClearTransformChannel(display_object);
    } else if (id < animation_bank->transformCount) {
        ModelAnim_BindTransformCurve(display_object, id, animation_bank->transformTracks[id], 0x10000);
        return 1;
    }

    return 0;
}

s32 ModelAnim_SetEventTrack(DisplayObject* display_object, s32 track_id) {
    ModelAssetNode* asset_node = display_object->node.children;
    ModelAnimationBank* animation_bank = asset_node->getAnimationBank(0, 0);

    if (track_id == -1) {
        ModelAnim_ClearEventTrack(display_object);
    } else if (track_id < animation_bank->eventTrackCount) {
        ModelAnim_BindEventTrack(display_object, track_id, animation_bank->eventTracks[track_id]);
        return 1;
    }

    return 0;
}

void Model_SetMaterialColor(DisplayObject* display_object, u8 r, u8 g, u8 b, u8 alpha) {
    Color_SetRGBA(&display_object->fogColor, r, g, b, alpha);
}

void Model_SetMaterialAlpha(DisplayObject* arg0, u8 arg1) {
    arg0->lodFraction = arg1;
}

/*
    known modes:
    - 1 = Gold (Harden)

*/
void Model_SetMaterialTextureMode(DisplayObject* display_object, u8 texture_mode) {
    display_object->textureMode = texture_mode;
}

ModelAnimationBank* ModelAnim_GetAnimationRecord(DisplayObject* arg0, s32 arg1) {
    ModelAnimationBank* var_v1 = NULL;

    if (arg0 == NULL) {
        arg0 = D_8006049C;
    }

    if (arg0 != NULL) {
        ModelAssetNode* tmp = arg0->node.children;

        var_v1 = tmp->getAnimationBank(arg1, 0);
    }

    return var_v1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80019BDC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80019BDC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80019D08; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80019D08.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80019DE0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80019DE0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80019E30; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80019E30.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80019E90; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80019E90.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80019F20; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80019F20.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80019F70; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80019F70.s")
#endif
