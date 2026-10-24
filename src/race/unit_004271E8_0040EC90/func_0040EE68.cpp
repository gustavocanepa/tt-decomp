extern char D_00585A30[];
extern char D_005FBEF0[];

extern "C" void func_0040EF20(char *a0, int a1);
extern "C" int func_004A8368(char *s);
extern "C" int func_004A64A8(char *str, unsigned int size, const char *fmt, ...);
extern "C" void *func_0047DB20(void *self, const char *path, int mode);

static inline char *step8(char *p) {
    return p + 8;
}

extern "C" int func_0040EE68(char *arg0, int arg1) {
    char obj[0x20];
    char *s0 = step8(D_00585A30);
    func_0040EF20(arg0, arg1);
    int n = func_004A8368(s0);
    char *buf = (char *)__builtin_alloca((((unsigned int)n + 0x26) >> 4) << 4);
    func_004A64A8(buf, n + 0x17, D_005FBEF0, s0, arg1);
    func_0047DB20(obj, buf, 1);
    if (*(int *)obj == 9) {
        return 0;
    }
    *(int *)(arg0 + 0xB0) = *(int *)(obj + 0x10);
    return 1;
}
