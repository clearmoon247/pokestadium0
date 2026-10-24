extern M2C_UNK D_800AF990;

void func_80025BA0(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(&D_800AF990, s16 *, 0) = 1;
    M2C_FIELD(&D_800AF990, s16 *, 2) = arg0;
    M2C_FIELD(&D_800AF990, s32 *, 4) = arg1;
    M2C_FIELD(&D_800AF990, s32 *, 8) = arg2;
    M2C_FIELD(&D_800AF990, s32 *, 0xC) = arg3;
    M2C_FIELD(&D_800AF990, s32 *, 0x10) = arg4;
}
