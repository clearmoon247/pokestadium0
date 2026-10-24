extern s16 D_800733D4;
extern s16 D_800733D8;

void func_80025BE4(s16 arg0) {
    if ((arg0 >= 0) && (arg0 < 4)) {
        D_800733D4 = arg0;
        D_800733D8 = 1;
    }
}
