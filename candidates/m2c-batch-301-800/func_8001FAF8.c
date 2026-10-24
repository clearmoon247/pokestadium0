void func_8001FAF8(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0) = (s8) (arg1 >> 0x10);
    M2C_FIELD(arg0, s8 *, 1) = (s8) (arg1 >> 8);
    M2C_FIELD(arg0, s8 *, 2) = arg1;
}
