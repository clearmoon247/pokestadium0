extern M2C_UNK D_800AD212;

u8 func_80022BAC(s32 arg0) {
    return *(&D_800AD212 + (arg0 * 0x48));
}
