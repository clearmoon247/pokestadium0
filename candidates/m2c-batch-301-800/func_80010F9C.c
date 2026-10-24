void func_80010F9C(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s32 *, 0x48) = (s32) ((arg1 << 0x10) - M2C_FIELD(arg0, s32 *, 0x4C));
}
