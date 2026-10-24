s32 func_891096F4(void *arg0, void *arg1) {
    s32 var_v0;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 *, 0x2C);
    var_v0 = (s32) temp_v1 >= (s32) M2C_FIELD(arg1, u8 *, 0);
    if (var_v0 != 0) {
        var_v0 = (s32) M2C_FIELD(arg1, u8 *, 1) >= (s32) temp_v1;
    }
    return var_v0;
}
