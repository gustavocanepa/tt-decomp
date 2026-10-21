/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
extern "C" int func_003F84B8(int, int) throw();
extern "C" int func_003F86F8(int, char *) throw();
extern "C" int func_004A64A8(char *, u32, const char *, ...);

extern "C" int func_003F8A40(int self, int a, const char *fmt, int flag, int start, int limit) {
    char buf[0x40];
    int r = 0;
    int mask = flag & 0xFF;
    int i;
    if (limit < start) return r;
    for (i = start; i <= limit; i++) {
        func_004A64A8(buf, 0x40, fmt, a, i);
        r = func_003F86F8(self, buf);
        if (r == 0) return r;
        r = func_003F84B8(r, mask);
        if (r == 0) return r;
    }
    return 1;
}
