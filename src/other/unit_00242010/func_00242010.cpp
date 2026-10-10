extern "C" void func_00220940(void *arg0, void *arg1);
extern "C" void func_00242058(void *arg0, void *arg1);

extern "C" void func_00242010(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00220940(s0, &local);
    func_00242058(s0, s1);
}
