extern void *D_800AA150;

void func_82168EC0(void) {
    void *temp_v1;

    temp_v1 = D_800AA150;
    D_800AA150 = temp_v1 + 8;
    M2C_FIELD(temp_v1, s32 *, 4) = 0;
    M2C_FIELD(temp_v1, s32 *, 0) = 0xE7000000;
}
