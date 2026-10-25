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
#include "m2c_macros.h"
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

extern u8* D_823028E4[][3];
void func_8001B884(s32, s32, s32, s32, u8*, s32, s32);

s32 BattleMenu_DrawSidebarRowTypeIcon(s32 arg0, s32 arg1, s8 arg2, s8 arg3) {
    s32 sp34;
    s32 sp30;

    if (arg2 != 0) {
        if (arg2 == -1) {
            func_8001B884(arg0, arg1, 0x20, 0x14, D_3005680, 0x20, 0x200000);
        } else {
            sp34 = (arg2 >> 4) & 0xF;
            sp30 = arg2 & 0xF;

            if (arg3 > 0) {
                if (sp30 < 3) {
                    sp30++;
                }
            } else if (sp30 > 0) {
                sp30--;
            }

            if (sp30 > 0) {
                func_8001B884(arg0 + 6, arg1, 0x18, 0x14, D_823028E4[sp34][sp30], 0x18, 0x200000);
                arg2 = (sp34 * 0x10) | sp30;
            } else {
                arg2 = 0;
            }
        }
    }
    return arg2;
}

void BattleMenu_DrawTeamOrderSidebarTeam0(void) {
    unk_D_84803760* temp_v0 = &D_82302B20[0];
    s32 i;
    s16 var_s2;
    s32 var_s1;

    if (temp_v0->unk_0F == -1) {
        var_s2 = 0x3F;
    } else {
        var_s2 = 0x4A;
    }

    gSPDisplayList(gDisplayListHead++, D_80060290);

    func_8001B884(0x2D, var_s2, 0x20, 0xC, D_3003C80, 0x20, 0x200000);
    func_8001B884(0x2D, var_s2 + 0xC, 0x20, 0x17, D_30050C0, 0x20, 0x200000);
    func_8001B884(0x2D, var_s2 + 0x23, 0x20, 0x17, D_30050C0, 0x20, 0x200000);
    func_8001B884(0x2D, var_s2 + 0x3A, 0x20, 0x17, D_30050C0, 0x20, 0x200000);
    func_8001B884(0x2D, var_s2 + 0x51, 0x20, 0x17, D_30050C0, 0x20, 0x200000);
    func_8001B884(0x25, var_s2 + 0x68, 0x28, 0x2E, D_3002E20, 0x28, 0x200000);

    if (temp_v0->unk_0F == -1) {
        BattleMenu_DrawSidebarLeadIcon(0x2D, 0x21, &D_82302B20[0]);
    } else {
        BattleMenu_DrawSidebarLeadIcon(0x2D, 0x1D, &D_82302B20[0]);
    }

    var_s1 = var_s2 + 0x76;
    for (i = 0; i < 6; i++) {
        temp_v0->unk_02[i] = BattleMenu_DrawSidebarRowTypeIcon(0x2D, var_s1 - i * 0x17, temp_v0->unk_02[i], temp_v0->unk_08[i]);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void BattleMenu_DrawTeamOrderSidebarTeam1(void) {
    unk_D_84803760* temp_v0 = &D_82302B20[1];
    s32 i;
    s16 var_s2;
    s32 var_s1;

    if (temp_v0->unk_0F == -1) {
        var_s2 = 0xF1;
    } else {
        var_s2 = 0xE6;
    }

    gSPDisplayList(gDisplayListHead++, D_80060290);

    func_8001B884(0x2D, var_s2, 0x28, 0x2C, D_3003F80, 0x28, 0x200000);
    func_8001B884(0x2D, var_s2 + 0x2C, 0x20, 0x17, D_30050C0, 0x20, 0x200000);
    func_8001B884(0x2D, var_s2 + 0x43, 0x20, 0x17, D_30050C0, 0x20, 0x200000);
    func_8001B884(0x2D, var_s2 + 0x5A, 0x20, 0x17, D_30050C0, 0x20, 0x200000);
    func_8001B884(0x2D, var_s2 + 0x71, 0x20, 0x17, D_30050C0, 0x20, 0x200000);
    func_8001B884(0x2D, var_s2 + 0x88, 0x20, 0xE, D_3004D40, 0x20, 0x200000);

    if (temp_v0->unk_0F == -1) {
        BattleMenu_DrawSidebarLeadIcon(0x2D, 0x189, &D_82302B20[1]);
    } else {
        BattleMenu_DrawSidebarLeadIcon(0x2D, 0x17C, &D_82302B20[1]);
    }

    var_s1 = var_s2 + 0xC;
    for (i = 0; i < 6; i++) {
        temp_v0->unk_02[i] = BattleMenu_DrawSidebarRowTypeIcon(0x2D, var_s1 + i * 0x17, temp_v0->unk_02[i], temp_v0->unk_08[i]);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

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

void BattleMenu_DrawConfirmButtonLabel(unk_D_848037A0* arg0) {
    s16 sp26;
    s16 sp24;

    if (arg0->unk_0003 == 0) {
        // clang-format off
        sp26 = 0x50; sp24 = 0x81;
        // clang-format on
    } else {
        sp26 = 0x1B1;
        sp24 = 0x123;
    }

    BattleMenu_DrawBorderedPanel(sp26, sp24, 0x76, 0x20, arg0->unk_0001);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(8, 0);
    Font_Printf(sp26 + 9, sp24 + 5, arg0->unk_001C->unk_008);
    Font_EndTexturedTextRendering();
}

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

M2C_UNK func_8003F6AC(M2C_UNK, s8 *);             /* extern */
M2C_UNK func_82300B30(s8, s8 *);                  /* extern */
extern s8 D_82302B48;
void func_82301B2C(s8 *arg0) {
    s8 temp_v1;
    s8 *temp_v0;

    if (M2C_FIELD(arg0, s8 *, 0xB) > 0) {
        M2C_FIELD(arg0, s8 *, 0xB) = 0;
        func_82300B30(M2C_FIELD(arg0, s8 *, 3), arg0);
        if (M2C_FIELD(arg0, s8 *, 9) != 0) {
            M2C_FIELD(arg0, s8 *, 6) = 2;
        }
        func_8003F6AC(3, arg0);
        temp_v1 = M2C_FIELD(arg0, s8 *, 2);
        if (temp_v1 != -1) {
            temp_v0 = (temp_v1 << 5) + &D_82302B48;
            M2C_FIELD(temp_v0, s8 *, 5) = 0;
            M2C_FIELD(temp_v0, s8 *, 0xB) = 0;
            M2C_FIELD(temp_v0, s8 *, 9) = 0;
            M2C_FIELD(temp_v0, s8 *, 6) = 2;
        }
    }
}

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

extern s32 D_82302B44;
extern SessionContext* D_82302BD0;

// Zero's order-select slot keeps only the first 0x20 bytes of Stadium 1's unk_D_848037A0.
typedef struct OrderSelectSlot {
    /* 0x00 */ char unk00[0xB];
    /* 0x0B */ s8 unk_000B;
    /* 0x0C */ s8 unk_000C[6];
    /* 0x12 */ char unk12[0x6];
    /* 0x18 */ BattleMon* unk_0018;
    /* 0x1C */ TeamRoster* unk_001C;
} OrderSelectSlot; // size = 0x20

void BattleMenu_CommitOrderSelection(void) {
    s32 i;
    s32 var_s4;
    TeamRoster* temp_s1;
    OrderSelectSlot* var_s2;

    var_s2 = (OrderSelectSlot*)&D_82302B48;
    var_s4 = D_82302B44;

    while (var_s4-- > 0) {
        temp_s1 = var_s2->unk_001C;
        if (temp_s1->unk_000 & 2) {
            temp_s1->numberOfPokemonBrought = temp_s1->rosterInfo->numberOfPokemonCanBePicked;
            _bcopy(temp_s1->rosterInfo->unk_028, temp_s1->pokemonPicked, sizeof(temp_s1->pokemonPicked));
        } else {
            BattleMenu_FillDefaultOrder(var_s2->unk_000C, var_s2->unk_000B);
            temp_s1->numberOfPokemonBrought = var_s2->unk_000B;

            for (i = 0; i < temp_s1->rosterInfo->numberOfPokemonCanBePicked; i++) {
                temp_s1->pokemonPicked[i] = var_s2->unk_0018[var_s2->unk_000C[i]];
            }
        }
        var_s2++;
    }

    BattleMenu_RearrangeLeadPokemon(&D_82302BD0->battleSides[0], &D_82302B20[0]);
    BattleMenu_RearrangeLeadPokemon(&D_82302BD0->battleSides[1], &D_82302B20[1]);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82302288; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_82302288.s")
#endif

extern s32 D_82302BFC;
extern s16 D_82302B42;
extern s16 D_82302B40;
extern s32 D_82302C00;
extern Controller D_82302BD8;
void BattleMenu_InitOrderSelectPanels(SessionContext* arg0) {
    BattleSessionTeams* temp_s0 = &arg0->battleSides[0];

    D_82302BD0 = arg0;
    D_82302B44 = 0;
    D_82302B40 = 2;
    D_82302B42 = 0;
    D_82302BFC = 0;
    D_82302C00 = 0;
    D_82302BD8.buttonPressed = 0;

    BattleMenu_InitTeamOrderState(&D_82302B20[0], &D_82302BD0->battleSides[0], D_82302BD0->ruleCategory);
    BattleMenu_InitTeamOrderState(&D_82302B20[1], &D_82302BD0->battleSides[1], D_82302BD0->ruleCategory);

    if (temp_s0->tagTeamSize == 1) {
        BattleMenu_AddOrderSelectPanel(0x50, 0x21, temp_s0->teamMember[0], 0, -1);
    } else if (temp_s0->teamMember[0]->controllerPort < temp_s0->teamMember[1]->controllerPort) {
        BattleMenu_AddOrderSelectPanel(0x50, 0x21, temp_s0->teamMember[0], 0, D_82302B44 + 1);
        BattleMenu_AddOrderSelectPanel(0x50, 0x81, temp_s0->teamMember[1], 0, D_82302B44 - 1);
    } else {
        BattleMenu_AddOrderSelectPanel(0x50, 0x21, temp_s0->teamMember[1], 0, D_82302B44 + 1);
        BattleMenu_AddOrderSelectPanel(0x50, 0x81, temp_s0->teamMember[0], 0, D_82302B44 - 1);
    }

    temp_s0++;
    if (temp_s0->tagTeamSize == 1) {
        BattleMenu_AddOrderSelectPanel(0x50, 0x146, temp_s0->teamMember[0], 1, -1);
    } else if (temp_s0->teamMember[0]->controllerPort < temp_s0->teamMember[1]->controllerPort) {
        BattleMenu_AddOrderSelectPanel(0x50, 0xE6, temp_s0->teamMember[0], 1, D_82302B44 + 1);
        BattleMenu_AddOrderSelectPanel(0x50, 0x146, temp_s0->teamMember[1], 1, D_82302B44 - 1);
    } else {
        BattleMenu_AddOrderSelectPanel(0x50, 0xE6, temp_s0->teamMember[1], 1, D_82302B44 + 1);
        BattleMenu_AddOrderSelectPanel(0x50, 0x146, temp_s0->teamMember[0], 1, D_82302B44 - 1);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82302644; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment005_15FCE0/func_82302644.s")
#endif
