/* Stadium Zero fragment013_232510. */
/* C ported from the Stadium 1 decomp: src/fragments/demo_scenes/demo_scenes_161E60.c, src/fragments/jigglypuff_doodle/jigglypuff_doodle.c. */

#include "fragments/demo_scenes/demo_scenes.h"
#include "geo_render.h"
#include "model_animation.h"
#include "model_animation_events.h"
#include "geo_layout.h"
#include "display_object_textures.h"
#include "model_renderer.h"
#include "graphics_textures.h"
#include "input.h"
#include "ui_graphics.h"
#include "save_data.h"
#include "text_system.h"
#include "jpeg_stream.h"
#include "audio_sfx.h"
#include "audio_loop_point.h"
#include "cry.h"
#include "gfx_buffer.h"
#include "gfx_rect.h"
#include "matrix.h"
#include "controller.h"
#include "math_util.h"
#include "memory.h"
#include "stage_loader.h"
#include "fragments/minigame_actor_framework/minigame_actor_framework.h"
#include "gb_save.h"
extern u8 D_30074E0[];
extern u8 D_30092E0[];
extern u8 D_300B6E0[];
extern u8 D_300B980[];
extern u8 D_300BAD0[];
extern u8 D_300BED0[];
extern u8 D_300C2D0[];
// Scene state passed in by the caller of this fragment; D_822036A4 points at it.
typedef struct DemoPlayer {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk01[0xC];
    /* 0x0D */ u8 unk_0D;
    /* 0x0E */ char unk0E[0x6];
    /* 0x14 */ TeamRoster* unk_14[2];
    /* 0x1C */ char unk1C[0xC];
} DemoPlayer; // size = 0x28

typedef struct DemoState {
    /* 0x0000 */ s8 unk_0000;
    /* 0x0001 */ s8 unk_0001;
    /* 0x0002 */ s8 unk_0002;
    /* 0x0003 */ s8 unk_0003;
    /* 0x0004 */ char unk0004[0x1024];
    /* 0x1028 */ DemoPlayer players[2];
    /* 0x1078 */ char unk1078[0x1C];
    /* 0x1094 */ u8 unk_1094;
    /* 0x1095 */ u8 unk_1095;
    /* 0x1096 */ u16 unk_1096;
} DemoState;

typedef struct unk_D_82203170 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk01[0x3];
    /* 0x04 */ void* unk_04;
    /* 0x08 */ u8* unk_08[6];
    /* 0x20 */ u8* unk_20[6];
    /* 0x38 */ TeamRoster* unk_38[2];
    /* 0x40 */ ExtendedRosterInfo* unk_40[2];
} unk_D_82203170; // size = 0x48
extern unk_D_82203170 D_82203170[2];
extern s8* D_822036A4;
extern s32 D_822036A8;
extern DepthBuffer* D_82203210[12];
s32 Completion_LightAngleCallbackA(s32, GraphNode*);
s32 Completion_LightAngleCallbackB(s32, GraphNode*);
typedef struct unk_D_86B0DBCC {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
} unk_D_86B0DBCC;
typedef struct unk_D_86B0DB98 {
    /* 0x00 */ u8* unk_00;
    /* 0x04 */ s16 unk_04;
} unk_D_86B0DB98;
typedef struct unk_D_86B0EBD8 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ char unk10[0x8];
    /* 0x18 */ s32 unk_18;
    /* 0x30 */ unk_D_86B0DAE0 unk_1C;
} unk_D_86B0EBD8;
typedef struct unk_D_86B0EBDC {
    /* 0x000 */ unk_D_86002F30* unk_000;
    /* 0x004 */ unk_D_86002F30* unk_004;
    /* 0x008 */ DisplayObject unk_008;
    /* 0x170 */ DisplayObject unk_170;
    /* 0x2D8 */ s32 unk_2D8;
    /* 0x2DC */ s32 unk_2DC;
    /* 0x2E0 */ char unk2E0[0x4];
    /* 0x2E4 */ s32 unk_2E4;
    /* 0x2E8 */ s32 unk_2E8;
    /* 0x2EC */ s32 unk_2EC;
    /* 0x2F0 */ s32 unk_2F0;
    /* 0x2F4 */ f32 unk_2F4;
    /* 0x2F8 */ char unk2F8[0x4];
    /* 0x2FC */ f32 unk_2FC;
    /* 0x300 */ f32 unk_300;
    /* 0x304 */ s32 unk_304;
    /* 0x308 */ s32 unk_308;
} unk_D_86B0EBDC;
typedef struct unk_D_86B0EBE0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
} unk_D_86B0EBE0;
extern s32 pad_D_86B0C4BC[3];

