extern s16 D_800B3654;
extern s16 D_800B3656;

void func_800374E0(s32 arg0, s16 arg1) {
    if (arg0 & 1) {
        D_800B3654 = arg1;
    }
    if (arg0 & 2) {
        D_800B3656 = arg1;
    }
}
