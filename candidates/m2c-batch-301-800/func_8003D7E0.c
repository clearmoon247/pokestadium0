extern M2C_UNK D_800B40D8;

u8 func_8003D7E0(s32 arg0) {
    u8 **temp_a1;
    u8 *temp_a2;

    temp_a1 = (arg0 * 4) + &D_800B40D8;
    temp_a2 = *temp_a1;
    *temp_a1 = temp_a2 + 1;
    return *temp_a2;
}
