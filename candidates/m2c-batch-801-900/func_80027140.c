extern s32 D_800733F0;

void func_80027140(s32 arg0, void *arg1) {
    if ((arg0 == 2) && (D_800733F0 != 0)) {
        M2C_FIELD(arg1, s32 *, 0x18) = (s32) D_800733F0;
    }
}
