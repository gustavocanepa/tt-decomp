extern "C" void func_00241F88(void *arg0, void *arg1);
extern "C" void func_0026D828(void *arg0, void *arg1);

extern "C" void func_0026D7E0(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00241F88(s0, &local);
    func_0026D828(s0, s1);
}
