extern "C" void func_001FBD88(void *arg0, void *arg1);
extern "C" void func_002273F0(void *arg0, void *arg1);

extern "C" void func_002273A8(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001FBD88(s0, &local);
    func_002273F0(s0, s1);
}
