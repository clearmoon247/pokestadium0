s32 func_8002D430(s32 arg0, s32 arg1) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD((arg0 + arg1), u8 *, 9);
    if ((s32) temp_v0 >= 0xA6) {
        return -2;
    }
    return temp_v0 - 1;
}
