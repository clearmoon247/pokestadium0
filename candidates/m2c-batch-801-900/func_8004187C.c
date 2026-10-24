extern M2C_UNK D_800FD698;

s32 func_8004187C(u32 arg0) {
    if (arg0 >= 2U) {
        return -1;
    }
    return *(&D_800FD698 + (arg0 * 4));
}
