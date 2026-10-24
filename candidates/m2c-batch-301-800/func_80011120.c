s32 func_80011120(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), u16 *, 0xA) == (M2C_FIELD(arg0, s16 *, 0x5C) + 2);
}
