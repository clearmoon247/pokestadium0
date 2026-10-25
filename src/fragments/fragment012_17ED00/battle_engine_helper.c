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

void func_8210840C(ActivePokemon*, ActivePokemon*, s32);
void func_82108648(ActivePokemon*, s32);

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

u8 func_82107A3C(s8 *arg0)
{
  int new_var;
  new_var = (*((u8 *) (((s8 *) arg0) + 0x7B7))) == 0;
  return *((u8 *) (((s8 *) (*((s8 **) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x85C))) + (new_var * 4))) + 8)))) + 2));
}

s32 BattleScene_GetParticipantSideIndex(ActivePokemon* active_pokemon) {
    if (active_pokemon == sSide1ActivePokemon) {
        return 0;
    }
    return 1;
}

u8 BattleScene_GetMoveCueDefaultAnchor(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    UNUSED s16 pad2;
    s16 move_index = active_pokemon->state.runtime.usedMove - 1;
    MovePresentationCue* move_cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[move_index];

    return move_cue->defaultAnchor;
}

u8 BattleScene_GetMoveCueAlternateAnchor(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    UNUSED s16 pad2;
    s16 move_index = active_pokemon->state.runtime.usedMove - 1;
    MovePresentationCue* move_cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[move_index];

    return move_cue->alternateAnchor;
}

s16 BattleScene_GetHitCueDefaultAnchor(ActivePokemon* active_pokemon) {
    MovePresentationCue* hit_cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->hitCue;

    return hit_cue->defaultAnchor;
}

s16 func_82107B54(ActivePokemon* active_pokemon) {
    MovePresentationCue* hit_cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->hitCue;

    return M2C_FIELD(hit_cue, u8*, 3);
}

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

typedef struct {
    /* 0x0 */ s32 unk_00;
    /* 0x4 */ s32 unk_04;
    /* 0x8 */ s32 unk_08;
} unk_D_8006A9CC; // size = 0xC
extern unk_D_8006A9CC D_8006A9CC[];

s32 func_82107F68(u8* arg0) {
    return D_8006A9CC[arg0[0x80A]].unk_00;
}

s32 func_82107F88(s8 *arg0)
{
  unsigned int new_var;
  return ((*((s32 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x85C))) + ((*((u8 *) (((s8 *) arg0) + 0x7B9))) * 4))) + 8))) + ((*((s32 *) (((s8 *) arg0) + 0x794))) * 0x50)) + (new_var = 0x4C);
}

void BattleScene_InitializeParticipantOwnerModel(ActivePokemon* active_pokemon) {
    ThumbnailState* presentation = &active_pokemon->thumbnail;
    ModelNodeView* model_view;
    s16 model_id;

    model_view = Battle_GetLoadedModelNode(active_pokemon, 0);
    model_id = Battle_GetDisplayModelId(active_pokemon, 0);
    ModelRenderer_AttachDisplayObject(&presentation->displayObject);

    if (active_pokemon == sActivePokemon[0]) {
        presentation->displayObject.effectSlot = 2;
        Model_InitDisplayObject(&presentation->displayObject, 1, model_id, model_view);
    } else {
        presentation->displayObject.effectSlot = 3;
        Model_InitDisplayObject(&presentation->displayObject, 2, model_id, model_view);
    }

    ModelAnim_SetAnimation(&presentation->displayObject, 0);
    ModelAnim_SetFrame(&presentation->displayObject, 0);
    presentation->displayObject.node.renderFlags &= ~0x40;
    Vec3f_SetComponentsDuplicate(&presentation->displayObject.position, 0.0f, 0.0f, 0.0f);
}

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

void Battle_LoadOwnerModelForSpecies(ActivePokemon* active_pokemon) {
    ActivePokemonState* state = &active_pokemon->state;
    UNUSED s32 pad[3];
    s16 object_type;

    Battle_GetLoadedModelNode(active_pokemon, 0);
    object_type = Battle_GetDisplayModelId(active_pokemon, 0);
    func_8210840C(active_pokemon, active_pokemon, object_type);
    BattleScene_ReinitParticipantThumbnailModel(active_pokemon, &active_pokemon->thumbnail, object_type);
    func_82108648(active_pokemon, object_type);
    Battle_ResetEventTrack(active_pokemon);
    state->flags &= 0x3800;
    Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.scale, 1.0f, 1.0f, 1.0f);
}

void func_821088BC(ActivePokemon* active_pokemon) {
    ActivePokemonState* state = &active_pokemon->state;
    UNUSED s32 pad[3];
    s16 object_type;

    Battle_GetLoadedModelNode(active_pokemon, 0);
    object_type = Battle_GetDisplayModelId(active_pokemon, 0);
    func_8210840C(active_pokemon, active_pokemon, object_type);
    BattleScene_ReinitParticipantThumbnailModel(active_pokemon, &active_pokemon->thumbnail, object_type);
    func_82108648(active_pokemon, object_type);
    Battle_ResetEventTrack(active_pokemon);
    M2C_FIELD(state, u8*, 0x2E) = 0;
    state->flags &= 0x3800;
    Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.scale, 1.0f, 1.0f, 1.0f);
}

