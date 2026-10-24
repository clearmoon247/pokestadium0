extern void *D_800AE8E0;

s32 func_800251A8(void) {
    return (M2C_FIELD(D_800AE8E0, u8 *, 0x7A49) | (M2C_FIELD(D_800AE8E0, u8 *, 0x7A48) << 8)) & 0xFFFF;
}
