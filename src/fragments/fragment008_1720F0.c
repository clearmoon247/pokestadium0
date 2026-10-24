/* Stadium Zero fragment008_1720F0. */

#include "global.h"
#include "m2c_macros.h"

s32 func_800246A8(M2C_UNK, s32);                    /* extern */

s32 func_88100020(void) {
    s32 var_s0;

    var_s0 = 0;
loop_1:
    if (func_800246A8(0x10, var_s0) == 0) {
        return var_s0;
    }
    var_s0 += 1;
    if (var_s0 == 0x10) {
        return -1;
    }
    goto loop_1;
}

#ifdef NON_MATCHING
/* TODO: decompile func_88100078; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100078.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88100100; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100100.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_881001A8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_881001A8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8810024C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_8810024C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88100348; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100348.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88100428; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100428.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_881004CC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_881004CC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_881005E4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_881005E4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_881007AC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_881007AC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88100898; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100898.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_881009A0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_881009A0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88100B2C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100B2C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88100BA4; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100BA4.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88100C24; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100C24.s")
#endif

M2C_UNK func_8002BC14(s32);                         /* extern */
extern s32 D_800603C0;

void func_88100CA8(s32 arg0) {
    func_8002BC14(D_800603C0);
}

#ifdef NON_MATCHING
/* TODO: decompile func_88100CD0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100CD0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88100D30; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100D30.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88100D9C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100D9C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88100E34; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88100E34.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8810105C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_8810105C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8810112C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_8810112C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_8810137C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_8810137C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88101478; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88101478.s")
#endif

void func_8810165C(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = 0xF;
}

void func_88101670(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = 0xF;
    M2C_FIELD(arg0, s32 *, 0) = (s32) (arg1 * 0xF);
}

#ifdef NON_MATCHING
/* TODO: decompile func_88101690; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88101690.s")
#endif

s32 func_881016B0(s32 *arg0) {
    return *arg0 == 0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_881016BC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_881016BC.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88101704; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88101704.s")
#endif

s32 func_88101734(s32 *arg0) {
    return *arg0;
}

#ifdef NON_MATCHING
/* TODO: decompile func_8810173C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_8810173C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88101A38; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88101A38.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88101D7C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88101D7C.s")
#endif

void func_88101DB4(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xBC) = arg1;
    switch (arg1) {                                 /* irregular */
    case 0:
        M2C_FIELD(arg0, s32 *, 4) = 0;
        return;
    case 1:
        M2C_FIELD(arg0, s32 *, 4) = 1;
        return;
    case 2:
        M2C_FIELD(arg0, s32 *, 4) = 2;
        return;
    }
}

#ifdef NON_MATCHING
/* TODO: decompile func_88101DF8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88101DF8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88101EC8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88101EC8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88101F1C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88101F1C.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88102184; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88102184.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_881025C8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_881025C8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88102600; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88102600.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88102688; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88102688.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88102710; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88102710.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88102794; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88102794.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88102834; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88102834.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_881028B8; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_881028B8.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_881029E0; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_881029E0.s")
#endif

#ifdef NON_MATCHING
/* TODO: decompile func_88102A2C; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88102A2C.s")
#endif

M2C_UNK func_8000B1FC();                            /* extern */
M2C_UNK func_8000B220();                            /* extern */
M2C_UNK func_88102834(s32);                         /* extern */
M2C_UNK func_881028B8(s32);                         /* extern */
extern s32 D_881030F8;

void func_88102B58(s32 arg0) {
    func_8000B1FC();
    func_8000B220();
    func_88102834(D_881030F8);
    func_881028B8(D_881030F8);
}

M2C_UNK func_80002DC0(s32);                         /* extern */
extern s32 D_881030F8;

void func_88102B98(void) {
    func_80002DC0(D_881030F8);
}

#ifdef NON_MATCHING
/* TODO: decompile func_88102BBC; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment008_1720F0/func_88102BBC.s")
#endif
