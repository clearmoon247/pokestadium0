void *func_800368F8(void *arg0, void *arg1) {
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) ((s16) (M2C_FIELD(arg1, u8 *, 0) << 8) | M2C_FIELD(arg1, u8 *, 1));
    M2C_FIELD(arg0, s16 *, 0xC0) = 0;
    return arg1 + 2;
}
