extern M2C_UNK D_80074A78;

s16 func_800336D0(s32 arg0, s32 arg1) {
    return *(&D_80074A78 + (*(arg0 + (arg1 * 2)) * 2));
}
