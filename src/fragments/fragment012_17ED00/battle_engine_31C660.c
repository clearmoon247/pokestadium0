/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_31C660.c, src/fragments/battle_engine/battle_engine_35DF70.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "model_renderer.h"

#include "fragments/battle_engine/battle_engine.h"
#include "moves.h"
#include "text_system.h"

s32 func_8211EF74(s32, s32, s32, ...);
extern s32 D_8219A520;
s32 func_82107F88(ActivePokemon*);
typedef void (*func_D_8438AE50)(void);
extern func_D_8438AE50 sMoveEffectHandlers[];

void func_82113660(void);
void Battle_Effect_Explosion(void);

void func_82113660(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_82113668; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82113668.s")
#endif

extern s32 D_8218C7C8;
extern s32 D_8218C7CC;
extern s32 D_8218C7D0;
extern s32 D_8218C7D4;

// Matches the ROM, but uses rodata data that is not placed in this file yet.
void Battle_Effect_Poison(void) {
    s32 sp1C = D_8219A520 + 0x88;

    if (!(sBattleTarget->unk_4D & 0x10) && (sBattleTarget->unk_15 == 0) && (sBattleTarget->roster[6] != 3) &&
        (sBattleTarget->roster[7] != 3)) {
        switch (sBattleUser->moveCache.unk_01) {
            case 2:
                if (sBattleScene.scene->unk_48 != 0x18) {
                    sBattleScene.scene->unk_48 = 0;
                    sp1C = D_8219A520 + 0x208;
                } else {
                    sp1C = D_8219A520 + 0x308;
                }

                if (Battle_Random() >= 0x34) {
                    return;
                }
                break;

            case 33:
                sBattleScene.scene->unk_48 = 0;
                sp1C = D_8219A520 + 0x208;
                if (Battle_Random() >= 0x67) {
                    return;
                }
                break;

            default:
                sBattleScene.scene->unk_48 = 0x16;
                sTypeEffectiveness = 0xA;
                HandleMoveEffectFlags();
                if (sBattleMoveFailed != 0) {
                    func_8211EF74(sp1C, -0x7D, D_8218C7C8, func_82107F88(sActivePokemon[!sBattleScene.scene->unk_2C]));
                    return;
                }
                break;
        }

        sBattleTarget->unk_15 |= 8;
        if (sBattleUser->moveCache.lastMove == TOXIC) {
            sBattleTarget->unk_4E |= 1;
            sBattleTarget->unk_51 = 0;
            func_8211EF74(sp1C, -0x7C, D_8218C7CC, func_82107F88(sActivePokemon[!sBattleScene.scene->unk_2C]));
        } else {
            func_8211EF74(sp1C, -0x7B, D_8218C7D0, func_82107F88(sActivePokemon[!sBattleScene.scene->unk_2C]));
        }
    } else if (sBattleUser->moveCache.unk_01 == 0x42) {
        if (sBattleScene.scene->unk_48 != 0x18) {
            sBattleMoveFailed = 1;
            sBattleScene.scene->unk_48 = 0x16;
            sConfused = 0;
        }
        func_8211EF74(sp1C, -0x7A, D_8218C7D4, func_82107F88(sActivePokemon[!sBattleScene.scene->unk_2C]));
    }
}

extern s32 D_8218C7D8;
extern s32 D_8218C7DC;

// Matches the ROM, but uses rodata data that is not placed in this file yet.
void Battle_Effect_DrainHP(void) {
    sBattleDamage /= 2;
    if (sBattleDamage == 0) {
        sBattleDamage = 1;
    }

    if (sBattleUser->unk_28 < sBattleUser->unk_0C + sBattleDamage) {
        sBattleUser->unk_0C = sBattleUser->unk_28;
    } else {
        sBattleUser->unk_0C += sBattleDamage;
    }

    if (sBattleUser->moveCache.unk_01 == 8) {
        func_8211EF74(D_8219A520 + 0x208, -0x79, D_8218C7D8, func_82107F88(sActivePokemon[!sBattleScene.scene->unk_2C]));
    } else {
        func_8211EF74(D_8219A520 + 0x208, -0x78, D_8218C7DC, func_82107F88(sActivePokemon[!sBattleScene.scene->unk_2C]));
    }
}

void Battle_Effect_Explosion(void) {
    sBattleScene.scene->unk_48 = 0x1E;
    sBattleUser->unk_0C = 0;
    sBattleUser->unk_15 = 0;
    sBattleUser->unk_4D &= ~0x80;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82113CD0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82113CD0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82113FC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82113FC8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821142B8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821142B8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211459C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211459C.s")
#endif
