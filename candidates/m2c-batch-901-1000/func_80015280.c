M2C_UNK func_8001380C(void *);                      /* extern */
M2C_UNK func_80015214(s16);                         /* extern */

void func_80015280(void *arg0) {
    func_80015214(M2C_FIELD(arg0, s16 *, 0x18));
    func_8001380C(arg0);
}
