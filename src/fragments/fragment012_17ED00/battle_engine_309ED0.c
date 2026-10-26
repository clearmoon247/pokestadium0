/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_309ED0.c, src/fragments/battle_engine/battle_engine_339CA0.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "model_animation.h"
#include "model_renderer.h"
#include "audio_commands.h"
#include "3D140.h"
#include "audio_fade.h"
#include "audio_loop_point.h"
#include "cry.h"
#include "matrix.h"
extern s32 pad_D_84390210[4];
extern s32 sMultihitCount;
extern s32 sMultihitCountdown;

#include "fragments/battle_engine/battle_engine.h"
#include "model_animation.h"
#include "geo_render.h"
#include "gfx_buffer.h"
#include "matrix.h"
#include "math_util.h"

#include "m2c_macros.h"
void func_821254B0(void);

void BattleScene_ResetAnimationStep(void);
void func_82124EF4(void);
void BattleScene_ClearPhaseFlag(void);
void BattleScene_SetPhaseFlag(void);
void BattleScene_SetPhase(UNUSED CameraNode* arg0, s32 arg1);
s32 BattleScene_TransitionToPhaseFull(s32 arg0);
s32 BattleScene_TransitionToPhase(s32 arg0);
void func_82126A1C(UNUSED CameraNode* arg0);
void BattleScene_PhaseSendOutAfterFaint(CameraNode* arg0);

void BattleScene_AdvanceSendOutPreparation(CameraNode* arg0);
void BattleScene_AdvanceSendOutCamera(CameraNode* arg0);
void BattleScene_AdvanceSendOutCameraClose(CameraNode* arg0);
void BattleScene_FinishSendOutCameraClose(CameraNode* arg0);
void BattleScene_AdvanceSendOutFollowupCamera(CameraNode* arg0);
void BattleScene_CompleteSendOutFollowup(UNUSED CameraNode* arg0);

void BattleScene_ResetAnimationStep(void) {
    sBattleScene.scene->unk_24 = 0;
}

void func_82105E4C(ActivePokemon*, s32);

void func_8210211C(ActivePokemon* active_pokemon);
void func_82108A0C(ActivePokemon* active_pokemon);
s32 func_82124A50(ActivePokemon* arg0) {
    UNUSED s32 pad[2];
    s32 sp1C = 0;

    if (!(arg0->state.flags & 0x2000)) {
        return 0;
    }

    if (sBattleScene.scene->unk_48 == 0x19) {
        return 0;
    }

    switch (sBattleScene.scene->unk_24) {
        case 0:
            func_8210211C(arg0);
            sp1C = 1;
            sBattleScene.scene->unk_24++;
            break;

        case 1:
            sp1C = 1;
            if (arg0->sessionTeams->uniqueStatusFlags & 0x10) {
                arg0->sessionTeams->uniqueStatusFlags &= ~0x90;
                func_82108A0C(arg0);
                sBattleScene.scene->unk_24++;
            }
            break;

        case 2:
            break;
    }
    return sp1C;
}

void func_821020FC(ActivePokemon*);

s32 BattleScene_AdvanceOwnerAnimation98(ActivePokemon* arg0) {
    UNUSED s32 pad[2];
    s32 sp1C = 0;

    if (!(arg0->state.flags & 0x2000)) {
        return 0;
    }

    switch (sBattleScene.scene->unk_24) {
        case 0:
            func_821020FC(arg0);
            sp1C = 1;
            sBattleScene.scene->unk_24++;
            break;

        case 1:
            sp1C = 1;
            if (arg0->sessionTeams->uniqueStatusFlags & 0x10) {
                arg0->sessionTeams->uniqueStatusFlags &= ~0x90;
                Battle_ReloadSubstituteDoll(arg0);
                sBattleScene.scene->unk_24++;
            }
            break;

        case 2:
            break;
    }
    return sp1C;
}

s32 func_82124BF8(ActivePokemon* arg0) {
    UNUSED s32 pad[2];
    s32 sp1C = 0;

    if (!(arg0->state.flags & 0x1000)) {
        return 0;
    }

    switch (sBattleScene.scene->unk_24) {
        case 0:
            func_8210211C(arg0);
            sp1C = 1;
            sBattleScene.scene->unk_24++;
            break;

        case 1:
            sp1C = 1;
            if (arg0->sessionTeams->uniqueStatusFlags & 0x10) {
                arg0->sessionTeams->uniqueStatusFlags &= ~0x90;
                func_82108A0C(arg0);
                func_82105E4C(arg0, 0x3800);
                sBattleScene.scene->unk_24++;
            }
            break;

        case 2:
            break;
    }
    return sp1C;
}

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void func_821020FC(ActivePokemon*);
void func_821089D0(ActivePokemon*);

