extern "C" void func_001EEF30(void *arg0, void *arg1);
extern "C" void func_001F0348(void *arg0, void *arg1);

extern "C" void func_001F0300(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001EEF30(s0, &local);
    func_001F0348(s0, s1);
}
