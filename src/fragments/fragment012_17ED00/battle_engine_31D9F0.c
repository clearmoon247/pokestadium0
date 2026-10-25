/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_2FA4D0.c, src/fragments/battle_engine/battle_engine_31D9F0.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "model_renderer.h"

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

#include "m2c_macros.h"

void func_8001B884(s32, s32, s32, s32, u8*, s32, s32);

void func_82116D20(void);
void func_82116D28(void);
s32 BattleHud_DrawBorderTile(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4);
void ParticleEffect_InitNoop(void);
void BattleHud_DrawPlainText(s16 arg0, s16 arg1, char* arg2);
void BattleScene_DrawStripWipeIfActive(void);

void func_82116D20(void) {
}

void func_82116D28(void) {
}

#ifdef NON_MATCHING
/* TODO: decompile func_82116D30; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_82116D30.s")
#endif

void BattleHud_DrawHpFractionText(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    UNUSED s32 pad[2];
    s8 sp70[7];
    UNUSED s32 pad2;
    u8** temp_s2;
    u8* var_v0;
    s32 i;

    temp_s2 = Memmap_GetSegmentVaddr(D_300B870);
    sprintf(sp70, "%3d/%3d", arg2, arg3);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    for (i = 0; i < sizeof(sp70); i++) {
        switch (sp70[i]) {
            case ' ':
                var_v0 = NULL;
                break;

            case '/':
                var_v0 = temp_s2[10];
                break;

            default:
                var_v0 = temp_s2[sp70[i] - '0'];
                break;
        }

        if (var_v0 != NULL) {
            func_8001B884(arg0, arg1, 8, 6, var_v0, 8, 0);
        }

        arg0 += 8;
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

M2C_UNK func_8001A384(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8001A944(s32, s32, s32);               /* extern */
M2C_UNK func_8001AA9C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8001AB6C();                            /* extern */
M2C_UNK func_8001ABBC();                            /* extern */
u32 func_800566BC(s32);                             /* extern */
M2C_UNK func_82116CF4(s16, s16, M2C_UNK, M2C_UNK, s8 *, s8 *); /* extern */
extern s8 D_8218B008;
extern s8 D_8218B014;
void func_82116FF4(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u32 sp24;
    s32 temp_v0;

    temp_v0 = arg2 * 3;
    func_82116CF4(arg0, arg1, 0x46, 0x11, temp_v0 + &D_8218B008, temp_v0 + &D_8218B014);
    func_8001AB6C();
    if (arg4 != 0) {
        func_8001AA9C(0xFF, 0x64, 0xFF, 0xFF);
    }
    sp24 = func_800566BC(arg3) >> 1;
    func_8001A384(2, 0);
    func_8001A944((arg0 - (sp24 * 5)) + 0x1E, arg1 + 2, arg3);
    func_8001ABBC();
}

#ifdef NON_MATCHING
/* TODO: decompile func_821170D0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821170D0.s")
#endif

void BattleHud_DrawSpeciesNameLabelAuto(ActivePokemon* arg0, TeamRoster* arg1, s16 arg2, s16 arg3, s32 arg4, u16 arg5, s32 arg6) {
    ActivePokemonState* ptr = &arg0->state;
    s32 var_t0 = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (ptr->moveSlotIllegality[i] == 1) {
            var_t0 = 1;
        }
    }

    if (arg6 == 0) {
        BattleHud_DrawSpeciesNameLabel(arg2, arg3, arg4, &arg1->unk_008, var_t0);
    } else {
        BattleHud_DrawSpeciesNameLabelBlink(arg2, arg3, arg4, &arg1->unk_008, arg5, var_t0);
    }
}

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
// Matches the ROM, but uses rodata data that is not placed in this file yet.
s32 BattleHud_DrawMovePpTextLTR(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    UNUSED s32 pad[2];
    s8 sp70[7];
    s32 i;
    u8** temp_s2;
    u8* var_v1;

    temp_s2 = Memmap_GetSegmentVaddr(D_300B870);
    sprintf(sp70, "%3d/%3d", arg2 & 0x3F, arg3);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    for (i = 0; i < 7; i++) {
        s32 c = sp70[i];

        switch (c) {
            case ' ':
                var_v1 = NULL;
                break;

            case '/':
                var_v1 = temp_s2[10];
                break;

            default:
                if ((c >= 0x30) && (c < 0x3A)) {
                    var_v1 = temp_s2[c - '0'];
                } else {
                    var_v1 = NULL;
                }
                break;
        }

        if (var_v1 != NULL) {
            func_8001B884(arg0, arg1, 8, 6, var_v1, 8, 0);
            arg0 += 8;
        }
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_821199E4.s")
#endif

#ifdef NON_MATCHING
// Matches the ROM, but uses rodata data that is not placed in this file yet.
s32 BattleHud_DrawMovePpTextRTL(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    UNUSED s32 pad[2];
    s8 sp70[7];
    s32 i;
    u8** temp_s2;
    u8* var_v1;

    temp_s2 = Memmap_GetSegmentVaddr(D_300B870);
    sprintf(sp70, "%3d/%3d", arg2 & 0x3F, arg3);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    for (i = 7; i > 0; i--) {
        s32 c = sp70[i];

        switch (c) {
            case ' ':
                var_v1 = NULL;
                break;

            case '/':
                var_v1 = temp_s2[10];
                break;

            default:
                if ((c >= 0x30) && (c < 0x3A)) {
                    var_v1 = temp_s2[c - '0'];
                } else {
                    var_v1 = NULL;
                }
                break;
        }

        if (var_v1 != NULL) {
            func_8001B884(arg0, arg1, 8, 6, var_v1, 8, 0);
            arg0 -= 8;
        }
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    return arg0;
}
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
