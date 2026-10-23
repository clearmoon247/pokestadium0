extern M2C_UNK D_800B3FE8;

s32 func_8003C83C(s32 arg0) {
    u8 *temp_v1;

    temp_v1 = arg0 + &D_800B3FE8;
    *temp_v1 ^= 1;
    return 0;
}
