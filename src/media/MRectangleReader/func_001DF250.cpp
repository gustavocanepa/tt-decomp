extern "C" void func_002A7578(void *arg0, void *arg1);
extern "C" void func_001DF298(void *arg0, void *arg1);

extern "C" void func_001DF250(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002A7578(s0, &local);
    func_001DF298(s0, s1);
}
