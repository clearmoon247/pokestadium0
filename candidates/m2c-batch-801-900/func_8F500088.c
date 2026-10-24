extern void *D_80060490;

void func_8F500088(s32 arg0, void *arg1) {
    if (arg0 == 2) {
        M2C_FIELD(arg1, s16 *, 0x1A) = (s16) (M2C_FIELD(D_80060490, s16 *, 0x18) - 1);
    }
}
