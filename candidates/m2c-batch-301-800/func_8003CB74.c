extern M2C_UNK D_800B3FF0;

s32 func_8003CB74(s32 arg0) {
    u8 *temp_v1;

    temp_v1 = arg0 + &D_800B3FF0;
    *temp_v1 |= 1;
    return 0;
}
