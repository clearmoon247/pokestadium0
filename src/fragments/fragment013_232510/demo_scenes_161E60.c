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

#ifdef NON_MATCHING
/* TODO: decompile func_82200020; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82200020.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_822000F0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_822000F0.s")
#endif

M2C_UNK func_8000B1FC();                            /* extern */
M2C_UNK func_8000B220();                            /* extern */
M2C_UNK func_8001B5F0();                            /* extern */

s32 func_82200108(void) {
    func_8000B1FC();
    func_8000B220();
    func_8001B5F0();
    return 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8220013C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_8220013C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82200278; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82200278.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82200510; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82200510.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_822005A8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_822005A8.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_82200858; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82200858.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8220091C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_8220091C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82200C04; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82200C04.s")
#endif

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

#ifdef NON_MATCHING
/* TODO: decompile func_82200E2C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82200E2C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82200F08; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82200F08.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82201084; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82201084.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82201348; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82201348.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82201444; signature not recovered. */
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
extern M2C_UNK D_82203268;
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

#ifdef NON_MATCHING
/* TODO: decompile func_82201DF8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82201DF8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82201F90; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82201F90.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_822020FC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_822020FC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82202228; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82202228.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_822023D4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_822023D4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82202494; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82202494.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82202728; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment013_232510/func_82202728.s")
#endif
