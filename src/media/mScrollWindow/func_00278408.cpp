extern "C" void func_001B7F10(void *arg0, void *arg1);
extern "C" void func_00278450(void *arg0, void *arg1);

extern "C" void func_00278408(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001B7F10(s0, &local);
    func_00278450(s0, s1);
}
