s8 *func_8000A460(s8 *arg0, s8 *arg1) {
    s8 *var_a1;
    s8 temp_v0;
    s8 temp_v0_2;
    void *var_v1;

    temp_v0 = *arg1;
    var_v1 = arg0 + 1;
    var_a1 = arg1 + 1;
    *arg0 = temp_v0;
    if (temp_v0 != 0) {
        do {
            temp_v0_2 = *var_a1;
            var_v1 += 1;
            var_a1 += 1;
            M2C_FIELD(var_v1, s8 *, -1) = temp_v0_2;
        } while (temp_v0_2 != 0);
    }
    return arg0;
}
