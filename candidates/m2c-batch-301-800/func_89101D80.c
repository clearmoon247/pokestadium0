s32 func_89101D80(void *arg0, s32 arg1) {
    s32 temp_t7;

    temp_t7 = M2C_FIELD(arg0, s32 *, 0x7C) ^ arg1;
    M2C_FIELD(arg0, s32 *, 0x7C) = temp_t7;
    return temp_t7 & arg1;
}
