extern void *D_800AA184;

s32 func_80006B28(void) {
    s32 var_v1;

    var_v1 = 0;
    if (D_800AA184 != NULL) {
        var_v1 = M2C_FIELD(D_800AA184, s8 *, 0xC) == 1;
    }
    return var_v1;
}
