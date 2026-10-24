extern M2C_UNK D_800FD6B2;
extern M2C_UNK D_800FD6B4;

void func_80041914(s32 arg0, s32 arg1) {
    s8 temp_v0;
    s8 temp_v1;

    temp_v0 = arg0 * 2;
    temp_v1 = arg1 * 2;
    M2C_FIELD(&D_800FD6B2, s8 *, 0) = temp_v0;
    M2C_FIELD(&D_800FD6B4, s8 *, 0) = temp_v0;
    M2C_FIELD(&D_800FD6B2, s8 *, 1) = temp_v1;
    M2C_FIELD(&D_800FD6B4, s8 *, 1) = temp_v1;
}
