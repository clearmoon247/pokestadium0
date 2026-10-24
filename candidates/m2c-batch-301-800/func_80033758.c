extern M2C_UNK D_80075690;

s16 func_80033758(s32 arg0, s32 arg1) {
    return *(&D_80075690 + (*(arg0 + (arg1 * 2)) * 2));
}
