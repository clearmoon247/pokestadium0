void func_80002D28(void *arg0, s32 *arg1, s32 arg2) {
    s32 *var_a1;
    s32 temp_t6;
    s32 temp_v0;
    s32 var_a2;
    void *var_a0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_a2 = arg2 - 1;
    if (arg2 > 0) {
        do {
            temp_t6 = *var_a1;
            temp_v0 = var_a2 > 0;
            var_a2 -= 1;
            var_a0 += 4;
            var_a1 += 4;
            M2C_FIELD(var_a0, s32 *, -4) = temp_t6;
        } while (temp_v0 != 0);
    }
}
