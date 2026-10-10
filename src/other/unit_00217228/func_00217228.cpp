extern "C" void func_001B33E8(void *arg0, void *arg1);
extern "C" void func_00217270(void *arg0, void *arg1);

extern "C" void func_00217228(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001B33E8(s0, &local);
    func_00217270(s0, s1);
}
