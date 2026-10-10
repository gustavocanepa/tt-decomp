extern "C" void func_002712D0(void *arg0, void *arg1);
extern "C" void func_002812F8(void *arg0, void *arg1);

extern "C" void func_002812B0(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002712D0(s0, &local);
    func_002812F8(s0, s1);
}
