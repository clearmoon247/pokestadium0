s32 func_8001FAC8(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 2) | (M2C_FIELD(arg0, u8 *, 0) << 0x10) | (M2C_FIELD(arg0, u8 *, 1) << 8);
}
