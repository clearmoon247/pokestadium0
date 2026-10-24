/* Stadium Zero fragment000_80C00. */

#include "global.h"
#include "m2c_macros.h"

#ifdef NON_MATCHING
/* TODO: decompile func_81111C20; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81111C20.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81111DC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81111DC8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81111F0C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81111F0C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81111FE0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81111FE0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81112024; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81112024.s")
#endif

f32 func_81111F0C(s8 *, s8 *);                  /* extern */
f32 func_81112024(s8 *, s8 *);                  /* extern */

void func_8111220C(s8 *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x80) != 0) {
        M2C_FIELD(arg0, f32 *, 0x38) = func_81111F0C(arg0 + 0x80, arg0);
    }
    if ((M2C_FIELD(arg0, u8 *, 0xA4) != 0) && (M2C_FIELD(arg0, s32 *, 0x44) != -1)) {
        M2C_FIELD(arg0, f32 *, 0x3C) = func_81112024(arg0 + 0x90, arg0);
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_81112278; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81112278.s")
#endif

void func_8111235C(s8 *arg0, s32 arg1, M2C_UNK arg2) {
    M2C_FIELD(arg0, s8 *, 0) = 0;
    M2C_FIELD(arg0, s8 *, 1) = 0;
    M2C_FIELD(arg0, s16 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = arg1;
    M2C_FIELD(arg0, f32 *, 8) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x14) = 0.0f;
}

#ifdef NON_MATCHING
/* TODO: decompile func_81112380; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81112380.s")
#endif
