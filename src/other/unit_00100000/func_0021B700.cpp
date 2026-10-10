extern "C" void func_001B7F10(void *arg0, void *arg1);
extern "C" void func_0021B748(void *arg0, void *arg1);

extern "C" void func_0021B700(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001B7F10(s0, &local);
    func_0021B748(s0, s1);
}