#include "fragments/jigglypuff_doodle/jigglypuff_doodle.h"
#include "math.h"
#include "geo_render.h"
#include "model_animation_events.h"
#include "geo_layout.h"
#include "display_object_textures.h"
#include "model_renderer.h"
#include "graphics_textures.h"
#include "input.h"
#include "ui_graphics.h"
#include "gallery.h"
#include "jpeg_stream.h"
#include "gfx_buffer.h"
#include "gfx_rect.h"
#include "matrix.h"
#include "controller.h"
#include "fragments/widget_toolkit/widget_toolkit.h"
#include "fragments/minigame_shared_graphics/minigame_shared_graphics.h"
#include "memory.h"
#include "stage_loader.h"
typedef struct unk_D_86301730 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ DisplayObject unk_004;
    /* 0x16C */ Vec3f unk_16C;
    /* 0x178 */ s8 unk_178;
    /* 0x179 */ s8 unk_179;
    /* 0x17A */ s8 unk_17A;
    /* 0x17B */ s8 unk_17B;
    /* 0x17C */ u16 unk_17C;
    /* 0x17E */ char pad17E[6];
} unk_D_86301730;

#include "m2c_macros.h"

s32 Completion_LightAngleCallbackA(s32 arg0, GraphNode* arg1);
void func_82200848(void);
void func_82200850(void);

void func_82200020(s32 arg0, CameraNode* arg1) {
    if (arg0 == 0) {
        GeoCamera_SetPerspective(arg1, 39.0f, 50.0f, 6400.0f);
        GeoCamera_SetEyeAtUp(arg1, 0.0f, 0.0f, 1507.0f, 0.0f, 0.0f, -165.0f, 0);
    }
}

s32 Completion_LightAngleCallbackA(s32 arg0, GraphNode* arg1) {
    unk_D_86002F34_alt18* ptr = (unk_D_86002F34_alt18*)arg1;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        Vec3f_CalculateDistanceAngles(&D_80060488->view.targetPosition, &D_80060488->view.eyePosition, &sp28, &sp26, &sp24);
        ptr->unk_1C = sp26 + 0x2000;
        ptr->unk_1E = sp24 - 0x2000;
    }
    return 0;
}

void func_822000F0(s32 arg0, s8 *arg1)
{
  s8 **new_var;
  if (arg0 == 0)
  {
    new_var = *((s8 ***) (((s8 *) arg1) + 0x14));
    *new_var = arg1;
  }
}

M2C_UNK func_8000B1FC();                            /* extern */
M2C_UNK func_8000B220();                            /* extern */
M2C_UNK func_8001B5F0();                            /* extern */

s32 func_82200108(void) {
    func_8000B1FC();
    func_8000B220();
    func_8001B5F0();
    return 0;
}

extern BinArchive* D_8220325C;

