/* Stadium Zero fragment005_15FCE0. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_order_select/battle_order_select.c. */

#include "fragments/battle_order_select/battle_order_select.h"
#include "geo_render.h"
#include "poke_icon.h"
#include "graphics_textures.h"
#include "input.h"
#include "ui_graphics.h"
#include "status_icons.h"
#include "pokemon_stats.h"
#include "text_system.h"
#include "jpeg_stream.h"
#include "audio_sfx.h"
#include "gfx_buffer.h"
#include "DDC0.h"
#include "controller.h"
#include "memory.h"
#include "stage_loader.h"
extern unk_D_84803760 D_82302B20[2];
extern u16 D_82302800[];

void BattleMenu_AppendOrderSlotIcon(s32 arg0, s32 arg1);
void BattleMenu_ResetOrderSlotIcons(s32 arg0);
void BattleMenu_DrawBorderedPanel(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
s32 BattleMenu_IsSlotAlreadySelected(unk_D_848037A0* arg0, s8 arg1);
void BattleMenu_HandleOrderSelectPanel_LevelCapNoticeInput(Controller* arg0, unk_D_848037A0* arg1);
void BattleMenu_RearrangeLeadPokemon(BattleSessionTeams* arg0, unk_D_84803760* arg1);
void BattleMenu_FillDefaultOrder(s8* arg0, s32 arg1);

#ifdef NON_MATCHING
/* TODO: decompile func_82300020; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_82300020.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8230016C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_8230016C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_823003B8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_823003B8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82300488; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_82300488.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_823005B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_823005B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_823006D8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_823006D8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_823008DC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_823008DC.s")
#endif

void BattleMenu_AppendOrderSlotIcon(s32 arg0, s32 arg1) {
    unk_D_84803760* temp_v0 = &D_82302B20[arg0];

    temp_v0->unk_02[temp_v0->unk_00] = ((arg1 + 1) << 4) | (temp_v0->unk_02[temp_v0->unk_00] & 0xF);
    temp_v0->unk_08[temp_v0->unk_00] = 1;
    temp_v0->unk_00++;
}

void BattleMenu_ResetOrderSlotIcons(s32 arg0) {
    unk_D_84803760* ptr = &D_82302B20[arg0];
    s32 i;

    for (i = 0; i < 6; i++) {
        ptr->unk_08[i] = -1;
    }
    ptr->unk_00 = 0;
}

void BattleMenu_DrawBorderedPanel(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    Ui_DrawBorderedPanelStyleB(arg0, arg1, arg2, arg3, D_82302800[arg4]);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82300BD0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_82300BD0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_823010E8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_823010E8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_823012D0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_823012D0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82301448; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_82301448.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82301658; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_82301658.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_823016FC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_823016FC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_823017EC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_823017EC.s")
#endif

s32 BattleMenu_IsSlotAlreadySelected(unk_D_848037A0* arg0, s8 arg1) {
    s32 i;
    s8 temp_v1;
    unk_D_848037A0* var_a2;

    for (i = 0; i < arg0->unk_000B; i++) {
        if (arg1 == arg0->unk_000C[i]) {
            return 1;
        }
    }

    return 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_823018F8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_823018F8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_823019AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_823019AC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82301A2C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_82301A2C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82301B2C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_82301B2C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82301BBC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_82301BBC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82301CCC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_82301CCC.s")
#endif

void BattleMenu_HandleOrderSelectPanel_LevelCapNoticeInput(Controller* arg0, unk_D_848037A0* arg1) {
    if (BTN_IS_PRESSED(arg0, BTN_A | BTN_B)) {
        arg1->unk_0005 = 0;
        arg1->unk_000B = 0;
        arg1->unk_0009 = 0;
        arg1->unk_0006 = 2;
        BattleMenu_ResetOrderSlotIcons(arg1->unk_0003);
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82301E28; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_82301E28.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82301EF4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_82301EF4.s")
#endif

void BattleMenu_RearrangeLeadPokemon(BattleSessionTeams* arg0, unk_D_84803760* arg1) {
    TeamRoster* temp_v0;
    s32 tmp;

    if (arg0->tagTeamSize == 2) {
        tmp = ((arg1->unk_02[0] >> 4) & 0xF) - 1;
        if (tmp == arg0->teamMember[1]->controllerPort) {
            temp_v0 = arg0->teamMember[0];
            arg0->teamMember[0] = arg0->teamMember[1];
            arg0->teamMember[1] = temp_v0;
        }
    }
}

void BattleMenu_FillDefaultOrder(s8* arg0, s32 arg1) {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < arg1; j++) {
            if (i == arg0[j]) {
                break;
            }
        }

        if (j == arg1) {
            arg0[arg1] = i;
            arg1 += 1;
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82302114; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_82302114.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82302288; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_82302288.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_823023EC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_823023EC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82302644; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_82302644.s")
#endif
