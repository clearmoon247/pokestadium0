/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_thumbnail.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "model_animation.h"
#include "model_renderer.h"
#include "model_renderer_callbacks.h"
#include "matrix.h"
#include "status.h"

#include "m2c_macros.h"

void BattleThumbnail_SetupOwnerCameraFraming(ActivePokemon* side1_pokemon, ActivePokemon* side2_pokemon);
void BattleThumbnail_OwnerCameraLifecycleNop(void);
void BattleThumbnail_TickOwnerCameraFraming(ActivePokemon* active_pokemon);
s32 BattleThumbnail_DispatchOwnerCameraLifecycle(s32 state, CameraNode* side1_camera_node, CameraNode* side2_camera_node);

void BattleThumbnail_ClearBothOwnerIdleFlags(void);
void BattleThumbnail_SetBothOwnerIdleFlags(void);
void BattleThumbnail_LoadOwnerCameraFramingConstants(ActivePokemon* active_pokemon);
void BattleThumbnail_ApplyOwnerCameraFraming(ActivePokemon* active_pokemon);
void BattleThumbnail_InitializeOwnerCameraFraming(CameraNode* side1_camera_node, ActivePokemon* side1_pokemon, CameraNode* side2_camera_node, ActivePokemon* side2_pokemon);
void BattleThumbnail_TickBothOwnerSlideAnimations(ActivePokemon* side1_pokemon, ActivePokemon* side2_pokemon);

/*
    Sets up the camera framing for both pokemons's thumbnails.
*/
void BattleThumbnail_SetupOwnerCameraFraming(ActivePokemon* side1_pokemon, ActivePokemon* side2_pokemon) {
    if (sBattleScene.scene->unk_1C == 1) {
        BattleThumbnail_SetBothOwnerIdleFlags();
    } else {
        BattleThumbnail_ClearBothOwnerIdleFlags();
    }
    BattleThumbnail_LoadOwnerCameraFramingConstants(side1_pokemon);
    BattleThumbnail_LoadOwnerCameraFramingConstants(side2_pokemon);
}

/*
    Nop
*/
void BattleThumbnail_OwnerCameraLifecycleNop(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_821072F8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821072F8.s")
#endif

/*
    Updates the camera coordinates for the owner's thumbnail.
*/
void BattleThumbnail_TickOwnerCameraFraming(ActivePokemon* active_pokemon) {
    BattleThumbnail_ApplyOwnerCameraFraming(active_pokemon);
}

M2C_UNK func_82107290(s8 *, s8 *);              /* extern */
M2C_UNK func_82107408(s8 *);                      /* extern */

void func_82107428(s32 arg0, s8 *arg1, s32 arg2, s8 *arg3) {
    M2C_FIELD(arg1, s32 *, 0x9CC) = arg0;
    M2C_FIELD(arg3, s32 *, 0x9CC) = arg2;
    func_82107290(arg1, arg3);
    func_82107408(arg1);
    func_82107408(arg3);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82107470; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107470.s")
#endif

s16 func_8000F1FC(s16, M2C_UNK, M2C_UNK, M2C_UNK);  /* extern */

void func_821075B4(s8 *arg0, M2C_UNK arg1) {
    s8 *temp_v1;
    s8 *temp_v1_2;

    if (M2C_FIELD(arg0, s32 *, 0x9E0) == 1) {
        M2C_FIELD(arg0, s32 *, 0x9F4) = 0;
        M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x9CC), s16 *, 0x1C) = func_8000F1FC(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x9CC), s16 *, 0x1C), -0x48, arg1, arg1);
        temp_v1 = M2C_FIELD(arg0, s8 **, 0x9CC);
        if (M2C_FIELD(temp_v1, s16 *, 0x1C) == -0x48) {
            M2C_FIELD(temp_v1, u8 *, 1) = (u8) (M2C_FIELD(temp_v1, u8 *, 1) & 0xFFFE);
            M2C_FIELD(arg0, u8 *, 0x865) = (u8) (M2C_FIELD(arg0, u8 *, 0x865) & 0xFFFE);
        }
    } else {
        M2C_FIELD(arg0, s32 *, 0x9F4) = 0;
        M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x9CC), s16 *, 0x1C) = func_8000F1FC(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x9CC), s16 *, 0x1C), 0x15F, arg1, arg1);
        temp_v1_2 = M2C_FIELD(arg0, s8 **, 0x9CC);
        if (M2C_FIELD(temp_v1_2, s16 *, 0x1C) == 0x15F) {
            M2C_FIELD(temp_v1_2, u8 *, 1) = (u8) (M2C_FIELD(temp_v1_2, u8 *, 1) & 0xFFFE);
            M2C_FIELD(arg0, u8 *, 0x865) = (u8) (M2C_FIELD(arg0, u8 *, 0x865) & 0xFFFE);
        }
    }
}

void BattleThumbnail_TickOwnerSlideAnimation(ActivePokemon* active_pokemon) {
    switch (active_pokemon->thumbnail.showing) {
        case 0:
            BattleThumbnail_TickOwnerSlideOut(active_pokemon, 9);
            break;

        case 1:
            BattleThumbnail_TickOwnerSlideIn(active_pokemon, 9);
            break;
    }
}

void BattleThumbnail_TickBothOwnerSlideAnimations(ActivePokemon* side1_pokemon, ActivePokemon* side2_pokemon) {
    BattleThumbnail_TickOwnerSlideAnimation(side1_pokemon);
    BattleThumbnail_TickOwnerSlideAnimation(side2_pokemon);
}

/*
    Dispatches the thumbnail's rendering based on the current of the battle
*/
s32 BattleThumbnail_DispatchOwnerCameraLifecycle(s32 state, CameraNode* side1_camera_node, CameraNode* side2_camera_node) {
    switch (state) {
        case 0:
            BattleThumbnail_OwnerCameraLifecycleNop();
            break;

        case 1:
        case 2:
            BattleThumbnail_TickBothOwnerSlideAnimations(sActivePokemon[0], sActivePokemon[1]);
            break;

        case 3:
            BattleThumbnail_InitializeOwnerCameraFraming(side1_camera_node, sActivePokemon[0], side2_camera_node, sActivePokemon[1]);
            break;
    }
    return 0;
}
