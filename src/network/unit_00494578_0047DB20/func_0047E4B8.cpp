/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" signed char *func_0047E188(signed char *) throw();
extern "C" signed char *func_0047E1C8(signed char *) throw();
extern "C" s32 func_004A8368(const char *) throw();
extern "C" void func_004F8588(void *, void *, s32) throw();
extern "C" signed char *func_0047E4B8(signed char *arg0, signed char *arg1) {
    signed char *p = func_0047E188(arg1);
    signed char *dst = arg0 + func_004A8368((const char *)arg0);
    while (*p != 0) {
        signed char *e = func_0047E1C8(p);
        s32 n = e - p;
        if (n == 0) break;
        *dst = 0x2F;
        dst++;
        signed char *d = dst;
        dst += n;
        func_004F8588(d, p, n);
        p = func_0047E188(e);
    }
    *dst = 0;
    return arg0;
}
