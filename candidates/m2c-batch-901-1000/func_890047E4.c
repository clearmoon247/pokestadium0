void func_890047E4(void *arg0, void *arg1) {
    u16 *temp_v0;

    if (M2C_FIELD(arg1, s32 *, 8) == 1) {
        temp_v0 = M2C_FIELD(arg0, u16 **, 0x30);
        *temp_v0 |= 0x200;
    }
}
