extern "C" void func_001B4330(void *arg0, void *arg1);
extern "C" void func_0028DED8(void *arg0, void *arg1);

extern "C" void func_0028DE90(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001B4330(s0, &local);
    func_0028DED8(s0, s1);
}
