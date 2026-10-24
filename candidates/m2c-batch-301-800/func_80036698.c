void *func_80036698(void *arg0, u8 *arg1) {
    u8 temp_t6;

    temp_t6 = *arg1;
    M2C_FIELD(arg0, u8 *, 0xC6) = temp_t6;
    if (temp_t6 & 0xFF) {
        M2C_FIELD(arg0, f32 *, 0x68) = (f32) M2C_FIELD(arg0, f32 *, 0x4C);
    }
    return arg1 + 1;
}
