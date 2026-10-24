void func_80039A44(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0xEC) = 0;
    M2C_FIELD(arg0, s8 *, 0xED) = (s8) (M2C_FIELD(arg0, s16 *, 0xBC) & 0x80);
    M2C_FIELD(arg0, s32 *, 0xA0) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
}
