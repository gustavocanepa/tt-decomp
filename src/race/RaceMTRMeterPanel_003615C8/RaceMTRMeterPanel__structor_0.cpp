/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
typedef short s16;
typedef unsigned int u32;
struct VEntry {
    s16 delta;
    s16 pad;
    void (*fn)(void *, s32, s32);
};
struct Meter {
    char pad0[0x14];
    char *vt;
    char pad18[0x70 - 0x18];
};
struct Self {
    char pad0[0x14];
    char *vt;
    s32 unk18;
    s32 unk1C;
    Meter m[4];
};
extern char D_005D0990[];
extern "C" s32 RaceDisplayObjectBase__structor_0(void *);
extern "C" void RaceMTRMeter__structor_0(void *) throw();
extern "C" void func_003615B8(void *, int) throw();

static inline void vc(Meter *m, s32 off, s32 a, s32 b) {
    VEntry *e = (VEntry *)(m->vt + off);
    e->fn((char *)m + e->delta, a, b);
}

extern "C" void RaceMTRMeterPanel__structor_0(Self *arg0) {
    s32 i;
    Meter *p;
    p = arg0->m;
    RaceDisplayObjectBase__structor_0(arg0);
    arg0->vt = D_005D0990;
    for (i = 3; i != -1; i--) {
        RaceMTRMeter__structor_0(p);
        p++;
    }
    arg0->unk1C = 0;
    arg0->unk18 = 0;
    p = arg0->m;
    i = 0;
    do {
        func_003615B8(p, i);
        i++;
        vc(p, 0x38, 0, 0);
        vc(p, 0x40, 0x80, 0x80);
        vc(p, 0x48, 0, 0);
        p++;
    } while (i < 4);
}
