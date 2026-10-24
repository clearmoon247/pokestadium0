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

#ifdef NON_MATCHING
/* TODO: decompile func_81600020; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment025_2B16A0/func_81600020.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_816001A8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment025_2B16A0/func_816001A8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_816002AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment025_2B16A0/func_816002AC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81600334; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment025_2B16A0/func_81600334.s")
#endif

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
