extern "C" void func_00241F88(void *arg0, void *arg1);
extern "C" void func_001D00A8(void *arg0, void *arg1);

extern "C" void func_001D0060(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00241F88(s0, &local);
    func_001D00A8(s0, s1);
}
