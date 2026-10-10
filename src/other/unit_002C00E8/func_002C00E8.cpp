extern "C" void func_002A7578(void *arg0, void *arg1);
extern "C" void func_002C0130(void *arg0, void *arg1);

extern "C" void func_002C00E8(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002A7578(s0, &local);
    func_002C0130(s0, s1);
}
