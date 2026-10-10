extern "C" void func_00202758(void *arg0, void *arg1);
extern "C" void func_0021A9F8(void *arg0, void *arg1);

extern "C" void func_0021A9B0(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00202758(s0, &local);
    func_0021A9F8(s0, s1);
}
