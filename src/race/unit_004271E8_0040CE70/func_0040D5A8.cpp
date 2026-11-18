extern void *D_00585C1C;

extern "C" int func_0040D428(void *a0, int a1, void *out);
extern "C" void func_00411D78(void *a0, int a1);

extern "C" void func_0040D5A8(void *arg0, int arg1) {
    unsigned char buf[0x40];
    func_0040D428(arg0, arg1, buf);
    func_00411D78(D_00585C1C, *(int *)(buf + 0xC));
}
