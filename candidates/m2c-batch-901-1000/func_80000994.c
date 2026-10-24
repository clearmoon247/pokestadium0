M2C_UNK func_8000087C();                            /* extern */
M2C_UNK func_8004A5A0(u8, M2C_UNK *);               /* extern */
extern M2C_UNK D_80087034;

void func_80000994(void *arg0) {
    func_8004A5A0(M2C_FIELD(arg0, u8 *, 0x1F), &D_80087034);
    func_8000087C();
}
