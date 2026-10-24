s64 func_8005C3B0(void) {
    M2C_ERROR(/* unknown instruction: trunc.l.d $f4, $f12 */);
    return (s64) M2C_ERROR(/* unknown instruction: dmfc1 $v0, $f4 */) >> 0x20;
}
