extern "C" void func_00202758(void *arg0, void *arg1);
extern "C" void func_00246260(void *arg0, void *arg1);

extern "C" void func_00246218(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00202758(s0, &local);
    func_00246260(s0, s1);
}
