typedef int s32;

extern "C" s32 func_003F84E0(void *arg0);
extern "C" void *func_003F86F8(void *arg0, char *arg1);
extern "C" int func_004A64A8(char *buf, int n, const char *fmt, ...);

extern "C" s32 func_003F8990(void *ctx, const char *name, const char *fmt, s32 first, s32 last) {
    char buf[64];
    s32 i;
    for (i = first; i <= last; i++) {
        void *p;
        func_004A64A8(buf, 0x40, fmt, name, i);
        p = func_003F86F8(ctx, buf);
        if (p == 0) {
            return 0;
        }
        if (func_003F84E0(p) == 0) {
            return 0;
        }
    }
    return 1;
}
