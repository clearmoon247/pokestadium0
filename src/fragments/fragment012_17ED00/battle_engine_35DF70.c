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

extern s32 D_8218C8A0;

void Battle_Effect_Recoil(void) {
    s32 var_v1;

    sBattleUser->unk_12 = sBattleUser->unk_0C;

    if (sBattleUser->moveCache.lastMove == STRUGGLE) {
        var_v1 = sBattleDamage >> 1;
    } else {
        var_v1 = sBattleDamage >> 2;
    }

    if (var_v1 == 0) {
        var_v1 += 1;
    }

    if (sBattleUser->unk_12 < var_v1) {
        sBattleUser->unk_12 = 0;
    } else {
        sBattleUser->unk_12 -= var_v1;
    }

    sBattleTarget->unk_12 = sBattleTarget->unk_0C;
    func_8211EF74(D_8219A520 + 0x408, -0x47, D_8218C8A0, func_82107F88(sActivePokemon[sBattleScene.scene->unk_2C]));
    sBattleScene.scene->unk_48 = 9;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82115278; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82115278.s")
#endif

extern s32 D_8218C8A8;
extern s32 D_8218C8AC;

// Matches the ROM, but uses rodata data that is not placed in this file yet.
extern u8 D_82199F36;

void Battle_Effect_Confuse(void) {
    sBattleScene.scene->unk_48 = 0x16;
    sConfused = 0;

    if (!(sBattleTarget->unk_4D & 0x10)) {
        HandleMoveEffectFlags();
        if ((sBattleMoveFailed == 0) && !(sBattleTarget->unk_4C & 0x80)) {
            sConfused = 1;
            sBattleTarget->unk_4C |= 0x80;
            sBattleTarget->unk_50 = (Battle_Random() & 3) + 2;
            func_8211EF74(D_8219A520 + 0x88, -0x45, D_8218C8A8, func_82107F88(sActivePokemon[!sBattleScene.scene->unk_2C]));
            return;
        }
    }

    if (D_82199F36 == 0) {
        func_8211EF74(D_8219A520 + 0x88, -0x44, D_8218C8AC);
    }
}

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

extern s32 D_8218C8C4;
extern s32 D_8218C8C8;

// Matches the ROM, but uses rodata data that is not placed in this file yet.
void Battle_Effect_LeechSeed(void) {
    HandleMoveEffectFlags();

    if ((sBattleMoveFailed == 0) && (sBattleTarget->roster[6] != 0x16) && (sBattleTarget->roster[7] != 0x16)) {
        if (!(sBattleTarget->unk_4D & 0x80)) {
            sBattleTarget->unk_4D |= 0x80;
            func_8211EF74(D_8219A520 + 0x88, -0x3E, D_8218C8C4, func_82107F88(sActivePokemon[!sBattleScene.scene->unk_2C]));
            return;
        }
    }

    sBattleScene.scene->unk_48 = 8;
    func_8211EF74(D_8219A520 + 0x88, -0x3D, D_8218C8C8, func_82107F88(sActivePokemon[!sBattleScene.scene->unk_2C]));
}

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

extern s32 D_8218C8DC;
extern s32 D_8218C8E0;

// Matches the ROM, but uses rodata data that is not placed in this file yet.
void Battle_Effect_Conversion(void) {
    sBattleScene.scene->unk_48 = 7;
    if (!(sBattleTarget->unk_4C & 0x40)) {
        sBattleUser->roster[6] = sBattleTarget->roster[6];
        sBattleUser->roster[7] = sBattleTarget->roster[7];
        func_8211EF74(D_8219A520 + 0x88, -0x38, D_8218C8DC, func_82107F88(sActivePokemon[!sBattleScene.scene->unk_2C]));
    } else {
        func_8211EF74(D_8219A520 + 0x88, -0x37, D_8218C8E0);
    }
}

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

extern s32 D_8218C900;
extern s32 D_8218C904;
extern s32 D_8218C908;
extern s32 D_8218C90C;

// Matches the ROM, but uses rodata data that is not placed in this file yet.
void Battle_Effect_ReflectLightScreen(void) {
    sBattleScene.scene->unk_48 = 7;
    if (sBattleUser->moveCache.unk_01 == 0x40) {
        if (!(sBattleUser->unk_4E & 2)) {
            sBattleUser->unk_4E |= 2;
            func_8211EF74(D_8219A520 + 0x88, -0x2F, D_8218C900, func_82107F88(sActivePokemon[sBattleScene.scene->unk_2C]));
        } else {
            func_8211EF74(D_8219A520 + 0x88, -0x2E, D_8218C904);
        }
    } else if (!(sBattleUser->unk_4E & 4)) {
        sBattleUser->unk_4E |= 4;
        func_8211EF74(D_8219A520 + 0x88, -0x2D, D_8218C908, func_82107F88(sActivePokemon[sBattleScene.scene->unk_2C]));
    } else {
        func_8211EF74(D_8219A520 + 0x88, -0x2C, D_8218C90C);
    }
}

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
