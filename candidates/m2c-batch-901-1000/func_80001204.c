M2C_UNK func_80004F34(M2C_UNK);                     /* extern */

void func_80001204(void *arg0, void *arg1, M2C_UNK arg2) {
    M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(arg1, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 0x54) = (s32) M2C_FIELD(arg1, s32 *, 8);
    func_80004F34(arg2);
}
