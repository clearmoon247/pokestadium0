/* Stadium Zero fragment000_80C00. */

#include "global.h"
#include "m2c_macros.h"

#ifdef NON_MATCHING
/* TODO: decompile func_81110210; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81110210.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_811105DC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_811105DC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81110694; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81110694.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8111073C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_8111073C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81110798; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81110798.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81110C6C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81110C6C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81110CA8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81110CA8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81110D6C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81110D6C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81110E3C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81110E3C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81111090; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81111090.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_811110B0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_811110B0.s")
#endif

void func_811110D0(s8 *arg0) {
    M2C_FIELD(arg0, s8 **, 0) = arg0;
    M2C_FIELD(arg0, s8 **, 4) = arg0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_811110E0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_811110E0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81111130; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81111130.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_811111E0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_811111E0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81111340; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81111340.s")
#endif

void func_8111147C(M2C_UNK *arg0, M2C_UNK *arg1) {
    if (M2C_FIELD(arg1, M2C_UNK **, 0) == NULL) {
        M2C_FIELD(arg1, M2C_UNK **, 0) = arg0;
        M2C_FIELD(arg1, M2C_UNK **, 4) = (M2C_UNK *) M2C_FIELD(arg0, M2C_UNK **, 4);
        *M2C_FIELD(arg0, M2C_UNK **, 4) = arg1;
        M2C_FIELD(arg0, M2C_UNK **, 4) = arg1;
        M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 1);
        M2C_FIELD(arg1, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
    }
}

void func_811114BC(s8 *arg0) {
    s8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, s8 **, 0);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s8 ***, 4) = (s8 **) M2C_FIELD(arg0, s8 ***, 4);
        *M2C_FIELD(arg0, s8 ***, 4) = M2C_FIELD(arg0, s8 **, 0);
        M2C_FIELD(arg0, s8 **, 0) = NULL;
    }
}

s8 *func_811114E8(s8 *arg0, s32 arg1) {
    s8 *temp_a0;
    s8 *var_v0;
    s8 *var_v1;

    var_v0 = M2C_FIELD(arg0, s8 **, 4);
    if (var_v0 == arg0) {
        return NULL;
    }
    var_v1 = var_v0;
    if (var_v0 != arg0) {
        do {
            if ((s32) M2C_FIELD(M2C_FIELD(var_v1, s8 **, 8), u8 *, 0x30) >= (s32) M2C_FIELD(M2C_FIELD(var_v0, s8 **, 8), u8 *, 0x30)) {
                var_v1 = var_v0;
            }
            var_v0 = M2C_FIELD(var_v0, s8 **, 4);
        } while (var_v0 != arg0);
    }
    if (var_v1 == NULL) {
        return NULL;
    }
    temp_a0 = M2C_FIELD(var_v1, s8 **, 8);
    if ((s32) M2C_FIELD(temp_a0, u8 *, 0x30) >= arg1) {
        return NULL;
    }
    return temp_a0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_81111568; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81111568.s")
#endif

M2C_UNK func_811110B0(s32);                         /* extern */

void func_81111688(s8 *arg0, s32 arg1) {
    func_811110B0(M2C_FIELD(arg0, s32 *, 0x44));
    M2C_FIELD(arg0, s32 *, 0x48) = arg1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_811116BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_811116BC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_811116E8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_811116E8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81111734; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81111734.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81111784; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81111784.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8111187C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_8111187C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_81111AF4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment000_80C00/func_81111AF4.s")
#endif
