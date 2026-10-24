void func_80020CC8(void *arg0, s16 arg1) {
    if (M2C_FIELD(arg0, s16 *, 8) >= arg1) {
        M2C_FIELD(arg0, s16 *, 0xA) = arg1;
    }
}
