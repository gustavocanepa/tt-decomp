extern "C" void func_002A7578(void *arg0, void *arg1);
extern "C" void func_0023C568(void *arg0, void *arg1);

extern "C" void func_0023C520(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002A7578(s0, &local);
    func_0023C568(s0, s1);
}
