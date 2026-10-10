typedef int s32;

extern void *D_005D9068;
extern "C" void func_00400D78(void *, s32);
extern "C" void func_0050E1A8(void *);
struct VEntry_vcall_0 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_0(char *o, s32 a0) {
    VEntry_vcall_0 *e = (VEntry_vcall_0 *)(*(char **)(o + 0x0) + 0x8);
    e->fn(o + e->delta, a0);
}

extern "C" void func_00563D58(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x0) = &D_005D9068;
    if ((char *)arg0 + 0xC != 0) {
        char *p0 = (char *)arg0 + 0xDC;
        while ((char *)arg0 + 0xC != p0) {
            p0 -= 0x34;
            vcall_0((char *)p0, 0x2);
        }
    }
    func_00400D78(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_0050E1A8(arg0);
    }
}
