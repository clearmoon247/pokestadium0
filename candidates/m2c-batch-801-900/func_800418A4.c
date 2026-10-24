extern M2C_UNK D_800FD6A8;

s32 func_800418A4(u32 arg0) {
    if (arg0 >= 2U) {
        return -1;
    }
    return *(&D_800FD6A8 + (arg0 * 4));
}
