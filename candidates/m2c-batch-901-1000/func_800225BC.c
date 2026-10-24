u8 *func_800221BC();                                /* extern */

u8 func_800225BC(void) {
    s32 sp1C;
    s32 var_v1;
    u8 *temp_v0;

    sp1C = 0;
    temp_v0 = func_800221BC();
    var_v1 = sp1C;
    if (temp_v0 != NULL) {
        var_v1 = (s32) *temp_v0;
    }
    return (u8) var_v1;
}
