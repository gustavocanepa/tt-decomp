extern "C" void func_001FBD88(void *arg0, void *arg1);
extern "C" void func_00219970(void *arg0, void *arg1);

extern "C" void func_00219928(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001FBD88(s0, &local);
    func_00219970(s0, s1);
}