s32 BattleScene_AdvanceBothOwnerAnimations(void) {
    UNUSED s32 pad[2];
    s32 sp1C = 0;
    ActivePokemonState* temp_a1 = &sActivePokemon[0]->state;
    ActivePokemonState* temp_a2 = &sActivePokemon[1]->state;

    if (sBattleScene.scene->unk_44 != 1) {
        return 0;
    }

    if (!(temp_a1->flags & 0x2000) && !(temp_a2->flags & 0x2000)) {
        return 0;
    }

    switch (sBattleScene.scene->unk_24) {
        case 0:
            if (temp_a1->flags & 0x2000) {
                func_821020FC(sActivePokemon[0]);
            }
            sp1C = 1;
            sBattleScene.scene->unk_24 = sBattleScene.scene->unk_24 + 1;
            break;

        case 1:
            sp1C = 1;
            if (temp_a1->flags & 0x2000) {
                if (sActivePokemon[0]->sessionTeams->uniqueStatusFlags & 0x10) {
                    sActivePokemon[0]->sessionTeams->uniqueStatusFlags &= ~0x90;
                    func_821089D0(sActivePokemon[0]);
                    sBattleScene.scene->unk_24 += 1;
                }
            } else {
                sBattleScene.scene->unk_24 = sBattleScene.scene->unk_24 + 1;
            }
            break;

        case 2:
            if (temp_a2->flags & 0x2000) {
                func_821020FC(sActivePokemon[1]);
            }
            sp1C = 1;
            sBattleScene.scene->unk_24 = sBattleScene.scene->unk_24 + 1;
            break;

        case 3:
            sp1C = 1;
            if (temp_a2->flags & 0x2000) {
                if (sActivePokemon[1]->sessionTeams->uniqueStatusFlags & 0x10) {
                    sActivePokemon[1]->sessionTeams->uniqueStatusFlags &= ~0x90;
                    func_821089D0(sActivePokemon[1]);
                    sBattleScene.scene->unk_24 += 1;
                }
            } else {
                sBattleScene.scene->unk_24 = sBattleScene.scene->unk_24 + 1;
            }
            break;

        case 4:
            break;
    }

    return sp1C;
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82124CD0.s")
#endif

M2C_UNK func_82108C0C(s32);                         /* extern */
extern s32 D_8219A544;
extern s8 *D_8219A5A0;

void func_82124E80(void) {
    M2C_FIELD(D_8219A5A0, s32 *, 0x50) = 1;
    func_82108C0C(D_8219A544);
}

M2C_UNK func_82108C0C(s32);                         /* extern */
extern s32 D_8219A540;
extern s32 D_8219A544;
extern s8 *D_8219A5A0;

void func_82124EB4(void) {
    M2C_FIELD(D_8219A5A0, s32 *, 0x50) = 3;
    func_82108C0C(D_8219A544);
    func_82108C0C(D_8219A540);
}

void func_82124EF4(void) {
}

void func_82124EFC(void) {
    s32 sp24;
    ActivePokemonState* temp_s0;
    ActivePokemonState* temp_s1;
    BattleMonRuntime* ptr;

    temp_s0 = &sActivePokemon[0]->state;
    temp_s1 = &sActivePokemon[1]->state;
    BattleScene_SetCameraSubstate(1, 1);

    sp24 = sBattleScene.scene->unk_2C;
    sBattleScene.scene->unk_2C = Battle_DetermineMoveOrder(sActivePokemon[0], sActivePokemon[1]);

    ptr = &sActivePokemon[sBattleScene.scene->unk_2C]->state.runtime;
    if (M2C_FIELD(ptr, u8*, 0x5A) == 0xFF) {
        sBattleScene.scene->unk_2C = !sBattleScene.scene->unk_2C;
    }

    if (sActivePokemon[0]->teamRoster->unk_000 & 2) {
        if (sBattleScene.scene->unk_2C == 0) {
            BattleAI_RecordUsedMove(temp_s0->rosterIndex, temp_s1->rosterIndex, 0);
        } else {
            BattleAI_RecordUsedMove(temp_s0->rosterIndex, temp_s1->rosterIndex, 1);
        }
    } else if (sActivePokemon[1]->teamRoster->unk_000 & 2) {
        if (sBattleScene.scene->unk_2C == 1) {
            BattleAI_RecordUsedMove(temp_s1->rosterIndex, temp_s0->rosterIndex, 0);
        } else {
            BattleAI_RecordUsedMove(temp_s1->rosterIndex, temp_s0->rosterIndex, 1);
        }
    }

    sBattleScene.scene->unk_2A = sBattleScene.scene->unk_2C;
    sBattleScene.scene->unk_38 = 0;
    temp_s0->unk_30 = 0;
    temp_s1->unk_30 = 0;
    if (sBattleScene.scene->unk_1C == 5) {
        sBattleScene.scene->unk_44 = 6;
    } else {
        sBattleScene.scene->unk_44 = 2;
    }
    Battle_ResolveMonAction();
    sBattleScene.scene->unk_2C = sp24;
}

#ifdef NON_MATCHING
/* TODO: decompile func_821250D4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821250D4.s")
#endif

void BattleScene_InitializeSwitchActions(void) {
    s32 sp2C;
    ActivePokemonState* sp28;
    ActivePokemonState* sp24;

    sp28 = &sActivePokemon[0]->state;
    sp24 = &sActivePokemon[1]->state;
    BattleScene_SetCameraSubstate(1, 1);

    sp2C = sBattleScene.scene->unk_2C;

    if ((sp28->unk_2D == 0xF) || (sp28->unk_2D == 0x10)) {
        if (sActivePokemon[0]->teamRoster->unk_000 & 2) {
            BattleAI_RecordUsedMove(sp28->rosterIndex, sp24->rosterIndex, 2);
        }
        sBattleScene.scene->unk_2C = 0;
        sBattleScene.scene->unk_2A = 0;
        sBattleScene.scene->unk_38 = 0;
        sBattleScene.scene->unk_44 = 2;
        BeginBattleForEntity(sActivePokemon[0]);
        sBattleScene.scene->unk_2C = sp2C;
    } else {
        if (sActivePokemon[0]->teamRoster->unk_000 & 2) {
            BattleAI_RecordUsedMove(sp24->rosterIndex, sp28->rosterIndex, 2);
        }
        sBattleScene.scene->unk_2C = 1;
        sBattleScene.scene->unk_2A = 1;
        sBattleScene.scene->unk_38 = 0;
        sBattleScene.scene->unk_44 = 2;
        BeginBattleForEntity(sActivePokemon[1]);
        sBattleScene.scene->unk_2C = sp2C;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82125384; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82125384.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821254B0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821254B0.s")
#endif

void BattleScene_ClearPhaseFlag(void) {
    sBattleScene.scene->unk_3C = 0;
}

void BattleScene_SetPhaseFlag(void) {
    sBattleScene.scene->unk_3C = 1;
}

void BattleScene_SetPhase(UNUSED CameraNode* arg0, s32 arg1) {
    sBattleScene.scene->unk_38 = arg1;
    sBattleScene.scene->unk_20 = 0;
}

M2C_UNK func_821079E8(M2C_UNK);                     /* extern */
extern s8 *D_8219A5A0;

void func_821255B4(s8 *arg0) {
    func_821079E8(0x1FFE);
    M2C_FIELD(D_8219A5A0, f32 *, 0x60) = (f32) M2C_FIELD(arg0, f32 *, 0x2C);
}

M2C_UNK func_821079E8(M2C_UNK);                     /* extern */
extern s8 *D_8219A5A0;

void func_821255EC(s8 *arg0) {
    func_821079E8(0x1FFE);
    M2C_FIELD(arg0, f32 *, 0x2C) = 30.0f;
    M2C_FIELD(D_8219A5A0, f32 *, 0x60) = 30.0f;
}

void func_80040738(void);
void func_8212562C(void) {
    BattleMonRuntime* runtime;
    BattleMonRuntime* other_runtime;
    ActivePokemonState* other_state;
    s32 other;

    if (sBattleScene.scene->unk_34 == 0) {
        BattleAnim_ClearRockThrowingMoveFlag(sActivePokemon[sBattleScene.scene->unk_2C]);
        func_80040738();
        BattleScene_ResetAnimationStep();
        runtime = &sActivePokemon[sBattleScene.scene->unk_2C]->state.runtime;
        other = sBattleScene.scene->unk_2C == 0;
        other_runtime = &sActivePokemon[other]->state.runtime;
        other_state = &sActivePokemon[other]->state;
        if ((runtime->usedMove == 0xFF) || (other_runtime->usedMove == 0xFF)) {
            if ((other_state->unk_2D != 0xF) && (other_state->unk_2D != 0x10)) {
                sBattleScene.scene->unk_20 = 0;
                sBattleScene.scene->unk_14 = 0;
                sBattleScene.scene->unk_38 = 4;
                return;
            }
        }
        func_821254B0();
        sBattleScene.scene->unk_20 = 0;
        sBattleScene.scene->unk_14 = 0;
        sBattleScene.scene->unk_38 = 3;
    } else {
        BattleAnim_ClearRockThrowingMoveFlag(sActivePokemon[sBattleScene.scene->unk_2C]);
        func_80040738();
        BattleScene_ResetAnimationStep();
        sBattleScene.scene->unk_20 = 0;
        sBattleScene.scene->unk_14 = 0;
        sBattleScene.scene->unk_38 = 4;
    }
}

void func_80040738(void);
s32 BattleScene_HandleFaintStatusCompletion(void) {
    s8* temp_v0 = (s8*)D_8219A540 + 0x7C6;

    if (((M2C_FIELD(temp_v0, u8*, 0x4D) & 0x80) || (M2C_FIELD(temp_v0, u8*, 0x15) & 0x18)) && (M2C_FIELD(temp_v0, u8*, 0x5A) == 0xFF)) {
        BattleAnim_ClearRockThrowingMoveFlag(sActivePokemon[sBattleScene.scene->unk_2C]);
        func_80040738();
        BattleScene_ResetAnimationStep();
        func_821254B0();
        sBattleScene.scene->unk_20 = 0;
        sBattleScene.scene->unk_14 = 0;
        M2C_FIELD(sBattleScene.scene, s32*, 0x38) = 3;
        return 1;
    }
    return 0;
}

extern ActivePokemon* D_84390200;
void func_821254B0(void);

void BattleScene_CompleteActionPhase(void) {
    if ((sBattleScene.scene->unk_34 == 0) && (M2C_FIELD(D_8219A540, u8*, 0x820) != 0xFF)) {
        BattleAnim_ClearRockThrowingMoveFlag(sActivePokemon[sBattleScene.scene->unk_2C]);
        Audio_FadeAndClearStoredSounds();
        BattleScene_ResetAnimationStep();
        func_821254B0();
        sBattleScene.scene->unk_20 = 0;
        sBattleScene.scene->unk_14 = 0;
        sBattleScene.scene->unk_38 = 3;
    } else if (BattleScene_HandleFaintStatusCompletion() == 0) {
        BattleAnim_ClearRockThrowingMoveFlag(sActivePokemon[sBattleScene.scene->unk_2C]);
        Audio_FadeAndClearStoredSounds();
        BattleScene_ResetAnimationStep();
        sBattleScene.scene->unk_20 = 0;
        sBattleScene.scene->unk_14 = 0;
        sBattleScene.scene->unk_38 = 4;
    }
}

s32 BattleScene_TransitionToPhaseFull(s32 arg0) {
    BattleScene_ClearPhaseFlag();
    BattleScene_ResetCameraFrameCounter();
    sBattleScene.scene->unk_48 = 0;
    sBattleScene.scene->unk_4C = 0;
    sBattleScene.scene->unk_20 = 0;
    sBattleScene.scene->unk_14 = 0;
    sBattleScene.scene->unk_38 = arg0;
    return 1;
}

s32 BattleScene_TransitionToPhase(s32 arg0) {
    BattleScene_ClearPhaseFlag();
    BattleScene_ResetCameraFrameCounter();
    sBattleScene.scene->unk_4C = 0;
    sBattleScene.scene->unk_20 = 0;
    sBattleScene.scene->unk_14 = 0;
    sBattleScene.scene->unk_38 = arg0;
    return 1;
}

extern s32 D_84390220;
extern s32 D_84390224;
s32 func_8211EE8C();

extern s32 D_8219A560;
extern s32 D_8219A564;
u16 func_82107CA0(ActivePokemon* active_pokemon);
void func_82125838(void);
void BattleScene_ResolveDisplayedHpCompletion(CameraNode* arg0) {
    if ((D_8219A560 == 1) && (D_8219A564 == 1)) {
        BattleScene_ResetCameraFrameCounter();
        func_8211EE8C();
        BattleScene_ClearPhaseFlag();
        if (func_82107CA0(sActivePokemon[sBattleScene.scene->unk_2C]) == 0) {
            BattleScene_SetPhase(arg0, 5);
            sBattleScene.scene->unk_2C = !sBattleScene.scene->unk_2C;
        } else if (func_82107CA0(sActivePokemon[!sBattleScene.scene->unk_2C]) == 0) {
            BattleScene_SetPhase(arg0, 5);
        } else {
            func_82125838();
        }
    }
}

M2C_UNK func_82125570();
M2C_UNK func_8212188C();
M2C_UNK func_82106220();
void func_82125594(CameraNode* arg0, s32 arg1);
M2C_UNK func_821259E8();
M2C_UNK func_82125990();
s32 func_82125930(M2C_UNK);

void BattleScene_UpdateDisplayedHpAndTransition(CameraNode* arg0) {
    u8* sp1C = (u8*)sActivePokemon[sBattleScene.scene->unk_2C] + 0x7C6;

    func_82125570();
    func_8212188C();
    func_8211EE8C();
    func_82106220(D_8219A540);

    if (Battle_GetActiveMonHp(sActivePokemon[sBattleScene.scene->unk_2C]) == 0) {
        sBattleScene.scene->unk_2C = !sBattleScene.scene->unk_2C;
        func_82125594(arg0, 5);
    } else if (Battle_GetActiveMonHp(sActivePokemon[!sBattleScene.scene->unk_2C]) == 0) {
        func_821259E8(arg0);
    } else if (sBattleScene.scene->unk_4C == 0xA) {
        func_82125990(0xA);
    } else if (sBattleScene.scene->unk_48 == 9) {
        func_82125930(9);
    } else if ((sp1C[0x15] & 0x18) || (sp1C[0x4D] & 0x80)) {
        func_82125930(6);
    } else {
        func_821259E8(arg0);
    }
}

s32 func_8210F31C(s32);                             /* extern */
M2C_UNK func_82125AC8(s32);                         /* extern */
extern s32 D_82199DE0;
extern s32 D_82199DE4;
extern s32 D_8219A560;
extern s32 D_8219A564;

void func_82125C34(s32 arg0) {
    D_8219A560 = func_8210F31C(D_82199DE0);
    D_8219A564 = func_8210F31C(D_82199DE4);
    func_82125AC8(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82125C80; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82125C80.s")
#endif

s32 func_82125930(M2C_UNK);                         /* extern */
extern s8 *D_8219A5A0;

s32 func_82125CC8(void) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(D_8219A5A0, s32 *, 0x48);
    if (temp_v0 == 7) {
        return func_82125930(7);
    }
    if (temp_v0 == 0x1E) {
        return func_82125930(0x1E);
    }
    if (temp_v0 == 0x1C) {
        return func_82125930(0x1C);
    }
    if (temp_v0 == 0x15) {
        return func_82125930(0x15);
    }
    if (temp_v0 == 0xF) {
        return func_82125930(0xF);
    }
    if (temp_v0 == 0x19) {
        return func_82125930(0x19);
    }
    if (temp_v0 == 0x1B) {
        return func_82125930(0x1B);
    }
    if (temp_v0 == 0x1D) {
        return func_82125930(0x1D);
    }
    if (temp_v0 == 0xC) {
        return func_82125930(0xC);
    }
    if (temp_v0 == 0xD) {
        return func_82125930(0xD);
    }
    if (temp_v0 == 0xE) {
        return func_82125930(0xE);
    }
    if (temp_v0 == 0x11) {
        return func_82125930(0x11);
    }
    if (temp_v0 == 0x1F) {
        return func_82125930(0x1F);
    }
    return 0;
}

s32 func_82125930(M2C_UNK);                         /* extern */
extern u8 D_82199F31;
extern s8 *D_8219A5A0;

s32 func_82125E5C(void) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(D_8219A5A0, s32 *, 0x48);
    if (temp_v0 == 0x16) {
        return func_82125930(0x16);
    }
    if (temp_v0 == 0x20) {
        return func_82125930(0x20);
    }
    if (temp_v0 == 0x1A) {
        return func_82125930(0x1A);
    }
    if (temp_v0 == 0x17) {
        return func_82125930(0x17);
    }
    if (temp_v0 == 0x14) {
        return func_82125930(0x14);
    }
    if (temp_v0 == 0x10) {
        return func_82125930(0x10);
    }
    if ((D_82199F31 != 0) || (temp_v0 == 8)) {
        return func_82125930(8);
    }
    return 0;
}

s32 BattleScene_PrepareResidualStatusPresentation(void) {
    s32 idx = sBattleScene.scene->unk_2C;
    BattleMonRuntime* temp_v1_2 = &sActivePokemon[idx]->state.runtime;

    if (((temp_v1_2->unk_4D & 0x80) || (temp_v1_2->unk_15 & 0x18)) && (temp_v1_2->usedMove == 0xFF)) {
        return BattleScene_TransitionToPhaseFull(0x23);
    }
    return 0;
}

void BattleScene_UpdateActiveOwnerPointers(void) {
    s32 idx;

    D_8219A544 = sActivePokemon[sBattleScene.scene->unk_2C];
    idx = sBattleScene.scene->unk_2C == 0;
    D_8219A540 = sActivePokemon[idx];
    sBattleScene.scene->unk_50 = 0;
}

M2C_UNK func_800419F8(M2C_UNK);                     /* extern */
M2C_UNK func_82108C0C(s32);                         /* extern */
M2C_UNK func_821218AC(s32, s32, f32, s32, f32, s32, s32); /* extern */
M2C_UNK func_82121D78(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_821224F4();                            /* extern */
M2C_UNK func_82124A40();                            /* extern */
M2C_UNK func_82125570();                            /* extern */
extern M2C_UNK D_8218B630;
extern s32 D_82199DE0;
extern s32 D_82199DE4;
extern s8 *D_8219A5A0;
extern f32 D_FLT_821962A4;

void func_8212601C(s32 arg0) {
    s8 *sp34;
    s8 *sp30;

    sp34 = D_8219A544;
    sp30 = D_8219A540;
    func_800419F8(0);
    func_82121D78(arg0, 0x41A00000, 0x457A0000);
    func_82124A40();
    M2C_FIELD(D_8219A5A0, s32 *, 0x14) = 0;
    M2C_FIELD(D_8219A5A0, s16 *, 0x58) = 0;
    M2C_FIELD(D_8219A5A0, s16 *, 0x5A) = 0;
    M2C_FIELD(D_8219A5A0, f32 *, 0x5C) = (f32) D_FLT_821962A4;
    M2C_FIELD(D_8219A5A0, s32 *, 0x34) = 0;
    func_821224F4();
    func_82125570();
    if ((M2C_FIELD(sp34, f32 *, 0x28) > 100.0f) && (M2C_FIELD(sp30, f32 *, 0x28) > 100.0f)) {
        func_821218AC(arg0, M2C_FIELD(&D_8218B630, s32 *, 0), M2C_FIELD(&D_8218B630, f32 *, 4) + 200.0f, M2C_FIELD(&D_8218B630, s32 *, 8), M2C_FIELD(D_8219A5A0, f32 *, 0x5C), (s32) M2C_FIELD(D_8219A5A0, s16 *, 0x58), (s32) M2C_FIELD(D_8219A5A0, s16 *, 0x5A));
    } else {
        func_821218AC(arg0, M2C_FIELD(&D_8218B630, s32 *, 0), M2C_FIELD(&D_8218B630, f32 *, 4), M2C_FIELD(&D_8218B630, s32 *, 8), M2C_FIELD(D_8219A5A0, f32 *, 0x5C), (s32) M2C_FIELD(D_8219A5A0, s16 *, 0x58), (s32) M2C_FIELD(D_8219A5A0, s16 *, 0x5A));
    }
    func_82108C0C(D_82199DE0);
    func_82108C0C(D_82199DE4);
    M2C_FIELD(D_8219A5A0, s32 *, 0x20) = (s32) (M2C_FIELD(D_8219A5A0, s32 *, 0x20) + 1);
}

void func_821247F0(void*, void*);
s32 func_82124810(void*, void*);
void func_82124830(void*, void*);
void func_82124874(void*, void*);

void func_821261A0(void* arg0, void* arg1, s32 arg2) {
    switch (arg2) {
        case 0:
            func_821247F0(arg1, arg0);
            break;
        case 1:
            func_82124810(arg1, arg0);
            break;
        case 2:
            func_82124830(arg1, arg0);
            break;
        default:
            func_82124874(arg1, arg0);
            break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82126220; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82126220.s")
#endif

void func_8212239C(ActivePokemon* arg0, CameraNode* arg1);
s32 func_82126220(ActivePokemon*);
void func_82126380(CameraNode* arg0) {
    if (func_82124A50(sActivePokemon[!sBattleScene.scene->unk_2C]) == 0) {
        Battle_ClearRuntimeFlags(sActivePokemon[!sBattleScene.scene->unk_2C], 0x3800);
        func_821261A0(sActivePokemon[!sBattleScene.scene->unk_2C], arg0, 3);
        func_80040738();
        BattleAnim_CleanupEffects(2);
        BattleScene_ResetCameraFrameCounter();
        Battle_ClearMessageCursor();
        func_8212239C(sActivePokemon[!sBattleScene.scene->unk_2C], arg0);
        if (func_82126220(sActivePokemon[!sBattleScene.scene->unk_2C]) != 0) {
            BattleScene_EnterStateRow(sActivePokemon[!sBattleScene.scene->unk_2C], 0x11);
            sBattleScene.scene->unk_20 = 0xA;
        } else {
            BattleScene_EnterStateRow(sActivePokemon[!sBattleScene.scene->unk_2C], 0);
            sBattleScene.scene->unk_20 += 1;
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_821264E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821264E4.s")
#endif

void func_821229AC(CameraNode* arg0, ActivePokemon* arg1);
s32 func_8211EE8C();
void func_80040738(void);

void BattleScene_AdvanceSendOutCameraClose(CameraNode* arg0) {
    func_821229AC(arg0, sActivePokemon[!sBattleScene.scene->unk_2C]);
    if (BattleScene_AdvanceCameraFrameCounter(0x19) != 0) {
        func_8211EE8C();
        func_80040738();
        sBattleScene.scene->unk_20++;
    }
}

s32 func_80041374(s32, u32);

void BattleScene_FinishSendOutCameraClose(CameraNode* arg0) {
    ActivePokemonState* temp_s0 = &sActivePokemon[!sBattleScene.scene->unk_2C]->state;

    func_821229AC(arg0, sActivePokemon[!sBattleScene.scene->unk_2C]);

    if (BattleScene_AdvanceCameraFrameCounter(5) != 0) {
        BattleAnim_CleanupEffects(1);
        func_80041374(3, 0);

        if (temp_s0->unk_2D != 0x12) {
            temp_s0->unk_2D = 0x10;
        }

        if (temp_s0->unk_2D == 0x12) {
            temp_s0->unk_2D = 0x13;
        }

        sBattleScene.scene->unk_20++;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8212684C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212684C.s")
#endif

void func_82126A1C(UNUSED CameraNode* arg0) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_82126A24; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82126A24.s")
#endif

void BattleScene_PhaseSendOutAfterFaint(CameraNode* arg0) {
    switch (sBattleScene.scene->unk_20) {
        case 0:
            BattleScene_AdvanceSendOutPreparation(arg0);
            break;

        case 1:
            BattleScene_AdvanceSendOutCamera(arg0);
            break;

        case 2:
            BattleScene_AdvanceSendOutCameraClose(arg0);
            break;

        case 3:
            BattleScene_FinishSendOutCameraClose(arg0);
            break;

        case 4:
            BattleScene_CompleteSendOutFollowup(arg0);
            break;

        case 5:
            func_82126A1C(arg0);
            break;

        case 10:
            BattleScene_AdvanceSendOutFollowupCamera(arg0);
            break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82126D20; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82126D20.s")
#endif

void func_82126D20(UNUSED CameraNode* arg0);
void func_82126E34(CameraNode* arg0) {
    switch (sBattleScene.scene->unk_20) {
        case 0:
            BattleScene_AdvanceSendOutPreparation(arg0);
            break;

        case 1:
            BattleScene_AdvanceSendOutCamera(arg0);
            break;

        case 2:
            BattleScene_AdvanceSendOutCameraClose(arg0);
            break;

        case 3:
            BattleScene_FinishSendOutCameraClose(arg0);
            break;

        case 4:
            func_82126D20(arg0);
            break;

        case 5:
            func_82126A1C(arg0);
            break;

        case 10:
            BattleScene_AdvanceSendOutFollowupCamera(arg0);
            break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82126EE0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82126EE0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82126F70; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82126F70.s")
#endif

void func_82126EE0(CameraNode* arg0);
void func_82126F70(CameraNode* arg0);
void func_82125594(CameraNode* arg0, s32 arg1);

void BattleScene_Phase2(CameraNode* arg0) {
    switch (sBattleScene.scene->unk_20) {
        case 0:
            func_82126EE0(arg0);
            break;

        case 1:
            func_82126F70(arg0);
            break;

        case 2:
            func_82125594(arg0, 2);
            break;
    }
}

void func_821272C0(s8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x7BE) = 0x800;
}

#ifdef NON_MATCHING
/* TODO: decompile func_821272CC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821272CC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82127354; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82127354.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82127724; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82127724.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82127DFC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82127DFC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212817C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212817C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82128510; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82128510.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82128780; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82128780.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82128848; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82128848.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82128CDC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82128CDC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82128E34; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82128E34.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82128F2C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82128F2C.s")
#endif

void func_82124984(ActivePokemon* arg0, CameraNode* arg1, s32 arg2);
void func_8212239C(ActivePokemon* arg0, CameraNode* arg1);
void func_821228B0(CameraNode* arg0, ActivePokemon* arg1);
s32 func_821058E8(ActivePokemon* arg0, s32 arg1);

void func_82128FBC(CameraNode* arg0) {
    switch (sBattleScene.scene->unk_3C) {
        case 0:
            M2C_FIELD(sBattleScene.scene, s32*, 0x50) = 4;
            if (BattleScene_AdvanceCameraFrameCounter(0x14) != 0) {
                BattleScene_SetPhaseFlag();
                func_82124984((ActivePokemon*)D_8219A544, arg0, 0);
                func_8212239C((ActivePokemon*)D_8219A544, arg0);
                BattleScene_ResetCameraSubstepCounter();
            }
            break;
        case 1:
            M2C_FIELD(sBattleScene.scene, s32*, 0x50) = 4;
            func_821228B0(arg0, (ActivePokemon*)D_8219A544);
            if (BattleScene_AdvanceCameraSubstepCounter(0xF) != 0) {
                Battle_ClearMessageCursor();
            }
            if (func_821058E8((ActivePokemon*)D_8219A544, 0x32) != 0) {
                Battle_ClearMessageCursor();
                BattleScene_ResetCameraFrameCounter();
                BattleScene_ClearPhaseFlag();
                M2C_FIELD(sBattleScene.scene, s32*, 0x50) = 0;
                sBattleScene.scene->unk_20++;
            }
            break;
    }
}

void func_821290CC(CameraNode* arg0) {
    switch (sBattleScene.scene->unk_3C) {
        case 0:
            M2C_FIELD(sBattleScene.scene, s32*, 0x50) = 4;
            if (BattleScene_AdvanceCameraFrameCounter(0x14) != 0) {
                BattleScene_SetPhaseFlag();
                func_82124984((ActivePokemon*)D_8219A544, arg0, 1);
                func_8212239C((ActivePokemon*)D_8219A544, arg0);
                Battle_ClearMessageCursor();
                BattleScene_ResetCameraSubstepCounter();
            }
            break;
        case 1:
            M2C_FIELD(sBattleScene.scene, s32*, 0x50) = 4;
            func_821228B0(arg0, (ActivePokemon*)D_8219A544);
            if (BattleScene_AdvanceCameraSubstepCounter(0xF) != 0) {
                Battle_ClearMessageCursor();
            }
            if (func_821058E8((ActivePokemon*)D_8219A544, 0x32) != 0) {
                Battle_ClearMessageCursor();
                BattleScene_ResetCameraFrameCounter();
                BattleScene_ClearPhaseFlag();
                M2C_FIELD(sBattleScene.scene, s32*, 0x50) = 0;
                sBattleScene.scene->unk_20++;
            }
            break;
    }
}

void func_821291E4(CameraNode* arg0) {
    switch (sBattleScene.scene->unk_3C) {
        case 0:
            M2C_FIELD(sBattleScene.scene, s32*, 0x50) = 4;
            if (BattleScene_AdvanceCameraFrameCounter(0x14) != 0) {
                BattleScene_SetPhaseFlag();
                func_82124984((ActivePokemon*)D_8219A544, arg0, 2);
                func_8212239C((ActivePokemon*)D_8219A544, arg0);
                Battle_ClearMessageCursor();
                BattleScene_ResetCameraSubstepCounter();
            }
            break;
        case 1:
            M2C_FIELD(sBattleScene.scene, s32*, 0x50) = 4;
            func_821228B0(arg0, (ActivePokemon*)D_8219A544);
            if (BattleScene_AdvanceCameraSubstepCounter(0xF) != 0) {
                Battle_ClearMessageCursor();
            }
            if (func_821058E8((ActivePokemon*)D_8219A544, 0x32) != 0) {
                Battle_ClearMessageCursor();
                BattleScene_ResetCameraFrameCounter();
                BattleScene_ClearPhaseFlag();
                M2C_FIELD(sBattleScene.scene, s32*, 0x50) = 0;
                sBattleScene.scene->unk_20++;
            }
            break;
    }
}

void func_821292FC(CameraNode* arg0) {
    switch (sBattleScene.scene->unk_3C) {
        case 0:
            M2C_FIELD(sBattleScene.scene, s32*, 0x50) = 4;
            if (BattleScene_AdvanceCameraFrameCounter(0x14) != 0) {
                BattleScene_SetPhaseFlag();
                func_82124984((ActivePokemon*)D_8219A544, arg0, 3);
                func_8212239C((ActivePokemon*)D_8219A544, arg0);
                Battle_ClearMessageCursor();
                BattleScene_ResetCameraSubstepCounter();
            }
            break;
        case 1:
            M2C_FIELD(sBattleScene.scene, s32*, 0x50) = 4;
            func_821228B0(arg0, (ActivePokemon*)D_8219A544);
            if (BattleScene_AdvanceCameraSubstepCounter(0xF) != 0) {
                Battle_ClearMessageCursor();
            }
            if (func_821058E8((ActivePokemon*)D_8219A544, 0x32) != 0) {
                Battle_ClearMessageCursor();
                BattleScene_ResetCameraFrameCounter();
                BattleScene_ClearPhaseFlag();
                M2C_FIELD(sBattleScene.scene, s32*, 0x50) = 0;
                sBattleScene.scene->unk_20++;
            }
            break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82129414; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82129414.s")
#endif

extern s32 D_8219A568;
void func_82128FBC(CameraNode*);
void func_821290CC(CameraNode*);
void func_821291E4(CameraNode*);

void func_8212954C(CameraNode* arg0) {
    if (sBattleScene.scene->unk_3C == 0) {
        D_8219A568 = BattleAnim_RandomRange(3);
        if (D_8219A568 >= 4) {
            D_8219A568 = 0;
        }
    }
    switch (D_8219A568) {
        case 0:
            func_82128FBC(arg0);
            break;
        case 1:
            func_821290CC(arg0);
            break;
        case 2:
            func_821291E4(arg0);
            break;
        default:
            func_82128FBC(arg0);
            break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8212960C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212960C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821296E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821296E4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821297BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821297BC.s")
#endif

void func_8211F034(s32, s32);
void func_821366B0(s32, ActivePokemon*);
s32 func_82105724(ActivePokemon*, s32);
extern s32 D_8219A520;
void func_821299B0(CameraNode* arg0) {
    switch (sBattleScene.scene->unk_3C) {
        case 0:
            if (BattleScene_AdvanceCameraFrameCounter(0x14) != 0) {
                sBattleScene.scene->unk_50 = 4;
                BattleScene_SetPhaseFlag();
                Battle_ClearMessageCursor();
                func_8211F034(D_8219A520 + 0x148, sBattleScene.scene->unk_2C);
                func_82124984((ActivePokemon*)D_8219A544, arg0, 3);
                func_8212239C((ActivePokemon*)D_8219A544, arg0);
                BattleScene_ResetCameraSubstepCounter();
                func_821366B0(7, (ActivePokemon*)D_8219A544);
            }
            break;
        case 1:
            func_821228B0(arg0, (ActivePokemon*)D_8219A544);
            if (BattleScene_AdvanceCameraSubstepCounter(0x28) != 0) {
                Battle_ClearMessageCursor();
            }
            if (func_82105724((ActivePokemon*)D_8219A544, 0x1E) != 0) {
                sBattleScene.scene->unk_50 = 0;
                Battle_ClearMessageCursor();
                BattleScene_ResetCameraFrameCounter();
                BattleScene_ClearPhaseFlag();
                sBattleScene.scene->unk_20 += 1;
            }
            break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82129AE8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82129AE8.s")
#endif

extern ActivePokemon* D_84390204;
M2C_UNK func_82124284(s32, s32, f32);
M2C_UNK func_821243DC(s32, s32, f32);
void BattleScene_ActionSetupAnimationVariantB(CameraNode* arg0) {
    M2C_FIELD(sBattleScene.scene, s32*, 0x50) = 2;
    switch (sBattleScene.scene->unk_3C) {
        case 0:
            M2C_FIELD(sBattleScene.scene, s32*, 0x50) = 2;
            BattleAnim_CleanupEffects(1);
            BattleScene_ClearCameraOffsetVectors();
            BattleScene_SetPhaseFlag();
            func_82124284((s32)arg0, D_8219A540, 0.0f);
            break;

        case 1:
            func_821243DC((s32)arg0, D_8219A540, 0.0f);
            if (M2C_FIELD(sBattleScene.scene, f32*, 0x74) <= 1.0f) {
                BattleScene_CleanupParticipantEffectMode((ActivePokemon*)D_8219A544);
                sBattleScene.scene->unk_20++;
                BattleScene_ResetCameraFrameCounter();
                BattleScene_ClearPhaseFlag();
            }
            break;
    }
}

extern s32 D_8219A540;
M2C_UNK func_82124284(s32, s32, f32);
M2C_UNK func_821243DC(s32, s32, f32);
f32 func_82107EC8(s32);

void func_82129D10(CameraNode* arg0) {
    M2C_FIELD(sBattleScene.scene, s32*, 0x50) = 2;
    switch (sBattleScene.scene->unk_3C) {
        case 0:
            BattleAnim_CleanupEffects(1);
            BattleScene_ClearCameraOffsetVectors();
            BattleScene_SetPhaseFlag();
            func_82124284((s32)arg0, D_8219A540, func_82107EC8(D_8219A540) * 2.0f);
            break;
        case 1:
            if (BattleAnim_IsSessionBusy((ActivePokemon*)D_8219A540) == 0) {
                func_821243DC((s32)arg0, D_8219A540, func_82107EC8(D_8219A540) * 2.0f);
                if (M2C_FIELD(sBattleScene.scene, f32*, 0x74) <= 1.0f) {
                    BattleScene_CleanupParticipantEffectMode((ActivePokemon*)D_8219A544);
                    sBattleScene.scene->unk_20++;
                    BattleScene_ClearPhaseFlag();
                    BattleScene_ResetCameraFrameCounter();
                }
            }
            break;
    }
}

M2C_UNK func_82106374(s32);                         /* extern */
f32 func_82107EC8(s32);                             /* extern */
M2C_UNK func_8212188C();                            /* extern */
M2C_UNK func_821224F4();                            /* extern */
M2C_UNK func_82124284(s32, s32, f32);               /* extern */
M2C_UNK func_821243DC(s32, s32, f32);               /* extern */
M2C_UNK func_82125570();                            /* extern */
M2C_UNK func_82125580();                            /* extern */
M2C_UNK func_8213B31C(M2C_UNK);                     /* extern */
extern s32 D_8219A540;
extern s32 D_8219A544;
extern s8 *D_8219A5A0;
extern f32 D_FLT_821963A0;
extern f32 D_FLT_821963A4;

void func_82129E30(s32 arg0) {
    s32 temp_v0;

    M2C_FIELD(D_8219A5A0, s32 *, 0x50) = 2;
    temp_v0 = M2C_FIELD(D_8219A5A0, s32 *, 0x3C);
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_8213B31C(1);
        func_821224F4();
        func_82125580();
        func_82124284(arg0, D_8219A540, -func_82107EC8(D_8219A540) * D_FLT_821963A0);
        return;
    case 1:
        func_821243DC(arg0, D_8219A540, -func_82107EC8(D_8219A540) * D_FLT_821963A4);
        if (M2C_FIELD(D_8219A5A0, f32 *, 0x74) <= 1.0f) {
            func_82106374(D_8219A544);
            func_82125570();
            func_8212188C();
            M2C_FIELD(D_8219A5A0, s32 *, 0x20) = (s32) (M2C_FIELD(D_8219A5A0, s32 *, 0x20) + 1);
        }
        return;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82129F5C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82129F5C.s")
#endif

M2C_UNK func_82106374(s32);                         /* extern */
M2C_UNK func_8212188C();                            /* extern */
M2C_UNK func_821224F4();                            /* extern */
M2C_UNK func_82124544(s32, s32, M2C_UNK, M2C_UNK, f32, f32, s32); /* extern */
M2C_UNK func_82124664(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_82125570();                            /* extern */
M2C_UNK func_82125580();                            /* extern */
M2C_UNK func_8213B31C(M2C_UNK);                     /* extern */
extern s32 D_8219A540;
extern s32 D_8219A544;
extern s8 *D_8219A5A0;

void func_8212A074(s32 arg0) {
    s32 temp_v0;

    M2C_FIELD(D_8219A5A0, s32 *, 0x50) = 2;
    temp_v0 = M2C_FIELD(D_8219A5A0, s32 *, 0x3C);
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_8213B31C(1);
        func_821224F4();
        func_82125580();
        func_82124544(arg0, D_8219A540, 0x41200000, 0x41400000, 3.5f, 6.0f, 0x11C6);
        return;
    case 1:
        func_82124664(arg0, D_8219A540, 0x11C6);
        if (M2C_FIELD(D_8219A5A0, f32 *, 0x74) <= (M2C_FIELD(D_8219A5A0, f32 *, 0x5C) + 1.0f)) {
            func_82106374(D_8219A544);
            M2C_FIELD(D_8219A5A0, s32 *, 0x20) = (s32) (M2C_FIELD(D_8219A5A0, s32 *, 0x20) + 1);
            func_82125570();
            func_8212188C();
        }
        return;
    }
}

extern s32 D_8219A568;
void func_82129C1C(CameraNode*);
void func_82129D10(CameraNode*);
void func_82129E30(s32);

void func_8212A190(CameraNode* arg0) {
    if (sBattleScene.scene->unk_3C == 0) {
        D_8219A568 = BattleAnim_RandomRange(3);
        if (D_8219A568 >= 4) {
            D_8219A568 = 0;
        }
    }
    switch (D_8219A568) {
        case 0:
            func_82129C1C(arg0);
            break;
        case 1:
            func_82129D10(arg0);
            break;
        case 2:
            func_82129E30((s32)arg0);
            break;
        default:
            func_82129C1C(arg0);
            break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8212A250; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212A250.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
typedef struct MoveAnimInfoZ {
    /* 0x00 */ u8 pad00[4];
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u8 pad06[4];
} MoveAnimInfoZ; // size = 0xA
extern MoveAnimInfoZ D_80073D90[];
void func_82106144(s32);
s32 func_82125E5C(void);
void func_82129F5C(CameraNode*);
void func_8212A250(CameraNode*);
void func_8212A328(CameraNode* arg0, s32 arg1) {
    UNUSED s32 pad;
    BattleMonRuntime* runtime = &((ActivePokemon*)D_8219A540)->state.runtime;

    if (BattleScene_AdvanceOwnerAnimation98((ActivePokemon*)D_8219A540) != 0) {
        return;
    }
    func_82106144(D_8219A544);
    if (6 == D_80073D90[runtime->usedMove - 1].unk_04) {
        arg1 = D_8219A568;
    }
    if ((arg1 != 5) && (arg1 != 6) && (arg1 != 7)) {
        D_8219A568 = arg1;
    }
    if (func_82125E5C() != 0) {
        return;
    }
    func_821255EC(arg0);
    switch (arg1) {
        case 0:
            BattleScene_ActionSetupAnimationVariantB(arg0);
            break;
        case 1:
            func_82129D10(arg0);
            break;
        case 2:
            func_82129E30((s32)arg0);
            break;
        case 3:
            func_82129F5C(arg0);
            break;
        case 4:
            func_8212A074((s32)arg0);
            break;
        case 5:
            func_8212A190(arg0);
            break;
        case 7:
            func_8212A250(arg0);
            break;
        default:
            BattleScene_ActionSetupAnimationVariantB(arg0);
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212A328.s")
#endif

extern s32 D_8219A578;

void func_8212A4A4(s8 *arg0) {
    D_8219A578 = 0;
    if (M2C_FIELD(arg0, s8 *, 1) != 0) {
        D_8219A578 = 1;
    }
}

M2C_UNK func_82108C0C(s32);                         /* extern */
M2C_UNK func_8211EE8C();                            /* extern */
s32 func_82121820(M2C_UNK);                         /* extern */
M2C_UNK func_8212188C();                            /* extern */
M2C_UNK func_8212189C();                            /* extern */
M2C_UNK func_82124A40();                            /* extern */
M2C_UNK func_82125570();                            /* extern */
M2C_UNK func_82125AC8(s32);                         /* extern */
extern s32 D_8219A544;
extern s8 *D_8219A5A0;

void func_8212A4CC(s32 arg0, s32 *arg1, s32 *arg2) {
    if ((*arg1 == 1) && (*arg2 == 1) && (func_82121820(0x1E) != 0)) {
        func_82108C0C(D_8219A544);
        M2C_FIELD(D_8219A5A0, s8 *, 0x1A) = 0;
        func_8212188C();
        func_8212189C();
        func_8211EE8C();
        func_82125570();
        func_82124A40();
        func_82125AC8(arg0);
    }
}

s32 func_8210C020(M2C_UNK);                         /* extern */
extern s32 D_8219A568;

void func_8212A554(s32 arg0) {
    s32 temp_v0;

    if (arg0 == 4) {
        temp_v0 = func_8210C020(3);
        D_8219A568 = temp_v0;
        if (temp_v0 >= 4) {
            D_8219A568 = 0;
        }
    } else if (arg0 != 5) {
        D_8219A568 = arg0;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8212A5AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212A5AC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212A67C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212A67C.s")
#endif

void func_8212A5AC(ActivePokemon* arg0, CameraNode* arg1);
void func_8212A67C(ActivePokemon* arg0, CameraNode* arg1);
void func_821247F0(void*, void*);
s32 func_82124810(void*, void*);
void func_82124830(void*, void*);
void func_82124874(void*, void*);

void func_8212A768(ActivePokemon* arg0, CameraNode* arg1, s32 arg2) {
    if (arg2 == 4) {
        func_8212A5AC(arg0, arg1);
    } else if (arg2 == 6) {
        func_8212A67C(arg0, arg1);
    } else {
        if (arg2 == 5) {
            arg2 = D_8219A568;
        }
        switch (arg2) {
            case 0:
                func_821247F0(arg1, arg0);
                break;
            case 1:
                func_82124810(arg1, arg0);
                break;
            case 2:
                func_82124830(arg1, arg0);
                break;
            case 3:
                func_82124874(arg1, arg0);
                break;
            default:
                func_82124874(arg1, arg0);
                break;
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8212A850; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212A850.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212AD10; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212AD10.s")
#endif
