/* Stadium Zero fragment010_17BE70. */
/* C ported from the Stadium 1 decomp: src/fragments/pikachu_reward/pikachu_reward.c, src/game_state.c. */

#include "fragments/pikachu_reward/pikachu_reward.h"
#include "geo_render.h"
#include "model_animation.h"
#include "display_object_textures.h"
#include "model_renderer.h"
#include "graphics_textures.h"
#include "ui_graphics.h"
#include "pokemon_stats.h"
#include "text_system.h"
#include "gb_save.h"
#include "jpeg_stream.h"
#include "audio_fade.h"
#include "audio_stored_fade.h"
#include "audio_sfx.h"
#include "cry.h"
#include "gfx_buffer.h"
#include "gfx_rect.h"
#include "DDC0.h"
#include "matrix.h"
#include "geo_layout.h"
#include "memory.h"
#include "stage_loader.h"
#include "util.h"
extern GraphNode* D_81702010;
extern GraphNode* D_81702014;
extern unk_D_86002F30* D_81702018;
extern DisplayObject D_81702020[4];
extern unk_D_832025C8 D_817025C0;
extern s32 D_81701B04;
extern char* D_81701B08;
extern u32 D_81701B4C[];

#include "game_state.h"
#include "functions.h"
#include "input.h"
#include "save_data.h"
#include "audio_commands.h"
#include "gallery.h"
#include "gb_data.h"
#include "jpeg_stream.h"
#include "gfx_buffer.h"
#include "DDC0.h"
#include "session.h"
#include "save_data.h"
#include "minigame_dispatch.h"
#include "gb_save.h"
#include "gb_tower_audio.h"
#include "leo.h"
#include "display_object_textures.h"
#include "pokemon_stats.h"
#include "controller.h"
#include "dp_intro.h"
#include "gb_tower.h"
#include "memory.h"
#include "rsp.h"
#include "stage_loader.h"
#include "lib/ultralib/include/PR/os_internal_reg.h"
extern u16 D_8006BBB0[16][256];
extern s32 pad_D_80075660;
extern s32 pad_D_80075664;
extern s32 gCurrentGameState;
extern s32 gLastGameState;
extern s32 pad_D_80075670;
extern s16 D_800733D4;
extern s16 D_800733D8;
extern unk_D_800AE520 D_800AF990;
extern s32 pad_D_800AE534[2];
extern SessionContext gSessionContext;

#include "m2c_macros.h"

