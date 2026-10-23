extern s32 D_818008A8;

s32 func_81800020(s32 arg0, void *arg1) {
    if (arg0 == 2) {
        M2C_FIELD(arg1, s16 *, 0x1A) = (s16) D_818008A8;
    }
    return 0;
}
