/* Stadium Zero fragment018_262620. */
/* C ported from the Stadium 1 decomp: src/fragments/pokedex/pokedex_214920.c. */

#include "fragments/pokedex/pokedex.h"
#include "geo_render.h"
#include "display_object_textures.h"
#include "poke_icon.h"
#include "model_renderer.h"
#include "graphics_textures.h"
#include "input.h"
#include "gb_data.h"
#include "game_state.h"
#include "table_view.h"
#include "text_system.h"
#include "gb_save.h"
#include "3D140.h"
#include "jpeg_stream.h"
#include "audio_sfx.h"
#include "gfx_rect.h"
#include "controller.h"
#include "memmap.h"
#include "memory.h"
#include "stage_loader.h"
#include "pokemon_stats.h"
s32 Pokedex_DrawListScrollArrows(unk_func_888044BC_050*, s32, s32);
s32 Pokedex_HandleSpeciesListInput(unk_func_888044BC_038*, Controller*);
void Pokedex_DrawTrainerInfoCard(unk_func_888044BC_03C_02C*, s32, s32);
s32 Pokedex_DrawSortOrderLabel(unk_func_888044BC_040_030*, s32, s32);
s32 Pokedex_HandleEntryMenuInput(unk_func_888044BC_040*, Controller*);
s32 Pokedex_DrawDataPanel(unk_func_888044BC_044_02C*, s32, s32);
s32 Pokedex_DrawPreview(unk_func_888044BC_04C_02C*, s32, s32);
extern StageContext* D_8A12FF9C;
extern StageContext* D_8A12FFA0;
extern ModelLoadContext* D_8A12FFA4;
extern s32 D_8A12FFA8;
extern s32 D_8A12FFAC;
extern s32 D_8A12FFB0;
extern u8 pad_D_88826948[0x58];
extern u32 pad_D_888269A4;
extern u8 gPokedexAlphabeticalOrder[];

#include "m2c_macros.h"

void Pokedex_LoadIcon(u8* arg0, s32 arg1);
void Pokedex_ExitAreaMapScreen(void);
void Pokedex_RunEntryFlow(void);
s32 Pokedex_GetHighestSeenSpeciesIndex(void);
void Pokedex_InitFramebuffers(void);

s32 func_8A10122C(void);
s32 Pokedex_ShowEntryMenu(void);
s32 Pokedex_ShowEntry(void);
s32 Pokedex_PlayCry(void);
s32 Pokedex_RedrawAreaMapTransition(u8 arg0);
s32 Pokedex_ShowAreaMapScreen(void);

#ifdef NON_MATCHING
/* TODO: decompile func_8A100020; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A100020.s")
#endif

s32 func_800209A4(s32, s8 *);                     /* extern */

