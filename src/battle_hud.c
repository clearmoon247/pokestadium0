/* Stadium Zero resident code. */
/* C ported from the Stadium 1 decomp: src/battle_hud.c. */

#include "battle_hud.h"
#include "model_renderer_callbacks.h"
#include "geo_render.h"
#include "util.h"
#include "memmap.h"
#include "fragments/particle_data_library/particle_data_library.h"
extern s32 D_800AFB20;
extern s16 D_800AFB24;

void ModelAnim_UpdateFrameChangeState(void);
s32 ModelPhase_IsIdle(void);
u8 ModelRenderer_GetActiveMode(void);
void Gfx_SetCombineMode(Gfx* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12, s32 arg13, s32 arg14, s32 arg15, s32 arg16);

void ModelAnim_UpdateFrameChangeState(void) {
    D_800AFB24 = (D_800AFB20 == D_80060484) ? 1 : 0;
    D_800AFB20 = D_80060484;
}

s32 ModelPhase_IsIdle(void) {
    return 0;
}

u8 ModelRenderer_GetActiveMode(void) {
    u8 ret = *(u8*)Memmap_GetSegmentVaddr(&D_8006049C->effectSlot);
    return ret;
}

extern s16 D_800AF7AE;
extern s16 D_800AFB26;
extern s16 D_800AFB30[];
extern u8 D_8100060C[];

void func_800325B0(u32 arg0) {
    void (*func)(u32);

    D_800AFB26 = 0;
    D_800AFB30[arg0 & 1] = 0;
    if (arg0 < 2) {
        ModelRenderer_ClearSlotModels(arg0);
        func = Util_ConvertAddrToVirtAddr(D_8100060C);
        func(arg0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8003260C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_8003260C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_800326B4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/1060/func_800326B4.s")
#endif

void Gfx_SetCombineMode(Gfx* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12, s32 arg13, s32 arg14, s32 arg15, s32 arg16) {
    gDPSetCombine(arg0++, GCCc0w0(arg1, arg3, arg5, arg7) | GCCc1w0(arg9, arg11), GCCc0w1(arg2, arg4, arg6, arg8) | GCCc1w1(arg10, arg13, arg15, arg12, arg14, arg16));
}
