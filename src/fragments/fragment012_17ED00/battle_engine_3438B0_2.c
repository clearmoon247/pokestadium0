/* Stadium Zero fragment012_17ED00. */
/* C ported from the Stadium 1 decomp: src/fragments/battle_engine/battle_engine_3438B0.c. */

#include "fragments/battle_engine/battle_engine.h"
#include "gfx_buffer.h"

#include "m2c_macros.h"

void BattleAnim_DrawFullScreenColorOverlay(u8 arg0, u8 arg1, u8 arg2, u8 arg3);

void BattleAnim_DrawFullScreenColorOverlay(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    gSPDisplayList(gDisplayListHead++, gDL_BeginColorFill);

    ParticleGfx_SetPrimColor(arg0, arg1, arg2, arg3);

    gSPTextureRectangle(gDisplayListHead++, 0, 0, 0x04FC, 0x03BC, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
    gSPDisplayList(gDisplayListHead++, gDL_EndColorFill);
}

#ifdef NON_MATCHING
/* TODO: decompile func_8216D720; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment012_17ED00/func_8216D720.s")
#endif

M2C_UNK func_8213A858(M2C_UNK);                     /* extern */

void func_8216D924(s32 arg0, M2C_UNK arg1) {
    func_8213A858(arg1);
}

M2C_UNK func_8213A784(M2C_UNK);                     /* extern */

void func_8216D948(s32 arg0, M2C_UNK arg1) {
    func_8213A784(arg1);
}
