extern M2C_UNK D_8006A9CC;

s32 func_82107F68(void *arg0) {
    return *(&D_8006A9CC + (M2C_FIELD(arg0, u8 *, 0x80A) * 0xC));
}
