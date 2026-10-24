/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_2FA4D0.c, src/ui_graphics.c. */

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

void Ui_DrawBorderStyleA(s32 x1, s32 y1, s32 width, s32 height);
void Ui_DrawBorderStyleB(s32 x1, s32 y1, s32 width, s32 height);
void Ui_DrawBorderStyleC(s32 x1, s32 y1, s32 width, s32 height);
void Ui_FillInsetRectangleA(s32 x1, s32 y1, s32 width, s32 height, u16 color);
void Ui_FillInsetRectangleB(s32 x1, s32 y1, s32 width, s32 height, u16 color);
void BattleHud_DrawGradientRect(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Color_RGB8* arg4, Color_RGB8* arg5);
void Ui_DrawBorderedPanel(s32 x1, s32 y1, s32 width, s32 height, u16 color);
void Ui_DrawBorderedPanelStyleB(s32 x1, s32 y1, s32 width, s32 height, u16 color);
void Ui_DrawBorderedPanelNoFill(s32 x1, s32 y1, s32 width, s32 height);
void Ui_Draw20x20Icon(s32 arg0, s32 arg1, s32 arg2);

void Ui_DrawTexturedRect8x8(s32 x1, s32 y1, s32 width, s32 height, u8* texture);

s32 func_8001D370(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4) {
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

void Ui_DrawBorderStyleA(s32 x1, s32 y1, s32 width, s32 height) {
    Ui_DrawTexturedRect8x8(x1, y1, 8, 8, D_10027D0);
    Ui_DrawTexturedRect8x8(x1, (y1 + height) - 8, 8, 8, D_1002850);
    Ui_DrawTexturedRect8x8((x1 + width) - 8, (y1 + height) - 8, 8, 8, D_10028D0);
    Ui_DrawTexturedRect8x8((x1 + width) - 8, y1, 8, 8, D_1002950);

    if (width > 16) {
        Ui_DrawTexturedRect8x8(x1 + 8, y1, width - 0x10, 8, D_10025D0);
        Ui_DrawTexturedRect8x8(x1 + 8, (y1 + height) - 8, width - 0x10, 8, D_1002650);
    }

    if (height > 16) {
        Ui_DrawTexturedRect8x8(x1, y1 + 8, 8, height - 0x10, D_10026D0);
        Ui_DrawTexturedRect8x8((x1 + width) - 8, y1 + 8, 8, height - 0x10, D_1002750);
    }
}

void Ui_DrawBorderStyleB(s32 x1, s32 y1, s32 width, s32 height) {
    Ui_DrawTexturedRect8x8(x1, y1, 8, 8, D_1002BD0);
    Ui_DrawTexturedRect8x8(x1, (y1 + height) - 8, 8, 8, D_1002C50);
    Ui_DrawTexturedRect8x8((x1 + width) - 8, (y1 + height) - 8, 8, 8, D_1002CD0);
    Ui_DrawTexturedRect8x8((x1 + width) - 8, y1, 8, 8, D_1002D50);

    if (width > 16) {
        Ui_DrawTexturedRect8x8(x1 + 8, y1, width - 0x10, 8, D_10029D0);
        Ui_DrawTexturedRect8x8(x1 + 8, (y1 + height) - 8, width - 0x10, 8, D_1002A50);
    }

    if (height > 16) {
        Ui_DrawTexturedRect8x8(x1, y1 + 8, 8, height - 0x10, D_1002AD0);
        Ui_DrawTexturedRect8x8((x1 + width) - 8, y1 + 8, 8, height - 0x10, D_1002B50);
    }
}

void Ui_DrawBorderStyleC(s32 x1, s32 y1, s32 width, s32 height) {
    Ui_DrawTexturedRect8x8(x1, y1, 8, 8, D_1002FD0);
    Ui_DrawTexturedRect8x8(x1, (y1 + height) - 8, 8, 8, D_1003050);
    Ui_DrawTexturedRect8x8((x1 + width) - 8, (y1 + height) - 8, 8, 8, D_10030D0);
    Ui_DrawTexturedRect8x8((x1 + width) - 8, y1, 8, 8, D_1003150);

    if (width > 16) {
        Ui_DrawTexturedRect8x8(x1 + 8, y1, width - 0x10, 8, D_1002DD0);
        Ui_DrawTexturedRect8x8(x1 + 8, (y1 + height) - 8, width - 0x10, 8, D_1002E50);
    }

    if (height > 16) {
        Ui_DrawTexturedRect8x8(x1, y1 + 8, 8, height - 0x10, D_1002ED0);
        Ui_DrawTexturedRect8x8((x1 + width) - 8, y1 + 8, 8, height - 0x10, D_1002F50);
    }
}

void Ui_FillInsetRectangleA(s32 x1, s32 y1, s32 width, s32 height, u16 color) {
    gSPDisplayList(gDisplayListHead++, D_80060270);
    gDPSetFillColor(gDisplayListHead++, (color << 0x10) | color);

    if (StageContext_IsHighResolution() != 0) {
        gDPFillRectangle(gDisplayListHead++, x1 + 7, y1 + 7, (x1 + width) - 8, (y1 + height) - 8);
    } else {
        gDPFillRectangle(gDisplayListHead++, x1 + 3, y1 + 3, (x1 + width) - 4, (y1 + height) - 4);
    }
}

void Ui_FillInsetRectangleB(s32 x1, s32 y1, s32 width, s32 height, u16 color) {
    gSPDisplayList(gDisplayListHead++, D_80060270);
    gDPSetFillColor(gDisplayListHead++, (color << 0x10) | color);

    if (StageContext_IsHighResolution() != 0) {
        gDPFillRectangle(gDisplayListHead++, x1 + 5, y1 + 5, (x1 + width) - 6, (y1 + height) - 6);
    } else {
        gDPFillRectangle(gDisplayListHead++, x1 + 3, y1 + 3, (x1 + width) - 4, (y1 + height) - 4);
    }
}

void BattleHud_DrawGradientRect(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Color_RGB8* arg4, Color_RGB8* arg5) {
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
    Gfx_SetVertexAttributes(&temp_s2[0], arg0, arg1, -1, 0, 0, arg4->r, arg4->g, arg4->b, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[1], arg0 + arg2, arg1, -1, 0, 0, arg4->r, arg4->g, arg4->b, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[2], arg0, arg1 + arg3, -1, 0, 0, arg5->r, arg5->g, arg5->b, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[3], arg0 + arg2, arg1 + arg3, -1, 0, 0, arg5->r, arg5->g, arg5->b, 0xFF);

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

void Ui_DrawBorderedPanel(s32 x1, s32 y1, s32 width, s32 height, u16 color) {
    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    if (StageContext_IsHighResolution() != 0) {
        Ui_DrawBorderStyleA(x1, y1, width, height);
    } else {
        Ui_DrawBorderStyleC(x1, y1, width, height);
    }

    if ((width >= 0xF) && (height >= 0xF)) {
        Ui_FillInsetRectangleA(x1, y1, width, height, color);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void Ui_DrawGradientPanel(s32 x1, s32 y1, s32 width, s32 height, Color_RGB8* top_color, Color_RGB8* bottom_color) {
    if ((width >= 0xF) && (height >= 0xF)) {
        if (StageContext_IsHighResolution() != 0) {
            func_8001DBB0(x1 + 6, y1 + 6, width - 0xC, height - 0xC, top_color, bottom_color);
        } else {
            func_8001DBB0(x1 + 2, y1 + 2, width - 4, height - 4, top_color, bottom_color);
        }
    }

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    if (StageContext_IsHighResolution() != 0) {
        Ui_DrawBorderStyleA(x1, y1, width, height);
    } else {
        Ui_DrawBorderStyleC(x1, y1, width, height);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void Ui_DrawBorderedPanelStyleB(s32 x1, s32 y1, s32 width, s32 height, u16 color) {
    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    if (StageContext_IsHighResolution() != 0) {
        Ui_DrawBorderStyleB(x1, y1, width, height);
    } else {
        Ui_DrawBorderStyleC(x1, y1, width, height);
    }

    if ((width >= 0xF) && (height >= 0xF)) {
        Ui_FillInsetRectangleB(x1, y1, width, height, color);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8001E24C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001E24C.s")
#endif

void Ui_DrawBorderedPanelNoFill(s32 x1, s32 y1, s32 width, s32 height) {
    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    if (StageContext_IsHighResolution() != 0) {
        Ui_DrawBorderStyleA(x1, y1, width, height);
    } else {
        Ui_DrawBorderStyleC(x1, y1, width, height);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8001E6C0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001E6C0.s")
#endif

void Ui_Draw20x20Icon(s32 arg0, s32 arg1, s32 arg2) {
    u8* var_t4;

    if (arg2 != 0) {
        var_t4 = D_2004320;
    } else {
        var_t4 = D_2004000;
    }

    gSPDisplayList(gDisplayListHead++, D_80060290);
    gDPLoadTextureBlock(gDisplayListHead++, var_t4, G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, arg0 << 2, arg1 << 2, (arg0 + 0x13) << 2, (arg1 + 0x13) << 2,
                        G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8001E9A0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001E9A0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8001EBDC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001EBDC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8001F320; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001F320.s")
#endif
