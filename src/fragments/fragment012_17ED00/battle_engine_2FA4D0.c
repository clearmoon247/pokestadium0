/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_2FA4D0.c, src/fragments/battle_engine/battle_engine_31D9F0.c, src/ui_graphics.c. */

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

#include "ui_graphics.h"
#include "graphics_textures.h"
#include "text_system.h"
#include "gfx_buffer.h"
#include "gfx_rect.h"
#include "hal_libc.h"
#include "stage_loader.h"
extern u8 D_10025D0[];
extern u8 D_1002650[];
extern u8 D_10026D0[];
extern u8 D_1002750[];
extern u8 D_10027D0[];
extern u8 D_1002850[];
extern u8 D_10028D0[];
extern u8 D_1002950[];
extern u8 D_10029D0[];
extern u8 D_1002A50[];
extern u8 D_1002AD0[];
extern u8 D_1002B50[];
extern u8 D_1002BD0[];
extern u8 D_1002C50[];
extern u8 D_1002CD0[];
extern u8 D_1002D50[];
extern u8 D_1002DD0[];
extern u8 D_1002E50[];
extern u8 D_1002ED0[];
extern u8 D_1002F50[];
extern u8 D_1002FD0[];
extern u8 D_1003050[];
extern u8 D_10030D0[];
extern u8 D_1003150[];
extern u8 D_10031D0[];
extern u8 D_1003750[];
extern u8 D_1003890[];
extern u8 D_1003930[];
extern u8 D_10039F0[];
extern u8 D_1003AB0[];
extern u8 D_1003B70[];
extern u8 D_1003C30[];
extern u8 D_1003CF0[];
extern u8 D_1003DB0[];
extern u8 D_1003E50[];
extern u8 D_1003EA0[];
extern u8 D_1003EC8[];
extern u8 D_1003EF0[];
extern u8 D_2004000[];
extern u8 D_2004320[];
extern Gfx gUiTranslucentFillDL[];
extern Gfx D_80060270[];
extern Gfx D_80060290[];
extern Gfx gUiEnvTintTextureDL[];
extern Gfx gUiRestoreTextureDL[];
extern Gfx D_80060990[];

#include "fragments/battle_engine/battle_engine.h"
#include "model_renderer.h"

#include "m2c_macros.h"

