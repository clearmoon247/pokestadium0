/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_3438B0.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "gfx_buffer.h"

#include "m2c_macros.h"

void func_8211F034(s32, s32);
extern s32 D_8219A520;

void BattleAnim_RenderNop1(void);
void BattleAnim_RenderNop2(void);

void BattleAnim_RenderNop1(void) {
}

void BattleAnim_RenderNop2(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_8212B270; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212B270.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212BA28; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212BA28.s")
#endif

void func_821255EC(CameraNode*);
void func_82110B44(ActivePokemon*);
void func_8212A850(CameraNode*, void*);
void func_8212AD10(CameraNode*, void*);
void func_8212B270(CameraNode*, void*);
void func_8212BA28(CameraNode*, void*);

void func_8212BF28(CameraNode* arg0, void* arg1) {
    s32 other;

    func_821255EC(arg0);
    sBattleScene.scene->unk_50 = 2;
    other = sBattleScene.scene->unk_2C == 0;
    func_82110B44(sActivePokemon[other]);
    if (sBattleScene.scene->unk_1A == 3) {
        func_8212BA28(arg0, arg1);
    } else if (sBattleScene.scene->unk_1A == 1) {
        func_8212B270(arg0, arg1);
    } else if (sBattleScene.scene->unk_1A == 2) {
        func_8212AD10(arg0, arg1);
    } else {
        func_8212A850(arg0, arg1);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8212BFF0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212BFF0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212C1C4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212C1C4.s")
#endif

s32 func_8210C020(M2C_UNK, s32);                    /* extern */
M2C_UNK func_82124984(s32, s32, M2C_UNK);           /* extern */
extern s32 D_8219A544;
extern s32 D_8219A568;
void func_8212C398(s32 arg0)
{
  s32 temp_v0;
  s32 var_v1;
 temp_v0 = func_8210C020(3, arg0); D_8219A568 = temp_v0; var_v1 = temp_v0; if (temp_v0 >= 4) { D_8219A568 = 0 ^ 0; var_v1 = 0; } switch (var_v1) { case 0:
      func_82124984(D_8219A544, arg0, 0);
      return;

    case 1:
      func_82124984(D_8219A544, arg0, 1);
      return;

    case 2:
      func_82124984(D_8219A544, arg0, 2);
      return;

    default:
      func_82124984(D_8219A544, arg0, 0);
      return;

  }

}

s32 func_8210C020(M2C_UNK, s32);                    /* extern */
M2C_UNK func_82124984(s32, s32, M2C_UNK);           /* extern */
extern s32 D_8219A544;
extern s32 D_8219A568;
void func_8212C454(s32 arg0)
{
  s32 temp_v0;
  s32 var_v1;
 temp_v0 = func_8210C020(4, arg0); D_8219A568 = temp_v0;
  var_v1 = temp_v0;
  if (temp_v0 >= 5)
  {
    D_8219A568 = 0;
    var_v1 = 0;
  }
  switch (var_v1)
  {
    case 0:
      func_82124984(D_8219A544, arg0, 0);
      return;

    case 1:
      func_82124984(D_8219A544, arg0, 1);
      return;

    case 2:
      func_82124984(D_8219A544, arg0, 2);
      return;

    case 3:
      func_82124984(D_8219A544, arg0, 3);
      return;

    default:
      func_82124984(D_8219A544, arg0, 0);
      return;

  }

}

s32 func_8210C020(M2C_UNK, s32);                    /* extern */
M2C_UNK func_82124984(s32, s32, M2C_UNK);           /* extern */
extern s32 D_8219A544;
extern s32 D_8219A568;
void func_8212C530(s32 arg0)
{
  s32 temp_v0;
  s32 var_v1;
 do { temp_v0 = func_8210C020(4, arg0); D_8219A568 = temp_v0; var_v1 = temp_v0 & 0xFFFFFFFFFFFFFFFF; } while (0);
  if (temp_v0 >= 5)
  {
    D_8219A568 = 0;
    var_v1 = 0;
  }
  switch (var_v1)
  {
    case 0:
      func_82124984(D_8219A544, arg0, 0);
      return;

    case 1:
      func_82124984(D_8219A544, arg0, 1);
      return;

    case 2:
      func_82124984(D_8219A544, arg0, 2);
      return;

    case 3:
      func_82124984(D_8219A544, arg0, 4);
      return;

    default:
      func_82124984(D_8219A544, arg0, 0);
      return;

  }

}

#ifdef NON_MATCHING
/* TODO: decompile func_8212C60C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212C60C.s")
#endif

void func_821247F0(void*, void*);
s32 func_82124810(void*, void*);
void func_82124830(void*, void*);
void func_82124874(void*, void*);

void func_8212C6E8(ActivePokemon* arg0, CameraNode* arg1, s32 arg2) {
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

typedef struct MoveAnimInfoZ {
    /* 0x00 */ u8 pad00[2];
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u8 pad04[2];
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u8 pad08[2];
} MoveAnimInfoZ; // size = 0xA
extern MoveAnimInfoZ D_80073D90[];
void func_8212C60C(s32, s32);

void func_8212C78C(s32 arg0) {
    BattleMonRuntime* runtime;

    runtime = &((ActivePokemon*)D_8219A544)->state.runtime;
    M2C_FIELD(sBattleScene.scene, s32*, 0x54) = 0;
    if (D_80073D90[runtime->usedMove - 1].unk_02 == 5) {
        func_8212C398(arg0);
    } else if (D_80073D90[runtime->usedMove - 1].unk_02 == 6) {
        func_8212C454(arg0);
    } else if (D_80073D90[runtime->usedMove - 1].unk_02 == 7) {
        func_8212C530(arg0);
    } else if (D_80073D90[runtime->usedMove - 1].unk_02 == 4) {
        M2C_FIELD(sBattleScene.scene, s32*, 0x54) = 1;
        func_8212C60C(arg0, D_80073D90[runtime->usedMove - 1].unk_02);
    } else {
        func_8212C60C(arg0, D_80073D90[runtime->usedMove - 1].unk_02);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8212C874; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212C874.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212CB58; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212CB58.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212CF90; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212CF90.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212D194; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212D194.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212D504; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212D504.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212D820; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212D820.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212DB28; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212DB28.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212DD14; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212DD14.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212DE30; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212DE30.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212E0B0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212E0B0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212E350; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212E350.s")
#endif

extern s32 D_84390220;
extern ActivePokemon* D_84390204;
extern s32 D_84390224;
#ifdef NON_MATCHING
/* TODO: decompile func_8212E634; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212E634.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212E7B0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212E7B0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212E9C8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212E9C8.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
void func_821255EC(CameraNode*);
void func_8212E9C8(ActivePokemon*);
void func_8212C6E8(ActivePokemon*, CameraNode*, s32);
void func_8212239C(ActivePokemon*, CameraNode*);
void func_821366B0(s32, ActivePokemon*);
s32 func_8210F31C(ActivePokemon*);
s32 func_82122DFC(CameraNode*, ActivePokemon*);
s32 func_82105724(ActivePokemon*, s32);
s32 func_82124BF8(ActivePokemon*);
void func_82125C34(CameraNode*);
extern s32 D_8219A560;
extern s32 D_8219A564;
void BattleScene_PhaseFaint(CameraNode* arg0) {
    func_821255EC(arg0);

    switch (sBattleScene.scene->unk_20) {
        case 0:
            if (BattleScene_AdvanceOwnerAnimation98((ActivePokemon*)D_8219A544) == 0) {
                func_8212E9C8((ActivePokemon*)D_8219A544);
                func_8211F034(D_8219A520 + 0xC8, sBattleScene.scene->unk_2C);
                sBattleScene.scene->unk_20 += 1;
            }
            break;

        case 1:
            BattleScene_ResetAnimationStep();
            BattleScene_EnterStateRow((ActivePokemon*)D_8219A544, 0xF);
            func_8212C6E8((ActivePokemon*)D_8219A544, arg0, D_8219A568 = BattleAnim_RandomRange(4));
            func_8212239C((ActivePokemon*)D_8219A544, arg0);
            BattleScene_SetDamageShakeAmplitude((ActivePokemon*)D_8219A544);
            func_821366B0(8, (ActivePokemon*)D_8219A544);
            sBattleScene.scene->unk_20 += 1;
            break;

        case 2:
            D_8219A560 = func_8210F31C(sActivePokemon[sBattleScene.scene->unk_2C]);
            D_8219A564 = func_8210F31C(sActivePokemon[!sBattleScene.scene->unk_2C]);
            func_82122DFC(arg0, (ActivePokemon*)D_8219A544);
            if (func_82105724((ActivePokemon*)D_8219A544, 0x32) != 0) {
                sBattleScene.scene->unk_20 += 1;
            }
            break;

        case 3:
            if (func_82124BF8((ActivePokemon*)D_8219A544) == 0) {
                sBattleScene.scene->unk_20 += 1;
            }
            break;

        case 4:
            D_8219A560 = func_8210F31C(sActivePokemon[sBattleScene.scene->unk_2C]);
            D_8219A564 = func_8210F31C(sActivePokemon[!sBattleScene.scene->unk_2C]);
            if (func_82122DFC(arg0, (ActivePokemon*)D_8219A544) != 0) {
                BattleScene_ResetAnimationStep();
                func_82125C34(arg0);
            }
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212EA84.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212ECC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212ECC8.s")
#endif

extern s32 D_8219A568;
void func_821247F0(void*, void*);
s32 func_82124810(void*, void*);
void func_82124830(void*, void*);
void func_82124874(void*, void*);

void func_8212EEC0(ActivePokemon* arg0, CameraNode* arg1) {
    D_8219A568 = BattleAnim_RandomRange(3);
    if (D_8219A568 >= 4) {
        D_8219A568 = 0;
    }
    switch (D_8219A568) {
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
/* TODO: decompile func_8212EF74; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212EF74.s")
#endif

void func_8212EF74(ActivePokemon*, CameraNode*);

void func_8212F044(CameraNode* arg0) {
    s32 other = sBattleScene.scene->unk_2C == 0;
    ActivePokemon* opp = sActivePokemon[other];
    BattleMonRuntime* runtime = &opp->state.runtime;

    if (D_80073D90[runtime->usedMove - 1].unk_06 == 5) {
        func_8212C6E8(opp, arg0, D_8219A568);
    } else if (D_80073D90[runtime->usedMove - 1].unk_06 == 4) {
        func_8212EEC0(opp, arg0);
    } else if (D_80073D90[runtime->usedMove - 1].unk_06 == 6) {
        func_8212EF74(opp, arg0);
    } else {
        func_8212C6E8(opp, arg0, D_80073D90[runtime->usedMove - 1].unk_06);
    }
}

M2C_UNK func_8211EE8C();                            /* extern */
M2C_UNK func_82125384();                            /* extern */
extern s8 *D_8219A5A0;

void func_8212F118(s32 arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(D_8219A5A0, s32 *, 0x20);
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_8211EE8C();
        func_82125384();
        /* fallthrough */
    case 1:
        return;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8212F16C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212F16C.s")
#endif

extern s32 D_84390228;
extern ActivePokemon* D_84390200;
void func_821255EC(CameraNode*);
void func_8212C6E8(ActivePokemon*, CameraNode*, s32);
void func_8210626C(ActivePokemon*);
void func_82124E80(void);
s32 func_821217DC(s32);
M2C_UNK func_8211EE8C();
void func_82125C34(CameraNode*);
extern ActivePokemon* D_8219A540;
void BattleScene_PhaseMoveFailedMessage(CameraNode* arg0) {
    ActivePokemonState* sp1C = &D_8219A540->state;

    func_821255EC(arg0);
    M2C_FIELD(sBattleScene.scene, s32*, 0x50) = 2;

    switch (sBattleScene.scene->unk_20) {
        case 0:
            BattleAnim_CleanupEffects(1);
            if (sp1C->flags & 0x200) {
                func_8212C6E8(D_8219A540, arg0, D_8219A568 = 2);
            } else {
                func_8212C6E8(D_8219A540, arg0, D_8219A568 = BattleAnim_RandomRange(2));
            }
            BattleScene_EnterStateRow((ActivePokemon*)D_8219A544, 0xC);
            func_8211F034(D_8219A520 + 0x88, sBattleScene.scene->unk_2C);
            BattleScene_ResetCameraFrameCounter();
            sBattleScene.scene->unk_20 += 1;
            func_8210626C(D_8219A540);
            break;

        case 1:
            func_82124E80();
            if (func_821217DC(0x32) != 0) {
                BattleScene_CleanupParticipantEffectMode((ActivePokemon*)D_8219A544);
                BattleScene_ClearPhaseFlag();
                BattleScene_ResetCameraFrameCounter();
                func_8211EE8C();
                BattleScene_ResetAnimationStep();
                func_82125C34(arg0);
            }
            break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8212F5B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212F5B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212F6E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212F6E4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212F894; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212F894.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212F9FC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212F9FC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8212FC98; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8212FC98.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821301EC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821301EC.s")
#endif

void func_82106354(ActivePokemon*);
extern ActivePokemon* D_8219A540;
s32 func_82124A50(ActivePokemon* active_pokemon);
void func_82108C0C(ActivePokemon* active_pokemon);
void func_80040738(void);
void func_82124894(CameraNode* arg0, ActivePokemon* arg1);
void func_82125AC8(CameraNode* arg0);
void BattleScene_Phase10(CameraNode* arg0) {
    switch (sBattleScene.scene->unk_20) {
        case 0:
            BattleScene_CleanupParticipantEffectMode((ActivePokemon*)D_8219A544);
            func_82106354(sActivePokemon[sBattleScene.scene->unk_2C]);
            if (func_82124A50(sActivePokemon[sBattleScene.scene->unk_2C]) == 0) {
                func_82108C0C((ActivePokemon*)D_8219A544);
                func_80040738();
                BattleAnim_CleanupEffects(1);
                BattleScene_ResetCameraFrameCounter();
                func_8211F034(D_8219A520 + 0x348, !sBattleScene.scene->unk_2C);
                BattleAnim_QueueEffectList6(3, D_8219A540);
                Audio_PlayCommand(0x23, 0, 0);
                func_82124894(arg0, D_8219A540);
                sBattleScene.scene->unk_20 += 1;
            }
            break;

        case 1:
            if (BattleScene_AdvanceCameraFrameCounter(0x37) != 0) {
                func_8211EE8C();
                func_8211F034(D_8219A520 + 0x2C8, !sBattleScene.scene->unk_2C);
                sBattleScene.scene->unk_20 += 1;
            }

        case 2:
            if (BattleScene_AdvanceCameraFrameCounter(0x3C) != 0) {
                func_8211EE8C();
                func_82125AC8(arg0);
            }
            break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82130628; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82130628.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82130B10; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82130B10.s")
#endif

void func_82130D48(ActivePokemon* active_pokemon) {
    BattleMon* party_pokemon = &active_pokemon->teamRoster->pokemonPicked[M2C_FIELD(active_pokemon, s32*, 0x9D0)];

    if (M2C_FIELD(party_pokemon, u8*, 5) & 0x20) {
        BattleAnim_StopOwnerCategoryParticles(1, active_pokemon);
        active_pokemon->displayObject.node.renderFlags |= 0x20;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82130DAC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82130DAC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821311A0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821311A0.s")
#endif

void func_82125FD0(void);
void func_8212601C(CameraNode* arg0);
void func_82126C74(CameraNode* arg0);
void func_82126E34(CameraNode* arg0);
void func_82127250(CameraNode* arg0);
void func_8212BFF0(CameraNode* arg0);
void func_8212C1C4(CameraNode* arg0);
void func_8212C874(CameraNode* arg0);
void func_8212CB58(CameraNode* arg0);
void func_8212CF90(CameraNode* arg0);
void func_8212D194(CameraNode* arg0);
void func_8212D504(CameraNode* arg0);
void func_8212D820(CameraNode* arg0);
void func_8212DB28(CameraNode* arg0);
void func_8212DE30(CameraNode* arg0);
void func_8212E0B0(CameraNode* arg0);
void func_8212E350(CameraNode* arg0);
void func_8212E634(CameraNode* arg0);
void func_8212E7B0(CameraNode* arg0);
void func_8212EA84(CameraNode* arg0);
void func_8212ECC8(CameraNode* arg0);
void func_8212F16C(CameraNode* arg0);
void func_8212F440(CameraNode* arg0);
void func_8212F5B4(CameraNode* arg0);
void func_8212F6E4(CameraNode* arg0);
void func_8212F894(CameraNode* arg0);
void func_8212F9FC(CameraNode* arg0);
void func_8212FC98(CameraNode* arg0);
void func_821301EC(CameraNode* arg0);
void func_82130494(CameraNode* arg0);
void func_82130628(CameraNode* arg0);
void func_82130B10(CameraNode* arg0);
void func_82130DAC(CameraNode* arg0);
void func_821311A0(CameraNode* arg0);
// Zero numbers its phases differently, so the cases call the Zero handlers by address.
void BattleScene_UpdatePhase(CameraNode* arg0) {
    func_82125FD0();
    switch (sBattleScene.scene->unk_38) {
    case 0:
        func_8212601C(arg0);
        BattleScene_SetPhase(arg0, 1);
        /* fallthrough */
    case 1:
        func_82127250(arg0);
        break;
    case 2:
        func_8212BFF0(arg0);
        break;
    case 3:
        func_8212C1C4(arg0);
        break;
    case 4:
        func_8212F118((s32)arg0);
        break;
    case 7:
        func_8212C874(arg0);
        break;
    case 30:
        func_8212CB58(arg0);
        break;
    case 29:
        func_8212DE30(arg0);
        break;
    case 28:
        func_8212CF90(arg0);
        break;
    case 25:
        func_8212D820(arg0);
        break;
    case 21:
        func_8212D194(arg0);
        break;
    case 27:
        func_8212DB28(arg0);
        break;
    case 12:
        func_8212E0B0(arg0);
        break;
    case 13:
        func_8212E350(arg0);
        break;
    case 14:
        func_8212E634(arg0);
        break;
    case 15:
        func_8212D504(arg0);
        break;
    case 17:
        func_8212E7B0(arg0);
        break;
    case 31:
        func_8212ECC8(arg0);
        break;
    case 20:
        func_8212EA84(arg0);
        break;
    case 8:
        func_8212F440(arg0);
        break;
    case 22:
        func_8212F5B4(arg0);
        break;
    case 32:
        func_8212F894(arg0);
        break;
    case 23:
        func_8212F9FC(arg0);
        break;
    case 10:
        func_82130494(arg0);
        break;
    case 6:
        func_8212FC98(arg0);
        break;
    case 33:
        func_82130B10(arg0);
        break;
    case 35:
        func_82130628(arg0);
        break;
    case 9:
        func_821301EC(arg0);
        break;
    case 16:
        func_8212F16C(arg0);
        break;
    case 11:
        func_82130DAC(arg0);
        break;
    case 18:
        func_821311A0(arg0);
        break;
    case 26:
        func_8212F6E4(arg0);
        break;
    case 5:
        func_82126C74(arg0);
        break;
    case 34:
        func_82126E34(arg0);
        break;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82131880; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82131880.s")
#endif

s32 func_82101FD4(s32);                             /* extern */
extern s32 D_82199DE0;
extern s8 *D_8219A5A0;

void func_821319FC(s32 arg0) {
    if (func_82101FD4(D_82199DE0) != 0) {
        M2C_FIELD(D_8219A5A0, s32 *, 0x20) = (s32) (M2C_FIELD(D_8219A5A0, s32 *, 0x20) + 1);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82131A3C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82131A3C.s")
#endif

M2C_UNK func_800407B0(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_82108A88(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_821365B0(M2C_UNK, s8 *, s8 *, M2C_UNK, s32); /* extern */
extern M2C_UNK D_82199DE0;
extern s8 *D_8219A5A0;

void func_82131C64(s32 arg0) {
    M2C_FIELD(M2C_FIELD(&D_82199DE0, s8 **, 0), u8 *, 1) = (u8) (M2C_FIELD(M2C_FIELD(&D_82199DE0, s8 **, 0), u8 *, 1) & 0xFFFE);
    M2C_FIELD(M2C_FIELD(&D_82199DE0, s8 **, 4), u8 *, 1) = (u8) (M2C_FIELD(M2C_FIELD(&D_82199DE0, s8 **, 4), u8 *, 1) & 0xFFFE);
    if (M2C_FIELD(M2C_FIELD(&D_82199DE0, s8 **, 0), f32 *, 0x64C) == 0.0f) {
        func_800407B0(1, 1, 0);
        func_82108A88(M2C_FIELD(&D_82199DE0, s8 **, 4), 1, 0);
        func_821365B0(0xA, M2C_FIELD(&D_82199DE0, s8 **, 4), M2C_FIELD(&D_82199DE0, s8 **, 4), 0xFF, 0xFF);
        M2C_FIELD(D_8219A5A0, s32 *, 0x20) = (s32) (M2C_FIELD(D_8219A5A0, s32 *, 0x20) + 1);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82131D24; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82131D24.s")
#endif

void BattleScene_IntroPanCamera(CameraNode* arg0) {
    Vec3f sp2C;

    sp2C.y = 0.0f;
    sp2C.z = 0.0f;
    sp2C.x = -150.0f;
    sActivePokemon[0]->displayObject.node.flags &= ~1;
    sActivePokemon[1]->displayObject.node.flags &= ~1;
    BattleAnim_ApproachF(&M2C_FIELD(sBattleScene.scene, f32*, 0x74), 60.000004f, 0.1f);
    BattleAnim_StepToS16(&M2C_FIELD(sBattleScene.scene, s16*, 0x58), 0, 0x1E);
    BattleScene_SetCameraEyeFromPosition(arg0, sp2C, M2C_FIELD(sBattleScene.scene, s16*, 0x58), 0x4000, M2C_FIELD(sBattleScene.scene, f32*, 0x74), 0.0f);

    if ((M2C_FIELD(sBattleScene.scene, s16*, 0x58) >= 0x2E) && (M2C_FIELD(sActivePokemon[0], f32*, 0x64C) == 2.5f)) {
        Audio_PlayCommand(2, 0, 0);
        M2C_FIELD(sActivePokemon[0], u8*, 0x626) |= 0x20;
        sBattleScene.scene->unk_20 += 1;
    }
}

s32 func_8001101C(s8 *, M2C_UNK *);               /* extern */
extern M2C_UNK D_82199DE0;
extern s8 *D_8219A5A0;

void func_8213201C(s32 arg0) {
    M2C_FIELD(M2C_FIELD(&D_82199DE0, s8 **, 0), u8 *, 1) = (u8) (M2C_FIELD(M2C_FIELD(&D_82199DE0, s8 **, 0), u8 *, 1) & 0xFFFE);
    M2C_FIELD(M2C_FIELD(&D_82199DE0, s8 **, 4), u8 *, 1) = (u8) (M2C_FIELD(M2C_FIELD(&D_82199DE0, s8 **, 4), u8 *, 1) & 0xFFFE);
    if (func_8001101C(M2C_FIELD(&D_82199DE0, s8 **, 0) + 0x624, &D_82199DE0) == 1) {
        M2C_FIELD(D_8219A5A0, s32 *, 0x20) = (s32) (M2C_FIELD(D_8219A5A0, s32 *, 0x20) + 1);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82132088; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82132088.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821321A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821321A4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82132238; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82132238.s")
#endif

M2C_UNK func_82125384();
void func_82122A7C(CameraNode* arg0, ActivePokemon* arg1);

void func_8213233C(CameraNode* arg0) {
    M2C_FIELD(sActivePokemon[0], u8*, 1) &= ~1;
    func_82122A7C(arg0, sActivePokemon[1]);
    sBattleScene.scene->unk_10++;
    if (sBattleScene.scene->unk_10 == 0x28) {
        Battle_ClearMessageCursor();
    }
    if (BattleScene_IsRowWaitCompleteWithEventCount(sActivePokemon[1], 0x3C) != 0) {
        Battle_ClearMessageCursor();
        func_82125384();
    }
}
