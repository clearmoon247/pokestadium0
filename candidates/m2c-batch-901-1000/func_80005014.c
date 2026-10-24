extern M2C_UNK D_800A9710;

s32 func_80005014(void) {
    s32 var_v1;

    var_v1 = M2C_FIELD(&D_800A9710, s32 *, 0xA1C) != 0;
    if (var_v1 == 0) {
        var_v1 = M2C_FIELD(&D_800A9710, s32 *, 0xA24) != 0;
    }
    return var_v1;
}
