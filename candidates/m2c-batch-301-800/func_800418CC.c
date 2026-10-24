extern M2C_UNK D_800FD6B4;

u8 func_800418CC(u32 arg0) {
    if (arg0 >= 2U) {
        return -1U;
    }
    return *(&D_800FD6B4 + arg0);
}
