extern "C" void func_00241F88(void *arg0, void *arg1);
extern "C" void func_0023E858(void *arg0, void *arg1);

extern "C" void func_0023E810(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00241F88(s0, &local);
    func_0023E858(s0, s1);
}
