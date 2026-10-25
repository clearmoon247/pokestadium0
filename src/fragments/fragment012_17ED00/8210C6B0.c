/* Stadium Zero fragment012_17ED00. */

#include "global.h"
#include "fragments/battle_engine/battle_engine.h"
#include "m2c_macros.h"

extern f32 D_82199EB0;
extern s32 D_82199EB8;

extern f32 D_FLT_82199EB0;

s32 func_8210C6B0(void) {
    if (D_FLT_82199EB0 >= 150.0f) {
        return 1;
    }
    D_FLT_82199EB0 += 1.0f;
    return 0;
}

extern f32 D_FLT_82199EB0;

void func_8210C6F8(void) {
    D_FLT_82199EB0 = 0.0f;
}

s32 func_8210C708(s8 *arg0) {
    s8 *temp_v1;

    temp_v1 = arg0 + 0x78C;
    if (M2C_FIELD(arg0, s32 *, 0x79C) == 3) {
        M2C_FIELD(temp_v1, u16 *, 0x1E) = (u16) (M2C_FIELD(temp_v1, u16 *, 0x1E) + 0x38E);
        return 1;
    }
    return 0;
}

void BattleScene_SelectActiveController(ActivePokemon* arg0) {
    ActivePokemonState* ptr = &arg0->state;

    M2C_FIELD(arg0, u8*, 0x7B9) = M2C_FIELD(arg0, u8*, 0x7B8);
    ptr->controller = &gControllers[arg0->sessionTeams->teamMember[M2C_FIELD(arg0, u8*, 0x7B9)]->controllerPort];
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210C778; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210C778.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210C82C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210C82C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210C8A0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210C8A0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210CA24; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210CA24.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210CACC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210CACC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210CBD4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210CBD4.s")
#endif

M2C_UNK func_8210CBD4();                            /* extern */
s32 func_8210CCDC(s8 *arg0, M2C_UNK arg1)
{
  *((s8 *) (((s8 *) arg0) + 0x7B6)) = 1;
  if (1)
  {
    *((s8 *) (((s8 *) arg0) + 0x7B6)) = 1;
    func_8210CBD4();
    *((s8 *) (((s8 *) arg0) + 0x7B6)) = 1;
  }
  return 0;
}

void BattleScene_ConfirmForcedMoveRepeat(ActivePokemon* arg0) {
    ActivePokemonState* ptr = &arg0->state;

    BattleScene_ApplyForcedActionDelay(arg0);
    ptr->unk_2A = 1;
    ptr->unk_10 = 3;
    ptr->unk_0C = ptr->unk_14;
}

void func_8210CD58(s8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x794) = (s32) M2C_FIELD(arg0, s32 *, 0x7A4);
    if (M2C_FIELD(arg0, u8 *, 0x7BA) != 0x10) {
        M2C_FIELD(arg0, u8 *, 0x7BA) = 0xFU;
    }
}

M2C_UNK func_8211F274();
M2C_UNK func_8211F288();
extern s32 D_8218C6FC;