s32 func_8A1000C0(s8 *arg0) {
    s32 var_v1;

    if (M2C_FIELD(arg0, s32 *, 0x1B0) != 0) {
        var_v1 = func_800209A4(M2C_FIELD(arg0, s32 *, 0x34) + 1, arg0) - 1;
    } else {
        var_v1 = M2C_FIELD(arg0, s32 *, 0x34);
    }
    return var_v1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8A100104; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A100104.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A100318; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A100318.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A1003D0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A1003D0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A100588; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A100588.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A100620; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A100620.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A10068C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A10068C.s")
#endif

extern Color_RGBA8 D_8A1057D4;
void func_8002A0AC(s32, s32, s32, s32, Color_RGBA8);
void func_80027F20(s32);

void func_8A100808(s32 arg0, s32 arg1, char* arg2, s32 arg3, s32 arg4) {
    if (arg4 & 0x10) {
        func_8002A0AC(arg0 + 3, arg1 + 3, 0xA2, 0x1E, D_8A1057D4);
    }
    Font_BeginTranslucentTextRendering();
    func_80027F20(arg4);
    Font_SetActive(0x10, 0);
    Font_Printf(arg0 + 0xC, arg1 + 6, arg2);
    Font_EndTexturedTextRendering();
}

#ifdef NON_MATCHING
/* TODO: decompile func_8A1008A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A1008A4.s")
#endif

s32 func_8002AE6C();                                /* extern */
M2C_UNK func_8002D9B8(s8 *, s32, s32, s32, s32);  /* extern */

void func_8A100954(s8 *arg0, s32 arg1) {
    if (func_8002AE6C() == 0) {
        func_8002D9B8(arg0 + 0x2C, M2C_FIELD(arg0, s32 *, 0) + 6, M2C_FIELD(arg0, s32 *, 4) + 0xC, arg1 | 0xFFED, 0);
    }
}

s32 func_8002BC14(s32);                             /* extern */
s32 func_8002DC04(s32);                             /* extern */
extern s32 D_800603C0;

s32 func_8A1009A4(s32 arg0) {
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_8002DC04(arg0 + 0x2C);
    var_v1 = temp_v0;
    if (temp_v0 == 0) {
        var_v1 = func_8002BC14(D_800603C0);
    }
    return var_v1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8A1009E0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A1009E0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A100A24; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A100A24.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A100BEC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A100BEC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A100C50; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A100C50.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A100F20; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A100F20.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A101020; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A101020.s")
#endif

M2C_UNK func_8002C064(M2C_UNK, M2C_UNK, u8, u8, s32); /* extern */
extern M2C_UNK D_8A1057D0;

void func_8A101118(void) {
    func_8002C064(0x38, 0x1E0, M2C_FIELD(&D_8A1057D0, u8 *, 0), M2C_FIELD(&D_8A1057D0, u8 *, 1), (s32) M2C_FIELD(&D_8A1057D0, u8 *, 2));
}

#ifdef NON_MATCHING
/* TODO: decompile func_8A101154; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A101154.s")
#endif

M2C_UNK func_800069CC();                            /* extern */
M2C_UNK func_80028060(M2C_UNK, M2C_UNK *, M2C_UNK *, s32); /* extern */
M2C_UNK func_8A1003D0(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_8A10068C(M2C_UNK *);                   /* extern */
extern M2C_UNK D_8A12FD2C;
extern M2C_UNK D_8A12FFC0;
extern M2C_UNK D_8A130174;
extern M2C_UNK D_8A1301A0;
extern s32 D_8A130230;
extern M2C_UNK D_8A130238;

s32 func_8A1011A4(s32 arg0) {
    M2C_UNK *var_a1;

    func_800069CC();
    func_8A101118();
    if (D_8A130230 == -1) {
        var_a1 = NULL;
    } else {
        var_a1 = &D_8A130238;
    }
    func_80028060(0, var_a1, &D_8A12FD2C, D_8A130230);
    func_8A1003D0(&D_8A12FFC0, 0x10);
    func_8A10068C(&D_8A130174);
    func_8A100954(&D_8A1301A0, 2);
    return 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8A10122C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A10122C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A1013C0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A1013C0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8A1014EC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A1014EC.s")
#endif

extern s32 D_8A12FF98;
extern u8 D_8A130204[];
s32 func_800196F8(s32);
s32 func_8002AAC4(void*);
void func_8A101020(void*, s32, s32);

s32 func_8A10164C(s32 arg0, s32 arg1) {
    UNUSED s32 pad[4];
    s32 sp1C;

    GeoRender_AdvanceFrameCounter();
    sp1C = func_800196F8(D_8A12FF98);
    BgStage_DrawFrame();
    if (func_8002AAC4(D_8A130204) != 0) {
        func_8A101118();
    }
    func_8A101020(D_8A130204, sp1C, arg1);
    return 0;
}

void Pokedex_LoadIcon(u8* arg0, s32 arg1) {
    unk_func_8001A024* sp1C;
    void* sp18;

    main_pool_push_state('ICON');
    sp1C = PokeIcon_CreateRenderList(D_8A12FFA4, 1, 0x50, 0x50);
    sp18 = PokeIcon_GetImage(sp1C, 0);
    func_80018234(sp1C, 0, arg1, 0x9530);
    PokeIcon_ProcessAllSlots(sp1C, 0);
    StageLoader_RunFrames(2);
    osInvalDCache(sp18, 0x3200);
    _bcopy(sp18, arg0, 0x3200);
    main_pool_pop_state('ICON');
}

#ifdef NON_MATCHING
/* TODO: decompile func_8A101760; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A101760.s")
#endif

M2C_UNK func_80002620(M2C_UNK);                     /* extern */
M2C_UNK func_800199E4(M2C_UNK *);                   /* extern */
extern M2C_UNK D_8A12FE30;

void func_8A1017DC(void) {
    func_800199E4(&D_8A12FE30);
    func_80002620(0x50494354);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8A10180C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A10180C.s")
#endif

M2C_UNK func_80006780();                            /* extern */
M2C_UNK func_800069CC();                            /* extern */
M2C_UNK func_8003BD3C(s32);                         /* extern */
s32 func_8003BECC();                                /* extern */
extern s32 D_8A12FFB8;
extern M2C_UNK D_8A1301A0;

s32 func_8A10193C(void) {
    func_8003BD3C(D_8A12FFB8 + 1);
    if (func_8003BECC() != 0) {
        do {
            func_800069CC();
            func_8A100954(&D_8A1301A0, 0x10);
            func_80006780();
        } while (func_8003BECC() != 0);
    }
    return 2;
}

M2C_UNK func_80005B98(M2C_UNK);                     /* extern */
M2C_UNK func_8000661C(s32);                         /* extern */
M2C_UNK func_800067BC(M2C_UNK);                     /* extern */
M2C_UNK func_80006828(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_8A1053E8(s32, s32, M2C_UNK, s32, s32); /* extern */
extern s32 D_8A12FFA8;
extern s32 D_8A12FFAC;
extern s32 D_8A12FFB8;
extern M2C_UNK func_8A104B00;

void func_8A1019AC(void) {
    func_80005B98(8);
    func_80006828(8, &func_8A1011A4);
    func_800067BC(2);
    func_8000661C(D_8A12FFA0);
    func_800067BC(2);
    func_8A1053E8(D_8A12FFB8 + 1, D_8A12FFA8, 0x70800, D_8A12FFAC, 0x4B000);
    func_80005B98(8);
    func_80006828(0xA, &func_8A104B00);
}

void Pokedex_ExitAreaMapScreen(void) {
    StageFade_Start(8);
    BgStage_RunUntilCondition(8, Pokedex_DrawAreaMapFrame);
    StageLoader_RunFrames(2);
    StageContext_SaveAndSwitch(D_8A12FF9C);
    Pokedex_ExitAreaMapPool();
    StageFade_Start(8);
    BgStage_RunUntilCondition(0xA, Pokedex_RedrawAreaMapTransition);
}

s32 Pokedex_ShowAreaMapScreen(void) {
    s32 var_s0 = 3;

    Pokedex_EnterAreaMapScreen();

    while (var_s0 == 3) {
        Cont_StartReadInputs();
        Cont_ReadInputs();
        Input_ResetRepeatState();
        Pokedex_DrawAreaMapFrame(0);
        if (Pokedex_CheckAreaMapExit() != 0) {
            var_s0 = 1;
        }
        BgStage_AdvanceFrame();
    }

    Audio_PlaySoundEffectById(SFX_MENU_BACK);
    Pokedex_ExitAreaMapScreen();
    return var_s0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8A101B30; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A101B30.s")
#endif

void Pokedex_RunEntryFlow(void) {
    s32 var_v0 = 1;

    while (var_v0 != 0) {
        switch (var_v0) {
            case 1:
                var_v0 = func_8A10122C();
                break;

            case 2:
                var_v0 = Pokedex_ShowEntryMenu();
                break;

            case 3:
                var_v0 = Pokedex_ShowEntry();
                break;

            case 4:
                var_v0 = Pokedex_PlayCry();
                break;

            case 5:
                var_v0 = Pokedex_ShowAreaMapScreen();
                break;
        }
    }
}

s32 Pokedex_GetHighestSeenSpeciesIndex(void) {
    s32 i;

    for (i = 151; i > 0; i--) {
        if (GbSave_GetSpeciesProgressLevel(D_8A12FFB0, i) != 0) {
            break;
        }
    }

    return i;
}

void Pokedex_InitFramebuffers(void) {
    u32 sp34;
    u32 sp30;
    u32 sp2C;
    DepthBuffer* sp28;

    sp28 = main_pool_alloc(sizeof(DepthBuffer), 0);

    sp34 = D_8A12FF9C->renderTargets[0]->img_p;
    D_8A12FFA8 = D_8A12FF9C->renderTargets[0]->img_p + 0x25800;
    sp30 = D_8A12FF9C->renderTargets[1]->img_p;
    D_8A12FFAC = D_8A12FF9C->renderTargets[1]->img_p + 0x25800;
    sp2C = D_8A12FF9C->renderTargets[1]->img_p + 0x70800;

    D_8A12FFA0->renderTargets[0] = main_pool_alloc(sizeof(DepthBuffer), 0);
    D_8A12FFA0->renderTargets[1] = main_pool_alloc(sizeof(DepthBuffer), 0);

    GfxImage_Initialize(D_8A12FFA0->renderTargets[0], 0, 2, 0x140, 0xF0, sp34);
    GfxImage_Initialize(D_8A12FFA0->renderTargets[1], 0, 2, 0x140, 0xF0, sp30);
    GfxImage_Initialize(sp28, 0, 2, 0x140, 0xF0, sp2C);
    GfxImage_AttachDepthBuffer(D_8A12FFA0->renderTargets[0], sp28);
    GfxImage_AttachDepthBuffer(D_8A12FFA0->renderTargets[1], sp28);
}

void func_80027FF8(void*, s32);
void func_8A101154(void*);

void func_8A101E84(void) {
    D_8A130230 = func_80025BD8();
    if (D_8A130230 != -1) {
        func_80027FF8(&D_8A130238, D_8A130230);
    }
    func_8A101154(&D_8A12FFC0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8A101ED4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment018_262620/func_8A101ED4.s")
#endif
