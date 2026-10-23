s32 func_80058940(void) {
    M2C_ERROR(/* mtc0 $t1, Status */);
    return M2C_ERROR(/* mfc0 Status */) & 1;
}
