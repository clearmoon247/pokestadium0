/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/poke_icon.c. */

#include "poke_icon.h"
#include "geo_node.h"
#include "geo_render.h"
#include "model_animation.h"
#include "display_object_textures.h"
#include "model_renderer.h"
#include "graphics_textures.h"
#include "jpeg_stream.h"
#include "gfx_rect.h"
#include "matrix.h"
#include "dp_intro.h"
#include "geo_layout.h"
#include "memory.h"
extern DisplayObject* D_800AD1C0;
s32 PokeIcon_CapturePreviewGeoNode(s32, GraphNode*);
s32 PokeIcon_CaptureGeoNode(s32, GraphNode*);

#include "m2c_macros.h"

s32 PokeIcon_CaptureGeoNode(s32 arg0, GraphNode* arg1);

s32 PokeIcon_CaptureGeoNode(s32 arg0, GraphNode* arg1) {
    if (arg0 == 0) {
        D_800AC7A0.unk_A04.unk_0C = arg1;
    }
    return 0;
}

s32 func_8000255C();                                /* extern */
s32 func_80002B10(s32, M2C_UNK);                    /* extern */
M2C_UNK func_80002B60(s32);                         /* extern */
M2C_UNK func_80010B3C(s32, M2C_UNK, M2C_UNK, s16, s32); /* extern */
s8 *func_80016C70(s32, M2C_UNK *);                /* extern */
extern M2C_UNK D_80060740;
extern s32 D_800AD1B0;

void func_80017F54(s8 *arg0, s16 arg1, s16 arg2) {
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_80002B10(func_8000255C(), 0);
    sp24 = temp_v0;
    M2C_FIELD(arg0, s8 **, 0xC) = func_80016C70(temp_v0, &D_80060740);
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) D_800AD1B0;
    func_80002B60(sp24);
    func_80010B3C(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xC), s32 *, 0xC), 0, 0, arg1, (s32) arg2);
}

#ifdef NON_MATCHING
/* TODO: decompile func_80017FDC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80017FDC.s")
#endif

M2C_UNK func_80017D00(s32);                         /* extern */
M2C_UNK func_800199E4(s32);                         /* extern */
M2C_UNK func_8004FD20(s32, s32, u16, u16);          /* extern */

void func_80018168(s8 *arg0) {
    s32 var_s0;
    s32 var_s2;
    u16 temp_a2;
    u16 temp_a3;
    s8 *temp_v0;
    s8 *temp_v1;

    if (M2C_FIELD(arg0, u8 *, 0) & 1) {
        func_80017D00(M2C_FIELD(arg0, s32 *, 4));
        func_800199E4(M2C_FIELD(arg0, s32 *, 0x10));
    }
    M2C_FIELD(arg0, u8 *, 0) = 0U;
    M2C_FIELD(arg0, s8 *, 2) = 0;
    M2C_FIELD(arg0, s8 *, 3) = -1;
    var_s2 = 0;
    if ((s32) M2C_FIELD(arg0, u8 *, 1) > 0) {
        var_s0 = 0;
        do {
            temp_v0 = M2C_FIELD(arg0, s32 *, 8) + var_s0;
            temp_v1 = M2C_FIELD(temp_v0, s8 **, 0xC);
            temp_a2 = M2C_FIELD(temp_v1, u16 *, 4);
            temp_a3 = M2C_FIELD(temp_v1, u16 *, 6);
            M2C_FIELD(temp_v0, s16 *, 0) = 0;
            M2C_FIELD((M2C_FIELD(arg0, s32 *, 8) + var_s0), s32 *, 4) = 0;
            func_8004FD20(M2C_FIELD(M2C_FIELD((M2C_FIELD(arg0, s32 *, 8) + var_s0), s8 **, 0xC), s32 *, 8), temp_a2 * temp_a3 * 2, temp_a2, temp_a3);
            var_s2 += 1;
            var_s0 += 0x14;
        } while (var_s2 < (s32) M2C_FIELD(arg0, u8 *, 1));
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_80018234; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80018234.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8001833C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001833C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800184C0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800184C0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80018550; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80018550.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8001882C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001882C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800189C0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800189C0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80018BA4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80018BA4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_80018D00; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80018D00.s")
#endif

s32 func_80018DEC(s8 *arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = 0;
    if (arg1 < (s32) M2C_FIELD(arg0, u8 *, 1)) {
        var_v1 = M2C_FIELD(M2C_FIELD((M2C_FIELD(arg0, s32 *, 8) + (arg1 * 0x14)), s8 **, 0xC), s32 *, 8);
    }
    return var_v1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_80018E24; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_80018E24.s")
#endif
