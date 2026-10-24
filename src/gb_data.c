/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/gb_data.c. */

#include "gb_data.h"
#include "string.h"
#include "gb_data.h"
#include "save_data.h"
#include "text_system.h"
#include "gb_tower.h"
#include "hal_libc.h"
#include "util.h"
extern const char sStatusNames[7][4];
extern const char sTypeNames[17][4];
extern const char sMoveNames[166][8];
extern SpeciesData gSpeciesData[152];
extern unk_D_80071D88 sStatusDisplayInfo[8];
extern char sMoveComments[165][8];
extern unk_D_80072338 gMoveDisplayInfo[166];
extern MoveData gMoveData[165];
extern char* D_8006B570[84];

#include "m2c_macros.h"

u16 GbData_ReadU16BE(u8* arg0);
u32 GbData_ReadU24BE(u8* arg0);
void GbData_WriteU16BE(u8* arg0, s32 arg1);
void GbData_WriteU24BE(u8* arg0, s32 arg1);
char* Text_UntranscodeFixedName(char* arg0, char* arg1);
char* Text_CopySpeciesName(char* arg0, s32 arg1);
char* Text_GetTmHmName(s32 arg0, char* arg1);
void Pokemon_FromGbRecordExt(BattleMon* arg0, GbPokemonRecordExt* arg1);
void Pokemon_ToGbRecordExt(unk_func_88205880_00D0* arg0, GbPokemonRecordExt* arg1);
u16 StatExpSqrt(u16 square);
void func_80020188(void);
u16 GetPokemonDV(s32 statId, u16 dvBits);
u32 CalculateStatValue(s32 statId, s32 speciesId, u16 statModifier, u16 level, u16 dvBits);
void Pokemon_RecalcStats(BattleMon* arg0);
u16 Pokemon_StatExpForTarget(s32 arg0, s32 arg1, u16 arg2, u16 arg3, u16 arg4);
u32 Pokemon_ExpForLevel(s32 arg0, u16 arg1);

char* Text_UntranscodeName(char* arg0, char* arg1);
char* Text_CopyString(char* arg0, char* arg1);
void Pokemon_FromGbRecord(BattleMon* arg0, GbPokemonRecord* arg1);
void Pokemon_ToGbRecord(BattleMon* arg0, GbPokemonRecord* arg1);

u16 GbData_ReadU16BE(u8* arg0) {
    return (arg0[0] << 8) | arg0[1];
}

u32 GbData_ReadU24BE(u8* arg0) {
    return (arg0[0] << 16) | (arg0[1] << 8) | arg0[2];
}

void GbData_WriteU16BE(u8* arg0, s32 arg1) {
    arg0[0] = (arg1 >> 8) & 0xFF;
    arg0[1] = arg1 & 0xFF;
}

