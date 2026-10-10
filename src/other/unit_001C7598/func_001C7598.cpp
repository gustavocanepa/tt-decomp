extern "C" void func_001DF1C8(void *arg0, void *arg1);
extern "C" void func_001C75E0(void *arg0, void *arg1);

extern "C" void func_001C7598(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001DF1C8(s0, &local);
    func_001C75E0(s0, s1);
}
