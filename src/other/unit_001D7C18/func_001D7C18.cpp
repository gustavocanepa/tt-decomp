extern "C" void func_002A2740(void *arg0, void *arg1);
extern "C" void func_001D7C60(void *arg0, void *arg1);

extern "C" void func_001D7C18(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002A2740(s0, &local);
    func_001D7C60(s0, s1);
}
