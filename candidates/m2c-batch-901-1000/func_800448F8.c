extern void *D_80075E44;

M2C_UNK *func_800448F8(void) {
    M2C_UNK *temp_a0;
    M2C_UNK *var_v1;

    var_v1 = NULL;
    temp_a0 = M2C_FIELD(D_80075E44, M2C_UNK **, 0x2C);
    if (temp_a0 != NULL) {
        var_v1 = temp_a0;
        M2C_FIELD(D_80075E44, M2C_UNK **, 0x2C) = (M2C_UNK *) *temp_a0;
        *temp_a0 = NULL;
    }
    return var_v1;
}
