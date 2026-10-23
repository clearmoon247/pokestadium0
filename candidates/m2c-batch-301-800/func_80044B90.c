extern M2C_UNK D_800FDE80;

u8 func_80044B90(s32 arg0) {
    return *(&D_800FDE80 + (arg0 & 0xFF));
}
