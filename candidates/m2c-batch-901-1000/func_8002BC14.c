s32 func_8002BC14(void *arg0) {
    s32 var_v1;
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 8);
    var_v1 = 0;
    if (temp_v0 & 0x4000) {
        return -1;
    }
    if (temp_v0 & 0x8000) {
        var_v1 = 1;
    }
    return var_v1;
}
