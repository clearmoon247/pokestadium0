/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_359F90.c, src/fragments/particle_math/particle_math_26F9B0.c. */

#include "fragments/particle_math/particle_math.h"

#include "fragments/battle_engine/battle_engine.h"
#include "gb_data.h"
#include "text_system.h"
#include "matrix.h"
#include "moves.h"
typedef struct unk_D_843C4DA0 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk06[0x3];
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ char unk0A[0xA];
    /* 0x13 */ u8 unk_13;
    /* 0x14 */ char unk14[0x1];
    /* 0x15 */ u8 unk_15;
    /* 0x16 */ char unk16[0x1];
    /* 0x17 */ u8 unk_17;
    /* 0x18 */ char unk18[0xB];
    /* 0x22 */ u8 unk_22;
    /* 0x24 */ u16 unk_24;
    /* 0x26 */ u16 unk_26;
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ u16 unk_2A;
    /* 0x2C */ u16 unk_2C;
    /* 0x2E */ char unk2E[0x1E];
} unk_D_843C4DA0;
extern u8 sBattleMoveFailed;
extern u8 sBattleCritFlag;
extern u8 D_82199F4E;
extern u16 sBattleDamage;
extern s32 pad_D_843C4DD0;
extern s32 pad_D_843C4DD4;
extern s32 pad_D_843C4DD8;
extern s32 pad_D_843C4DDC;
extern s32 pad_D_843C4DE0;
extern s32 pad_D_843C4DE4;
extern s32 pad_D_843C4DE8;
extern s32 sTypeEffectiveness;
extern s32 pad_D_843C4DF0[21];
extern u8 sConfused;
extern u8 sStatCanBeChangedFurther;
extern s32 pad_D_843C4E48[252];
extern BattleMonRuntime* sBattleUser;
extern BattleMonRuntime* sBattleTarget;
extern BattleMonRuntime D_8219A3C8[2];
extern StatStageMultiplier gStatStageMultipliers[];
extern u8 sTypeEffects[];
extern u8 sHighCritMoves[];
#define PRINTF(x) ((void)(x))

s32 func_82111DC4(void);
s32 Battle_CheckFaintAfterMove(void);

void Battle_CheckAllBroughtFainted_HP(ActivePokemon* arg0);
void Battle_CheckAllBroughtFainted_Status(ActivePokemon* arg0);
void Battle_CheckAllBroughtFainted_PP(ActivePokemon* arg0);
void Battle_CheckAllBroughtFainted_Level(ActivePokemon* arg0);

s32 func_82111DC4(void) {
    return 1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82111DCC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82111DCC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821125C0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821125C0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821129E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821129E4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82112ADC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82112ADC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82112C1C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82112C1C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82112D5C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82112D5C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82112E9C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82112E9C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82112FDC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82112FDC.s")
#endif

s32 Battle_CheckFaintAfterMove(void) {
    if (sBattleTarget->unk_0C == 0) {
        Battle_CheckAllBroughtFainted_Level(sActivePokemon[!sBattleScene.scene->unk_2C]);
    }

    if (sBattleUser->unk_0C == 0) {
        Battle_CheckAllBroughtFainted_Level(sActivePokemon[sBattleScene.scene->unk_2C]);
    }

    if ((sBattleUser->unk_0C != 0) && (sBattleTarget->unk_0C != 0) && (sBattleUser->unk_12 == 0)) {
        Battle_CheckAllBroughtFainted_PP(sActivePokemon[sBattleScene.scene->unk_2C]);
        return 0;
    } else if ((sBattleUser->unk_0C != 0) && (sBattleTarget->unk_0C != 0) && (sBattleUser->unk_15 & 0x18) &&
               (sBattleUser->unk_0E == 0)) {
        Battle_CheckAllBroughtFainted_HP(sActivePokemon[sBattleScene.scene->unk_2C]);
        return 0;
    } else if ((sBattleUser->unk_0C != 0) && (sBattleTarget->unk_0C != 0) && (sBattleUser->unk_4D & 0x80) &&
               (sBattleUser->unk_10 == 0)) {
        Battle_CheckAllBroughtFainted_Status(sActivePokemon[sBattleScene.scene->unk_2C]);
        return 0;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_821132C8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821132C8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82113524; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82113524.s")
#endif
