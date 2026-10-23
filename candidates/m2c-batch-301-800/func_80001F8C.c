extern M2C_UNK D_800A8D20;

void func_80001F8C(s32 arg0) {
    void *temp_v0;

    temp_v0 = (arg0 * 8) + &D_800A8D20;
    M2C_FIELD(temp_v0, s32 *, 0) = 0;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
}
