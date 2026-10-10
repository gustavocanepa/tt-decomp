extern "C" void func_002A2740(void *arg0, void *arg1);
extern "C" void func_00296AC0(void *arg0, void *arg1);

extern "C" void func_00296A78(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002A2740(s0, &local);
    func_00296AC0(s0, s1);
}
