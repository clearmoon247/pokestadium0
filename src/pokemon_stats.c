/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/pokemon_stats.c. */

#include "pokemon_stats.h"
#include "gb_data.h"
#include "save_data.h"
#include "text_system.h"
#include "gb_tower.h"
#include "hal_libc.h"
#include "util.h"
extern u8 D_8006B8C4[0x420];
typedef struct unk_func_800228F0_sp24 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ char unk_04[0x10];
    /* 0x14 */ char unk_14[0x8];
} unk_func_800228F0_sp24;
extern u8 gDexToInternalIndex[];
extern u8 gInternalIndexToDex[];
extern u32 D_800AD330;
extern u8 D_800AD334;
extern u8 D_800AD335;
extern GbSaveMainData D_800AD338;

u16 Pokemon_LevelFromExp(s32 arg0, u32 arg1);
void Pokemon_PrepareBattleMon(BattleMon* arg0);
u8 Move_GetIdFromTableIndex(s32 tm_hm_index);
u8 func_80020984(s32 arg0);
u8 func_80020994(s32 arg0);
void Deck_InitializeSaveBackend(DeckHandle* arg0);
void Deck_InitializeBoxBackend(DeckHandle* arg0);
DeckHandle* Deck_Open(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
DeckHandle* Deck_OpenAndSetName(s32 arg0, s32 arg1, s32 arg2, s32 arg3, char* arg4, u16 arg5);
s32 Deck_CloseAndFlushBox(DeckHandle* arg0);
s32 Deck_CloseAndFlush(DeckHandle* arg0);
s32 Deck_ReadEntries(u8* arg0, s32 arg1, DeckHandle* arg2);
s32 Deck_WriteEntries(u8* arg0, s32 arg1, DeckHandle* arg2);

s32 GbSave_HasPlayerNameMarker(u8* arg0);
s32 Deck_GetCapacity(s32 arg0);
s32 Deck_GetEntrySize(s32 arg0);
s32 Deck_GetCount(s32 arg0, s32 arg1, s32 arg2);
void Deck_DeleteEntry(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 Deck_ReadEntry(s32 arg0, s32 arg1, s32 arg2, s32 arg3, BattleMon* arg4);
s32 Deck_WriteEntry(s32 arg0, s32 arg1, s32 arg2, s32 arg3, unk_func_88205880_00D0* arg4);

// The Japanese build compiles the functions from here through Deck_WriteEntries into the
// gb_data object (gb_data.c includes this file with POKEMON_STATS_HEAD_ONLY defined); the
// Japanese pokemon_stats object starts at GbSave_HasPlayerNameMarker.
u16 Pokemon_LevelFromExp(s32 arg0, u32 arg1) {
    s32 i;

    for (i = 1; i < 100; i++) {
        if (arg1 < Pokemon_ExpForLevel(arg0, i + 1)) {
            break;
        }
    }

    return i;
}

void Pokemon_PrepareBattleMon(BattleMon* arg0) {
    s32 i;
    s32 temp_a3;
    s32 var_v0;
    s32 idx;

    Pokemon_RecalcStats(arg0);
    arg0->statusCondition = 0;
    arg0->hp = arg0->unk_26;

    for (i = 0; i < 4; i++) {
        if (arg0->unk_09[i] != 0) {
            temp_a3 = (arg0->unk_20[i] >> 6) & 3;
            var_v0 = gMoveData[arg0->unk_09[i] - 1].unk_05;

            if (var_v0 >= 0x28) {
                var_v0 = var_v0 + (temp_a3 * 7);
            } else {
                var_v0 = var_v0 + ((var_v0 / 5) * temp_a3);
            }

            arg0->unk_20[i] = (temp_a3 << 6) + var_v0;
        }
    }
}

u8 Move_GetIdFromTableIndex(s32 tm_hm_index) {
    extern u8 D_8006B8C4[];

    return D_8006B8C4[tm_hm_index];
}

u8 func_80020984(s32 arg0) {
    extern u8 D_8006B8FB[];

    return D_8006B8FB[arg0];
}

u8 func_80020994(s32 arg0) {
    extern u8 D_8006B993[];

    return D_8006B993[arg0];
}

#ifdef NON_MATCHING
/* TODO: decompile func_800209A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800209A4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800209B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800209B4.s")
#endif

void Deck_InitializeSaveBackend(DeckHandle* arg0) {
    if (arg0->unk_00 == 1) {
        arg0->unk_04 |= 1;
        Deck_SetSaveEntryCount(arg0->unk_01, arg0->unk_03, 0);
    }

    arg0->unk_05 = Deck_GetSaveRecordSize(arg0->unk_01);
    arg0->unk_06 = Deck_GetSaveRecordCapacity(arg0->unk_01);
    arg0->unk_08 = Deck_GetSaveEntryCount(arg0->unk_01, arg0->unk_03);

    if (arg0->unk_00 == 2) {
        arg0->unk_0A = arg0->unk_08;
    } else {
        arg0->unk_0A = 0;
    }
}

void Deck_InitializeBoxBackend(DeckHandle* arg0) {
    if (arg0->unk_00 == 1) {
        arg0->unk_04 |= 1;
        Deck_DeleteEntry(arg0->unk_01, arg0->unk_02, arg0->unk_03, 0);
    }

    arg0->unk_05 = Deck_GetEntrySize(arg0->unk_01);
    arg0->unk_06 = Deck_GetCapacity(arg0->unk_01);
    arg0->unk_08 = Deck_GetCount(arg0->unk_01, arg0->unk_02, arg0->unk_03);

    if (arg0->unk_00 == 2) {
        arg0->unk_0A = arg0->unk_08;
    } else {
        arg0->unk_0A = 0;
    }
}

DeckHandle* Deck_Open(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    DeckHandle* sp1C;

    sp1C = Util_Malloc(sizeof(DeckHandle));
    if (sp1C != NULL) {
        sp1C->unk_00 = arg3;
        sp1C->unk_01 = arg0;
        sp1C->unk_02 = arg1;
        sp1C->unk_03 = arg2;
        sp1C->unk_04 = 0;

        switch (arg0 & 0xF0) {
            case 16:
                Deck_InitializeSaveBackend(sp1C);
                break;

            case 32:
                Deck_InitializeBoxBackend(sp1C);
                break;
        }
    }

    return sp1C;
}

DeckHandle* Deck_OpenAndSetName(s32 arg0, s32 arg1, s32 arg2, s32 arg3, char* arg4, u16 arg5) {
    DeckHandle* sp24;
    DeckHandle* temp_v0;
    DeckHandle* var_v1;

    sp24 = Deck_Open(arg0, arg1, arg2, 1);
    if ((sp24 != NULL) && (arg0 & 0xF0)) {
        Deck_SetSaveEntryTrainerIdAndName(arg0, arg2, arg3, arg4, arg5);
    }
    return sp24;
}

s32 Deck_CloseAndFlushBox(DeckHandle* arg0) {
    s32 sp1C = 0;

    if ((arg0->unk_01 & 0x10) && (arg0->unk_04 & 1)) {
        Save_InvalidateTypedRecord(arg0->unk_01, arg0->unk_03);
        sp1C = 1;
    }

    Util_Free(arg0);

    return sp1C;
}

s32 Deck_CloseAndFlush(DeckHandle* arg0) {
    s32 sp1C = 0;

    if ((arg0->unk_01 & 0x10) && (arg0->unk_04 & 1)) {
        Save_CommitTypedRecord(arg0->unk_01, arg0->unk_03);
        sp1C = 1;
    }

    Util_Free(arg0);

    return sp1C;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80020CC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80020CC8.s")
#endif

s32 Deck_ReadEntries(u8* arg0, s32 arg1, DeckHandle* arg2) {
    s32 var_s3;
    s32 var_s4;
    s32 var_v1;
    s32 tmp;

    var_s4 = 0;
    var_s3 = arg1 - 1;
    tmp = arg1 > 0;

    if (tmp) {}

    if (tmp != 0) {
        for (; arg2->unk_0A < arg2->unk_08;) {
            var_v1 = 0;
            switch (arg2->unk_01 & 0xF0) {
                case 16:
                    var_v1 = Deck_ReadSaveEntry(arg2->unk_01, arg2->unk_03, arg2->unk_0A, arg0);
                    break;

                case 32:
                    var_v1 = Deck_ReadEntry(arg2->unk_01, arg2->unk_02, arg2->unk_03, arg2->unk_0A, arg0);
                    break;
            }

            tmp = var_s3 > 0;
            if (var_v1 == 0) {
                break;
            }

            arg2->unk_0A++;
            var_s3 -= 1;
            var_s4 += 1;
            arg0 += arg2->unk_05;

            if (!tmp) {
                break;
            }
        }
    }
    return var_s4;
}

s32 Deck_WriteEntries(u8* arg0, s32 arg1, DeckHandle* arg2) {
    s32 var_s2;
    s32 var_s4;
    s32 var_s5;
    s32 tmp;

    var_s5 = 0;
    var_s4 = arg1 - 1;
    tmp = arg1 > 0;

    if (tmp) {}

    if (tmp) {
        for (; arg2->unk_0A < arg2->unk_06;) {
            var_s2 = 0;
            switch (arg2->unk_01 & 0xF0) {
                case 16:
                    var_s2 = Save_WriteTypedRecord(arg2->unk_01, arg2->unk_03, arg2->unk_0A, arg0);
                    arg2->unk_08 = Deck_GetSaveEntryCount(arg2->unk_01, arg2->unk_03);
                    break;

                case 32:
                    var_s2 = Deck_WriteEntry(arg2->unk_01, arg2->unk_02, arg2->unk_03, arg2->unk_0A, arg0);
                    arg2->unk_08 = Deck_GetCount(arg2->unk_01, arg2->unk_02, arg2->unk_03);
                    break;
            }

            tmp = var_s4 > 0;
            if (var_s2 == 0) {
                break;
            }

            var_s4 -= 1;
            arg2->unk_0A++;
            var_s5 += 1;
            arg0 += arg2->unk_05;
            arg2->unk_04 |= 1;

            if (!tmp) {
                break;
            }
        }
    }

    return var_s5;
}
