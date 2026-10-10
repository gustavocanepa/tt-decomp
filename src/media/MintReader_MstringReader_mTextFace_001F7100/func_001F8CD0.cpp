extern "C" void func_00202758(void *arg0, void *arg1);
extern "C" void func_001F8D18(void *arg0, void *arg1);

extern "C" void func_001F8CD0(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00202758(s0, &local);
    func_001F8D18(s0, s1);
}
