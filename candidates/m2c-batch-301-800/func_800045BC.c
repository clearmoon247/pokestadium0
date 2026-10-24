s32 func_800045BC(void *arg0, u32 arg1) {
    s32 var_v1;

    var_v1 = 0;
    if (arg1 < (u32) M2C_FIELD(arg0, u32 *, 0xC)) {
        var_v1 = M2C_FIELD((arg0 + (arg1 * 0x10)), s32 *, 0x18);
    }
    return var_v1;
}
