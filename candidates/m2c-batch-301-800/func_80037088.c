void *func_80037088(void *arg0, u8 *arg1) {
    u8 temp_t6;

    temp_t6 = *arg1;
    M2C_FIELD(arg0, u8 *, 0xE7) = temp_t6;
    if (!(temp_t6 & 0xFF)) {
        M2C_FIELD(arg0, s16 *, 0xBC) = 0x80;
    }
    return arg1 + 1;
}
