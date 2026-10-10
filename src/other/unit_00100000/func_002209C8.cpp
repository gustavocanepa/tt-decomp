extern "C" void func_00202758(void *arg0, void *arg1);
extern "C" void func_00220A10(void *arg0, void *arg1);

extern "C" void func_002209C8(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00202758(s0, &local);
    func_00220A10(s0, s1);
}
