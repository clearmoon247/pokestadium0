M2C_UNK func_8000087C();                            /* extern */
M2C_UNK func_8004CF40(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_80087034;

void func_80000964(void *arg0) {
    func_8004CF40(M2C_FIELD(arg0, s32 *, 0x1C), &D_80087034);
    func_8000087C();
}
