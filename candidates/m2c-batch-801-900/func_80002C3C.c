void func_80002C3C(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0) >= arg1) {
        M2C_FIELD(arg0, s32 *, 4) = arg1;
        M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 8) + arg1);
    }
}
