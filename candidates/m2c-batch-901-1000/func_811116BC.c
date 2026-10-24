extern f32 D_FLT_811858D4;

void func_811116BC(void *arg0, void *arg1) {
    M2C_FIELD(arg0, void **, 0x48) = arg1;
    M2C_FIELD(arg0, u8 *, 0x30) = (u8) M2C_FIELD(M2C_FIELD(arg1, void **, 0x54), u8 *, 5);
    M2C_FIELD(arg0, u8 *, 0x5C) = (u8) (M2C_FIELD(arg0, u8 *, 0x5C) | 0x10);
    M2C_FIELD(arg0, f32 *, 0x6C) = (f32) D_FLT_811858D4;
}
