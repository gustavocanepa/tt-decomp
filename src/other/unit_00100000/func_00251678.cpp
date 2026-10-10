extern "C" void func_00278380(void *arg0, void *arg1);
extern "C" void func_002516C0(void *arg0, void *arg1);

extern "C" void func_00251678(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00278380(s0, &local);
    func_002516C0(s0, s1);
}
