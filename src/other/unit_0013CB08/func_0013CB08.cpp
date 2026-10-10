extern "C" void func_00202758(void *arg0, void *arg1);
extern "C" void func_0013CB50(void *arg0, void *arg1);

extern "C" void func_0013CB08(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00202758(s0, &local);
    func_0013CB50(s0, s1);
}
