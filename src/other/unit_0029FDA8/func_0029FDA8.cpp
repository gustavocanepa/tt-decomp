extern "C" void func_002BC2C8(void *arg0, void *arg1);
extern "C" void func_0029FDF0(void *arg0, void *arg1);

extern "C" void func_0029FDA8(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002BC2C8(s0, &local);
    func_0029FDF0(s0, s1);
}
