/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_helper.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "model_animation.h"
#include "model_animation_events.h"
#include "model_renderer.h"
#include "text_system.h"
#include "matrix.h"
#include "pokemon.h"
#include "status.h"

#include "m2c_macros.h"

f32 BattleScene_GetParticipantModelXOffset(ActivePokemon* active_pokemon);
void BattleScene_SetParticipantModelScale(ActivePokemon* active_pokemon, f32 scale);
s32 BattleScene_GetParticipantSideIndex(ActivePokemon* active_pokemon);
void BattleScene_GetParticipantModelRotation(ActivePokemon* pokemon, Vec3s* dest);
s32 BattleAnim_GetSpeciesBySideIndex(s32 side);
s32 BattleAnim_GetOwnerSpecies(ActivePokemon* active_pokemon);
u8 BattleScene_IsParticipantModelVisible(ActivePokemon* active_pokemon);
void BattleScene_GetParticipantModelPosition(ActivePokemon* pokemon, Vec3f* dest);

#ifdef NON_MATCHING
/* TODO: decompile func_82107790; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107790.s")
#endif

f32 BattleScene_GetParticipantModelXOffset(ActivePokemon* active_pokemon) {
    if (BattleScene_GetParticipantSideIndex(active_pokemon) == 0) {
        if ((active_pokemon->displayObject.objectType == GYARADOS) || (active_pokemon->displayObject.objectType == ONIX)) {
            return -200.0f;
        }

        if ((active_pokemon->displayObject.objectType == VENUSAUR) || (active_pokemon->displayObject.objectType == LAPRAS)) {
            return -175.0f;
        }
        return -150.0f;
    }

    if ((active_pokemon->displayObject.objectType == GYARADOS) || (active_pokemon->displayObject.objectType == ONIX)) {
        return 200.0f;
    }

    if ((active_pokemon->displayObject.objectType == VENUSAUR) || (active_pokemon->displayObject.objectType == LAPRAS)) {
        return 175.0f;
    }

    return 150.0f;
}

#ifdef NON_MATCHING
/* TODO: decompile func_821079E8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821079E8.s")
#endif

void BattleScene_SetParticipantModelScale(ActivePokemon* active_pokemon, f32 scale) {
    active_pokemon->displayObject.scale.x = scale;
    active_pokemon->displayObject.scale.y = scale;
    active_pokemon->displayObject.scale.z = scale;
}

u8 func_82107A30(s8 *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x860), u8 *, 2);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82107A3C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107A3C.s")
#endif

s32 BattleScene_GetParticipantSideIndex(ActivePokemon* active_pokemon) {
    if (active_pokemon == sSide1ActivePokemon) {
        return 0;
    }
    return 1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82107A80; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107A80.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82107AD0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107AD0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82107B20; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107B20.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82107B54; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107B54.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82107B88; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107B88.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82107BC4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107BC4.s")
#endif

u8 func_82107BF4(s8 *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x820);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82107BFC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107BFC.s")
#endif

void BattleScene_GetParticipantModelRotation(ActivePokemon* pokemon, Vec3s* dest) {
    dest->x = pokemon->displayObject.rotation.x;
    dest->y = pokemon->displayObject.rotation.y;
    dest->z = pokemon->displayObject.rotation.z;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82107CA0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107CA0.s")
#endif

s16 func_82107CC4(s8 *arg0) {
    return (s16) (M2C_FIELD(arg0, s32 *, 0x60C) << 0xE);
}

s32 BattleAnim_GetSpeciesBySideIndex(s32 side) {
    return sActivePokemon[side]->displayObject.objectType;
}

s32 BattleAnim_GetOwnerSpecies(ActivePokemon* active_pokemon) {
    return active_pokemon->displayObject.objectType;
}

u8 BattleScene_IsParticipantModelVisible(ActivePokemon* active_pokemon) {
    s32 visible = active_pokemon->displayObject.node.flags & 1;
    return visible;
}

void BattleScene_GetParticipantModelPosition(ActivePokemon* pokemon, Vec3f* dest) {
    dest->x = pokemon->displayObject.position.x;
    dest->y = pokemon->displayObject.position.y;
    dest->z = pokemon->displayObject.position.z;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82107D24; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107D24.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82107DDC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107DDC.s")
#endif

void func_82107EA0(s8 *arg0, s8 *arg1) {
    M2C_FIELD(arg1, f32 *, 0) = (f32) M2C_FIELD(arg0, f32 *, 0x648);
    M2C_FIELD(arg1, f32 *, 4) = (f32) (M2C_FIELD(arg0, f32 *, 0x64C) + 2.5f);
    M2C_FIELD(arg1, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x650);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82107EC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107EC8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82107F18; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107F18.s")
#endif

ModelNodeView* Battle_GetLoadedModelNode(ActivePokemon* active_pokemon, s32 node_index) {
    return active_pokemon->sessionTeams->loadedModel->unk_00[2]->unk_00[node_index];
}

s16 func_82107F58(s8 *arg0, M2C_UNK arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x85C), s16 *, 2);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82107F68; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107F68.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82107F88; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107F88.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82107FB8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82107FB8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82108090; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82108090.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821081D0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821081D0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82108340; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82108340.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210840C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210840C.s")
#endif

void BattleScene_ReinitParticipantThumbnailModel(ActivePokemon* pokemon, ThumbnailState* thumbnail, s16 object_type) {
    ModelNodeView* model_node;

    model_node = Battle_GetLoadedModelNode(pokemon, 0);
    ModelRenderer_ClearDisplayObject(&thumbnail->displayObject);

    if (pokemon == sActivePokemon[0]) {
        thumbnail->displayObject.effectSlot = 0x2;
    } else {
        thumbnail->displayObject.effectSlot = 0x3;
    }

    if (pokemon == sActivePokemon[0]) {
        Model_InitDisplayObject(&thumbnail->displayObject, 1, object_type, model_node);
    } else {
        Model_InitDisplayObject(&thumbnail->displayObject, 2, object_type, model_node);
    }

    ModelAnim_SetFrame(&thumbnail->displayObject, 0);
    ModelAnim_SetAnimation(&thumbnail->displayObject, 0);
    thumbnail->displayObject.node.renderFlags &= ~0x40;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82108648; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82108648.s")
#endif

void Battle_ResetEventTrack(ActivePokemon* active_pokemon) {
    if (active_pokemon->state.flags & ACTIVE_SLEEP) {
        BattleAnim_TrySetModelEventTrackFromRow(active_pokemon, 0xAF, 2);
    } else {
        active_pokemon->state.unk_36 = 0;
        ModelAnim_SetEventFrame(&active_pokemon->displayObject, 0);
        ModelAnim_SetEventTrack(&active_pokemon->displayObject, -1);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210881C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210881C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821088BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821088BC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82108960; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82108960.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821089D0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821089D0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82108A0C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82108A0C.s")
#endif

void func_82108A88(s8 *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x610) = arg1;
    M2C_FIELD(arg0, s32 *, 0x614) = arg2;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82108A94; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82108A94.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82108C0C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82108C0C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82108D68; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82108D68.s")
#endif

void func_82108DC8(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x860) = (s32) M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x85C) + (arg1 * 4)), s32 *, 8);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82108DE0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82108DE0.s")
#endif

void func_82108DE8(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x858) = arg1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82108DF0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82108DF0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82108DF8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82108DF8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82108E40; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82108E40.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82108FB4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82108FB4.s")
#endif
