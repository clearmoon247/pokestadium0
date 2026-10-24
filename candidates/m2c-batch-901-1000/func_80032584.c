u8 *func_80001B10(s32);                             /* extern */
extern s32 D_8006049C;

u8 func_80032584(void) {
    return *func_80001B10(D_8006049C + 0xA6);
}
