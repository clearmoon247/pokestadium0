s32 func_80003160(void *arg0) {
    return (M2C_FIELD(arg0, u8 *, 1) | (M2C_FIELD(arg0, u8 *, 0) << 8)) & 0xFFFF;
}
