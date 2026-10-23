void func_80002C64(void *arg0) {
    s32 temp_v0;

    temp_v0 = arg0 + 0x10;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = temp_v0;
    M2C_FIELD(arg0, s32 *, 0xC) = temp_v0;
}
