extern void *D_800AE8E0;

s32 func_80025100(s8 *arg0, s32 *arg1) {
    if (arg0 != NULL) {
        *arg0 = M2C_FIELD(D_800AE8E0, s8 *, 0x7A42);
    }
    if (arg1 != NULL) {
        *arg1 = M2C_FIELD(D_800AE8E0, s32 *, 0x7A44);
    }
    return 1;
}
