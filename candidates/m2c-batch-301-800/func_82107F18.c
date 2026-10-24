extern M2C_UNK D_FLT_8218934C;

f32 func_82107F18(void *arg0) {
    return *(&D_FLT_8218934C + (M2C_FIELD(arg0, s16 *, 0x1A) * 0x10)) * M2C_FIELD(arg0, f32 *, 0x34);
}
