extern "C" void func_002A7578(void *arg0, void *arg1);
extern "C" void func_0014D5C8(void *arg0, void *arg1);

extern "C" void func_0014D580(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002A7578(s0, &local);
    func_0014D5C8(s0, s1);
}
