extern s16 D_8219A8B2;
extern s16 D_8219A8B4;
extern s16 D_8219A8B6;

void func_82140410(void *arg0) {
    D_8219A8B2 = (s16) M2C_FIELD(arg0, u8 *, 0xBA);
    D_8219A8B4 = (s16) M2C_FIELD(arg0, u8 *, 0xBB);
    D_8219A8B6 = (s16) M2C_FIELD(arg0, u8 *, 0xBC);
}