void func_8220013C(void) {
    unk_D_82203170* team;
    s32 i;

    main_pool_push_state('ICON');

    for (i = 0, team = D_82203170; i < 2; i++, team++) {
        if (((DemoState*)D_822036A4)->unk_0001 != 0) {
            team->unk_00 = 0;
        } else if (((DemoState*)D_822036A4)->players[i].unk_0D == 2) {
            team->unk_00 = 2;
        } else {
            team->unk_00 = 1;
        }

        team->unk_38[0] = ((DemoState*)D_822036A4)->players[i].unk_14[0];
        team->unk_40[0] = ((DemoState*)D_822036A4)->players[i].unk_14[0]->rosterInfo;
        team->unk_04 = BinArchive_GetFile(D_8220325C, team->unk_40[0]->unk_003);

        if (((DemoState*)D_822036A4)->players[i].unk_0D == 2) {
            team->unk_38[1] = ((DemoState*)D_822036A4)->players[i].unk_14[1];
            team->unk_40[1] = ((DemoState*)D_822036A4)->players[i].unk_14[1]->rosterInfo;
        } else {
            team->unk_38[1] = NULL;
            team->unk_40[1] = NULL;
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82200278; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82200278.s")
#endif

extern u8* D_86B10828;
extern GraphNode* D_86B106B4;
extern DepthBuffer* D_82203208;
extern GraphNode* D_82203240;
extern GraphNode* D_82203244;
extern s32 D_82203264;
void func_82200278(void);

s32 func_82200510(s32 arg0) {
    s32 sp24 = func_82200108();

    GeoRender_AdvanceFrameCounter();
    PokeIcon_ProcessNextSlot((unk_func_8001A024*)D_82203264, 0);
    GfxImage_SetRenderTarget(&gDisplayListHead, D_82203208);
    GfxImage_ClearDepthRectangle(&gDisplayListHead, 0, 0, 0x140, 0xF0);
    Geo_RenderRootNode(D_82203244);
    BgStage_DrawFrame();
    func_82200278();
    Geo_RenderRootNode(D_82203240);
    return sp24;
}

s32 func_822005A8(s32 arg0) {
    s32 sp24 = func_82200108();

    GeoRender_AdvanceFrameCounter();
    PokeIcon_ProcessNextSlot((unk_func_8001A024*)D_82203264, 0);
    BgStage_DrawFrame();
    GfxImage_ClearDepthRectangle(&gDisplayListHead, 0, 0, 0x140, 0xF0);
    Geo_RenderRootNode(D_82203244);
    return sp24;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82200618; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82200618.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82200714; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82200714.s")
#endif

void func_82200848(void) {
}

void func_82200850(void) {
}


void func_82200858(unk_D_82203170* arg0, s32 arg1) {
    s32 i;
    s32 slot = arg1 * 6;

    for (i = 0; i < 6; i++) {
        if (i < arg0->unk_40[0]->numberOfPokemonCanBePicked) {
            func_8001833C((unk_func_8001A024*)D_82203264, slot, &arg0->unk_40[0]->unk_028[i], 1);
        }
        arg0->unk_08[i] = PokeIcon_GetImage((unk_func_8001A024*)D_82203264, slot++);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8220091C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_8220091C.s")
#endif

extern u8 D_82202C60[];
extern u8 D_82202C7C[];
extern u8 D_82202CD0[];
extern u8 D_82202CEC[];
extern u8 D_82400000[];
extern u8 D_00175570[];
extern u8 D_0017BE70[];
extern DisplayObject D_82203268;
void func_82200618(void);
void func_8220091C(void);
void func_82200714(void);

void func_82200C04(void) {
    CameraNode* camera = D_82203240->children;

    Fragment_LoadAndCall((((u32)D_82400000 & 0x0FF00000) >> 0x14) - 0x10, D_00175570, D_0017BE70, 0,
                         (u32)D_822036A4);
    func_8220013C();
    func_82200858(&D_82203170[0], 0);
    func_82200858(&D_82203170[1], 1);
    if (((DemoState*)D_822036A4)->unk_0000 == 0) {
        Vec3f_FromVec3s(&camera->view.targetPosition, (Vec3s*)(D_82202CEC + 2));
        Vec3f_FromVec3s(&camera->view.eyePosition, (Vec3s*)(D_82202CD0 + 2));
    } else {
        Vec3f_FromVec3s(&camera->view.targetPosition, (Vec3s*)(D_82202C7C + 2));
        Vec3f_FromVec3s(&camera->view.eyePosition, (Vec3s*)(D_82202C60 + 2));
    }
    StageLoader_RunFrames(2);
    StageFade_Start(0x80);
    if (((DemoState*)D_822036A4)->unk_0000 == 0) {
        Audio_PlayMusicIfChanged(0x12);
    } else {
        Audio_PlayMusicIfChanged(6);
    }
    BgStage_RunUntilCondition(0x40, func_82200510);
    func_82200618();
    func_8220091C();
    func_82200714();
    ModelRenderer_ClearDisplayObject(&D_82203268);
    if (((DemoState*)D_822036A4)->unk_1095 & 2) {
        Save_ResetAndCommitTypedRecord(0x15, 0);
        ((DemoState*)D_822036A4)->unk_1095 &= ~3;
    }
}

M2C_UNK func_80025100(s8 *, M2C_UNK);               /* extern */
M2C_UNK func_80025168(s8);                          /* extern */
extern s8 *D_822036A4;

void func_82200DA4(void) {
    s8 sp1F;

    func_80025100(&sp1F, 0);
    switch (sp1F) {                                 /* irregular */
    case 0:
        func_80025168((s8) (sp1F + 1));
        M2C_FIELD(D_822036A4, u16 *, 0x1096) = (u16) (M2C_FIELD(D_822036A4, u16 *, 0x1096) | 8);
        return;
    case 1:
        func_80025168((s8) (sp1F + 1));
        M2C_FIELD(D_822036A4, u16 *, 0x1096) = (u16) (M2C_FIELD(D_822036A4, u16 *, 0x1096) | 0x10);
        return;
    }
}


void func_82200E2C(void) {
    DemoState* state = (DemoState*)D_822036A4;
    s32 player = state->unk_1094;
    TeamRoster* roster;
    ExtendedRosterInfo* info;
    BattleMon* mon;
    s32 i;
    s32 j;

    if ((player >= 0) && (player < 4)) {
        roster = state->players[0].unk_14[0];
        info = roster->rosterInfo;
        for (i = 0; i < info->numberOfPokemonCanBePicked; i++) {
            if (info->unk_028[i].unk_00.unk_01 != 0) {
                return;
            }
        }

        for (i = 0; i < roster->numberOfPokemonBrought; i++) {
            mon = &roster->pokemonPicked[i];
            if ((mon->unk_00.unk_00 == 0x19) && (mon->unk_00.unk_01 == 0)) {
                for (j = 0; j < 4; j++) {
                    if (mon->unk_09[j] == 0) {
                        break;
                    }
                    if (mon->unk_09[j] == 0x39) {
                        return;
                    }
                }
                state->unk_1096 |= 0x20;
                return;
            }
        }
    }
}

s32 func_800251A8(void);
void func_800251C8(u16 arg0);

void func_82200F08(void) {
    u16 lo = func_800251A8() & 0xFF;
    u16 hi = (func_800251A8() >> 8) & 0xFF;

    ((DemoState*)D_822036A4)->unk_1096 |= 2;

    if (((DemoState*)D_822036A4)->unk_0000 == 1) {
        ((DemoState*)D_822036A4)->unk_1096 |= 4;
        func_82200E2C();
        if (!(hi & 1)) {
            hi |= 1;
            func_800251C8((hi << 8) | lo);
            func_82200DA4();
            Save_CommitTypedRecord(0x14, 0);
        }
    } else if (((DemoState*)D_822036A4)->unk_0000 == 2) {
        if (((DemoState*)D_822036A4)->unk_0002 >= lo) {
            lo++;
            func_800251C8((hi << 8) | lo);
            Save_CommitTypedRecord(0x14, 0);
        }
        if (((DemoState*)D_822036A4)->unk_0002 == 3) {
            ((DemoState*)D_822036A4)->unk_1096 |= 4;
            func_82200E2C();
            if (!(hi & 2)) {
                hi |= 2;
                func_800251C8((hi << 8) | lo);
                func_82200DA4();
                Save_CommitTypedRecord(0x14, 0);
            }
        }
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_82201084; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82201084.s")
#endif

extern u8 D_8F625700[];
void func_8001C058(s32, s32, s32, s32, u8*, s32, s32);

void func_82201348(DepthBuffer* arg0) {
    u8* sp34 = (u8*)Util_ConvertAddrToVirtAddr((uintptr_t)D_8F625700);

    GfxImage_SetRenderTarget(&gDisplayListHead, arg0);
    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
    gDPSetEnvColor(gDisplayListHead++, 255, 50, 20, 255);
    func_8001C058(0, 0, 0x40, 0x20, sp34, 0x40, 0);
    func_8001C058(0, 0x20, 0x40, 0x20, sp34 + 0x400, 0x40, 0);
    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

#ifdef NON_MATCHING
void func_82201444(unk_D_82203170* arg0, s32 arg1) {
    s32 slot = arg1 * 6;
    s32 i;
    s32 j;

    if (arg0->unk_00 == 2) {
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 3; j++) {
                if (j < arg0->unk_38[i]->numberOfPokemonBrought) {
                    func_8001833C((unk_func_8001A024*)D_82203264, slot, &arg0->unk_38[i]->pokemonPicked[j], 1);
                }
                arg0->unk_08[i * 3 + j] = PokeIcon_GetImage((unk_func_8001A024*)D_82203264, slot);
                arg0->unk_20[i * 3 + j] = D_82203210[slot]->img_p;
                slot++;
            }
        }
    } else {
        for (j = 0; j < 6; j++) {
            if (j < arg0->unk_38[0]->numberOfPokemonBrought) {
                func_8001833C((unk_func_8001A024*)D_82203264, slot, &arg0->unk_38[0]->pokemonPicked[j], 1);
            }
            arg0->unk_08[j] = PokeIcon_GetImage((unk_func_8001A024*)D_82203264, slot);
            arg0->unk_20[j] = D_82203210[slot]->img_p;
            slot++;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82201444.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82201600; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82201600.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_822017F0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_822017F0.s")
#endif

M2C_UNK func_80006780();                            /* extern */
M2C_UNK func_80006828(M2C_UNK, M2C_UNK (*)(M2C_UNK)); /* extern */
s32 func_80018E24(s32);                             /* extern */
M2C_UNK func_800407B0(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_822005A8(M2C_UNK);                     /* extern */
M2C_UNK func_82201084(s32);                         /* extern */
M2C_UNK func_82201600(s32);                         /* extern */
s32 func_822017F0();                                /* extern */
extern s32 D_82203264;
extern s8 *D_822036A4;

void func_822018EC(void) {
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;

    func_800407B0(0x3D, 0, 0);
    func_80006828(5, func_822005A8);
    if (func_822017F0() != 0) {
        func_800407B0(0x3D, 1, 0);
    }
    var_s0 = 0x64;
    do {
        func_82201084(var_s0);
        func_822005A8(0);
        func_80006780();
        var_s0 -= 4;
    } while (var_s0 >= 0);
    if (func_80018E24(D_82203264) == 0) {
        do {
            func_822005A8(0);
            func_80006780();
        } while (func_80018E24(D_82203264) == 0);
    }
    var_s0_2 = 1;
    if ((M2C_FIELD(D_822036A4, s8 *, 0) == 0) && (M2C_FIELD(D_822036A4, s8 *, 1) == 0)) {
        var_s0_3 = 1;
        do {
            func_82201600(var_s0_3);
            func_80006828(6, func_822005A8);
            var_s0_3 += 1;
        } while (var_s0_3 != 0xD);
    } else {
        do {
            func_82201600(var_s0_2);
            func_80006828(8, func_822005A8);
            var_s0_2 += 1;
        } while (var_s0_2 != 7);
    }
    func_80006828(0x1E, func_822005A8);
}

M2C_UNK func_8001107C(M2C_UNK *, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK func_800407B0(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
extern DisplayObject D_82203268;
extern s8 *D_822036A4;
extern M2C_UNK D_8F6256E0;

void func_82201A3C(void) {
    if (M2C_FIELD(D_822036A4, u8 *, 0x1050) == 1) {
        func_800407B0(0x3D, 3, 0);
    } else {
        func_800407B0(0x3D, 4, 0);
    }
    M2C_FIELD(&D_82203268, u8 *, 2) = (u8) (M2C_FIELD(&D_82203268, u8 *, 2) | 0x20);
    func_8001107C(&D_82203268, 0, &D_8F6256E0);
    func_80006828(0x96, &func_822005A8);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82201AC4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82201AC4.s")
#endif

extern DisplayObject D_822033D0;
extern DisplayObject D_82203538;
extern ModelNodeView* D_82203254;
extern ModelNodeView* D_82203258;
extern u8* D_82202C1C[];
extern u8* D_82202C3C[];
extern s32 D_8220354C;
void func_82200F08(void);
s32 func_82201AC4(void);

s32 func_82201DF8(void) {
    s32 sp24 = 0;

    if (((DemoState*)D_822036A4)->players[1].unk_00 == 1) {
        Model_InitDisplayObject(&D_822033D0, 1, 0, D_82203254);
        Model_InitDisplayObject(&D_82203538, 1, 0, D_82203258);
        ModelAnim_BindTransformCurve(&D_822033D0, 1, D_82202C1C[((DemoState*)D_822036A4)->unk_0003], 0x10000);
        ModelAnim_BindTransformCurve(&D_82203538, 1, D_82202C3C[((DemoState*)D_822036A4)->unk_0003], 0x10000);
        func_800407B0(0x50, 0, 0);
        D_8220354C = ((DemoState*)D_822036A4)->unk_0003 - 1;
        if (((DemoState*)D_822036A4)->unk_0003 == 8) {
            BgStage_RunUntilCondition(0x5A, func_822005A8);
            func_800407B0(0x51, 0, 0);
            BgStage_RunUntilCondition(0x19, func_822005A8);
            func_800407B0(0x52, 0, 0);
            BgStage_RunUntilCondition(0x37, func_822005A8);
            func_82200F08();
        } else {
            BgStage_RunUntilCondition(0x55, func_822005A8);
            func_800407B0(0x51, 0, 0);
            BgStage_RunUntilCondition(0xF, func_822005A8);
            sp24 = func_82201AC4();
        }
    }
    return sp24;
}

extern DisplayObject D_82203268;
extern ModelNodeView* D_82203250;
extern u8 D_8F625614[];
extern u8 D_8F61F87C[];
void func_82201444(unk_D_82203170* arg0, s32 arg1);
M2C_UNK func_82201084(s32);
void func_82200714(void);
void func_80041374(s32 arg0, s32 arg1);

void func_82201F90(void) {
    CameraNode* camera = D_82203240->children;

    func_8220013C();
    func_82201444(&D_82203170[0], 0);
    func_82201444(&D_82203170[1], 1);
    Vec3f_SetComponentsDuplicate(&camera->view.targetPosition, -1200.0f, 300.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(&camera->view.eyePosition, 200.0f, 50.0f, 0.0f);
    StageLoader_RunFrames(2);
    Model_InitDisplayObject(&D_82203268, 1, 0, D_82203250);
    if (((DemoState*)D_822036A4)->players[1].unk_00 == 1) {
        ModelAnim_BindTransformCurve(&D_82203268, 1, D_8F625614, 0x10000);
    } else {
        ModelAnim_BindTransformCurve(&D_82203268, 1, D_8F61F87C, 0x10000);
    }
    D_82203268.node.renderFlags &= ~0x20;
    StageFade_Start(0x20);
    Audio_PlayMusicIfChanged(0xD);
    func_82201084(0x64);
    func_82200618();
    func_822018EC();
    func_82201A3C();
    func_80041374(0x3D, 0);
    func_82200714();
    ModelRenderer_ClearDisplayObject(&D_82203268);
    ((DemoState*)D_822036A4)->unk_1096 |= 1;
}

extern DisplayObject D_82203268;
extern u8 D_82400000[];
extern u8 D_00175570[];
extern u8 D_0017BE70[];
extern s16 D_822033E8;
extern s16 D_82203550;
void func_8220013C(void);
void func_8220091C(void);

void func_822020FC(void) {
    DemoState* state = (DemoState*)D_822036A4;

    if (state->players[1].unk_00 == 1) {
        if (state->unk_0003 < 8) {
            state->unk_0003++;
            ModelRenderer_ClearDisplayObject(&D_82203268);
            main_pool_pop_state('ICON');
            Fragment_LoadAndCall((((u32)D_82400000 & 0x0FF00000) >> 0x14) - 0x10, D_00175570, D_0017BE70, 0,
                                 (u32)D_822036A4);
            func_8220013C();
            func_82200858(&D_82203170[0], 0);
            func_82200858(&D_82203170[1], 1);
            D_822033E8 = ((DemoState*)D_822036A4)->unk_0003;
            D_82203550 = ((DemoState*)D_822036A4)->unk_0003;
            Audio_PlayMusicIfChanged(0xF);
            func_8220091C();
        } else {
            BgStage_RunUntilCondition(0x20, func_822005A8);
            ((DemoState*)D_822036A4)->unk_1096 |= 1;
        }
    } else {
        state->unk_1096 |= 1;
    }
}

void func_82202228(void) {
    CameraNode* camera = D_82203240->children;

    func_8220013C();
    func_82201444(&D_82203170[0], 0);
    func_82201444(&D_82203170[1], 1);
    Vec3f_SetComponentsDuplicate(&camera->view.targetPosition, -1200.0f, 300.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(&camera->view.eyePosition, 200.0f, 50.0f, 0.0f);
    StageLoader_RunFrames(2);
    Model_InitDisplayObject(&D_82203268, 1, 0, D_82203250);
    if (((DemoState*)D_822036A4)->players[1].unk_00 == 1) {
        ModelAnim_BindTransformCurve(&D_82203268, 1, D_8F625614, 0x10000);
    } else {
        ModelAnim_BindTransformCurve(&D_82203268, 1, D_8F61F87C, 0x10000);
    }
    D_82203268.node.renderFlags &= ~0x20;
    StageFade_Start(0x20);
    if (((DemoState*)D_822036A4)->unk_0003 < 8) {
        Audio_PlayMusicIfChanged(0xD);
    } else {
        Audio_PlayMusicIfChanged(0x10);
    }
    func_82201084(0x64);
    func_82200618();
    func_822018EC();
    func_82201A3C();
    if (func_82201DF8() != 0) {
        ((DemoState*)D_822036A4)->unk_1096 |= 0x41;
    } else {
        func_822020FC();
    }
    func_80041374(0x3D, 0);
    func_82200714();
    ModelRenderer_ClearDisplayObject(&D_82203268);
}


void func_822023D4(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 12; i++) {
        D_82203210[i] = GfxImage_Allocate(0, 2, 0x68, 0xC, 0);
        for (j = 0; j < 0x68 * 0xC; j++) {
            ((u16*)D_82203210[i]->img_p)[j] = 0xFFFE;
        }
    }
}

extern DisplayObject* D_82203200;
extern GraphNode* D_82203248;
extern GraphNode* D_8220324C;
extern ModelNodeView* D_82203250;
extern ModelNodeView* D_82203254;
extern ModelNodeView* D_82203258;
extern DisplayObject D_82203268;
extern DisplayObject D_822033D0;
extern DisplayObject D_82203538;
extern Color_RGBA8 D_822036A0;
extern u8 D_8220301C[];
extern u8 D_82202DDC[];
extern u8 D_82202E9C[];
extern u8 D_82202F5C[];
extern u8 D_82202D40[];
extern u8 D_8EC13F98[];
extern u8 D_8ED0E1A0[];
extern u8 D_8EE0F378[];
extern u8 D_8F504830[];
extern u8 D_8F619890[];
extern u8 D_8EB300B0[];
extern u8 D_8EB37440[];
extern u8 D_8F20A788[];
void func_800270B4(s32 arg0, s32 arg1, s32 arg2, u8* arg3, s32 arg4, s32 arg5);

void func_82202494(s32 arg0) {
    MemoryBlock* block = MainPool_AllocState(main_pool_get_available(), 0);

    switch (D_822036A8) {
        case 0:
            D_82203240 = process_geo_layout(block, D_8220301C);
            break;

        case 1:
            D_82203240 = process_geo_layout(block, D_82202DDC);
            break;

        case 2:
            D_82203240 = process_geo_layout(block, D_82202E9C);
            break;

        case 3:
            D_82203240 = process_geo_layout(block, D_82202F5C);
            break;
    }

    D_82203244 = process_geo_layout(block, D_82202D40);
    if ((arg0 > 0) && (arg0 < 7)) {
        D_82203248 = process_geo_layout(block, D_8EC13F98);
    } else if (arg0 == 7) {
        D_82203248 = process_geo_layout(block, D_8ED0E1A0);
    } else if (arg0 == 8) {
        D_82203248 = process_geo_layout(block, D_8EE0F378);
    }
    D_8220324C = process_geo_layout(block, D_8F504830);
    D_82203250 = (ModelNodeView*)process_geo_layout(block, D_8F619890);
    D_82203254 = (ModelNodeView*)process_geo_layout(block, D_8EB300B0);
    D_82203258 = (ModelNodeView*)process_geo_layout(block, D_8EB37440);
    MainPool_FinalizeAllocation(block);

    if (D_822036A8 == 0) {
        func_800270B4(0, 0xD89, -0x2C07, D_82203208->img_p, 0x16A8, 0x10FE);
    } else {
        func_800270B4(0, 0, 0, D_82203208->img_p, 0xC80, 0x960);
        ModelAnim_BindTransformCurve(D_82203200, 1, D_8F20A788, 0x10000);
    }
    func_822023D4();
    ModelRenderer_InitDisplayRoots();
    ModelRenderer_AttachDisplayObject(&D_82203268);
    ModelRenderer_AttachDisplayObject(&D_822033D0);
    ModelRenderer_AttachDisplayObject(&D_82203538);
    Color_SetRGB(&D_822036A0, 0xFF, 0xFF, 0xFF);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82202728; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82202728.s")
#endif
