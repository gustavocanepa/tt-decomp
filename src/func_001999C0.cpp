/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned short u16;

struct VE3480 {
    short delta;
    short index;
    void *fn;
};

extern "C" void func_0019B420(void *arg0, void *arg1);
extern "C" void *exception__structor_0(s32 arg0);
extern char D_005AD1E0[];

extern "C" s32 func_001999C0(void *arg0, s32 arg1) {
    char *q = (char *)arg0 + arg1 * 4;
    void **s2 = (void **)(q + 0x34);
    char *s0 = (char *)*s2;
    unsigned int fl = *(u16 *)(s0 + 0x48);
    if (((fl >> 1) & 1) == 0) {
        VE3480 *e = (VE3480 *)(*(char **)(s0 + 0x4C) + 0x48);
        if (((s32 (*)(void *, void *))e->fn)(s0 + e->delta, *(void **)((char *)arg0 + 0x30)) == 0) {
            char *n = (char *)exception__structor_0(0x50);
            func_0019B420(n, s0);
            *(void **)(n + 0x4C) = D_005AD1E0;
            if (*s2 != 0) {
                char *a2 = (char *)*s2;
                VE3480 *e2 = (VE3480 *)(*(char **)(a2 + 0x4C) + 8);
                ((void (*)(void *, void *))e2->fn)(a2 + e2->delta, (void *)3);
            }
            *s2 = n;
        }
        return 1;
    }
    return 0;
}
