void *func_80036D8C(void *arg0, u8 *arg1) {
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg0, void **, 0x84);
    M2C_FIELD(arg0, void **, 0x90) = (void *) (*(M2C_FIELD(temp_a2, s32 *, 0x14) + (*arg1 * 4)) + temp_a2);
    return arg1 + 1;
}
