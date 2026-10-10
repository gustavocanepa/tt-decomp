extern "C" void func_001B33E8(void *arg0, void *arg1);
extern "C" void func_0026EA08(void *arg0, void *arg1);

extern "C" void func_0026E9C0(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001B33E8(s0, &local);
    func_0026EA08(s0, s1);
}
