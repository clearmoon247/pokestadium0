extern M2C_UNK D_800B40C8;

s32 func_8003CC2C(s32 arg0, s32 arg1) {
    *(&D_800B40C8 + arg0) = arg1 & 0xF;
    return 0;
}
