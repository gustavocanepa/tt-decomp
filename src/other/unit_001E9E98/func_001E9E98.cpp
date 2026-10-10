extern "C" void func_002712D0(void *arg0, void *arg1);
extern "C" void func_001E9EE0(void *arg0, void *arg1);

extern "C" void func_001E9E98(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002712D0(s0, &local);
    func_001E9EE0(s0, s1);
}