void BattleHud_DrawTranslucentShadowRect(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void Ui_DrawGradientRectangle(s32 x1, s32 y1, s32 width, s32 height, Color_RGB8* top_color,
                              Color_RGB8* bottom_color);
void func_82116D20(void);
void func_82116D28(void);
s32 BattleHud_DrawBorderTile(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4);
void ParticleEffect_InitNoop(void);
void BattleHud_DrawPlainText(s16 arg0, s16 arg1, char* arg2);
void BattleScene_DrawStripWipeIfActive(void);

#ifdef NON_MATCHING
/* TODO: decompile func_82116480; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82116480.s")
#endif

void BattleHud_DrawTranslucentShadowRect(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    DepthBuffer* temp_s1;
    Vtx* temp_s2;
    Mtx* sp84;
    Vp* sp80;

    temp_s1 = GfxImage_GetCurrent();
    temp_s2 = Gfx_AllocDisplayList(sizeof(Vtx) * 4);
    sp84 = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    sp80 = Gfx_AllocDisplayList(sizeof(Vp) * 1);
    Gfx_SetViewportDimensions(sp80, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)sp80 & 0x1FFFFFFF);

    guOrtho(sp84, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    Gfx_SetVertexAttributes(&temp_s2[0], arg0, arg1, -1, 0, 0, 0, 0, 0, arg4);
    Gfx_SetVertexAttributes(&temp_s2[1], arg0 + arg2, arg1, -1, 0, 0, 0, 0, 0, arg4);
    Gfx_SetVertexAttributes(&temp_s2[2], arg0, arg1 + arg3, -1, 0, 0, 0, 0, 0, arg4);
    Gfx_SetVertexAttributes(&temp_s2[3], arg0 + arg2, arg1 + arg3, -1, 0, 0, 0, 0, 0, arg4);

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)sp84 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&gIdentityMtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
}

void Ui_DrawGradientRectangle(s32 x1, s32 y1, s32 width, s32 height, Color_RGB8* top_color,
                              Color_RGB8* bottom_color) {
    Vtx* temp_s2;
    DepthBuffer* temp_s1;
    Mtx* sp7C;
    Vp* sp78;

    temp_s1 = GfxImage_GetCurrent();
    temp_s2 = Gfx_AllocDisplayList(sizeof(Vtx) * 4);
    sp7C = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    sp78 = Gfx_AllocDisplayList(sizeof(Vp) * 1);

    Gfx_SetViewportDimensions(sp78, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)sp78 & 0x1FFFFFFF);

    guOrtho(sp7C, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);
    Gfx_SetVertexAttributes(&temp_s2[0], x1, y1, -1, 0, 0, top_color->r, top_color->g, top_color->b, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[1], x1 + width, y1, -1, 0, 0, top_color->r, top_color->g, top_color->b, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[2], x1, y1 + height, -1, 0, 0, bottom_color->r, bottom_color->g,
                            bottom_color->b, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[3], x1 + width, y1 + height, -1, 0, 0, bottom_color->r, bottom_color->g,
                            bottom_color->b, 0xFF);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);

    gSPMatrix(gDisplayListHead++, (u32)sp7C & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&gIdentityMtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPVertex(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_82116CF4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82116CF4.s")
#endif

void func_82116D20(void) {
}

void func_82116D28(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_82116D30; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82116D30.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82116EB4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82116EB4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82116FF4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82116FF4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821170D0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821170D0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211724C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211724C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821172F0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821172F0.s")
#endif

s32 BattleHud_DrawBorderTile(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4) {
    UNUSED s32 pad[4];
    s32 sp2C;
    s32 sp28;

    if (arg2 < 9) {
        sp2C = 0x400;
    } else {
        sp2C = 0;
    }

    // clang-format off
    if (arg3 < 9) { sp28 = 0x400; } else { sp28 = 0; }
    // clang-format on

    gDPLoadTextureBlock(gDisplayListHead++, arg4, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRect(arg0, arg1, (arg0 + arg2) - 1, (arg1 + arg3) - 1, sp2C, sp28, 0);
}

void ParticleEffect_InitNoop(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_82117610; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82117610.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211778C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211778C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82117908; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82117908.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82117DD0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82117DD0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82118738; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82118738.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82118FD8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82118FD8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82119364; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82119364.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_821196A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821196A4.s")
#endif

M2C_UNK func_8001A944(s32, s32, s32);               /* extern */
u32 func_800566BC(s32);                             /* extern */

void func_82119994(s32 arg0, s32 arg1, s32 arg2) {
    func_8001A944(arg0 - ((func_800566BC(arg2) >> 1) * 0xA), arg1, arg2);
}

#ifdef NON_MATCHING
/* TODO: decompile func_821199E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821199E4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82119B48; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82119B48.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82119CAC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82119CAC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211AAC4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211AAC4.s")
#endif

void BattleHud_DrawPlainText(s16 arg0, s16 arg1, char* arg2) {
    Font_BeginTranslucentTextRendering();
    Font_SetActive(1, 0);
    Font_Printf(arg0, arg1, arg2);
    Font_EndTexturedTextRendering();
}

#ifdef NON_MATCHING
/* TODO: decompile func_8211AEA4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211AEA4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211B208; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211B208.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211B484; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211B484.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211B900; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211B900.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211BEA8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211BEA8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211C1B8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211C1B8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211C43C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211C43C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211C6C0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211C6C0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211C9FC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211C9FC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211CB0C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211CB0C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211CBCC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211CBCC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211CC8C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211CC8C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211D06C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211D06C.s")
#endif

void BattleScene_DrawStripWipeIfActive(void) {
    if (BattleScene_GetStripWipeState() != 0) {
        BattleScene_DrawStripWipe();
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8211D3D8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211D3D8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211D5F4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211D5F4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211D874; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211D874.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211D920; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211D920.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211DDC0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211DDC0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211E164; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211E164.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211E414; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211E414.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211E5F4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211E5F4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8211E794; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8211E794.s")
#endif
