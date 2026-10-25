/* Stadium Zero fragment025_2B16A0. */
/* C ported from the Stadium 1 decomp: src/fragments/fatal_error_screen/fatal_error_screen.c. */

#include "fragments/fatal_error_screen/fatal_error_screen.h"
#include "graphics_textures.h"
#include "ui_graphics.h"
#include "text_system.h"
#include "jpeg_stream.h"
#include "gfx_buffer.h"
#include "memory.h"
#include "stage_loader.h"
extern s32 D_81600A70;
extern s32 D_81600A74;

s32 FatalError_DrawFrame(u8 arg0);

void FatalError_DrawBackgroundPattern(s32 arg0, s32 arg1, s32 arg2);
void FatalError_DrawMessagePanel(s32 arg0);
void FatalError_DrawPortDiagram(s32 arg0);

void func_8001B884(s32, s32, s32, s32, u8*, s32, s32);
#ifdef NON_MATCHING
/* TODO: decompile func_81600020; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment025_2B16A0/func_81600020.s")
#endif

void FatalError_DrawIcon(s32 arg0, s32 arg1) {
    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    func_8001B884(arg0, arg1, 0x18, 0x18, D_2002000, 0x18, 0x200000);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

#ifdef NON_MATCHING
/* TODO: decompile func_816002AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment025_2B16A0/func_816002AC.s")
#endif

void FatalError_DrawPortDiagram(s32 arg0) {
    u16 sp80[] = {
        0x00BC,
        0x00C6,
        0x00DF,
        0x00E9,
    };

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    Gfx_DrawTextureRgba16(0x98, 0xA1, 8, 8, D_20069A0, 8, 0);

    gSPTextureRectangle(gDisplayListHead++, 0x01C8, 0x0284, 0x0260, 0x02A4, G_TX_RENDERTILE, 0, 0, 0, 0x0400);
    gSPDisplayList(gDisplayListHead++, D_80060290);

    Gfx_DrawTextureRgba16(0x4D, 0x94, 0x40, 0x20, D_2002900, 0x40, 0x200000);
    Gfx_DrawTextureRgba16(0x4D, 0xB4, 0x40, 0x20, D_2003900, 0x40, 0x200000);
    Gfx_DrawTextureRgba16(0x4D, 0xD4, 0x40, 6, D_2004900, 0x40, 0x200000);
    Gfx_DrawTextureRgba16(0x5D, 0x98, 0x18, 0x18, D_2002480, 0x18, 0x200000);
    Gfx_DrawTextureRgba16(0xAA, 0xAA, 0x64, 0x12, D_2004C00, 0x64, 0x200000);
    Gfx_DrawTextureRgba16(0xAA, 0xBC, 0x64, 0x12, D_2005A10, 0x64, 0x200000);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    Gfx_DrawTextureRgba16(0x9B, 0xD4, 8, 8, D_20068A0, 8, 0);

    gSPTextureRectangle(gDisplayListHead++, 0x026C, 0x02A4, 0x028C, 0x0350, G_TX_RENDERTILE, 0, 0, 0x0400, 0);

    func_8001B884(sp80[arg0], 0xD4, 8, 8, D_2006920, 8, 0);

    gSPTextureRectangle(gDisplayListHead++, 0x028C, 0x0350, sp80[arg0] << 2, 0x0370, G_TX_RENDERTILE, 0, 0, 0, 0x0400);

    func_8001B884(sp80[arg0], 0xC0, 8, 8, D_2006820, 8, 0);

    gSPTextureRectangle(gDisplayListHead++, sp80[arg0] << 2, 0x0320, (sp80[arg0] + 8) << 2, 0x0350, G_TX_RENDERTILE, 0,
                        0x00E0, 0x0400, 0);
    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

s32 FatalError_DrawFrame(u8 arg0) {
    BgStage_DrawFrame();
    FatalError_DrawBackgroundPattern(0x55, 0x70, 0x88);
    FatalError_DrawMessagePanel(D_81600A74);
    FatalError_DrawPortDiagram(D_81600A70);
    return 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_816007C4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment025_2B16A0/func_816007C4.s")
#endif
