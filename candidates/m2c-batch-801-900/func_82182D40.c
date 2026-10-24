extern M2C_UNK D_821CEEA0;
extern M2C_UNK D_821CF268;

void func_82182D40(void) {
    M2C_UNK *var_v1;

    var_v1 = &D_821CEEA0;
    do {
        var_v1 += 0x1E4;
        M2C_FIELD(var_v1, s16 *, -0x1E4) = 0;
    } while (var_v1 != &D_821CF268);
}
