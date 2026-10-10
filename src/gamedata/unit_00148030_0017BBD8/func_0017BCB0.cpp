extern "C" void func_001BE138(void *arg0, void *arg1);
extern "C" void func_0017BCF8(void *arg0, void *arg1);

extern "C" void func_0017BCB0(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001BE138(s0, &local);
    func_0017BCF8(s0, s1);
}
