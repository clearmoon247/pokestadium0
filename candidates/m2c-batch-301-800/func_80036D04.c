void *func_80036D04(void *arg0, void *arg1) {
    M2C_FIELD(arg0, u8 *, 0xEB) = (u8) M2C_FIELD(arg1, u8 *, 0);
    M2C_FIELD(arg0, u8 *, 0xE1) = (u8) M2C_FIELD(arg1, u8 *, 1);
    M2C_FIELD(arg0, u8 *, 0xE2) = (u8) M2C_FIELD(arg1, u8 *, 2);
    return arg1 + 3;
}
