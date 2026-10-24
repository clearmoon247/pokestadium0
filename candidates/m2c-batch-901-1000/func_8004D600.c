void func_8004D600(void *arg0) {
    void **temp_v0_2;
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, void ***, 4) = (void **) M2C_FIELD(arg0, void ***, 4);
    }
    temp_v0_2 = M2C_FIELD(arg0, void ***, 4);
    if (temp_v0_2 != NULL) {
        *temp_v0_2 = M2C_FIELD(arg0, void **, 0);
    }
}
