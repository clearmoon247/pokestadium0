extern M2C_UNK D_FLT_8006EBB0;

void func_8213FA60(void *arg0) {
    M2C_FIELD(arg0, f32 *, 0x7C) = (f32) (*(&D_FLT_8006EBB0 + (((s32) M2C_FIELD(arg0, u16 *, 0x90) >> 4) * 4)) * M2C_FIELD(arg0, f32 *, 0x70));
}
