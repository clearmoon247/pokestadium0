void *func_80056690(void *arg0, u8 *arg1, s32 arg2) {
    s32 var_a2;
    u8 *var_v1;
    u8 temp_t6;
    void *var_v0;

    var_a2 = arg2;
    var_v0 = arg0;
    var_v1 = arg1;
    if (var_a2 != 0) {
        do {
            temp_t6 = *var_v1;
            var_a2 -= 1;
            var_v0 += 1;
            var_v1 += 1;
            M2C_FIELD(var_v0, u8 *, -1) = temp_t6;
        } while (var_a2 != 0);
    }
    return arg0;
}
