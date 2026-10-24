s32 func_800566BC(u8 *arg0) {
    u8 *var_v1;
    u8 temp_t7;

    var_v1 = arg0;
    if (*arg0 != 0) {
        do {
            temp_t7 = M2C_FIELD(var_v1, u8 *, 1);
            var_v1 += 1;
        } while (temp_t7 != 0);
    }
    return var_v1 - arg0;
}
