struct S003789E8 {
    char pad[4];
    int unk4;
};

extern "C" void func_0031A3E0(void *arg0);
extern "C" void func_003A5F88(void *arg0, int arg1);
extern "C" void func_0031A3E8(void *arg0, void *arg1);

extern "C" void func_00321620(void *arg0, void *arg1, void *arg2, S003789E8 *arg3) {
    void *s0 = (char *) arg0 + 0xEA8;
    void *s1 = (char *) arg0 + 0xF00;
    if (arg3->unk4 != 0) {
        func_0031A3E0(s1);
    }
    func_003A5F88(s0, 1);
    func_0031A3E8(s1, s0);
}
