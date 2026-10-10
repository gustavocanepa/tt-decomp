extern "C" void func_001B1560(void *arg0, void *arg1);
extern "C" void func_001CF900(void *arg0, void *arg1);

extern "C" void func_001CF8B8(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001B1560(s0, &local);
    func_001CF900(s0, s1);
}
