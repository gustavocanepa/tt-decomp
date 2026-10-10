typedef int s32;

extern void *D_005D1230;
extern "C" void func_0038E308(void *, s32);
extern "C" void func_0050E1A8(void *);
struct VEntry_vcall_0 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_0(char *o, s32 a0) {
    VEntry_vcall_0 *e = (VEntry_vcall_0 *)(*(char **)(o + 0x14) + 0x8);
    e->fn(o + e->delta, a0);
}

struct RaceEventDisplay__structor_3_arg0 {
    char pad0[0x14];
    void *unk14;
};

extern "C" void RaceEventDisplay__structor_3(void *arg0, s32 arg1) {
    ((struct RaceEventDisplay__structor_3_arg0 *)arg0)->unk14 = &D_005D1230;
    if ((char *)arg0 + 0x50 != 0) {
        char *p0 = (char *)arg0 + 0xad0;
        while ((char *)arg0 + 0x50 != p0) {
            p0 -= 0x150;
            vcall_0((char *)p0, 0x2);
        }
    }
    func_0038E308(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_0050E1A8(arg0);
    }
}
