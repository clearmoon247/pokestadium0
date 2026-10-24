/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_317E70.c, src/fragments/battle_engine/battle_engine_359F90.c. */

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

#include "fragments/battle_engine/battle_engine.h"
#include "geo_render.h"
#include "model_renderer.h"
#include "matrix.h"
#include "fragments/particle_math/particle_math.h"
#include "memory.h"

#include "m2c_macros.h"

s32 IsByteInArray(u8 lookup, u8* array, s32 array_length);
void func_8210FA74(void);
void Battle_SetActiveMoveFromSlotIndex(void);
s32 Battle_CheckMoveSuccess(void);
void ComputePokemonStat(s32 arg0, BattleMon* arg1);
void ComputeAllPokemonStats(BattleMon* arg0);
void func_82110FB0(void);
void func_82110FB8(void);
void Battle_ExecuteMoveAnimation(void);
s32 Battle_Effect_Metronome(void);
void Battle_ApplyPoisonOrBurnDamage(void);
void func_82111870(void);
void BattleAnim_EffectEndNop(void);

u8 Battle_Random(void);
void Battle_IncrementMoveUsage(void);

s32 IsByteInArray(u8 lookup, u8* array, s32 array_length) {
    while (array_length--) {
        if (lookup == *array) {
            return 1;
        }
        array++;
    }

    return 0;
}

void func_8210FA74(void) {
}

void Battle_SetActiveMoveFromSlotIndex(void) {
    D_8219A3C8[0].usedMove = D_8219A3C8[0].moves[D_82199F4E];
}

s32 Battle_CheckMoveSuccess(void) {
    Battle_ExecuteMoveEffect();

    if (sBattleMoveFailed == 1) {
        return 0;
    }
    return 1;
}

void ComputePokemonStat(s32 arg0, BattleMon* arg1) {
    u16 i;
    u16 spC;
    u16 spA;
    u16 tmp;
    u16 sp6;
    u16 temp_a0;

    switch (arg0) {
        case 1:
            spA = gSpeciesData[arg1->unk_24].baseHitPoints;
            spC = arg1->unk_14;
            break;

        case 2:
            spA = gSpeciesData[arg1->unk_24].baseAttack;
            spC = arg1->unk_16;
            break;

        case 3:
            spA = gSpeciesData[arg1->unk_24].baseDefense;
            spC = arg1->unk_18;
            break;

        case 4:
            spA = gSpeciesData[arg1->unk_24].baseSpeed;
            spC = arg1->unk_1A;
            break;

        case 5:
            spA = gSpeciesData[arg1->unk_24].baseSpecial;
            spC = arg1->unk_1C;
            break;
    }

    for (i = 1; i < 255; i++) {
        if (SQ(i) >= spC) {
            break;
        }
    }

    tmp = D_8219A3C8[0].unk_24;

    switch (arg0) {
        case 1:
            sp6 = ((tmp & 0x1000) >> 9) | ((tmp & 0x100) >> 6) | ((tmp & 0x10) >> 3) | (tmp & 1);
            break;

        case 2:
            sp6 = (tmp >> 0xC) & 0xF;
            break;

        case 3:
            sp6 = (tmp >> 8) & 0xF;
            break;

        case 4:
            sp6 = (tmp >> 4) & 0xF;
            break;

        case 5:
            sp6 = tmp & 0xF;
            break;
    }

    temp_a0 = ((((spA + sp6) * 2) + (i >> 2)) * arg1->unk_24) / 100;
    if (arg0 == 1) {
        temp_a0 += arg1->unk_24 + 0xA;
    } else {
        temp_a0 += 5;
    }

    if (temp_a0 >= 0x3E8) {
        temp_a0 = 0x3E7;
    }

    switch (arg0) {
        case 1:
            arg1->unk_26 = temp_a0;
            break;

        case 2:
            arg1->unk_28 = temp_a0;
            break;

        case 3:
            arg1->unk_2A = temp_a0;
            break;

        case 4:
            arg1->unk_2C = temp_a0;
            break;

        case 5:
            arg1->unk_2E = temp_a0;
            break;
    }
}

