extern M2C_UNK D_800870D0;

s32 func_80001AA4(void) {
    s32 var_v1;

    var_v1 = 1;
    if (M2C_FIELD(&D_800870D0, s32 *, 0xA98) != 0) {
        var_v1 = M2C_FIELD(&D_800870D0, s32 *, 0xA24) > 0;
    }
    return var_v1;
}
