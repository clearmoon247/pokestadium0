extern M2C_UNK D_80074E80;

s16 func_800336F0(s32 arg0, s32 arg1) {
    return *(&D_80074E80 + (*(arg0 + (arg1 * 2)) * 2));
}