void ComputeAllPokemonStats(BattleMon* arg0) {
    ComputePokemonStat(0, arg0);
    ComputePokemonStat(1, arg0);
    ComputePokemonStat(2, arg0);
    ComputePokemonStat(3, arg0);
    ComputePokemonStat(4, arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8210FDD0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210FDD0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8210FF40; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8210FF40.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211009C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211009C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821102F0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821102F0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821107F0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821107F0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82110890; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82110890.s")
#endif

extern s8 D_82199F31;
extern s16 D_82199F50;
extern s8 *D_8219A3C0;
extern s8 *D_8219A3C4;
extern s8 *D_8219A5A0;

void func_82110984(void) {
    s32 temp_v0;

    D_82199F50 = 0;
    temp_v0 = M2C_FIELD(D_8219A5A0, s32 *, 0x1C);
    if ((temp_v0 == 5) || (temp_v0 == 9) || (temp_v0 == 6) || (temp_v0 == 0xA)) {
        if (M2C_FIELD(D_8219A3C4, u8 *, 0x4C) & 0x40) {
            D_82199F31 = 1;
        } else {
            D_82199F31 = 0;
        }
    } else {
        D_82199F31 = 1;
    }
    M2C_FIELD(D_8219A3C0, u8 *, 0x4C) = (u8) (M2C_FIELD(D_8219A3C0, u8 *, 0x4C) & 0xFFDF);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82110A10; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82110A10.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82110B44; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82110B44.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82110B6C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82110B6C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82110BA4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82110BA4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82110BDC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82110BDC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82110EAC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82110EAC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82110EE4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82110EE4.s")
#endif

void func_82110FB0(void) {
}

void func_82110FB8(void) {
}

void Battle_ExecuteMoveAnimation(void) {
    sBattleUser->moveCache.lastMove = gMoveData[sBattleUser->usedMove - 1].unk_00;
    sBattleUser->moveCache.unk_01 = gMoveData[sBattleUser->usedMove - 1].unk_01;
    sBattleUser->moveCache.unk_02 = gMoveData[sBattleUser->usedMove - 1].unk_02;
    sBattleUser->moveCache.unk_03 = gMoveData[sBattleUser->usedMove - 1].unk_03;
    sBattleUser->moveCache.unk_04 = gMoveData[sBattleUser->usedMove - 1].unk_04;
    sBattleUser->moveCache.unk_05 = gMoveData[sBattleUser->usedMove - 1].unk_05;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82111080; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82111080.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82111150; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82111150.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821111D0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821111D0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821112AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821112AC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821113E8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821113E8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821115F4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821115F4.s")
#endif

s32 Battle_Effect_Metronome(void) {
    s32 move_pulled;

    Battle_IncrementMoveUsage();
    do {
        do {
            move_pulled = Battle_Random();
        } while (move_pulled == 0 || move_pulled >= 0xA5);
    } while (move_pulled == METRONOME);
    sBattleUser->usedMove = move_pulled;
    Battle_ExecuteMoveAnimation();
    return 1;
}

void Battle_ApplyPoisonOrBurnDamage(void) {
    u16 var_a0;

    if (sBattleUser->unk_12 != 0xFFFF) {
        sBattleUser->unk_0E = sBattleUser->unk_12;
    } else {
        sBattleUser->unk_0E = sBattleUser->unk_0C;
    }

    var_a0 = (sBattleUser->unk_28 >> 4) & 0xFFFF;
    if (var_a0 == 0) {
        var_a0++;
    }

    if (sBattleUser->unk_4E & 1) {
        sBattleUser->unk_51++;
        var_a0 *= sBattleUser->unk_51;
    }

    if (sBattleUser->unk_0E < var_a0) {
        sBattleUser->unk_0E = 0;
    } else {
        sBattleUser->unk_0E -= var_a0;
    }

    sBattleUser->unk_10 = sBattleUser->unk_0E;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8211176C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211176C.s")
#endif

void func_82111870(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_82111878; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82111878.s")
#endif

void BattleAnim_EffectEndNop(void) {
}

M2C_UNK func_82110FC0();                            /* extern */
M2C_UNK func_821115F4();                            /* extern */
M2C_UNK func_8211EF74(s32, M2C_UNK, s32);           /* extern */
extern s32 D_8218C784;
extern s8 *D_8219A3C0;
extern s8 *D_8219A3C4;
extern s32 D_8219A520;
extern s8 *D_8219A5A0;

s32 func_821119F8(void) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(D_8219A3C4, u8 *, 0x58);
    if ((temp_v0 == 0x77) || (temp_v0 == 0)) {
        M2C_FIELD(D_8219A5A0, s32 *, 0x48) = 0x1C;
        func_8211EF74(D_8219A520 + 0x88, 0x20, D_8218C784);
        return 0;
    }
    M2C_FIELD(D_8219A3C0, u8 *, 0x5A) = temp_v0;
    func_821115F4();
    func_82110FC0();
    return 1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82111A78; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82111A78.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82111AC4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82111AC4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82111C00; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82111C00.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82111CD4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82111CD4.s")
#endif
