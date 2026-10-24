void func_80002814(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = arg0 - 0x10;
    M2C_FIELD(temp_v0, s32 *, 8) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0xC) = arg1;
}