s32 PikachuReward_PositionSurfingPikachuModel(s32 arg0, DisplayObject* arg1);
void Controller_PollInputs(void);
void PikachuReward_UpdateFollowerVisibility(void);
s32 PikachuReward_RenderFrame(u8 arg0);
void PikachuReward_DrawTextBoxPanel(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void PikachuReward_DrawSelectionCursor(s16 arg0, s16 arg1);
void PikachuReward_ShowTextForFrames(char* arg0, s32 arg1);
void PikachuReward_ScrollTextIn(s8* arg0);
void PikachuReward_PlayIntroCamera(void);
void PikachuReward_SetupFollowerModel(DisplayObject* arg0, s16 arg1, s16 arg2, s16 arg3);
void PikachuReward_SetupScene(void);

void PikachuReward_UpdateLeadPikachuAnimation(void);

s32 PikachuReward_PositionSurfingPikachuModel(s32 arg0, DisplayObject* arg1) {
    if (arg0 == 2) {
        arg1->rotation.z -= 0x80;
        arg1->position.x = D_81702020->position.x;
        arg1->position.y = D_81702020->position.y + 70.0f;
    }
    return 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_81700064; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment010_17BE70/func_81700064.s")
#endif

extern s8 *D_817027A8;

s32 func_81700130(void) {
    s32 var_v1;
    s8 *var_v0;

    var_v0 = D_817027A8;
    var_v1 = 0;
loop_1:
    if (M2C_FIELD(var_v0, u8 *, 9) != 0) {
        var_v1 += 1;
        var_v0 += 1;
        if (var_v1 != 4) {
            goto loop_1;
        }
    }
    return var_v1;
}

void Controller_PollInputs(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

#ifdef NON_MATCHING
/* TODO: decompile func_81700190; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment010_17BE70/func_81700190.s")
#endif

void PikachuReward_UpdateFollowerVisibility(void) {
    if (D_81701B04 == -1) {
        D_81702020[1].node.flags &= ~1;
        D_81702020[2].node.flags &= ~1;
        D_81702020[3].node.flags &= ~1;
        return;
    }

    switch (D_81701B04) {
        case 0x0:
            D_81702020[1].node.flags |= 1;
            break;

        case 0x8:
            D_81702020[2].node.flags |= 1;
            break;

        case 0x10:
            D_81702020[3].node.flags |= 1;
            break;

        case 0x46:
            D_81702020[1].node.flags &= ~1;
            break;

        case 0x4E:
            D_81702020[2].node.flags &= ~1;
            break;

        case 0x56:
            D_81702020[3].node.flags &= ~1;
            break;
    }

    if (D_81701B04 < 0x57) {
        D_81701B04++;
    }
}

s32 PikachuReward_RenderFrame(u8 arg0) {
    GeoRender_AdvanceFrameCounter();
    PikachuReward_UpdateLeadPikachuAnimation();
    PikachuReward_UpdateFollowerVisibility();
    BgStage_DrawFrame();
    GfxImage_FillCurrent(&gDisplayListHead, 1);
    Geo_RenderRootNode(D_81702010);
    return 0;
}

void PikachuReward_DrawBlinkingStarIcon(s16 arg0, s16 arg1) {
    s32 var_a3;

    if (D_817025C0.unk_00 < 0x10) {
        var_a3 = D_817025C0.unk_00 * 0x10;
    } else if (D_817025C0.unk_00 < 0x23) {
        var_a3 = 0xFF;
    } else if (D_817025C0.unk_00 < 0x32) {
        var_a3 = (-D_817025C0.unk_00 * 0x10) + 0x320;
    } else {
        var_a3 = 0;
    }

    D_817025C0.unk_00++;
    if (D_817025C0.unk_00 >= 0x3D) {
        D_817025C0.unk_00 = 0;
    }

    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, var_a3);
    Font_DrawCharAt(arg0, arg1, 0x2177);
}

void PikachuReward_DrawTextBoxPanel(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    Color_RGB8 sp24 = { 0x00, 0x00, 0x32 };
    Color_RGB8 sp20 = { 0x00, 0x00, 0xC8 };

    Ui_DrawGradientPanel(arg0, arg1, arg2, arg3, &sp24, &sp20);
}

void PikachuReward_DrawSelectionCursor(s16 arg0, s16 arg1) {
    gSPDisplayList(gDisplayListHead++, D_80060290);

    Gfx_DrawTextureRgba16(arg0, arg1, 0x18, 0xE, Util_ConvertAddrToVirtAddr(D_8FC00090), 0x18, 0x200000);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void PikachuReward_ShowTextForFrames(char* arg0, s32 arg1) {
    while (arg1-- > 0) {
        Controller_PollInputs();
        PikachuReward_RenderFrame(0);
        PikachuReward_DrawTextBoxPanel(0x1E, 0x20, 0x104, 0x30);
        Font_BeginTranslucentTextRendering();
        Font_SetActive(2, 0);
        Font_SetLineHeight(0x10);
        Font_Printf(0x2E, 0x28, arg0);
        Font_EndTexturedTextRendering();
        BgStage_AdvanceFrame();
    }

    D_81701B08 = arg0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_81700630; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment010_17BE70/func_81700630.s")
#endif

void PikachuReward_ScrollTextIn(s8* arg0) {
    s32 i;
    s32 x1 = 0x1E;
    s32 x2 = 0x122;
    s32 y1 = 0x28;
    s32 y2 = 0x48;

    for (i = 1; i < 9; i++) {
        Controller_PollInputs();
        PikachuReward_RenderFrame(0);
        PikachuReward_DrawTextBoxPanel(0x1E, 0x20, 0x104, 0x30);

        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, x1, y1, x2, y2);

        Font_BeginTranslucentTextRendering();
        Font_SetActive(2, 0);
        Font_SetLineHeight(0x10);
        Font_Printf(0x2E, y1 - i * 4, D_81701B08);
        Font_Printf(0x2E, y2 - i * 4, arg0);
        Font_EndTexturedTextRendering();
        BgStage_AdvanceFrame();
    }

    D_81701B08 = arg0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_817008B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment010_17BE70/func_817008B4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81700A80; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment010_17BE70/func_81700A80.s")
#endif

M2C_UNK func_80005B98(M2C_UNK);                     /* extern */
M2C_UNK func_8000A7FC(M2C_UNK);                     /* extern */
M2C_UNK func_800199F8(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_80019A90(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_81700588(s32, M2C_UNK);                /* extern */
M2C_UNK func_8170070C(s32);                         /* extern */
extern s32 D_81701B00;
extern s32 D_81701B1C;
extern M2C_UNK D_FLT_81702020;

void func_81700D7C(void) {
    func_8170070C(D_81701B1C);
    M2C_FIELD(&D_FLT_81702020, s16 *, 0x20) = -0x800;
    func_800199F8(&D_FLT_81702020, 5);
    func_80019A90(&D_FLT_81702020, 0);
    D_81701B00 = 1;
    func_81700588(D_81701B1C, 0x46);
    func_80005B98(0x1E);
    func_8000A7FC(0x3C);
    func_81700588(D_81701B1C, 0x1E);
}

M2C_UNK func_80005B98(M2C_UNK);                     /* extern */
M2C_UNK func_8000A7B0(M2C_UNK);                     /* extern */
M2C_UNK func_800199F8(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_80019A90(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_800414B0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_81700588(s32, M2C_UNK);                /* extern */
M2C_UNK func_8170070C(s32);                         /* extern */
extern s32 D_81701B00;
extern s32 D_81701B48;
extern M2C_UNK D_FLT_81702020;

void func_81700E04(void) {
    func_800199F8(&D_FLT_81702020, 9);
    func_80019A90(&D_FLT_81702020, 6);
    func_800414B0(0, 0x39, 0x19, 0);
    D_81701B00 = 1;
    func_8000A7B0(0x13);
    func_8170070C(D_81701B48);
    func_81700588(D_81701B48, 0x98);
    func_80005B98(0x1E);
    func_81700588(D_81701B48, 0x1E);
}

void PikachuReward_PlayIntroCamera(void) {
    s32 i;
    CameraNode* temp_s1 = D_81702010->children;

    D_81702020->rotation.y = 0x1000;

    for (i = 0; i < 120; i++) {
        Controller_PollInputs();
        temp_s1->view.targetPosition.y = 0x320 - ((i * 0x1E0) / 120);
        temp_s1->view.eyePosition.y = 0x320 - ((i * 0x1E0) / 120);
        D_81702020->rotation.y += 0x200;
        PikachuReward_RenderFrame(0);
        BgStage_AdvanceFrame();
    }
}

M2C_UNK func_80006780();                            /* extern */
M2C_UNK func_800199F8(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_81700160();                            /* extern */
M2C_UNK func_81700370(M2C_UNK);                     /* extern */
M2C_UNK func_81700468(s16, s16, s16, s16);          /* extern */
M2C_UNK func_81700630(s32, M2C_UNK);                /* extern */
M2C_UNK func_8170070C(s32);                         /* extern */
s32 func_817008B4(s32);                             /* extern */
extern s32 D_81701B0C;
extern s32 D_81701B10;
extern s32 D_81701B14;
extern s32 D_81701B18;
extern M2C_UNK D_FLT_81702020;

s32 func_81700F78(void) {
    s16 var_s0;
    s16 var_s1;
    s32 var_s2;

    var_s0 = 0x14;
    var_s1 = 0x10;
    func_800199F8(&D_FLT_81702020, 8);
    var_s2 = 0;
    do {
        func_81700160();
        func_81700370(0);
        func_81700468((s16) (0xA0 - (var_s0 / 2)), (s16) (0x38 - (var_s1 / 2)), var_s0, var_s1);
        func_80006780();
        var_s2 += 1;
        var_s0 += 0x1E;
        var_s1 += 4;
    } while (var_s2 != 8);
    func_81700630(D_81701B0C, 1);
    func_8170070C(D_81701B10);
    func_81700630(D_81701B10, 1);
loop_3:
    func_8170070C(D_81701B14);
    if (func_817008B4(D_81701B14) != 0) {
        return 1;
    }
    func_8170070C(D_81701B18);
    if (func_817008B4(D_81701B18) != 0) {
        func_81700D7C();
        return 0;
    }
    goto loop_3;
}

#ifdef NON_MATCHING
/* TODO: decompile func_817010E8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment010_17BE70/func_817010E8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_817012C0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment010_17BE70/func_817012C0.s")
#endif

s32 func_80020AFC(M2C_UNK, s32, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK func_80020C60(s32);                         /* extern */
M2C_UNK func_80020DF0(M2C_UNK *, s32, s32);         /* extern */
s32 func_80021B30(s32);                             /* extern */
s32 func_80021FF4(s32);                             /* extern */
M2C_UNK func_80022118(s32);                         /* extern */
M2C_UNK func_80022188(s32);                         /* extern */
M2C_UNK func_817012C0(M2C_UNK);                     /* extern */
extern s32 D_817025C4;
extern M2C_UNK D_817025C8;

void func_817014A4(s32 arg0) {
    M2C_UNK var_s0;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_80020AFC(0x20, arg0, 0, 1);
    func_80020DF0(&D_817025C8, D_817025C4, temp_v0);
    func_80020C60(temp_v0);
    func_817012C0(0);
    func_817012C0(0);
    func_80022118(arg0);
    if (func_80021FF4(arg0) == 0) {
        do {
            var_s0 = 2;
loop_3:
            temp_v0_2 = func_80021B30(arg0);
            if (temp_v0_2 == 1) {
                var_s0 = 1;
            }
            if (temp_v0_2 == 3) {
                var_s0 = 3;
            }
            func_817012C0(var_s0);
            if (temp_v0_2 != 2) {
                goto loop_3;
            }
            func_817012C0(0);
            func_817012C0(0);
        } while (func_80021FF4(arg0) == 0);
    }
    func_80022188(arg0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_817015B0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment010_17BE70/func_817015B0.s")
#endif

M2C_UNK func_80005B98(M2C_UNK);                     /* extern */
M2C_UNK func_800067BC(M2C_UNK);                     /* extern */
M2C_UNK func_80006828(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_8000A7B0(M2C_UNK);                     /* extern */
M2C_UNK func_81700E98();                            /* extern */
s32 func_81700F78();                                /* extern */
s32 func_817010E8();                                /* extern */
M2C_UNK func_817015B0(s32);                         /* extern */

void func_81701710(void) {
    s32 temp_v0;

    func_8000A7B0(0x11);
    func_800067BC(2);
    func_80005B98(0x28);
    func_80006828(0xA, &func_81700370);
    func_81700E98();
    if (func_81700F78() != 0) {
        temp_v0 = func_817010E8();
        if (temp_v0 >= 0) {
            func_817015B0(temp_v0);
        }
    }
    func_800067BC(2);
}

void PikachuReward_SetupFollowerModel(DisplayObject* arg0, s16 arg1, s16 arg2, s16 arg3) {
    Model_InitDisplayObject(arg0, 0, 0, D_81702014);
    ModelAnim_BindTransformCurve(arg0, 0, D_8FC011C4, 0x10000);
    arg0->node.flags &= ~1;
    Vec3f_SetComponentsDuplicate(&arg0->scale, 1.5f, 1.5f, 1.5f);
    arg0->position.x = arg1;
    arg0->position.y = arg2;
    arg0->rotation.z = arg3;
}

void PikachuReward_SetupScene(void) {
    MemoryBlock* temp_v0;
    s32 i;

    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    D_81702010 = process_geo_layout(temp_v0, D_81701B4C);
    D_81702014 = process_geo_layout(temp_v0, D_8FC01070);

    MainPool_FinalizeAllocation(temp_v0);
    ModelRenderer_InitDisplayRoots();

    for (i = 0; i < 4; i++) {
        ModelRenderer_AttachDisplayObject(&D_81702020[i]);
    }

    Model_InitDisplayObject(&D_81702020[0], 0, 0, D_81702018->unk_08->unk_00[0]);
    Vec3f_SetComponentsDuplicate(&D_81702020[0].scale, 16.0f, 16.0f, 16.0f);
    ModelAnim_SetAnimation(&D_81702020[0], 0);
    D_81702020->node.renderFlags &= ~0x40;
    PikachuReward_SetupFollowerModel(&D_81702020[1], -0x50, 0x17C, 0x1800);
    PikachuReward_SetupFollowerModel(&D_81702020[2], 0, 0x17C, 0);
    PikachuReward_SetupFollowerModel(&D_81702020[3], 0x50, 0x17C, -0x1800);
}

#ifdef NON_MATCHING
/* TODO: decompile func_81701984; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment010_17BE70/func_81701984.s")
#endif
