extern u16 D_80060484;
extern void *D_80060490;

s32 func_800158D8(void) {
    s32 var_v1;

    var_v1 = 1;
    if (D_80060490 != NULL) {
        var_v1 = D_80060484 == M2C_FIELD(D_80060490, u16 *, 0x1A);
    }
    return var_v1;
}
