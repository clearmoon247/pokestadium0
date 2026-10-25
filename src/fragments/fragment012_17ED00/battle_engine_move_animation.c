/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_move_animation.c, src/fragments/battle_engine/battle_engine_thumbnail.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "model_animation.h"
#include "model_animation_events.h"
#include "model_renderer.h"
#include "pokemon_stats.h"
#include "text_system.h"
#include "gb_save.h"
#include "audio_commands.h"
#include "jpeg_stream.h"
#include "audio_fade.h"
#include "audio_stored_fade.h"
#include "audio_loop_point.h"
#include "cry.h"
#include "matrix.h"
#include "memory.h"
#include "moves.h"
#include "pokemon.h"
#include "status.h"
extern PokemonBattleCues sSide1BattleCues;
extern PokemonBattleCues sSide2BattleCues;
extern SpeciesModelTransform sSide1PresentationTransform;
extern SpeciesModelTransform sSide2PresentationTransform;
extern ActivePokemon* sActivePokemon[2];
extern ActivePokemon* sSide1ActivePokemon;
extern ActivePokemon* sSide2ActivePokemon;
extern MovePresentationCue* sCurrentAnimation;
extern ModelDimensions sPokemonModelDimensions[2];
extern SwayLayoutConfig sDefaultSwayLayout;
extern BattleSceneStateTickSlot sBattleSceneStateTickSlots[7];
extern s32 sBattleSceneStateTickSlotIndex;
extern PokemonBattleCues* sSideBattleCues[];
extern SpeciesModelTransform* sSidePresentationTransform[];
extern TagTeamPartners* sPlayerTagTeam[];
extern u8 sPokemonWithAlternateSleepIdle[];
extern u8 sPokemonWithAlternateSleepHitReactions[];
extern u8 sPokemonWithNewHmInYellow[];
extern u8 sCharizardLearnsFlyInYellow[];
extern u8 sButterfreeLearnsFlashInYellow[];
extern u8 sVenonatLearnsFlashInYellow[];
extern u8 sVenomothLearnsFlashInYellow[];
extern u8 sDiglettLearnsCutInYellow[];
extern u8 sDugtrioLearnsCutInYellow[];
extern u8 sKabutopsLearnsCutInYellow[];
extern u8 sMewtwoLearnsNothingNewInYellow[];
extern u8 sMewLearnsNothingNewInYellow[];
extern u8* sPokemonYellowHmAdditions[];
extern u8 sAerodactyl;
extern u8 sFearow;
extern u8 sFarfetchD;
extern u8 sDoduoEvoLine[];
extern char** sBattleMessagesTable;
extern char** sPokemonNameTable;
extern char** sMoveNameTable;
extern char** sStatusConditionNameTable;
extern char** sBattleControllerDisconnectedMessage;
#define PARTNER_PIKACHU_CUE_BANK 152
#define DIGLETT_OB1 (DIGLETT - 1)
#define DUGTRIO_OB1 (DUGTRIO - 1)
#define ELECTRODE_OB1 (ELECTRODE - 1)
#define SQUIRTLE_OB1 (SQUIRTLE - 1)
#define WARTORTLE_OB1 (WARTORTLE - 1)
#define BLASTOISE_OB1 (BLASTOISE - 1)
#define CLOYSTER_OB1  (CLOYSTER - 1)

#include "fragments/battle_engine/battle_engine.h"
#include "model_animation.h"
#include "model_renderer.h"
#include "model_renderer_callbacks.h"
#include "matrix.h"
#include "status.h"

#include "m2c_macros.h"

void func_8003FE58(u8, s16, s32);

void BattleScene_ClearStateTickCallbacks(void);
void BattleScene_QueueRowEffectList3(ActivePokemon* actor, s32 effect_entry);
void BattleAnim_PlayMoveEffectScript(ActivePokemon* user, s32 move_id);
void BattleAnim_PlayChargingMoveEffectScript(ActivePokemon* user, s32 move_id);
void BattleAnim_PlayMoveEffectEnd(ActivePokemon* user, s32 move_id);
void BattleAnim_ClearRockThrowingMoveFlag(ActivePokemon* active_pokemon);
void BattleScene_StateCallbackNop(ActivePokemon* active_pokemon);
void BattleScene_RegisterStateTickCallback(ActivePokemon* active_pokemon, BattleSceneStateCallback callback);
void BattleScene_SetOpponentEventTrackA6(ActivePokemon* active_pokemon);
void func_82105E64(ActivePokemon* active_pokemon);
void BattleScene_AllocateParticipants(BattleSessionTeams* battle_teams);
void BattleScene_UpdateParticipantsAndQueueEffects(UNUSED ActivePokemon* side1_pokemon, UNUSED ActivePokemon* side2_pokemon);
s32 BattleScene_DispatchLifecycle(s32 lifecycle_stage, BattleSessionTeams* session_teams);
void BattleThumbnail_SetFlagToUpdatePokemonThumbnail(CameraNode* camera);

void BattleAnim_SetModelEventTrackFromRow(ActivePokemon* pokemon, s32 cue_index);
void BattleScene_TryQueueIdleCueEffect(ActivePokemon* active_pokemon);
void BattleScene_AllocateParticipantRecord(BattleSessionTeams* session_teams, s32 side_index);
void BattleScene_InitializeRuntime(BattleSessionTeams* session_teams);

/**
 * Resets all seven state tick slots to the sentinel (no-op) callback.
 */
// called on any fade in battle
void BattleScene_ClearStateTickCallbacks(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        sBattleSceneStateTickSlots[i].callback = sBattleSceneStateTickSentinel;
    }
}

/**
 * Queues effect list 3 entry `effect_entry` on the actor's own display object
 * with no anchors (0xFF).
 */
// called on move select... sometimes. called on faint
void BattleScene_QueueRowEffectList3(ActivePokemon* actor, s32 effect_entry) {
    BattleAnim_QueueEffectList3(effect_entry, &actor->displayObject, &actor->displayObject, 0xFF, 0xFF);
}

/**
 * Queues the main move effect script for `move_id`, using the user's move
 * cue anchors and the opposing participant as the fallback owner.
 */
// played on gengar using thunderbolt in bug boy glc fight
void BattleAnim_PlayMoveEffectScript(ActivePokemon* user, s32 move_id) {
    UNUSED s16 pad;
    s16 camera_shot;
    s32 target_side_index;

    target_side_index = BattleScene_GetParticipantSideIndex(user) == 0;
    camera_shot = BattleScene_GetMoveCueDefaultAnchor(user);
    BattleAnim_QueueMoveEffectScript(move_id, user, sActivePokemon[target_side_index], camera_shot, BattleScene_GetMoveCueAlternateAnchor(user));
}

