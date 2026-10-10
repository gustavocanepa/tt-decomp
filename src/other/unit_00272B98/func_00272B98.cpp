extern "C" void func_00201C68(void *arg0, void *arg1);
extern "C" void func_00272BE0(void *arg0, void *arg1);

extern "C" void func_00272B98(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00201C68(s0, &local);
    func_00272BE0(s0, s1);
}
