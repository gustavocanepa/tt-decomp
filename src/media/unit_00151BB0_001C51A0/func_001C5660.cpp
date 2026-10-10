extern "C" void func_001FCAD0(void *arg0, void *arg1);
extern "C" void func_001C56A8(void *arg0, void *arg1);

extern "C" void func_001C5660(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001FCAD0(s0, &local);
    func_001C56A8(s0, s1);
}