/**
 * Handles charing moves by routing to BattleAnim_SetQueuedEffectList in @src/fragments/battle_engine/battle_engine_309ED0.c
 * to which calls BattleAnim_SetQueuedEffectList unlike BattleAnim_QueueMoveEffectScript
 * Fury Swipes uses this function as a hack to allow it to both spawn the "slashing" animation of other slashing moves
 * while also being a mulithit attack.
 */
// guess: plays during changing moves like skull base
// but for some reason connected to fury swipes too?
void BattleAnim_PlayChargingMoveEffectScript(ActivePokemon* user, s32 move_id) {
    UNUSED s16 pad;
    s16 camera_shot;
    s32 target_side_index;

    target_side_index = BattleScene_GetParticipantSideIndex(user) == 0;
    camera_shot = BattleScene_GetMoveCueDefaultAnchor(user);
    BattleAnim_QueueChargingMoveEffectScript(move_id, user, sActivePokemon[target_side_index], camera_shot, BattleScene_GetMoveCueAlternateAnchor(user));
}

/**
 * Queues the end-of-move effect for `move_id` on the opposing participant,
 * anchored by the user's hit cue fields.
 */
// play on move end
void BattleAnim_PlayMoveEffectEnd(ActivePokemon* user, s32 move_id) {
    UNUSED s16 pad;
    s16 default_anchor; // TODO: more descriptive name
    s32 target_side;

    target_side = BattleScene_GetParticipantSideIndex(user) == 0;
    default_anchor = BattleScene_GetHitCueDefaultAnchor(user);
    BattleAnim_QueueMoveEffectEnd(move_id, sActivePokemon[target_side], user, default_anchor, BattleScene_GetHitCueAlternateAnchor(user));
}

void BattleScene_TickClearAnimRecordIfLoaded(ActivePokemon* active_pokemon) {
    if (BattleAnim_TryRegisterAssetTables(active_pokemon) != 0) {
        active_pokemon->animationTimer = 0;
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    }
}

s32 func_82101FD4(ActivePokemon*);
void func_8210568C(ActivePokemon*, s32, s32);

void BattleScene_TickStartRowAnimRecord(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    s32 row_index = active_pokemon->animationState;
    s32 cue_index = sBattleSceneStateRowTable[row_index].unk_20;
    MovePresentationCue* cue;

    cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[cue_index];
    if (func_82101FD4(active_pokemon) != 0) {
        func_8210568C(active_pokemon, cue_index, 2);
        active_pokemon->animationTimer = 0;
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
        ModelAnim_SetAnimation(&active_pokemon->displayObject, cue->id);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82101DB0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82101DB0.s")
#endif

void func_82101EC0(s8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x620) = 0;
}

void BattleScene_ResetOpponentStateFrameCounter(ActivePokemon* active_pokemon) {
    sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->animationTimer = 0;
}

void BattleAnim_SetFlagForRockThrowingMoves(ActivePokemon* active_pokemon) {
    BattleMonRuntime* active_pokemon_runtime = &active_pokemon->state.runtime;

    if (active_pokemon_runtime->usedMove == STRENGTH || active_pokemon_runtime->usedMove == ROCK_SLIDE || active_pokemon_runtime->usedMove == ROCK_THROW) {
        sActivePokemon[0]->displayObject.node.renderFlags |= 2;
        sActivePokemon[1]->displayObject.node.renderFlags |= 2;
    }
}

/**
 * Clears render flag 0x2 on both participants.
 */
// triggers at the end of move animations and at the end of damage animation of using a rock throwing move
void BattleAnim_ClearRockThrowingMoveFlag(ActivePokemon* active_pokemon) {
    sActivePokemon[0]->displayObject.node.renderFlags &= ~2;
    sActivePokemon[1]->displayObject.node.renderFlags &= ~2;
}

s32 func_82101F84(s8 *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x85C), u8 *, 0x1D) & 0xD0;
}

M2C_UNK func_80019F20(s8 *);                      /* extern */

s32 func_82101F94(s8 *arg0) {
    func_80019F20(M2C_FIELD(arg0, s8 **, 0x85C));
    return M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x85C), u8 *, 0x1D) & 0xC0;
}

s32 func_82101FC4(s8 *arg0) {
    return *M2C_FIELD(arg0, u8 **, 0x85C) & 0xD0;
}

s32 BattleAnim_TryRegisterAssetTables(ActivePokemon* active_pokemon) {
    if (BattleAnim_PollAssetLoadBusyFlags(active_pokemon) == 0) {
        BattleAnim_RegisterAssetTablesForSession(active_pokemon->sessionTeams);
        return 1;
    }
    return 0;
}

void BattleScene_LoadMoveResourceList(ActivePokemon* active_pokemon) {
    // FAKE
    if (sBattleScene.scene->unk_48 == 0xE) {
        BattleAnim_LoadMoveResourceList(active_pokemon->sessionTeams, BattleScene_GetParticipantUsedMove(active_pokemon));
    } else {
        BattleAnim_LoadMoveResourceList(active_pokemon->sessionTeams, BattleScene_GetParticipantUsedMove(active_pokemon));
    }
}

void BattleScene_LoadRowResourceList(ActivePokemon* active_pokemon) {
    s32 row_index = active_pokemon->animationState;

    BattleAnim_LoadModeResourceList(active_pokemon->sessionTeams, sBattleSceneStateRowTable[row_index].mode);
}

s16 func_82107BF4();                                /* extern */
M2C_UNK func_821368B0(s32, s16);                    /* extern */

void func_821020C8(s8 *arg0) {
    func_821368B0(M2C_FIELD(arg0, s32 *, 0x85C), func_82107BF4());
}

void func_821020FC(s8 *arg0) {
    s8 *temp_v0;

    M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x85C), s16 *, 2) = 0x98;
    temp_v0 = M2C_FIELD(arg0, s8 **, 0x85C);
    M2C_FIELD(temp_v0, u8 *, 0) = (u8) (M2C_FIELD(temp_v0, u8 *, 0) | 0x80);
}

void func_8210211C(s8 *arg0) {
    s8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, s8 **, 0x85C);
    M2C_FIELD(temp_v0, u8 *, 0) = (u8) (M2C_FIELD(temp_v0, u8 *, 0) | 0x80);
    M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x85C), s16 *, 2) = (s16) M2C_FIELD(arg0, s16 *, 0x84C);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210213C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210213C.s")
#endif

