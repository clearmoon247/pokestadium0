extern s16 D_8219A8B2;
extern s16 D_8219A8B4;
extern s16 D_8219A8B6;

void func_82140438(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0xBA) = (s8) D_8219A8B2;
    M2C_FIELD(arg0, s8 *, 0xBB) = (s8) D_8219A8B4;
    M2C_FIELD(arg0, s8 *, 0xBC) = (s8) D_8219A8B6;
}
