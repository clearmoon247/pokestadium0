extern M2C_UNK D_800AA1E0;

void func_80008014(s32 arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(&D_800AA1E0, s32 *, 0x9CC) = (s32) (arg0 | 0xA0000000);
    M2C_FIELD(&D_800AA1E0, s16 *, 0x9D0) = arg1;
    M2C_FIELD(&D_800AA1E0, s16 *, 0x9D2) = arg2;
}
