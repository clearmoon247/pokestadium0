/* Stadium Zero fragment003_15F390. */
/* C ported from the Stadium 1 decomp: src/fragments/n64_logo/n64_logo.c. */

#include "fragments/n64_logo/n64_logo.h"
#include "save_data.h"
#include "gb_data.h"
#include "ui_graphics.h"
#include "text_system.h"
#include "3D140.h"
#include "jpeg_stream.h"
#include "audio_sfx.h"
#include "audio_channel.h"
#include "gfx_buffer.h"
#include "gfx_rect.h"
#include "memory.h"
#include "stage_loader.h"

void N64Logo_DrawLogoTexture(void);
s32 N64Logo_DrawFrame(UNUSED u8 arg0);
void N64Logo_WaitForElapsed(u64 arg0);
void N64Logo_ScanGbSavePorts(void);

void N64Logo_DrawLogoTexture(void) {
    s32 var_t4;
    u8* var_t5;
    u32 tmp = 0xF;

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
    gDPPipeSync(gDisplayListHead++);

    var_t5 = D_2000000;
    for (var_t4 = 0x40; var_t4 < 0xB0; var_t4 += 0x10, var_t5 += 0x1000) {
        gDPLoadTextureBlock(gDisplayListHead++, var_t5, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 7, 4, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, 0x0180, var_t4 << 2, 0x037C, (var_t4 + tmp) << 2, G_TX_RENDERTILE, 0, 0,
                            0x1000, 0x0400);
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureConvert(gDisplayListHead++, G_TC_FILT);
}

s32 N64Logo_DrawFrame(UNUSED u8 arg0) {
    BgStage_DrawFrame();
    GfxImage_FillCurrent(&gDisplayListHead, 1);
    N64Logo_DrawLogoTexture();

    return 0;
}

void N64Logo_WaitForElapsed(u64 arg0) {
    u32 temp_ret = 0xF;

    while (temp_ret < 0xF4240) {
        temp_ret = __ull_div(__ll_mul(osGetTime() - arg0, 0x40), 0xBB8);
    }
}

void N64Logo_ScanGbSavePorts(void) {
    main_pool_push_state('GPAK');

    GbSave_ScanAllPorts();

    main_pool_pop_state('GPAK');
}

#ifdef NON_MATCHING
/* TODO: decompile func_815003A4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment003_15F390/func_815003A4.s")
#endif
