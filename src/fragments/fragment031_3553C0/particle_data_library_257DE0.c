/* Stadium Zero fragment031_3553C0. */
/* C ported from the Stadium 1 decomp: src/fragments/particle_data_library/particle_data_library_257DE0.c. */

#include "fragments/particle_data_library/particle_data_library.h"
#include "gfx_buffer.h"
#include "geo_render.h"
#include "battle_hud.h"

#include "m2c_macros.h"

void DisplayList_InitRotationMatrixSegment(s32 arg0, DisplayListState* state);

void DisplayList_BuildRotationMatrixSegment(Gfx* gfx);

#ifdef NON_MATCHING
/* TODO: decompile func_8F200160; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment031_3553C0/func_8F200160.s")
#endif

s32 func_8000515C(M2C_UNK);                         /* extern */
M2C_UNK func_8F200160(s32, s32, s32, s8 *);       /* extern */
extern u16 D_80060484;

void func_8F200244(s32 arg0, s8 *arg1) {
    s32 temp_v0;

    if (arg0 == 2) {
        temp_v0 = func_8000515C(0x50);
        M2C_FIELD(arg1, s32 *, 0x18) = temp_v0;
        func_8F200160(temp_v0, D_80060484 & 7, M2C_FIELD(arg1, s32 *, 0x14), arg1);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8F200290; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment031_3553C0/func_8F200290.s")
#endif

s32 func_8000515C(M2C_UNK);                         /* extern */
M2C_UNK func_8F200290(s32, s32, s8 *);            /* extern */

void func_8F2003AC(s32 arg0, s8 *arg1) {
    s32 temp_v0;

    if (arg0 == 2) {
        temp_v0 = func_8000515C(0x58);
        M2C_FIELD(arg1, s32 *, 0x18) = temp_v0;
        func_8F200290(temp_v0, M2C_FIELD(arg1, s32 *, 0x14), arg1);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_8F2003EC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment031_3553C0/func_8F2003EC.s")
#endif

void DisplayList_InitRotationMatrixSegment(s32 arg0, DisplayListState* state) {
    Gfx* gfx;

    if (arg0 == 2) {
        gfx = (Gfx*)Gfx_AllocDisplayList(0x50);
        state->gfx = gfx;
        DisplayList_BuildRotationMatrixSegment(gfx);
    }
}
