extern u32 D_8005F680;
extern u32 D_8005F684;

void func_80005C90(u32 arg0, u32 arg1) {
    if (arg0 < 3U) {
        D_8005F680 = arg0;
    }
    if (arg1 < 2U) {
        D_8005F684 = arg1;
    }
}
