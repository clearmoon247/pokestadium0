extern M2C_UNK D_800AD210;

s32 func_80022EDC(s32 arg0) {
    return (*(&D_800AD210 + (arg0 * 0x48)) & 0x4000) != 0;
}