void BattleScene_TickRow10CleanupAndEnterState18(ActivePokemon* active_pokemon) {
    if (active_pokemon->animationTimer == 20) {
        active_pokemon->sessionTeams->uniqueStatusFlags |= 0x80;
    }

    if (active_pokemon->sessionTeams->uniqueStatusFlags & 0x10) {
        active_pokemon->sessionTeams->uniqueStatusFlags &= ~0x90;
        Battle_LoadOwnerModelForSwitchIn(active_pokemon);
        BattleThumbnail_TickOwnerCameraFraming(active_pokemon);
        Audio_PlayCommand(2, 0, 0);
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        BattleScene_EnterStateRow(active_pokemon, 18);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82102398; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82102398.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821024C8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821024C8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210278C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210278C.s")
#endif

void Battle_HandleStatBoostingMoveAnimation(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime = &active_pokemon->state.runtime;
    UNUSED s16 pad;
    s16 move;
    MovePresentationCue* anim;

    move = runtime->usedMove;
    BattleScene_GetParticipantSideIndex(active_pokemon);
    anim = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[runtime->usedMove - 1];

    if (active_pokemon->animationTimer == (anim->unk_09 + 1)) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (((move == GROWTH) || (move == MEDITATE) || (move == AGILITY) || (move == HARDEN) || (move == WITHDRAW) ||
                 (move == SWORDS_DANCE) || (move == DOUBLE_TEAM) || (move == MINIMIZE) || (move == DEFENSE_CURL) || (move == BARRIER) ||
                 (move == AMNESIA) || (move == ACID_ARMOR) || (move == SHARPEN)) &&
                (sStatCanBeChangedFurther == 1)) {
                BattleAnim_QueueEffectList6(3, active_pokemon);
                Audio_PlayCommand(35, 0, 0);
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        }
    }
}

void func_82102A34(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime;
    MovePresentationCue* cue;

    runtime = &active_pokemon->state.runtime;
    cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[runtime->usedMove - 1];
    if ((active_pokemon->animationTimer == (cue->unk_09 + 0x1F)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        if (runtime->usedMove == 0x6A) {
            Model_SetMaterialTextureMode(&active_pokemon->displayObject, 1);
        }
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82102AEC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82102AEC.s")
#endif

void BattleScene_TickRow21PlaySpeciesSound(ActivePokemon* active_pokemon) {
    s8* cue = (s8*)sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)];

    if ((M2C_FIELD(cue, u8*, 4) + 1) == M2C_FIELD(active_pokemon, s32*, 0x620)) {
        if (func_82101F84((s8*)active_pokemon) == 0) {
            func_8003FE58(1, active_pokemon->displayObject.objectType, 0);
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82102C3C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82102C3C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82102D10; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82102D10.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82102E94; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82102E94.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82102FF4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82102FF4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82103178; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82103178.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821032B0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821032B0.s")
#endif

void func_82134EBC(ActivePokemon*, s32);
void func_821033DC(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    MovePresentationCue* hit_cue = (MovePresentationCue*)((u8*)sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)] + 0x738);

    ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
    ModelAnim_SetAnimation(&active_pokemon->displayObject, hit_cue->id);
    func_82134EBC(active_pokemon, 0x1E);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210343C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210343C.s")
#endif

void func_82134DEC(s16);

void BattleScene_TickRow1PlayOwnerCry(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    ActivePokemonState* state = &active_pokemon->state;
    BattleMon* party_pokemon_ptr = &active_pokemon->teamRoster->pokemonPicked[M2C_FIELD(active_pokemon, s32*, 0x9D0)];

    if ((state->flags & ACTIVE_UNDERGROUND) || (state->flags & ACTIVE_FREEZE) || (party_pokemon_ptr->statusCondition & STATUS_SLEEP_MASK)) {
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    } else if (active_pokemon->animationTimer == 1) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (active_pokemon->displayObject.objectType >= SUBSTITUTE_DOLL) {
                func_82134DEC(state->model);
            } else {
                func_82134DEC(active_pokemon->displayObject.objectType);
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_821036F4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821036F4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210384C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210384C.s")
#endif

void func_82103998(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[2];
    s32 row_index = active_pokemon->animationState;

    if (BattleAnim_TryRegisterAssetTables(active_pokemon) != 0) {
        active_pokemon->sessionTeams->displayModel = active_pokemon->state.runtime.id;
        active_pokemon->sessionTeams->unk_04 = (TeamRoster*)&active_pokemon->teamRoster->pokemonPicked[active_pokemon->state.rosterIndex];
        active_pokemon->animationTimer = 0;
        BattleScene_QueueRowEffectList3(active_pokemon, sBattleSceneStateRowTable[row_index].mode);
        Audio_PlayCommand(3, 0, 0);
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    }
}

void BattleScene_TickQueueRowEffectList3OnFirstFrame(ActivePokemon* active_pokemon) {
    BattleScene_GetParticipantSideIndex(active_pokemon);
    if ((active_pokemon->animationTimer == 1) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        s32 row_index = active_pokemon->animationState;

        BattleScene_QueueRowEffectList3(active_pokemon, sBattleSceneStateRowTable[row_index].mode);
        Audio_PlayCommand(3, 0, 0);
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    }
}

void BattleScene_TickRow20CleanupAndEnterState18(ActivePokemon* active_pokemon) {
    if (active_pokemon->animationTimer == 79) {
        active_pokemon->sessionTeams->uniqueStatusFlags |= 0x80;
    }

    if (active_pokemon->sessionTeams->uniqueStatusFlags & 0x10) {
        active_pokemon->sessionTeams->uniqueStatusFlags &= ~0x90;

        Battle_LoadOwnerModelForSwitchIn(active_pokemon);
        BattleThumbnail_TickOwnerCameraFraming(active_pokemon);
        Audio_PlayCommand(2, 0, 0);

        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;

        BattleScene_EnterStateRow(active_pokemon, 18);
    }
}

void BattleScene_ResetOwnerModelIfLoaded(ActivePokemon* active_pokemon) {
    if (active_pokemon->sessionTeams->uniqueStatusFlags & 0x10) {
        active_pokemon->sessionTeams->uniqueStatusFlags &= ~0x90;
        Battle_ResetOwnerModelToSubstituteDoll(active_pokemon);
    }
}

void BattleScene_EnterRow8StartMappedMoveAnim(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[2];
    s32 charge_move_cue = sChargeMoveCues[active_pokemon->state.runtime.usedMove - 1];
    MovePresentationCue* cue;

    cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[charge_move_cue];
    active_pokemon->animationTimer = 0;
    ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
    ModelAnim_SetAnimation(&active_pokemon->displayObject, cue->id);
    BattleAnim_SetModelEventTrackFromRow(active_pokemon, charge_move_cue);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82103C64; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82103C64.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82103DA4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82103DA4.s")
#endif

void BattleScene_EnterRow9QueueEffectList6(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime = &sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->state.runtime;

    if (runtime->unk_4C & 0x20) {
        if ((runtime->usedMove == BIND) || (runtime->usedMove == WRAP) || (runtime->usedMove == STRING_SHOT)) {
            BattleAnim_QueueEffectList6(2, active_pokemon);
            BattleScene_SetParticipantModelTransform(active_pokemon, 16, 0);
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82103EF4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82103EF4.s")
#endif

void BattleScene_Row13PlaySequences14And21(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime = &active_pokemon->state.runtime;

    if (runtime->unk_15 & 8) {
        BattleAnim_PlayBattleSequenceById(active_pokemon, 20);
    }

    if (runtime->unk_15 & 0x10) {
        BattleAnim_PlayBattleSequenceById(active_pokemon, 33);
    }

    sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82104038; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82104038.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82104120; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82104120.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82104208; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82104208.s")
#endif

void BattleScene_TickQueueList3Selector2OrCFromB10(ActivePokemon* active_pokemon) {
    u8* cue = (u8*)sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)] + 0x79B;
    s32 first_effect_frame;

    if (cue[9] == 1) {
        first_effect_frame = cue[0xA] - 76;
    } else {
        first_effect_frame = cue[0xA] - 35;
    }

    if ((BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) && ((first_effect_frame <= 0) || (first_effect_frame == M2C_FIELD(active_pokemon, s32*, 0x620)))) {
        if (cue[9] == 1) {
            BattleAnim_QueueEffectList3(2, active_pokemon, active_pokemon, 0xFF, 0xFF);
        } else {
            BattleAnim_QueueEffectList3(12, active_pokemon, active_pokemon, 0xFF, 0xFF);
        }
        Audio_PlayCommand(3, 0, 0);
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_821044C8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821044C8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82104648; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82104648.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821047C4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821047C4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821048BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821048BC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821049E8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821049E8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82104AB0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82104AB0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82104AFC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82104AFC.s")
#endif

/**
 * Empty state callback used as the tick-slot sentinel and table filler.
 */
void BattleScene_StateCallbackNop(ActivePokemon* active_pokemon) {
}

/**
 * Stores `callback` in the first free tick slot (sentinel), if any.
 */
void BattleScene_RegisterStateTickCallback(ActivePokemon* active_pokemon, BattleSceneStateCallback callback) {
    UNUSED BattleSceneStateTickSlot* unused_slot;
    s32 i;

    for (i = 0; i < 7; i++) {
        if (sBattleSceneStateTickSentinel == sBattleSceneStateTickSlots[i].callback) {
            sBattleSceneStateTickSlots[i].callback = callback;
            sBattleSceneStateTickSlots[i].unk_00 = active_pokemon;
            break;
        }
    }
}

/**
 * Sets the cue 166 (unkA60) event track on the participant at this side index.
 */
void BattleScene_SetOpponentEventTrackA6(ActivePokemon* active_pokemon) {
    BattleAnim_SetModelEventTrackFromRow(sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon)], BATTLE_CUE_A60);
}

void BattleScene_EnterStateRow(ActivePokemon* active_pokemon, s32 row_index) {
    active_pokemon->animationState = row_index;

    sBattleSceneStateRowTable[row_index].unk_04[0](active_pokemon);
    sBattleSceneStateRowTable[row_index].unk_04[1](active_pokemon);
    sBattleSceneStateRowTable[row_index].unk_04[2](active_pokemon);

    BattleScene_RegisterStateTickCallback(active_pokemon, sBattleSceneStateRowTable[row_index].unk_04[3]);
    BattleScene_RegisterStateTickCallback(active_pokemon, sBattleSceneStateRowTable[row_index].unk_04[4]);
    BattleScene_RegisterStateTickCallback(active_pokemon, sBattleSceneStateRowTable[row_index].unk_04[5]);
    BattleScene_RegisterStateTickCallback(active_pokemon, sBattleSceneStateRowTable[row_index].unk_04[6]);
}

void BattleScene_TickStateCallbacks(void) {
    sActivePokemon[0]->animationTimer++;
    sActivePokemon[1]->animationTimer++;

    for (sBattleSceneStateTickSlotIndex = 0; sBattleSceneStateTickSlotIndex < 7; sBattleSceneStateTickSlotIndex++) {
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback(sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_00);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82104DB0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82104DB0.s")
#endif

extern s32 D_8219A750;

void func_82104E14(ActivePokemon* active_pokemon) {
    BattleScene_GetParticipantSideIndex(active_pokemon);
    if (D_8219A750 == 0) {
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        return;
    }
    if ((active_pokemon->animationTimer == D_8219A750) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        BattleAnim_QueueEffectList6(1, active_pokemon);
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82104EAC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82104EAC.s")
#endif

s32 func_82101FD4(ActivePokemon*);
void func_82101F00(ActivePokemon*);
void func_821054C4(ActivePokemon*, s32);

void BattleScene_StartHitCueAnimation(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[4];
    MovePresentationCue* cue = (MovePresentationCue*)((u8*)sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)] + 0x738);
    UNUSED s32 pad2;

    if (func_82101FD4(active_pokemon) != 0) {
        func_82101F00(active_pokemon);
        func_821054C4(active_pokemon, 0xA8);
        active_pokemon->animationTimer = 0;
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
        ModelAnim_SetAnimation(&active_pokemon->displayObject, cue->id);
    }
}

extern s32 D_8219A74C;
void func_821050D0(ActivePokemon* active_pokemon) {
    if (D_8219A74C == M2C_FIELD(active_pokemon, s32*, 0x620)) {
        if (func_82101F84((s8*)active_pokemon) == 0) {
            func_8003FE58(M2C_FIELD(active_pokemon, u8*, 0x820), active_pokemon->displayObject.objectType, 1);
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        }
    }
}

void func_82105140(ActivePokemon* active_pokemon) {
    if (D_8219A74C == M2C_FIELD(active_pokemon, s32*, 0x620)) {
        if (func_82101F84((s8*)active_pokemon) == 0) {
            func_8003FE58(M2C_FIELD(active_pokemon, u8*, 0x820), active_pokemon->displayObject.objectType, 0);
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_821051B0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821051B0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210524C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210524C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82105344; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82105344.s")
#endif

extern s32 D_8219A740;

void func_821053E0(s8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x820) = (s8) D_8219A740;
}

M2C_UNK func_82101AD0();                            /* extern */
M2C_UNK func_82104C68(s32, M2C_UNK);                /* extern */
M2C_UNK func_8213B31C(M2C_UNK);                     /* extern */

void func_821053F0(s32 arg0) {
    func_8213B31C(2);
    func_82101AD0();
    func_82104C68(arg0, 5);
}

M2C_UNK func_82101AD0();                            /* extern */
M2C_UNK func_82104C68(s32, M2C_UNK);                /* extern */
M2C_UNK func_8213B31C(M2C_UNK);                     /* extern */

void func_82105428(s32 arg0) {
    func_8213B31C(2);
    func_82101AD0();
    func_82104C68(arg0, 6);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82105460; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82105460.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82105484; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82105484.s")
#endif

void func_821054A8(s8 *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x820) == 0x6A) {
        M2C_FIELD(arg0, s8 *, 0x1C) = 0;
    }
}

void BattleAnim_SetModelEventTrackFromRow(ActivePokemon* pokemon, s32 cue_index) {
    s32 random_offset;
    s32 event_track;
    ActivePokemonState* pokemon_state = &pokemon->state;

    if (func_82101FC4(pokemon) == 0) {
        event_track = sSideBattleCues[BattleScene_GetParticipantSideIndex(pokemon)]->moveCues[cue_index].unk_01;
        if ((event_track != 0xFF) && (pokemon_state->unk_36 != 2)) {
            if ((cue_index == BATTLE_CUE_IDLE) && (pokemon->displayObject.objectType == DUGTRIO)) {
                ModelAnim_SetEventFrame(&pokemon->displayObject, 0);
                random_offset = BattleAnim_RandomRange(3);
                if (random_offset >= 3) {
                    random_offset = 2;
                }
                ModelAnim_SetEventTrack(&pokemon->displayObject, event_track + random_offset);
            } else {
                ModelAnim_SetEventFrame(&pokemon->displayObject, 0);
                ModelAnim_SetEventTrack(&pokemon->displayObject, event_track);
                pokemon_state->unk_36 = 1;
            }
        }
    }
}

s32 func_82101FC4();

s32 BattleAnim_TrySetModelEventTrackFromRow(ActivePokemon* active_pokemon, s32 cue_index, s32 event_state) {
    UNUSED s32 pad;
    s32 event_track;

    if (func_82101FC4(active_pokemon) != 0) {
        return 0;
    }

    event_track = sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[cue_index].unk_01;
    if (event_track == 0xFF) {
        return 1;
    }

    ModelAnim_SetEventFrame(&active_pokemon->displayObject, 0);
    ModelAnim_SetEventTrack(&active_pokemon->displayObject, event_track);
    ModelAnim_SetEventFrame(&active_pokemon->displayObject, active_pokemon->displayObject.eventTrack.data->endFrame);

    active_pokemon->state.unk_36 = event_state;
    return 0;
}

void func_8210568C(ActivePokemon* active_pokemon, s32 cue_index, s32 event_state) {
    UNUSED s32 pad;
    s32 event_track;

    if (func_82101FC4(active_pokemon) == 0) {
        event_track = sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[cue_index].unk_01;
        if (event_track != 0xFF) {
            ModelAnim_SetEventFrame(&active_pokemon->displayObject, 0);
            ModelAnim_SetEventTrack(&active_pokemon->displayObject, event_track);
            active_pokemon->state.unk_36 = event_state;
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82105724; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82105724.s")
#endif

s32 BattleScene_IsRowWaitCompleteWithEventCount(ActivePokemon* active_pokemon, s32 frame_limit) {
    UNUSED u8 unused_value;
    BattleMon* party_pokemon = &active_pokemon->teamRoster->pokemonPicked[M2C_FIELD(active_pokemon, s32*, 0x9D0)];
    u8* cue = (u8*)sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)] + 0x722;

    if ((M2C_FIELD(active_pokemon, u16*, 0x7C2) & 2) || (M2C_FIELD(party_pokemon, u8*, 5) & 7) || ((M2C_FIELD(active_pokemon, u16*, 0x7C2) & 0x200) && !(M2C_FIELD(active_pokemon, u16*, 0x7C2) & 0x400)) || (M2C_FIELD(active_pokemon, u16*, 0x7C2) & 0x4000)) {
        if (BattleScene_AdvanceCameraFrameCounter(frame_limit) != 0) {
            return 1;
        }
        return 0;
    }

    if ((cue[0xA] < 11) || (cue[0xA] == 0xFF)) {
        if (active_pokemon->displayObject.transformAnim.animationId == -1) {
            return 1;
        }
        return ModelAnim_IsAnimationDone(&active_pokemon->displayObject);
    }

    if (BattleScene_AdvanceCameraFrameCounter(cue[0xA] + 1) != 0) {
        return 1;
    }

    return 0;
}

s32 func_821058E8(ActivePokemon* active_pokemon, s32 frame_limit) {
    MovePresentationCue* idle_cue;
    BattleMon* party_pokemon;
    UNUSED s32 pad;
    MovePresentationCue* move_cue;

    party_pokemon = &active_pokemon->teamRoster->pokemonPicked[M2C_FIELD(active_pokemon, s32*, 0x9D0)];
    move_cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[M2C_FIELD(active_pokemon, u8*, 0x820) - 1];
    idle_cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->idleCues;

    if ((active_pokemon->state.flags & ACTIVE_FREEZE) || (party_pokemon->statusCondition & STATUS_SLEEP_MASK) ||
        ((active_pokemon->state.flags & ACTIVE_AIRBORNE) && !(active_pokemon->state.flags & ACTIVE_AIR_ACTION)) || (active_pokemon->state.flags & ACTIVE_UNDERGROUND)) {
        if (BattleScene_AdvanceCameraFrameCounter(frame_limit) != 0) {
            return 1;
        }
        return 0;
    }

    if (active_pokemon->displayObject.transformAnim.animationId == -1) {
        return 1;
    }

    if (move_cue->id == idle_cue->id) {
        if (move_cue->frameCounter != 0xFF) {
            sBattleScene.scene->unk_14++;
            if (move_cue->frameCounter == active_pokemon->animationTimer) {
                return 1;
            }
            return 0;
        }
        if (BattleScene_AdvanceCameraFrameCounter(frame_limit) != 0) {
            return 1;
        }
        return 0;
    }

    sBattleScene.scene->unk_14++;

    if (move_cue->frameCounter != 0xFF) {
        if (move_cue->frameCounter == active_pokemon->animationTimer) {
            return 1;
        }
        return 0;
    }
    return ModelAnim_IsAnimationDone(&active_pokemon->displayObject);
}

s32 func_82105AB0(ActivePokemon* active_pokemon, s32 frame_limit) {
    MovePresentationCue* idle_cue;
    BattleMon* party_pokemon;
    UNUSED s32 pad;
    s32 charge_move;
    MovePresentationCue* move_cue;

    party_pokemon = &active_pokemon->teamRoster->pokemonPicked[M2C_FIELD(active_pokemon, s32*, 0x9D0)];
    charge_move = sChargeMoveCues[active_pokemon->state.runtime.usedMove - 1];
    move_cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[charge_move];
    idle_cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->idleCues;

    if ((active_pokemon->state.flags & ACTIVE_FREEZE) || (party_pokemon->statusCondition & STATUS_SLEEP_MASK) ||
        ((active_pokemon->state.flags & ACTIVE_AIRBORNE) && !(active_pokemon->state.flags & ACTIVE_AIR_ACTION)) || (active_pokemon->state.flags & ACTIVE_UNDERGROUND)) {
        if (BattleScene_AdvanceCameraFrameCounter(frame_limit) != 0) {
            return 1;
        }
        return 0;
    }

    if (active_pokemon->displayObject.transformAnim.animationId == -1) {
        return 1;
    }

    if (move_cue->id == idle_cue->id) {
        if (move_cue->frameCounter != 0xFF) {
            sBattleScene.scene->unk_14++;
            if (move_cue->frameCounter == active_pokemon->animationTimer) {
                return 1;
            }
            return 0;
        }
        if (BattleScene_AdvanceCameraFrameCounter(frame_limit) != 0) {
            return 1;
        }
        return 0;
    }

    sBattleScene.scene->unk_14++;

    if (move_cue->frameCounter != 0xFF) {
        if (move_cue->frameCounter == active_pokemon->animationTimer) {
            return 1;
        }
        return 0;
    }
    return ModelAnim_IsAnimationDone(&active_pokemon->displayObject);
}

s32 BattleScene_IsRowAnimWaitComplete(ActivePokemon* active_pokemon, s32 frame_limit) {
    MovePresentationCue* cue = (MovePresentationCue*)((u8*)sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)] + 0x738);

    if ((active_pokemon->state.flags & ACTIVE_FREEZE) || ((active_pokemon->state.flags & ACTIVE_AIRBORNE) && !(active_pokemon->state.flags & ACTIVE_AIR_ACTION))) {
        if (BattleScene_AdvanceCameraFrameCounter(frame_limit) != 0) {
            return 1;
        }
        return 0;
    }

    if (M2C_FIELD(active_pokemon, s16*, 0x40) == -1) {
        return 1;
    }

    if (M2C_FIELD(active_pokemon, s16*, 0x40) != cue->id) {
        return 1;
    }

    return ModelAnim_IsAnimationDone(&active_pokemon->displayObject);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82105D3C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82105D3C.s")
#endif

void func_82105E38(s8 *arg0, unsigned short arg1)
{
  s8 *new_var;
  new_var = (s8 *) arg0;
  *((u16 *) (new_var + 0x7C2)) = (u16) ((*((u16 *) (new_var + 0x7C2))) | arg1);
}

void func_82105E4C(s8 *arg0, unsigned short arg1)
{
  *((u16 *) (((s8 *) arg0) + 0x7C2)) = (u16) ((*((u16 *) (((s8 *) arg0) + 0x7C2))) & (~arg1));
}

/**
 * Empty callback. Not referenced by any state row.
 */
void func_82105E64(ActivePokemon* active_pokemon) {
}

void BattleScene_ResetBothParticipantsAnimationState(void) {
    ActivePokemonState* side1_pokemon_state;
    ActivePokemonState* side2_pokemon_state;
    UNUSED s32 pad[2];
    ActivePokemon* side1_pokemon;
    ActivePokemon* side2_pokemon;
    MovePresentationCue* cue;

    side1_pokemon_state = &sActivePokemon[0]->state;
    side2_pokemon_state = &sActivePokemon[1]->state;
    side1_pokemon = sActivePokemon[0];
    side2_pokemon = sActivePokemon[1];

    if (side1_pokemon_state->flags & ACTIVE_AIR_SETTLE) {
        sActivePokemon[0]->displayObject.position.y = 200.0f;
        func_82105E38(sActivePokemon[0], ACTIVE_AIRBORNE);
        Battle_ClearRuntimeFlags(sActivePokemon[0], ACTIVE_AIR_SETTLE);
    }

    if (side2_pokemon_state->flags & ACTIVE_AIR_SETTLE) {
        sActivePokemon[1]->displayObject.position.y = 200.0f;
        func_82105E38(sActivePokemon[1], ACTIVE_AIRBORNE);
        Battle_ClearRuntimeFlags(sActivePokemon[1], ACTIVE_AIR_SETTLE);
    }

    if ((side1_pokemon_state->flags & ACTIVE_UNDERGROUND) && (side1_pokemon->displayObject.objectType == DUGTRIO)) {
        cue = (MovePresentationCue*)((u8*)sSideBattleCues[0] + 0x3DE);
        ModelAnim_SetFrame(&sActivePokemon[0]->displayObject, 0);
        ModelAnim_SetAnimation(&sActivePokemon[0]->displayObject, cue->id);
    }

    if ((side2_pokemon_state->flags & ACTIVE_UNDERGROUND) && (side2_pokemon->displayObject.objectType == DUGTRIO)) {
        cue = (MovePresentationCue*)((u8*)sSideBattleCues[1] + 0x3DE);
        ModelAnim_SetFrame(&sActivePokemon[1]->displayObject, 0);
        ModelAnim_SetAnimation(&sActivePokemon[1]->displayObject, cue->id);
    }

}

#ifdef NON_MATCHING
/* TODO: decompile func_82105FCC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82105FCC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82106144; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82106144.s")
#endif

void BattleScene_CleanupOpponentSpecialAnimFlag(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[2];
    ActivePokemon* target = sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0];

    if (target->state.flags & ACTIVE_UNDERGROUND) {
        target->displayObject.node.renderFlags |= 0x20;
        target->displayObject.node.flags |= 1;
        BattleAnim_StopOwnerCategoryParticles(4, target);
        Battle_ClearRuntimeFlags(target, 0x4000);
    }
}

void func_821366B0(u8 category, ActivePokemon* owner);
void func_82106220(ActivePokemon* active_pokemon) {
    if (M2C_FIELD(active_pokemon, u16*, 0x7C2) & 0x40) {
        func_82105E4C((s8*)active_pokemon, 0x40);
        func_82105E38((s8*)active_pokemon, 0x80);
        func_821366B0(2, active_pokemon);
    }
}

extern f32 D_FLT_82189354[];

typedef struct { f32 v; f32 pad[3]; } RestHeightRow;

void BattleScene_CleanupOpponentAnimationFlags(ActivePokemon* active_pokemon) {
    ActivePokemon* target = sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0];
    ActivePokemonState* target_state = &target->state;

    if (target_state->flags & ACTIVE_UNDERGROUND) {
        target->displayObject.node.renderFlags |= 0x20;
        target->displayObject.node.flags |= 1;
        BattleAnim_StopOwnerCategoryParticles(4, target);
        Battle_ClearRuntimeFlags(target, 0x4000);
    }

    if (target_state->flags & ACTIVE_RETURN_RESET) {
        target->displayObject.position.y = ((RestHeightRow*)D_FLT_82189354)[M2C_FIELD(target, s16*, 0x1A)].v;
        Battle_ClearRuntimeFlags(target, 0x608);
    }

    if ((active_pokemon->state.flags & 0x80) && !(M2C_FIELD(target, u8*, 0x812) & 0x20)) {
        Battle_ClearRuntimeFlags(active_pokemon, 0x80);
        BattleAnim_StopOwnerCategoryParticles(2, active_pokemon);
    }
}

M2C_UNK func_82107A5C();                            /* extern */

void func_82106354(void) {
    func_82107A5C();
}


#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void BattleScene_CleanupParticipantEffectMode(ActivePokemon* active_pokemon) {
    switch (active_pokemon->modelTransformId) {
        case 14:
            BattleScene_SetParticipantModelTransform(active_pokemon, 0, 0);
            BattleScene_PositionParticipantModel(active_pokemon);
            break;

        case 13:
        case 15:
        case 16:
            BattleScene_SetParticipantModelTransform(active_pokemon, 0, 0);
            if (active_pokemon->state.runtime.scaleResize == 0) {
                Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.scale, 1.0f, 1.0f, 1.0f);
            } else {
                Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.scale, 0.8f, 0.8f, 0.8f);
            }
            break;

        case 12:
            BattleScene_SetParticipantModelTransform(active_pokemon, 0, 0);
            if (active_pokemon->state.runtime.scaleResize == 0) {
                Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.scale, 1.0f, 1.0f, 1.0f);
            } else {
                Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.scale, 0.8f, 0.8f, 0.8f);
            }
            break;

        case 10:
            BattleScene_SetParticipantModelTransform(active_pokemon, 0, 0);
            active_pokemon->displayObject.position.y = ((RestHeightRow*)D_FLT_82189354)[M2C_FIELD(active_pokemon, s16*, 0x1A)].v;
            active_pokemon->displayObject.rotation.x = 0;
            break;

        case 9:
            BattleScene_SetParticipantModelTransform(active_pokemon, 0, 0);
            Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.scale, 0.8f, 0.8f, 0.8f);
            BattleScene_HideParticipantSecondaryModels(active_pokemon);
            break;

        case 7:
            BattleScene_SetParticipantModelTransform(active_pokemon, 0, 0);
            BattleScene_HideParticipantSecondaryModels(active_pokemon);
            break;

        case 6:
            BattleScene_SetParticipantModelTransform(active_pokemon, 0, 0);
            BattleScene_HideParticipantSecondaryModels(active_pokemon);
            BattleScene_PositionParticipantModel(active_pokemon);
            Vec3s_SetComponents(&active_pokemon->displayObject.rotation, 0, active_pokemon->facingDirection << 0xE, 0);
            break;

        case 4:
            BattleScene_SetParticipantModelTransform(active_pokemon, 0, 0);
            active_pokemon->displayObject.rotation.y = active_pokemon->facingDirection << 0xE;
            BattleScene_HideParticipantSecondaryModels(active_pokemon);
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82106374.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821065B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821065B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82106AC0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82106AC0.s")
#endif

void func_821366B0(u8 category, ActivePokemon* owner);


void BattleAnim_ResetFreezeStatusAndRestoreAnimation(ActivePokemon* arg0) {
    u8* ptr = (u8*)&arg0->teamRoster->pokemonPicked[M2C_FIELD(arg0, s32*, 0x9D0)];

    if (!(M2C_FIELD(arg0, u16*, 0x7C2) & 2) && (ptr[5] & 0x20)) {
        func_821366B0(1, arg0);
        M2C_FIELD(arg0, u8*, 2) &= ~0x20;
        func_82105E38((s8*)arg0, 2);
    }
}

void func_8210568C(ActivePokemon* active_pokemon, s32 cue_index, s32 event_state);
void func_82134EBC(ActivePokemon*, s32);

void BattleAnim_TriggerStatusAfflictionCry(ActivePokemon* active_pokemon) {
    BattleMon* party_pokemon = &active_pokemon->teamRoster->pokemonPicked[M2C_FIELD(active_pokemon, s32*, 0x9D0)];

    if ((party_pokemon->statusCondition & STATUS_SLEEP_MASK) && !(active_pokemon->state.flags & ACTIVE_SLEEP)) {
        func_8210568C(active_pokemon, BATTLE_CUE_SLEEP_IDLE, 2);
        func_821366B0(3, active_pokemon);
        func_82134EBC(active_pokemon, 50);
    }
}

void BattleScene_AllocateParticipantRecord(BattleSessionTeams* session_teams, s32 side_index) {
    ActivePokemon* active_pokemon = main_pool_alloc(0xA8C, 0);

    sActivePokemon[side_index] = active_pokemon;

    bzero(active_pokemon, 0xA8C);
    bzero(&sActivePokemon[side_index]->state, sizeof(ActivePokemonState));
    bzero(&sActivePokemon[side_index]->state.runtime, sizeof(BattleMonRuntime));
    bzero(&sActivePokemon[side_index]->thumbnail, sizeof(ThumbnailState));
    bzero(&sActivePokemon[side_index]->state.runtime.moveCache, sizeof(CachedMoveData));
    bzero(&sActivePokemon[side_index]->state.unk_9C, sizeof(unk_D_84390010_654_09C));
    bzero(&sActivePokemon[side_index]->state.unk_AC, sizeof(unk_D_84390010_654_0AC));
    bzero(&sActivePokemon[side_index]->captionState, sizeof(MonCaptionState));
    sActivePokemon[side_index]->sessionTeams = session_teams;
}

M2C_UNK func_8211F3F4();                            /* extern */

void func_82106D18(void) {
    func_8211F3F4();
}

/**
 * Allocates both participants and the message queues.
 */
void BattleScene_AllocateParticipants(BattleSessionTeams* battle_teams) {
    BattleScene_AllocateParticipantRecord(&battle_teams[0], 0);
    BattleScene_AllocateParticipantRecord(&battle_teams[1], 1);
    Battle_InitMessageQueues();
    sSide1ActivePokemon = sActivePokemon[0];
    sSide2ActivePokemon = sActivePokemon[1];
}

#ifdef NON_MATCHING
/* TODO: decompile func_82106D90; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82106D90.s")
#endif

extern s32 D_84390174;
extern unk_D_84390178 D_84390178;
void func_821079E8(s32);

void func_821081D0(ActivePokemon*);

void func_82107FB8(ActivePokemon*);
void func_82108090(ActivePokemon*, void*);
void func_82108340(ActivePokemon*);
void func_82121D5C(s32, s32);
void func_82108A88(ActivePokemon*, s32, s32);
void func_8211F430(void);
void func_8211F274(ActivePokemon*);

void BattleScene_InitializePresentation(UNUSED BattleSessionTeams* session_teams) {
    BattleScene_InitializeParticipantController(sActivePokemon[0]);
    BattleScene_InitializeParticipantController(sActivePokemon[1]);
    func_821081D0(sActivePokemon[0]);
    func_821081D0(sActivePokemon[1]);
    func_82107FB8(sActivePokemon[0]);
    func_82107FB8(sActivePokemon[1]);
    func_82108090(sActivePokemon[0], &sActivePokemon[0]->afterimages);
    func_82108090(sActivePokemon[1], &sActivePokemon[1]->afterimages);
    func_82108340(sActivePokemon[0]);
    func_82108340(sActivePokemon[1]);

    switch (gSessionContext.mode) {
        case 0:
            func_82121D5C(8, 0);
            break;
        case 1:
        case 2:
            func_82121D5C(4, 0);
            break;
        case 3:
            func_82121D5C(5, 50);
            break;
        case 4:
            func_82121D5C(7, 0);
            break;
        case 6:
            func_82121D5C(9, 50);
            break;
        case 5:
            func_82121D5C(0xB, 0);
            break;
    }

    func_82108A88(sActivePokemon[0], 0, 0);
    func_82108A88(sActivePokemon[1], 0, 0);
    func_821079E8(0x1FFE);
    func_8211F430();
    func_8211F274(sActivePokemon[0]);
    func_8211F274(sActivePokemon[1]);
}

void BattleScene_ResetParticipantAuxTransform(UNUSED ActivePokemon* owner, ActivePokemon* active_pokemon, s32 facing_direction) {
    Vec3f_SetComponentsDuplicate(&active_pokemon->modelTransform, 0.0f, 0.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(&active_pokemon->modelTransform.rotation, 0.0f, 0.0f, 0.0f);
    active_pokemon->facingDirection = facing_direction;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82106FE0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82106FE0.s")
#endif

/**
 * Per-frame idle presentation for both participants.
 */
void BattleScene_UpdateParticipantsAndQueueEffects(UNUSED ActivePokemon* side1_pokemon, UNUSED ActivePokemon* side2_pokemon) {
    Battle_ReturnToIdleAnimIfFinished(sActivePokemon[0], sActivePokemon[0]);
    Battle_ReturnToIdleAnimIfFinished(sActivePokemon[1], sActivePokemon[1]);
    BattleAnim_PlayTransformInducingAnimation(0);
    BattleAnim_PlayTransformInducingAnimation(1);
    BattleScene_TryQueueIdleCueEffect(sActivePokemon[0]);
    BattleScene_TryQueueIdleCueEffect(sActivePokemon[1]);
}

/**
 * Battle scene lifecycle dispatcher: allocate (0), update (1, 2),
 * initialize (3) and HUD render (5). Always returns 0.
 */
s32 BattleScene_DispatchLifecycle(s32 lifecycle_stage, BattleSessionTeams* session_teams) {
    switch (lifecycle_stage) {
        case 0:
            BattleScene_AllocateParticipants(session_teams);
            break;

        case 1:
        case 2:
            BattleScene_UpdateParticipantsAndQueueEffects(sActivePokemon[0], sActivePokemon[1]);
            break;

        case 3:
            BattleScene_InitializeRuntime(session_teams);
            break;

        case 5:
            Battle_RenderHud();
            break;
    }

    return 0;
}

void BattleThumbnail_TriggerOwnerModelAnimation(ActivePokemon* active_pokemon) {
    ModelAnim_SetFrame(&active_pokemon->thumbnail.displayObject, active_pokemon->thumbnail.idleTimer);
    ModelAnim_SetAnimation(&active_pokemon->thumbnail.displayObject, active_pokemon->thumbnail.idleAnimation);
    BattleThumbnail_SetFlagToUpdatePokemonThumbnail(active_pokemon->thumbnail.camera);
}

void func_821071AC(s8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x9D8) = 0;
}

void func_821071B4(s8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x9D8) = 1;
}

extern M2C_UNK D_82199DE0;

void func_821071C0(void) {
    M2C_FIELD(M2C_FIELD(&D_82199DE0, s8 **, 0), s32 *, 0x9D8) = 0;
    M2C_FIELD(M2C_FIELD(&D_82199DE0, s8 **, 4), s32 *, 0x9D8) = 0;
}

extern M2C_UNK D_82199DE0;

void func_821071DC(void) {
    M2C_FIELD(M2C_FIELD(&D_82199DE0, s8 **, 0), s32 *, 0x9D8) = 1;
    M2C_FIELD(M2C_FIELD(&D_82199DE0, s8 **, 4), s32 *, 0x9D8) = 1;
}

/*
    Sets flag to update the thumbnail.
    Battle_RenderActivePokemonThumbnail in @src/fragments/battle_engine/battle_engine_main.c
*/
void BattleThumbnail_SetFlagToUpdatePokemonThumbnail(CameraNode* camera) {
    camera->node.flags |= 0x10;
}

void BattleThumbnail_LoadOwnerCameraFramingConstants(ActivePokemon* active_pokemon) {
    s32 side;

    if (active_pokemon == sActivePokemon[0]) {
        side = 0;
    } else {
        side = 1;
    }

    active_pokemon->thumbnail.camera->viewport.width = sSideThumbnailSettings[side].width;
    active_pokemon->thumbnail.camera->viewport.x = sSideThumbnailSettings[side].x;
    active_pokemon->thumbnail.camera->viewport.y = sSideThumbnailSettings[side].y;

    active_pokemon->thumbnail.side = sSideThumbnailSettings[side].unk_14;

    active_pokemon->thumbnail.camera->perspective.nearPlane = sSideThumbnailSettings[side].nearPlane;
    active_pokemon->thumbnail.camera->perspective.farPlane = sSideThumbnailSettings[side].farPlane;
    active_pokemon->thumbnail.camera->perspective.verticalFieldOfView = sSideThumbnailSettings[side].verticalFieldOfView;
}
