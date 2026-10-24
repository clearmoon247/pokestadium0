void func_811098C0(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = (arg1 + 0xF) & ~0xF;
    M2C_FIELD(arg0, s32 *, 0) = temp_v0;
    M2C_FIELD(arg0, s32 *, 4) = temp_v0;
    M2C_FIELD(arg0, s32 *, 8) = (s32) (arg2 - (arg1 & 0xF));
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
}
