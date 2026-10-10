extern "C" void func_001EEF30(void *arg0, void *arg1);
extern "C" void func_00216420(void *arg0, void *arg1);

extern "C" void func_002163D8(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001EEF30(s0, &local);
    func_00216420(s0, s1);
}
