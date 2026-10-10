extern "C" void func_001D7B90(void *arg0, void *arg1);
extern "C" void func_001DB310(void *arg0, void *arg1);

extern "C" void func_001DB2C8(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001D7B90(s0, &local);
    func_001DB310(s0, s1);
}
