extern M2C_UNK D_800AD248;
extern M2C_UNK D_800AD24C;

void func_80022C40(s32 arg0, void *arg1) {
    s32 temp_t6;

    temp_t6 = arg0 * 0x48;
    M2C_FIELD(arg1, s32 *, 0) = (s32) *(&D_800AD248 + temp_t6);
    M2C_FIELD(arg1, s32 *, 4) = (s32) *(&D_800AD24C + temp_t6);
}
