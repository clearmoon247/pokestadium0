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

#ifdef NON_MATCHING
/* TODO: decompile func_821138A0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821138A0.s")
#endif

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
