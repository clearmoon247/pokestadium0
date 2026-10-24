void *func_80002BA4(void *arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg0 + 0x10;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = (s32) ((arg1 & ~3) - 0x10);
    M2C_FIELD(arg0, s32 *, 8) = temp_v1;
    M2C_FIELD(arg0, s32 *, 0xC) = temp_v1;
    return arg0;
}
