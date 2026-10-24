extern u8 D_82199F4E;
extern M2C_UNK D_8219A3C8;

void func_8210FA7C(void) {
    M2C_FIELD(&D_8219A3C8, u8 *, 0x5A) = (u8) M2C_FIELD((&D_8219A3C8 + D_82199F4E), u8 *, 0x1F);
}
