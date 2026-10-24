extern "C" void func_003A49D0(const int *s, int *d);
extern "C" void func_003A4A00(int *d, const int *s);
extern "C" void func_0042FB00(void *a, int b, void *c);

extern "C" void func_003A4AE0(void *arg0, const void *arg1) {
    int tmp[8];
    func_003A49D0((const int *)arg0, tmp);
    __builtin_memcpy(arg0, arg1, 0x4540);
    func_003A4A00((int *)arg0, tmp);
    func_0042FB00((char *)arg0 + 0x14, ((int *)arg0)[1], arg0);
}
