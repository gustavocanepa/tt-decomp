extern "C" void func_002A7578(void *arg0, void *arg1);
extern "C" void func_002A1EE0(void *arg0, void *arg1);

extern "C" void func_002A1E98(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002A7578(s0, &local);
    func_002A1EE0(s0, s1);
}
