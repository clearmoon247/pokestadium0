extern M2C_UNK D_80060990;
extern void *D_800AA150;

void func_8001ABBC(void) {
    void *temp_v1;

    temp_v1 = D_800AA150;
    D_800AA150 = temp_v1 + 8;
    M2C_FIELD(temp_v1, s32 *, 0) = 0xDE000000;
    M2C_FIELD(temp_v1, M2C_UNK **, 4) = &D_80060990;
}
