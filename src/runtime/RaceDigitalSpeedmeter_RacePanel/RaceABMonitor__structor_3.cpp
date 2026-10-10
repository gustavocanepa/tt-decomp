typedef int s32;

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, s32);
};

extern void *D_005D0580;
extern void *D_005D0FB8;
extern void *D_005D0E28;
extern void *D_005D0D78;
extern void *D_005D0E88;
extern void *D_005D0EF0;
extern void *D_005D0F50;
extern void *D_005D5CB8;
extern void *D_005D1128;
extern void *D_005D0D20;
extern void *D_005D1450;
extern void *D_005D06C8;
extern "C" void func_0038E308(void *, s32);
extern "C" void func_0035A650(void *, s32);
extern "C" void func_0050E1A8(void *);

static inline void destroy(char *m, void *vtbl) {
    *(void **)(m + 0x14) = vtbl;
    func_0038E308(m, 0);
}

static inline void ab_monitor(char *m) {
    *(void **)(m + 0x14) = &D_005D0D78;
    if (m + 0x20 != 0) {
        char *p0 = m + 0x80;
        while (m + 0x20 != p0) {
            VEntry *e;
            p0 -= 0x30;
            e = (VEntry *)(*(char **)(p0 + 0x14) + 0x8);
            e->fn(p0 + e->delta, 2);
        }
    }
    func_0038E308(m, 0);
}

extern "C" void RaceABMonitor__structor_3(void *arg0, s32 arg1) {
    char *self = (char *)arg0;
    *(void **)(self + 0x14) = &D_005D0580;
    destroy(self + 0x328, &D_005D0FB8);
    destroy(self + 0x2E4, &D_005D0FB8);
    destroy(self + 0x2A0, &D_005D0FB8);
    destroy(self + 0x274, &D_005D0E28);
    ab_monitor(self + 0x1F4);
    destroy(self + 0x1B8, &D_005D0E88);
    destroy(self + 0x160, &D_005D0EF0);
    destroy(self + 0x128, &D_005D0F50);
    destroy(self + 0x104, &D_005D5CB8);
    destroy(self + 0xD4, &D_005D1128);
    destroy(self + 0xAC, &D_005D0D20);
    destroy(self + 0x84, &D_005D0D20);
    destroy(self + 0x4C, &D_005D1450);
    func_0035A650(self + 0x30, 2);
    *(void **)(self + 0x14) = &D_005D06C8;
    func_0038E308(self, 0);
    if ((arg1 & 0x1) != 0) {
        return func_0050E1A8(self);
    }
}
