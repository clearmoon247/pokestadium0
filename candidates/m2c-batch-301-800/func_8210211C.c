void func_8210211C(void *arg0) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0x85C);
    M2C_FIELD(temp_v0, u8 *, 0) = (u8) (M2C_FIELD(temp_v0, u8 *, 0) | 0x80);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x85C), s16 *, 2) = (s16) M2C_FIELD(arg0, s16 *, 0x84C);
}
