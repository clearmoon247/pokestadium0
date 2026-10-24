s32 func_8004FC10(void *arg0, s32 arg1, s32 arg2) {
    if (arg1 == 2) {
        *(M2C_FIELD(arg0, s32 *, 0x1C) + (M2C_FIELD(arg0, s32 *, 0x14) * 4)) = arg2;
        M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg0, s32 *, 0x14) + 1);
    }
    return 0;
}
