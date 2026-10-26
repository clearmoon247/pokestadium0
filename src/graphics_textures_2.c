/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/graphics_textures.c. */

#include "global.h"
#include "graphics_textures.h"
#include "string.h"
#include "jpeg_stream.h"
#include "gfx_buffer.h"
#include "ui_graphics.h"
#include "gfx_rect.h"
#include "matrix.h"
#include "memory.h"
#include "stdarg.h"
#include "lib/ultralib/src/libc/xstdio.h"
extern FontContext* font_context;

#include "m2c_macros.h"
extern Gfx D_80060950[];
extern Gfx D_800609A8[];

void Font_ResetContext(UNUSED s32 arg0, UNUSED s32 arg1);
s32 Font_GetSetIndexFromMask(s32 mask);
void Font_Free(void);
char* String_CopyBytesAndAdvance(char* buffer, const char* data, u32 size);
void Gfx_SetEnvColor(s32 r, s32 g, s32 b, s32 a);
void Gfx_SetPrimColor(s32 r, s32 g, s32 b, s32 a);
void Font_EndTexturedTextRendering(void);

void Font_ResetContext(UNUSED s32 arg0, UNUSED s32 arg1) {
    font_context = NULL;
}

s32 Font_GetSetIndexFromMask(s32 mask) {
    s32 index = 0;

    if (mask != 0x1) {
        if (mask == 0x2) {
            index = 1;
        } else if (mask == 0x4) {
            index = 2;
        } else if (mask == 0x8) {
            index = 3;
        } else if (mask == 0x10) {
            index = 4;
        } else if (mask == 0x20) {
            index = 5;
        }
    }

    return index;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8001A118; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001A118.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8001A194; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001A194.s")
#endif

void Font_Free(void) {
    main_pool_try_free(font_context);
}

void Font_SetActive(s32 mask, s32 arg1) {
    if (font_context != NULL) {
        font_context->unk_50 = Font_GetSetIndexFromMask(mask);
        font_context->unk_51 = arg1;
        font_context->line_break_flag &= ~2;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8001A3E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001A3E4.s")
#endif

char* String_CopyBytesAndAdvance(char* buffer, const char* data, u32 size) {
    return (char*)memcpy(buffer, data, size) + size;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8001A944; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001A944.s")
#endif

M2C_UNK func_8001A3E4(s16, s16, s16);               /* extern */
void func_8001AA60(s32 arg0, s32 arg1, s32 arg2) {
    func_8001A3E4(arg0, arg1, (s16) (arg2 & 0x7F7F));
}

void Gfx_SetEnvColor(s32 r, s32 g, s32 b, s32 a) {
    gDPSetEnvColor(gDisplayListHead++, r, g, b, a);
}

void Gfx_SetPrimColor(s32 r, s32 g, s32 b, s32 a) {
    gDPSetPrimColor(gDisplayListHead++, 0, 0, r, g, b, a);
}

extern s8 *D_800AD200;
void func_8001AB2C(s32 arg0) {
    M2C_FIELD(D_800AD200, s8 *, 0x3A) = arg0;
}

extern s8 *D_800AD200;

void func_8001AB3C(void) {
    M2C_FIELD(D_800AD200, u8 *, 0x3B) = (u8) (M2C_FIELD(D_800AD200, u8 *, 0x3B) | 4);
}

extern s8 *D_800AD200;

void func_8001AB54(void) {
    M2C_FIELD(D_800AD200, u8 *, 0x3B) = (u8) (M2C_FIELD(D_800AD200, u8 *, 0x3B) & 0xFFFB);
}

void Font_BeginTranslucentTextRendering(void) {
    font_context->line_break_flag = 0;
    font_context->line_height = 0x28;
    font_context->unk_4C = 0;

    gSPDisplayList(gDisplayListHead++, D_80060950);
}

void Font_EndTexturedTextRendering(void) {
    gSPDisplayList(gDisplayListHead++, D_80060990);
}

void Font_EnableTwoCycleTexturing(void) {
    font_context->line_break_flag |= 1;
    font_context->line_break_flag &= ~2;

    gSPDisplayList(gDisplayListHead++, D_800609A8);
}

extern Gfx D_800609D8[];

void Font_DisableTwoCycleTexturing(void) {
    M2C_FIELD(font_context, u8*, 0x3B) &= ~3;
    gSPDisplayList(gDisplayListHead++, D_800609D8);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8001AC7C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001AC7C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8001ADA0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001ADA0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8001AFB0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001AFB0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8001B25C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001B25C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8001B32C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001B32C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8001B3AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001B3AC.s")
#endif
