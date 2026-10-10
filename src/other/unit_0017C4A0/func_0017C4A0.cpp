extern "C" void func_001B4330(void *arg0, void *arg1);
extern "C" void func_0017C4E8(void *arg0, void *arg1);

extern "C" void func_0017C4A0(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001B4330(s0, &local);
    func_0017C4E8(s0, s1);
}
