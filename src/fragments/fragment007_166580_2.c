/* Stadium Zero fragment007_166580, second object (starts at 0x82008C40). */

#include "global.h"
#include "m2c_macros.h"

#ifdef NON_MATCHING
/* TODO: decompile func_82008C40; signature not recovered. */
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/fragments/fragment007_166580/func_82008C40.s")
#endif

void func_82008D54(s8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0) = 0;
    M2C_FIELD(arg0, s8 *, 1) = 0;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s8 *, 0x1D) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
}

/*
 * func_82008D7C
 *
 * Sets up four slot lists inside the session context (gSessionContext,
 * D_800AE8F0) and registers each list that is in use with one of two
 * groups.  Each of the four arguments is a count: a list is only set up when
 * its count is greater than 0, and is then initialised with
 * func_82008C40(list, extra, count - 1, count - 1).
 *
 *   arg0 -> list D_800AE8F4 (extra block D_800AF104), group A
 *   arg1 -> list D_800AEAF8 (extra block D_800AF30C), group A
 *   arg2 -> list D_800AECFC (extra block D_800AF514), group B
 *   arg3 -> list D_800AEF00 (extra block D_800AF71C), group B
 *
 * Group A is the block at D_800AF924 (context offset 0x1034) and group B the
 * block at D_800AF94C (offset 0x105C); both are cleared first with
 * func_82008D54.  In a group, byte +1 is the number of registered lists and
 * the pointers to them are stored from offset +8, in registration order.
 * The four words at context offsets 4, 0x208, 0x40C and 0x610 (the first
 * word of each list) are cleared as well.
 *
 * What the lists and groups are used for is not established here;
 * func_82008C40 is still assembly.
 */
void func_82008C40(void*, void*, s32, s32);
extern u8 D_800AE8F0[];
extern u8 D_800AE8F4[];
extern u8 D_800AEAF8[];
extern u8 D_800AECFC[];
extern u8 D_800AEF00[];
extern u8 D_800AF104[];
extern u8 D_800AF30C[];
extern u8 D_800AF514[];
extern u8 D_800AF71C[];
extern s8 D_800AF924;
extern s8 D_800AF94C;

void func_82008D7C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp;

    func_82008D54(&D_800AF924);
    func_82008D54(&D_800AF94C);
    D_800AE8F0[4] = 0;
    D_800AE8F0[0x208] = 0;
    D_800AE8F0[0x40C] = 0;
    D_800AE8F0[0x610] = 0;
    if (arg0 > 0) {
        temp = arg0 - 1;
        func_82008C40(D_800AE8F4, D_800AF104, temp, temp);
        *(u8**)&D_800AE8F0[0x103C + D_800AE8F0[0x1035] * 4] = D_800AE8F4;
        D_800AE8F0[0x1035] = D_800AE8F0[0x1035] + 1;
    }
    if (arg1 > 0) {
        temp = arg1 - 1;
        func_82008C40(D_800AEAF8, D_800AF30C, temp, temp);
        *(u8**)&D_800AE8F0[0x103C + D_800AE8F0[0x1035] * 4] = D_800AEAF8;
        D_800AE8F0[0x1035] = D_800AE8F0[0x1035] + 1;
    }
    if (arg2 > 0) {
        temp = arg2 - 1;
        func_82008C40(D_800AECFC, D_800AF514, temp, temp);
        *(u8**)&D_800AE8F0[0x1064 + D_800AE8F0[0x105D] * 4] = D_800AECFC;
        D_800AE8F0[0x105D] = D_800AE8F0[0x105D] + 1;
    }
    if (arg3 > 0) {
        temp = arg3 - 1;
        func_82008C40(D_800AEF00, D_800AF71C, temp, temp);
        *(u8**)&D_800AE8F0[0x1064 + D_800AE8F0[0x105D] * 4] = D_800AEF00;
        D_800AE8F0[0x105D] = D_800AE8F0[0x105D] + 1;
    }
}

M2C_UNK func_80021894(M2C_UNK);                     /* extern */
void func_82008D7C(s32, s32, s32, s32);

void func_82008F14(void) {
    func_80021894(0);
    func_80021894(1);
    func_82008D7C(1, 0, 2, 0);
}
