extern "C" void func_002BC2C8(void *arg0, void *arg1);
extern "C" void func_002A6378(void *arg0, void *arg1);

extern "C" void func_002A6330(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002BC2C8(s0, &local);
    func_002A6378(s0, s1);
}
