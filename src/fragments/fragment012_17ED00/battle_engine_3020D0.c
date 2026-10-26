/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_3020D0.c, src/fragments/battle_engine/battle_engine_31D9F0.c, src/fragments/battle_engine/battle_engine_32A640.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "graphics_textures.h"
#include "ui_graphics.h"
#include "status_icons.h"
#include "game_state.h"
#include "text_system.h"
#include "3D140.h"
#include "gfx_buffer.h"
#include "gfx_rect.h"
#include "matrix.h"
#include "controller.h"
#include "memmap.h"
#include "memory.h"
#include "stdarg.h"
#include "moves.h"
extern unk_D_843901A0* gBattleMessageQueues;

#include "fragments/battle_engine/battle_engine.h"
#include "model_renderer.h"

#include "fragments/battle_engine/battle_engine.h"

#include "m2c_macros.h"

void Battle_ClearAllMessageQueues(void);
void Battle_ClearMessageCursor(void);
void Battle_SimpleStringFormat(s8* arg0, s8* arg1, ...);
void func_8211F3E4(void);
void func_8211F3EC(void);
void BattleScene_ResetMessageQueue(void);

#ifdef NON_MATCHING
/* TODO: decompile func_8211E890; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211E890.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211EB10; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211EB10.s")
#endif

void Battle_ClearAllMessageQueues(void) {
    gBattleMessageQueues->unk_088[0] = 0;
    gBattleMessageQueues->unk_088[1] = 0;
    gBattleMessageQueues->unk_0C8[0] = 0;
    gBattleMessageQueues->unk_0C8[1] = 0;
    gBattleMessageQueues->unk_108[0] = 0;
    gBattleMessageQueues->unk_108[1] = 0;
    gBattleMessageQueues->unk_148[0] = 0;
    gBattleMessageQueues->unk_148[1] = 0;
    gBattleMessageQueues->unk_188[0] = 0;
    gBattleMessageQueues->unk_188[1] = 0;
    gBattleMessageQueues->unk_1C8[0] = 0;
    gBattleMessageQueues->unk_1C8[1] = 0;
    gBattleMessageQueues->unk_448[0][0] = 0;
    gBattleMessageQueues->unk_448[0][1] = 0;
    gBattleMessageQueues->unk_448[1][0] = 0;
    gBattleMessageQueues->unk_448[1][1] = 0;
    gBattleMessageQueues->unk_208[0] = 0;
    gBattleMessageQueues->unk_208[1] = 0;
    gBattleMessageQueues->unk_308[0] = 0;
    gBattleMessageQueues->unk_308[1] = 0;
    gBattleMessageQueues->unk_2C8[0] = 0;
    gBattleMessageQueues->unk_2C8[1] = 0;
    gBattleMessageQueues->unk_348[0] = 0;
    gBattleMessageQueues->unk_348[1] = 0;
    gBattleMessageQueues->unk_388[0] = 0;
    gBattleMessageQueues->unk_388[1] = 0;
    gBattleMessageQueues->unk_3C8[0] = 0;
    gBattleMessageQueues->unk_3C8[1] = 0;
    gBattleMessageQueues->unk_408[0] = 0;
    gBattleMessageQueues->unk_408[1] = 0;
}

void Battle_ClearMessageCursor(void) {
    gBattleMessageQueues->unk_004 = 0;
    gBattleMessageQueues->unk_048[0] = 0;
    gBattleMessageQueues->unk_048[1] = 0;
    gBattleMessageQueues->unk_008[0] = 0;
    gBattleMessageQueues->unk_008[1] = 0;
}

void Battle_SimpleStringFormat(s8* arg0, s8* arg1, ...) {
    va_list args;
    s8* src;
    s8* fmt;
    s32 len;

    len = 0;
    va_start(args, arg1);
    fmt = arg1;

    while (*fmt != 0) {
        if (*fmt != 0x25) {
            arg0[len++] = *fmt;
        } else {
            fmt++;
            if (*fmt == 0x73) {
                src = va_arg(args, s8*);
                while (*src != 0) {
                    arg0[len] = *src;
                    src++;
                    len++;
                }
            }
        }
        fmt++;
    }
    arg0[len] = 0;
}

void func_8211EF74(s8* arg0, s8 id, s8* arg1, ...) {
    va_list args;
    s8* src;
    s8* fmt;
    s32 len;

    arg0[0] = id;
    len = 1;
    va_start(args, arg1);
    fmt = arg1;

    while (*fmt != 0) {
        if (*fmt != 0x25) {
            arg0[len++] = *fmt;
        } else {
            fmt++;
            if (*fmt == 0x73) {
                src = va_arg(args, s8*);
                while (*src != 0) {
                    arg0[len] = *src;
                    src++;
                    len++;
                }
            }
        }
        fmt++;
    }
    arg0[len] = 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8211F034; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211F034.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211F0DC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211F0DC.s")
#endif

void func_8211F0DC(void);
void Battle_DrawCompactStatusBoxesIfVisible(void) {
    ActivePokemon* ptr1 = sActivePokemon[0];
    ActivePokemon* ptr2 = sActivePokemon[1];

    if (sBattleScene.scene->unk_30 == 0) {
        BattleHud_DrawCompactMonStatusBox(ptr1, 0x15, 0xF, ptr1->sessionTeams->teamMember[M2C_FIELD(ptr1, s32*, 0x9D4)]->controllerPort);
        BattleHud_DrawCompactMonStatusBox(ptr2, 0xE1, 0xF, ptr2->sessionTeams->teamMember[M2C_FIELD(ptr2, s32*, 0x9D4)]->controllerPort);
        func_8211F0DC();
    }
}

void func_8211F274(s8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0xA04) = 0;
    M2C_FIELD(arg0, s32 *, 0xA08) = 0;
    M2C_FIELD(arg0, s8 *, 0xA4C) = 0;
    M2C_FIELD(arg0, s8 *, 0xA0C) = 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8211F288; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211F288.s")
#endif

void func_8211C43C(u8, s32, s32, s8*);
extern ActivePokemon* sSide1ActivePokemon;
void func_8211F2E0(ActivePokemon* arg0) {
    TeamRoster* roster = arg0->teamRoster;
    s8 c = arg0->captionState.unk_48[arg0->captionState.unk_04];

    if (c != 0) {
        if ((c == 0xA) || (c == 0x20)) {
            arg0->captionState.unk_08[arg0->captionState.unk_04] = c;
            arg0->captionState.unk_04++;
            c = arg0->captionState.unk_48[arg0->captionState.unk_04];
        }
        if ((c > 0x20) && (c < 0x40)) {
            arg0->captionState.unk_08[arg0->captionState.unk_04] = c;
            arg0->captionState.unk_04++;
        } else {
            arg0->captionState.unk_08[arg0->captionState.unk_04] = c;
            arg0->captionState.unk_08[arg0->captionState.unk_04 + 1] = arg0->captionState.unk_48[arg0->captionState.unk_04 + 1];
            arg0->captionState.unk_04 += 2;
        }
    }
    arg0->captionState.unk_08[arg0->captionState.unk_04] = 0;
    if (arg0->captionState.unk_48[0] != 0) {
        if (arg0 == sSide1ActivePokemon) {
            func_8211C43C(M2C_FIELD(roster, u8*, 1), 0x5F, 0xE, arg0->captionState.unk_08);
        } else {
            func_8211C43C(M2C_FIELD(roster, u8*, 1), 0x17, 0xBB, arg0->captionState.unk_08);
        }
    }
}

void func_8211F3E4(void) {
}

void func_8211F3EC(void) {
}

extern void* D_8219A520;

void func_8211F3F4(void) {
    D_8219A520 = main_pool_alloc(0x4C8, 0);
    bzero(D_8219A520, 0x4C8);
}

void BattleScene_ResetMessageQueue(void) {
    gBattleMessageQueues->unk_004 = 0;
    gBattleMessageQueues->unk_008[gBattleMessageQueues->unk_004] = 0;
    Battle_ClearMessageCursor();
}

#ifdef NON_MATCHING
/* TODO: decompile func_8211F46C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211F46C.s")
#endif