void Battle_ResetOwnerModelToSubstituteDoll(ActivePokemon* active_pokemon) {
    Model_SetMaterialColor(&active_pokemon->displayObject, 0xFF, 0xFF, 0xFF, active_pokemon->state.alpha = 0xFF);
    active_pokemon->state.model = active_pokemon->displayObject.objectType;
    func_8210840C(active_pokemon, active_pokemon, SUBSTITUTE_DOLL);
    func_82108648(active_pokemon, SUBSTITUTE_DOLL);
    Battle_ResetEventTrack(active_pokemon);
}

void Battle_ReloadSubstituteDoll(ActivePokemon* active_pokemon) {
    func_8210840C(active_pokemon, active_pokemon, SUBSTITUTE_DOLL);
    func_82108648(active_pokemon, SUBSTITUTE_DOLL);
    Battle_ResetEventTrack(active_pokemon);
}

void Battle_ReloadDisplayModel(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[3];
    ActivePokemonState* state = &active_pokemon->state;
    s16 object_type = Battle_GetDisplayModelId(active_pokemon, 0);

    state->alpha = 0xFF;
    Model_SetMaterialColor(&active_pokemon->displayObject, 0xFF, 0xFF, 0xFF, state->alpha);
    func_8210840C(active_pokemon, active_pokemon, object_type);
    func_82108648(active_pokemon, object_type);
    Battle_ResetEventTrack(active_pokemon);
}

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

void Battle_SetModelToHitAnim(ActivePokemon* active_pokemon) {
    extern PokemonBattleCues* D_82189180[];
    MovePresentationCue* hit_cue = &D_82189180[BattleScene_GetParticipantSideIndex(active_pokemon)]->hitCue;

    if (active_pokemon->displayObject.transformAnim.animationId != -1) {
        ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
        ModelAnim_SetAnimation(&active_pokemon->displayObject, hit_cue->id);
    }
}

void func_82108DC8(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x860) = (s32) M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x85C) + (arg1 * 4)), s32 *, 8);
}

void func_82108DE0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x7B7) = arg1;
}

void func_82108DE8(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x858) = arg1;
}

void func_82108DF0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x7B9) = arg1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82108DF8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82108DF8.s")
#endif

s32 Battle_FreezeClauseInEffect(ActivePokemon* active_pokemon) {
    s32 i;
    ActivePokemonState* state;
    BattleMon* pokemon;

    state = &active_pokemon->state;

    for (i = 0; i < BattleScene_GetTeamMemberTeamSize(active_pokemon); i++) {
        pokemon = &active_pokemon->teamRoster->pokemonPicked[i];
        if ((pokemon->statusCondition & STATUS_FREEZE) && (active_pokemon->state.runtime.roster[state->rosterIndex + state->teamMemberIndex * 3] == 0)) {
            return 1;
        }
    }

    if (active_pokemon->sessionTeams->tagTeamSize == 2) {
        for (i = 0; i < BattleScene_GetPartnerTeamSize(active_pokemon); i++) {
            pokemon = &active_pokemon->sessionTeams->teamMember[state->teamMemberIndex == 0]->pokemonPicked[i];
            if ((pokemon->statusCondition & STATUS_FREEZE) &&
                (active_pokemon->state.runtime.roster[state->rosterIndex + (state->teamMemberIndex == 0) * 3] == 0)) {
                return 1;
            }
        }
    }

    return 0;
}

s32 Battle_SleepClauseInEffect(ActivePokemon* active_pokemon) {
    s32 i;
    ActivePokemonState* state;
    BattleMon* pokemon;

    state = &active_pokemon->state;

    for (i = 0; i < BattleScene_GetTeamMemberTeamSize(active_pokemon); i++) {
        pokemon = &active_pokemon->teamRoster->pokemonPicked[i];
        if ((pokemon->statusCondition & STATUS_SLEEP_MASK) && (active_pokemon->state.runtime.roster[state->rosterIndex + state->teamMemberIndex * 3] == 0)) {
            return 1;
        }
    }

    if (active_pokemon->sessionTeams->tagTeamSize == 2) {
        for (i = 0; i < BattleScene_GetPartnerTeamSize(active_pokemon); i++) {
            pokemon = &active_pokemon->sessionTeams->teamMember[state->teamMemberIndex == 0]->pokemonPicked[i];
            if ((pokemon->statusCondition & STATUS_SLEEP_MASK) && (active_pokemon->state.runtime.roster[state->rosterIndex + (state->teamMemberIndex == 0) * 3] == 0)) {
                return 1;
            }
        }
    }
    return 0;
}