void GbData_WriteU24BE(u8* arg0, s32 arg1) {
    arg0[0] = (arg1 >> 16) & 0xFF;
    arg0[1] = (arg1 >> 8) & 0xFF;
    arg0[2] = (arg1) & 0xFF;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8001FB10; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001FB10.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8001FBE4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001FBE4.s")
#endif

char* Text_UntranscodeFixedName(char* arg0, char* arg1) {
    char sp18[6];

    _bcopy(arg1, sp18, 5);

    sp18[5] = 'P';

    return Text_UntranscodeName(arg0, sp18);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8001FD00; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001FD00.s")
#endif

char* Text_CopySpeciesName(char* arg0, s32 arg1) {
    Text_CopyString(arg0, (char*)*(u32*)D_80064C44[arg1]);
    return arg0;
}

char* Text_GetTmHmName(s32 arg0, char* arg1) {
    // "ひでんマシン%02d"
    static const char D_0007CCA0[] = { 164, 210, 164, 199, 164, 243, 165, 222, 165, 183,
                                       165, 243, 37, 48, 50, 100, 0, 0, 0, 0 };
    // "わざマシン%02d"
    static const char D_0007CCB4[] = { 164, 239, 164, 182, 165, 222, 165, 183,
                                       165, 243, 37, 48, 50, 100, 0, 0 };

    if ((arg0 > 0) && (arg0 < 84)) {
        HAL_Strcpy(arg1, D_8006B570[arg0 - 1]);
    } else if ((arg0 >= 196) && (arg0 < 201)) {
        sprintf(arg1, D_0007CCA0, arg0 - 195, arg0);
    } else if ((arg0 >= 201) && (arg0 < 0xFF)) {
        sprintf(arg1, D_0007CCB4, arg0 - 200, arg0);
    } else {
        HAL_Strcpy(arg1, D_8006B570[6]);
    }

    return arg1;
}

s16 func_8001FAB0(s8 *);                          /* extern */
s32 func_8001FAC8(s8 *);                          /* extern */
s8 func_80020994(u8);                               /* extern */
M2C_UNK func_80056690(s8 *, s8 *, M2C_UNK);     /* extern */

void func_8001FE84(s8 *arg0, s8 *arg1) {
    M2C_FIELD(arg0, s8 *, 0) = func_80020994(M2C_FIELD(arg1, u8 *, 0));
    M2C_FIELD(arg0, s8 *, 1) = 0;
    M2C_FIELD(arg0, s16 *, 2) = func_8001FAB0(arg1 + 1);
    M2C_FIELD(arg0, u8 *, 4) = (u8) M2C_FIELD(arg1, u8 *, 3);
    M2C_FIELD(arg0, u8 *, 5) = (u8) M2C_FIELD(arg1, u8 *, 4);
    M2C_FIELD(arg0, u8 *, 6) = (u8) M2C_FIELD(arg1, u8 *, 5);
    M2C_FIELD(arg0, u8 *, 7) = (u8) M2C_FIELD(arg1, u8 *, 6);
    M2C_FIELD(arg0, u8 *, 8) = (u8) M2C_FIELD(arg1, u8 *, 7);
    M2C_FIELD(arg0, s16 *, 0xE) = func_8001FAB0(arg1 + 0xC);
    M2C_FIELD(arg0, s32 *, 0x10) = func_8001FAC8(arg1 + 0xE);
    M2C_FIELD(arg0, s16 *, 0x14) = func_8001FAB0(arg1 + 0x11);
    M2C_FIELD(arg0, s16 *, 0x16) = func_8001FAB0(arg1 + 0x13);
    M2C_FIELD(arg0, s16 *, 0x18) = func_8001FAB0(arg1 + 0x15);
    M2C_FIELD(arg0, s16 *, 0x1A) = func_8001FAB0(arg1 + 0x17);
    M2C_FIELD(arg0, s16 *, 0x1C) = func_8001FAB0(arg1 + 0x19);
    M2C_FIELD(arg0, s16 *, 0x1E) = func_8001FAB0(arg1 + 0x1B);
    func_80056690(arg0 + 9, arg1 + 8, 4);
    func_80056690(arg0 + 0x20, arg1 + 0x1D, 4);
}

void Pokemon_FromGbRecordExt(BattleMon* arg0, GbPokemonRecordExt* arg1) {
    Pokemon_FromGbRecord(arg0, &arg1->unk_00);
    arg0->unk_24 = arg1->unk_21;
    arg0->unk_26 = GbData_ReadU16BE(arg1->unk_22);
    arg0->unk_28 = GbData_ReadU16BE(arg1->unk_24);
    arg0->unk_2A = GbData_ReadU16BE(arg1->unk_26);
    arg0->unk_2C = GbData_ReadU16BE(arg1->unk_28);
    arg0->unk_2E = GbData_ReadU16BE(arg1->unk_2A);
}

M2C_UNK func_8001FAE8(s8 *, u16);                 /* extern */
M2C_UNK func_8001FAF8(s8 *, s32);                 /* extern */
s8 func_80020984(u8);                               /* extern */
M2C_UNK func_80056690(s8 *, s8 *, M2C_UNK);     /* extern */

void func_8001FFE8(s8 *arg0, s8 *arg1) {
    M2C_FIELD(arg1, s8 *, 0) = func_80020984(M2C_FIELD(arg0, u8 *, 0));
    func_8001FAE8(arg1 + 1, M2C_FIELD(arg0, u16 *, 2));
    M2C_FIELD(arg1, u8 *, 3) = (u8) M2C_FIELD(arg0, u8 *, 4);
    M2C_FIELD(arg1, u8 *, 4) = (u8) M2C_FIELD(arg0, u8 *, 5);
    M2C_FIELD(arg1, u8 *, 5) = (u8) M2C_FIELD(arg0, u8 *, 6);
    M2C_FIELD(arg1, u8 *, 6) = (u8) M2C_FIELD(arg0, u8 *, 7);
    M2C_FIELD(arg1, u8 *, 7) = (u8) M2C_FIELD(arg0, u8 *, 8);
    func_8001FAE8(arg1 + 0xC, M2C_FIELD(arg0, u16 *, 0xE));
    func_8001FAF8(arg1 + 0xE, M2C_FIELD(arg0, s32 *, 0x10));
    func_8001FAE8(arg1 + 0x11, M2C_FIELD(arg0, u16 *, 0x14));
    func_8001FAE8(arg1 + 0x13, M2C_FIELD(arg0, u16 *, 0x16));
    func_8001FAE8(arg1 + 0x15, M2C_FIELD(arg0, u16 *, 0x18));
    func_8001FAE8(arg1 + 0x17, M2C_FIELD(arg0, u16 *, 0x1A));
    func_8001FAE8(arg1 + 0x19, M2C_FIELD(arg0, u16 *, 0x1C));
    func_8001FAE8(arg1 + 0x1B, M2C_FIELD(arg0, u16 *, 0x1E));
    func_80056690(arg1 + 8, arg0 + 9, 4);
    func_80056690(arg1 + 0x1D, arg0 + 0x20, 4);
}

void Pokemon_ToGbRecordExt(unk_func_88205880_00D0* arg0, GbPokemonRecordExt* arg1) {
    Pokemon_ToGbRecord(arg0->unk_000, arg1);
    arg1->unk_21 = arg0->unk_000[0].unk_24;
    GbData_WriteU16BE(arg1->unk_22, arg0->unk_000[0].unk_26);
    GbData_WriteU16BE(arg1->unk_24, arg0->unk_000[0].unk_28);
    GbData_WriteU16BE(arg1->unk_26, arg0->unk_000[0].unk_2A);
    GbData_WriteU16BE(arg1->unk_28, arg0->unk_000[0].unk_2C);
    GbData_WriteU16BE(arg1->unk_2A, arg0->unk_000[0].unk_2E);
}

u16 StatExpSqrt(u16 square) {
    u16 i;

    for (i = 1; i < 255; i++) {
        if (SQ(i) >= square) {
            break;
        }
    }
    return i;
}

void func_80020188(void) {
}

u16 GetPokemonDV(s32 statId, u16 dvBits) { //GetPokemonDV
    u16 dvValue;

    switch (statId) {
        case STAT_HP: // HP DV (derived from the LSBs of other DVs)
            dvValue = ((dvBits & 0x1000) >> 9)  // Special DV bit 0 → HP DV bit 0
                    | ((dvBits & 0x0100) >> 6)  // Speed DV bit 0 → HP DV bit 1
                    | ((dvBits & 0x0010) >> 3)  // Defense DV bit 0 → HP DV bit 2
                    | (dvBits & 0x0001);        // Attack DV bit 0 → HP DV bit 3
            break;

        case STAT_SPECIAL: // Special DV
            dvValue = (dvBits >> 12) & 0xF;
            break;

        case STAT_SPEED: // Speed DV
            dvValue = (dvBits >> 8) & 0xF;
            break;

        case STAT_DEFENSE: // Defense DV
            dvValue = (dvBits >> 4) & 0xF;
            break;

        case STAT_ATTACK: // Attack DV
            dvValue = dvBits & 0xF;
            break;
    }

    return dvValue;
}

u32 CalculateStatValue(s32 statId, s32 speciesId, u16 statModifier, u16 level, u16 dvBits) {
    u16 statValue;
    u16 baseStat;
    u16 dvValue;

    switch (statId) {
        case STAT_HP:
            baseStat = gBaseStats[speciesId].baseHP;
            break;
        case STAT_SPECIAL:
            baseStat = gBaseStats[speciesId].baseSpecial;
            break;
        case STAT_SPEED:
            baseStat = gBaseStats[speciesId].baseSpeed;
            break;
        case STAT_DEFENSE:
            baseStat = gBaseStats[speciesId].baseDefense;
            break;
        case STAT_ATTACK:
            baseStat = gBaseStats[speciesId].baseAttack;
            break;
    }

    // Get the Pokémon's DV for the stat (or HP DV)
    dvValue = GetPokemonDV(statId, dvBits);

    // Compute the preliminary stat value
    statValue = (((StatExpSqrt(statModifier) / 4) + ((baseStat + dvValue) * 2)) * level) / 100;

    // Add final adjustments
    if (statId == STAT_HP) {
        statValue += level + 10;
    } else {
        statValue += 5;
    }

    // Cap at 999
    if (statValue > 999) {
        statValue = 999;
    }

    return statValue;
}

void Pokemon_RecalcStats(BattleMon* arg0) {
    arg0->unk_24 = Pokemon_LevelFromExp(arg0->unk_00.unk_00, arg0->unk_10);
    arg0->unk_26 = CalculateStatValue(1, arg0->unk_00.unk_00, arg0->unk_14, arg0->unk_24, arg0->unk_1E);
    arg0->unk_28 = CalculateStatValue(2, arg0->unk_00.unk_00, arg0->unk_16, arg0->unk_24, arg0->unk_1E);
    arg0->unk_2A = CalculateStatValue(3, arg0->unk_00.unk_00, arg0->unk_18, arg0->unk_24, arg0->unk_1E);
    arg0->unk_2C = CalculateStatValue(4, arg0->unk_00.unk_00, arg0->unk_1A, arg0->unk_24, arg0->unk_1E);
    arg0->unk_2E = CalculateStatValue(5, arg0->unk_00.unk_00, arg0->unk_1C, arg0->unk_24, arg0->unk_1E);
}

u16 Pokemon_StatExpForTarget(s32 arg0, s32 arg1, u16 arg2, u16 arg3, u16 arg4) {
    s32 i;
    s32 tmp;

    for (i = 1; i < 0xFFFF; i += 2) {
        tmp = CalculateStatValue(arg0, arg1, i + 2, arg3, arg4);
        if (arg2 < tmp) {
            break;
        }
    }

    return i;
}

u32 Pokemon_ExpForLevel(s32 arg0, u16 arg1) {
    u32 sp4;

    switch (gBaseStats[arg0].unk_13) {
        case 0:
            sp4 = arg1 * arg1 * arg1;
            break;

        case 1:
            sp4 = (((arg1 * arg1 * arg1 * 3) / 4) + (arg1 * 10 * arg1)) - 30;
            break;

        case 2:
            sp4 = (((arg1 * arg1 * arg1 * 3) / 4) + (arg1 * 20 * arg1)) - 30;
            break;

        case 3:
            sp4 = ((((arg1 * arg1 * arg1 * 6) / 5) - (arg1 * 15 * arg1)) + (arg1 * 100)) - 140;
            break;

        case 4:
            sp4 = (arg1 * arg1 * arg1 * 4) / 5;
            break;

        case 5:
            sp4 = (arg1 * arg1 * arg1 * 5) / 4;
            break;
    }

    return sp4;
}
