/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_35DF70.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "moves.h"
#include "text_system.h"
typedef void (*func_D_8438AE50)(void);
extern func_D_8438AE50 sMoveEffectHandlers[];

#include "m2c_macros.h"

s32 func_8211EF74(s32, s32, s32, ...);
extern s32 D_8219A520;
s32 func_82107F88(ActivePokemon*);

void Battle_Effect_Bide(void);
void Battle_Effect_Thrash(void);
void Battle_Effect_MultiHit(void);
void Battle_Effect_Recharge(void);
void Battle_Effect_Rage(void);
void Battle_ExecuteMoveEffect(void);

void Battle_RunMoveEffect(void);

void Battle_Effect_Bide(void) {
    sBattleScene.scene->unk_48 = 0x1B;
    sBattleUser->moveCache.unk_01 = 0;
    sBattleUser->unk_4C |= 1;
    sBattleUser->unk_54 = 0;
    sBattleUser->unk_4F = (Battle_Random() & 1) + 2;
}

void Battle_Effect_Thrash(void) {
    sBattleUser->moveCache.unk_01 = 0;
    sBattleUser->unk_4C |= 2;
    sBattleUser->unk_4F = (Battle_Random() & 1) + 2;
}

extern s32 D_8218C870;
extern s32 D_8218C874;

void Battle_Effect_ForceSwitchOrFlee(void) {
    if (sBattleUser->moveCache.lastMove == TELEPORT) {
        sBattleScene.scene->unk_48 = 8;
        func_8211EF74(D_8219A520 + 0x88, -0x53, D_8218C870);
        return;
    }
    sBattleScene.scene->unk_48 = 8;
    func_8211EF74(D_8219A520 + 0x88, -0x52, D_8218C874, func_82107F88(sActivePokemon[!sBattleScene.scene->unk_2C]));
}

void Battle_Effect_MultiHit(void) {
    s32 var_v1;

    if (!(sBattleUser->unk_4C & 4)) {
        sBattleUser->unk_4C |= 4;

        switch (sBattleUser->moveCache.unk_01) {
            case 0x4D:
                sBattleUser->moveCache.unk_01 = 2;

            case 0x2C:
                sBattleUser->unk_54 = 2;
                sBattleUser->unk_4F = sBattleUser->unk_54;
                break;

            default:
                var_v1 = Battle_Random() & 3;
                if (var_v1 >= 2) {
                    var_v1 = Battle_Random() & 3;
                }
                sBattleUser->unk_4F = sBattleUser->unk_54 = var_v1 + 2;
                break;
        }

        sMultihitCount = sBattleUser->unk_54 - 1;
        sBattleScene.scene->unk_48 = 0x18;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82114C20; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82114C20.s")
#endif

void Battle_Effect_OHKO(void) {
    sBattleDamage = 0;
    sBattleCritFlag = 0xFF;
    if (sBattleUser->speed < sBattleTarget->speed) {
        sBattleMoveFailed = 1;
        return;
    }
    sBattleDamage = 0xFFFF;
    sBattleCritFlag = 2;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82114D10; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82114D10.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82114F9C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82114F9C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82115024; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82115024.s")
#endif

extern s32 D_8218C898;
extern s32 D_8218C89C;

void Battle_Effect_FocusEnergy(void) {
    sBattleScene.scene->unk_48 = 7;
    if (sBattleUser->unk_4D & 4) {
        func_8211EF74(D_8219A520 + 0x88, -0x49, D_8218C898);
        return;
    }
    sBattleUser->unk_4D |= 4;
    func_8211EF74(D_8219A520 + 0x88, -0x48, D_8218C89C, func_82107F88(sActivePokemon[sBattleScene.scene->unk_2C]));
}

#ifdef NON_MATCHING
/* TODO: decompile func_82115194; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82115194.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82115278; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82115278.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82115340; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82115340.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211545C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211545C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821155DC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821155DC.s")
#endif

void Battle_Effect_Recharge(void) {
    sBattleUser->unk_4D |= 0x20;
}

void Battle_Effect_Rage(void) {
    sBattleUser->unk_4D |= 0x40;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8211576C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211576C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821158C8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821158C8.s")
#endif

s32 func_8211EF74(s32, s32, s32, ...);
extern s32 D_8218C8CC;
extern s32 D_8219A520;
extern s8 *D_8219A5A0;

void func_821159D0(void) {
    M2C_FIELD(D_8219A5A0, s32 *, 0x48) = 7;
    func_8211EF74(D_8219A520 + 0x88, -0x3C, D_8218C8CC);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82115A14; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82115A14.s")
#endif

s32 func_8211EF74(s32, s32, s32, ...);
extern s32 D_8218C8D8;
extern s32 D_8219A520;

void func_82115B64(void) {
    func_8211EF74(D_8219A520 + 0x88, -0x39, D_8218C8D8);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82115B98; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82115B98.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82115C68; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82115C68.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82115DE0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82115DE0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82115FCC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82115FCC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821162C4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821162C4.s")
#endif

void Battle_RunMoveEffect(void) {
    BattleMonRuntime* ptr = &sActivePokemon[sBattleScene.scene->unk_2C]->state.runtime;
    s32 idx = ptr->moveCache.unk_01;

    if (sMoveEffectHandlers[idx - 1] != NULL) {
        sMoveEffectHandlers[idx - 1]();
    }
}

void Battle_ExecuteMoveEffect(void) {
    Battle_RunMoveEffect();
}
