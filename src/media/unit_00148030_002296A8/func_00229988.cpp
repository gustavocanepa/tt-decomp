extern "C" void func_001B33E8(void *arg0, void *arg1);
extern "C" void func_002299D0(void *arg0, void *arg1);

extern "C" void func_00229988(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001B33E8(s0, &local);
    func_002299D0(s0, s1);
}
