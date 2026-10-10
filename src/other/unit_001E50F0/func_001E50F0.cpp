extern "C" void func_001E4920(void *arg0, void *arg1);
extern "C" void func_001E4F30(void *arg0, void *arg1);

extern "C" void func_001E50F0(void *arg0) {
    void *s0 = arg0;
    int local;

    func_001E4920(&local, s0);
    func_001E4F30(s0, &local);
}
