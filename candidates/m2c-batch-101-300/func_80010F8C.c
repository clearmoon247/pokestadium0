s32 func_80010F8C(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x4C) = arg1;
    return (s32) M2C_FIELD(arg0, s32 *, 0x48) >> 0x10;
}
