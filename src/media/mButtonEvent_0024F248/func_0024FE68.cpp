extern "C" void func_001B7F10(void *arg0, void *arg1);
extern "C" void func_0024FEB0(void *arg0, void *arg1);

extern "C" void func_0024FE68(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001B7F10(s0, &local);
    func_0024FEB0(s0, s1);
}
