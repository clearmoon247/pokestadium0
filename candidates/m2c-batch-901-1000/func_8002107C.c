void func_8002107C(u32 arg0, u32 arg1) {
    s32 var_v0;
    u32 var_a0;
    u8 temp_t6;

    var_a0 = arg0;
    var_v0 = 0;
    if (var_a0 < arg1) {
        do {
            temp_t6 = *var_a0;
            var_a0 += 1;
            var_v0 += temp_t6;
        } while (var_a0 < arg1);
    }
    *arg1 = (s8) (0xFF - var_v0);
}
