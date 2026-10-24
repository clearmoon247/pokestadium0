void func_8004D630(void *arg0, void **arg1) {
    void *temp_v0;

    M2C_FIELD(arg0, void ***, 4) = arg1;
    M2C_FIELD(arg0, void **, 0) = (void *) *arg1;
    temp_v0 = *arg1;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, void **, 4) = arg0;
    }
    *arg1 = arg0;
}
