/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/input.c. */

#include "global.h"
#include "input.h"
extern s32 pad_D_800AC880[0x2];
extern s32 D_800AB02C;
extern Controller* D_800AB030;

void Input_ResetRepeatState(void);

void Input_ResetRepeatState(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_8001B5F8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001B5F8.s")
#endif

void func_8001B5F8(s32, s32, s32, s32, s32);

void Gfx_DrawTextureRgba32(s32 x1, s32 y1, s32 draw_width, s32 height, u8* texture, s32 load_width, s32 texture_spread_x_mode) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_RGBA, G_IM_SIZ_32b, load_width, height, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    func_8001B5F8(x1, y1, draw_width, height, texture_spread_x_mode);
}

void Gfx_DrawTextureRgba16(s32 x1, s32 y1, s32 draw_width, s32 height, u8* texture, s32 load_width, s32 texture_spread_x_mode) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, load_width, height, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    func_8001B5F8(x1, y1, draw_width, height, texture_spread_x_mode);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8001BA54; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001BA54.s")
#endif

void Gfx_DrawTextureIa8(s32 x1, s32 y1, s32 draw_width, s32 height, u8* texture, s32 load_width, s32 texture_spread_x_mode) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_IA, G_IM_SIZ_8b, load_width, height, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    func_8001B5F8(x1, y1, draw_width, height, texture_spread_x_mode);
}

void Gfx_DrawTextureIa16(s32 x1, s32 y1, s32 draw_width, s32 height, u8* texture, s32 load_width, s32 texture_spread_x_mode) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_IA, G_IM_SIZ_16b, load_width, height, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    func_8001B5F8(x1, y1, draw_width, height, texture_spread_x_mode);
}

void Gfx_DrawTextureI4(s32 x1, s32 y1, s32 draw_width, s32 height, u8* texture, s32 load_width, s32 texture_spread_x_mode) {
    gDPLoadTextureBlock_4b(gDisplayListHead++, texture, G_IM_FMT_I, load_width, height, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_8001B5F8(x1, y1, draw_width, height, texture_spread_x_mode);
}

void Gfx_DrawTextureI8(s32 x1, s32 y1, s32 draw_width, s32 height, u8* texture, s32 load_width, s32 texture_spread_x_mode) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_I, G_IM_SIZ_8b, load_width, height, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_8001B5F8(x1, y1, draw_width, height, texture_spread_x_mode);
}

void Gfx_DrawTextureI16(s32 x1, s32 y1, s32 draw_width, s32 height, u8* texture, s32 load_width, s32 texture_spread_x_mode) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_I, G_IM_SIZ_16b, load_width, height, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_8001B5F8(x1, y1, draw_width, height, texture_spread_x_mode);
}


void Gfx_DrawTextureRgba16Ia8(s32 x1, s32 y1, s32 draw_width, s32 height, u8* texture, u8* texture_multi, s32 load_width, s32 texture_x_spread_mode) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, load_width, height, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gDPLoadMultiBlock(gDisplayListHead++, texture_multi, 0x0100, 1, G_IM_FMT_I, G_IM_SIZ_8b, load_width, height, 0,
                      G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                      G_TX_NOLOD);

    func_8001B5F8(x1, y1, draw_width, height, texture_x_spread_mode);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8001C97C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001C97C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8001CC90; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001CC90.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8001CE20; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001CE20.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8001D148; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8001D148.s")
#endif
