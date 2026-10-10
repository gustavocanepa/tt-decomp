extern "C" void func_002A7578(void *arg0, void *arg1);
extern "C" void func_002BC398(void *arg0, void *arg1);

extern "C" void func_002BC350(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002A7578(s0, &local);
    func_002BC398(s0, s1);
}
