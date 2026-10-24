extern M2C_UNK D_FLT_8006DBB0;

void func_8213FA88(void *arg0) {
    M2C_FIELD(arg0, f32 *, 0x78) = (f32) (*(&D_FLT_8006DBB0 + (((s32) M2C_FIELD(arg0, u16 *, 0x92) >> 4) * 4)) * M2C_FIELD(arg0, f32 *, 0x70));
}
