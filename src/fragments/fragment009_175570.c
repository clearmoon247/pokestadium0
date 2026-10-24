/* Stadium Zero fragment009_175570. */

#include "global.h"
#include "m2c_macros.h"

#ifdef NON_MATCHING
/* TODO: decompile func_82400020; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment009_175570/func_82400020.s")
#endif

void func_824000F0(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0) = 0;
    M2C_FIELD(arg0, s8 *, 1) = 1;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 8) = arg1;
    M2C_FIELD(arg0, s8 *, 0x1D) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_82400118; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment009_175570/func_82400118.s")
#endif

void func_824001B4(s8 *arg0) {
    M2C_FIELD(arg0, s8 *, 2) = 0;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x103C), s8 **, 0x1FC), s8 *, 3) = (s8) (M2C_FIELD(arg0, s8 *, 3) + 0x16);
    M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x1064), s8 **, 0x1FC), s8 *, 3) = (s8) (M2C_FIELD(arg0, s8 *, 3) + 0x16);
}

#ifdef NON_MATCHING
/* TODO: decompile func_824001E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment009_175570/func_824001E4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82400270; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment009_175570/func_82400270.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_82400304; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment009_175570/func_82400304.s")
#endif

M2C_UNK func_824001E4(s8 *);                        /* extern */
M2C_UNK func_82400270(s8 *);                        /* extern */
M2C_UNK func_82400304(s8 *);                        /* extern */

s32 func_82400374(s32 arg0, s8 *arg1) {
    s8 temp_v0;

    temp_v0 = *arg1;
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_824001B4(arg1);
        break;
    case 1:
        func_824001E4(arg1);
        break;
    case 2:
        func_82400270(arg1);
        break;
    case -1:
        func_82400304(arg1);
        break;
    }
    return 0;
}
