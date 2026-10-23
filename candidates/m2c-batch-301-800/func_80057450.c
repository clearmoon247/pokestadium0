extern void *D_80077C20;

s32 func_80057450(void *arg0) {
    void *var_a0;

    var_a0 = arg0;
    if (var_a0 == NULL) {
        var_a0 = D_80077C20;
    }
    return M2C_FIELD(var_a0, s32 *, 4);
}
