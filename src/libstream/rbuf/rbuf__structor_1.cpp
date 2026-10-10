typedef int s32;

extern void *D_005DB208;
extern "C" void func_004C26C0(void *);
extern "C" void func_004A45D0(void *);
extern "C" void func_0050E1A8(void *);
struct VEntry_vcall_0 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_0(char *o, s32 a0) {
    VEntry_vcall_0 *e = (VEntry_vcall_0 *)(*(char **)(o + 0x1c) + 0x8);
    e->fn(o + e->delta, a0);
}

extern "C" void rbuf__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x40) = &D_005DB208;
    func_004C26C0(arg0);
    if (*(void **)(arg0) != 0) {
        vcall_0((char *)*(void **)(arg0), 0x3);
    }
    func_004A45D0(*(void **)((char *)arg0 + 0x1c));
    if ((arg1 & 0x1) != 0) {
        return func_0050E1A8(arg0);
    }
}