s32 BattleScene_ValidateSelectedPartyMember(ActivePokemon* arg0) {
    if (arg0->sessionTeams->teamMember[M2C_FIELD(arg0, u8*, 0x7B9)]->pokemonPicked[arg0->state.unk_18].hp != 0) {
        return 1;
    }

    func_8211F274(arg0);
    func_8211F288(arg0, D_8218C6FC);
    return 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210CDEC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210CDEC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210CEE8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210CEE8.s")
#endif

s32 func_82107F88(s32);                             /* extern */
M2C_UNK func_8211F274();                            /* extern */
M2C_UNK func_8211F288(s32, s32, s32);               /* extern */
extern s32 D_8218C700;

void func_8210CFE4(s32 arg0) {
    func_8211F274();
    func_8211F288(arg0, D_8218C700, func_82107F88(arg0));
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210D020; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210D020.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210D1B0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210D1B0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210D378; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210D378.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210D4B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210D4B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210D6BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210D6BC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210D838; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210D838.s")
#endif

void BattleScene_CollectPlayerAction(ActivePokemon* arg0, ActivePokemon* arg1) {
    UNUSED s32 pad;
    BattleMonRuntime* sp20 = &arg0->state.runtime;
    BattleMonRuntime* sp1C = &arg1->state.runtime;

    if (BattleScene_HandlePlayerForcedActionState(arg0, arg1) == 0) {
        if (!(sp20->unk_4D & 0x60)) {
            sp20->unk_4C &= ~8;
            sp1C->unk_4C &= ~8;
            if (!(sp20->unk_4C & 0x12)) {
                if (BattleScene_HandlePlayerActionInput(arg0) == 0) {
                    if (!(sp20->unk_15 & 0x27)) {
                        if (!(sp20->unk_4C & 0x21)) {
                            if (sp1C->unk_4C & 0x20) {
                                BattleScene_HandlePlayerMoveSelectionLocked(arg0, arg0->state.controller);
                                sp20->usedMove = 0xFF;
                            } else {
                                BattleScene_HandlePlayerMoveSelection(arg0);
                            }
                        } else {
                            BattleScene_HandlePlayerMoveSelectionLocked(arg0, arg0->state.controller);
                        }
                    } else {
                        BattleScene_HandlePlayerMoveSelectionLocked(arg0, arg0->state.controller);
                    }
                }
            } else {
                BattleScene_ConfirmForcedMoveRepeat(arg0);
            }
        } else {
            BattleScene_ConfirmForcedMoveRepeat(arg0);
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210DA30; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210DA30.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210DAEC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210DAEC.s")
#endif

void BattleScene_CompleteCpuForcedAction(ActivePokemon* arg0, UNUSED ActivePokemon* arg1) {
    ActivePokemonState* ptr = &arg0->state;

    BattleScene_ApplyForcedActionDelay(arg0);
    ptr->unk_2A = 1;
    ptr->unk_04 = 1;
    ptr->unk_0C = ptr->unk_14;
    ptr->unk_10 = 3;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210DCE4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210DCE4.s")
#endif

s32 func_8210DA30(ActivePokemon* arg0);
void BattleScene_ApplyCpuChoice(ActivePokemon* arg0, ActivePokemon* arg1) {
    ActivePokemonState* sp18;
    ActivePokemonState* sp14;
    s32 var_v0;

    sp18 = &arg0->state;
    sp14 = &arg1->state;

    if ((D_82199EB0 == 30.0f) && (D_82199EB8 < 4)) {
        BattleAnim_PlaySoundEffect2();
    }

    if (D_82199EB8 < 4) {
        if (D_82199EB0 >= 30.0f) {
            sp18->unk_10 = 1;
            sp18->unk_04 = 1;
        }
    }

    if ((D_82199EB0 >= 90.0f) || ((sp14->unk_10 == 3) && (D_82199EB0 >= 10.0f))) {
        if (D_82199EB8 < 4) {
            BattleAnim_PlaySoundEffect2();
            sp18->unk_04 = 1;
            sp18->unk_10 = 3;
            if (func_8210DA30(arg0) != 0) {
                sp18->unk_14 = 4;
                sp18->unk_0C = 4;
            } else {
                var_v0 = D_82199EB8;
                sp18->unk_14 = var_v0;
                sp18->unk_0C = var_v0;
            }
        }
    }
}

s32 BattleScene_ApplyCpuSwitchChoice(ActivePokemon* arg0, ActivePokemon* arg1) {
    ActivePokemonState* sp1C = &arg0->state;
    ActivePokemonState* sp18 = &arg1->state;

    if ((D_82199EB0 == 30.0f) && (D_82199EB8 >= 4)) {
        BattleAnim_PlaySoundEffect2();
    }

    if (D_82199EB0 >= 30.0f) {
        if (D_82199EB8 >= 4) {
            sp1C->unk_10 = 2;
            sp1C->unk_04 = 2;
        }
    }

    if ((D_82199EB0 >= 90.0f) || ((sp18->unk_10 == 3) && (D_82199EB0 >= 10.0f))) {
        if (D_82199EB8 >= 4) {
            BattleAnim_PlaySoundEffect2();
            sp1C->unk_1C = 0;
            sp1C->unk_18 = D_82199EB8 - 4;
            sp1C->unk_1E = 0;
            sp1C->unk_10 = 3;
            sp1C->unk_04 = 2;
        }
    }

    if (D_82199EB8 >= 4) {
        return 1;
    }
    return 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210E0A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210E0A4.s")
#endif

extern f32 D_82199EB0;
extern s32 D_82199EBC;
s32 BattleScene_CollectCpuAction(ActivePokemon* arg0, ActivePokemon* arg1) {
    BattleMonRuntime* sp34 = &arg0->state.runtime;
    BattleMonRuntime* sp30 = &arg1->state.runtime;
    ActivePokemonState* sp2C = &arg0->state;
    ActivePokemonState* sp28 = &arg1->state;

    if (BattleScene_WaitForCpuChoice(arg0, arg1) != 0) {
        return 0;
    }

    if (!(sp34->unk_4D & 0x60)) {
        sp34->unk_4C &= ~8;
        sp30->unk_4C &= ~8;

        if (!(sp34->unk_4C & 0x12)) {
            if (BattleScene_ApplyForcedActionDelay(arg0) != 0) {
                return 0;
            }

            if (D_82199EB0 == 0.0f) {
                D_82199EBC = 0;
                return 0;
            }

            BattleScene_TriggerCpuChoice(sp34, sp30, sp2C, sp28, arg1);

            if (BattleScene_ApplyCpuSwitchChoice(arg0, arg1) != 0) {
                return 0;
            }

            if (!(sp34->unk_15 & 0x27)) {
                if (!(sp34->unk_4C & 0x21)) {
                    if (sp30->unk_4C & 0x20) {
                        BattleScene_CompleteCpuMoveAction(arg0, arg1);
                        sp34->usedMove = 0xFF;
                    } else if (BattleScene_ApplyForcedActionDelay(arg0) != 0) {
                        return 0;
                    } else {
                        if (D_82199EB0 == 0.0f) {
                            D_82199EBC = 0;
                            return 0;
                        }
                        BattleScene_TriggerCpuChoice(sp34, sp30, sp2C, sp28, arg1);
                        BattleScene_ApplyCpuChoice(arg0, arg1);
                    }
                } else {
                    BattleScene_CompleteCpuMoveAction(arg0, arg1);
                }
            } else {
                BattleScene_CompleteCpuMoveAction(arg0, arg1);
            }
        } else {
            BattleScene_CompleteCpuForcedAction(arg0, arg1);
        }
    } else {
        BattleScene_CompleteCpuForcedAction(arg0, arg1);
    }

    return 0;
}

extern s8 D_82199DE0;
void func_8210E318(void)
{
  s8 *temp_v1;
  s8 **new_var;
  s8 *temp_a1;
  int pad;
  temp_a1 = (s8 *) (*((s8 **) (((s8 *) (*((s8 **) (((s8 *) (&D_82199DE0)) + 0)))) + 0x9CC)));
  temp_v1 = *((s8 **) (((s8 *) (*((s8 **) (((s8 *) (&D_82199DE0)) + 0)))) + 0x9CC));
  *((u8 *) (temp_a1 + 1)) = (u8) ((*((u8 *) (((s8 *) temp_v1) + 1))) | 1);
  *((u8 *) (((s8 *) (*((s8 **) (((s8 *) (&D_82199DE0)) + 0)))) + 0x865)) = (u8) ((*((u8 *) (((s8 *) (*((s8 **) (((s8 *) (&D_82199DE0)) + 0)))) + 0x865))) | 1);
  new_var = (s8 **) (((s8 *) (&D_82199DE0)) + 4);
  ;
  *((u8 *) (((s8 *) (*((s8 **) (((s8 *) (*((s8 **) (((s8 *) (&D_82199DE0)) + 4)))) + 0x9CC)))) + 1)) = (u8) ((*((u8 *) (((s8 *) (*((s8 **) (((s8 *) (*((s8 **) (((s8 *) (&D_82199DE0)) + 4)))) + 0x9CC)))) + 1))) | 1);
  *((u8 *) (((s8 *) (*new_var)) + 0x865)) = (u8) ((*((u8 *) (((s8 *) (*new_var)) + 0x865))) | 1);
}

extern s8 D_82199DE0;
void func_8210E36C(void)
{
  s8 *temp_a1;
  s8 *temp_v1;
  ;
  *((u8 *) (((s8 *) (*((s8 **) (((s8 *) (*((s8 **) (((s8 *) (&D_82199DE0)) + 0)))) + 0x9CC)))) + 1)) = (u8) ((*((u8 *) (((s8 *) (*((s8 **) (((s8 *) (*((s8 **) (((s8 *) (&D_82199DE0)) + 0)))) + 0x9CC)))) + 1))) & 0xFFFE);
  *((u8 *) (((s8 *) (*((s8 **) (((s8 *) (&D_82199DE0)) + 0)))) + 0x865)) = (u8) ((*((u8 *) (((s8 *) (*((s8 **) (((s8 *) (&D_82199DE0)) + 0)))) + 0x865))) & 0xFFFE);
  ;
  *((u8 *) (((s8 *) (*((s8 **) (((s8 *) (*((s8 **) (((s8 *) (&D_82199DE0)) + 4)))) + 0x9CC)))) + 1)) = (u8) ((*((u8 *) (((s8 *) (*((s8 **) (((s8 *) (*((s8 **) (((s8 *) (&D_82199DE0)) + 4)))) + 0x9CC)))) + 1))) & 0xFFFE);
  *((u8 *) (((s8 *) (*((s8 **) (((s8 *) (&D_82199DE0)) + 4)))) + 0x865)) = (u8) ((*((u8 *) (((s8 *) (*((s8 **) (((s8 *) (&D_82199DE0)) + 4)))) + 0x865))) & 0xFFFE);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210E3C0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210E3C0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210E484; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210E484.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210E504; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210E504.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210E6D0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210E6D0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210E6F4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210E6F4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210E790; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210E790.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210E924; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210E924.s")
#endif
