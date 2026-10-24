extern M2C_UNK D_800AB460;

void *func_800113B4(s32 arg0) {
    void *var_v1;

    var_v1 = NULL;
    if (arg0 <= 0) {
        var_v1 = &D_800AB460 + (M2C_FIELD(&D_800AB460, s32 *, 0x10A0) << 6) + (arg0 << 6);
    }
    return var_v1;
}
