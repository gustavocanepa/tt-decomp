#include "types.h"

struct func_0047EE40_arg0;

struct VEntry1 {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct VEntry0 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Inner_004ADBB8 {
    char pad0[0x98];
    s32 f98;
    char pad9c[0xC];
    char *vt;
};

struct Obj_004ADBB8 {
    char pad0[0x58];
    Inner_004ADBB8 **pp58;
    char pad5c[0x48];
    char *vt;
};

extern "C" s32 func_0047EE40(struct func_0047EE40_arg0 *arg0);
extern "C" void func_0047CE70(s32 arg0, void *arg1);
extern "C" void func_0047C9A8(Inner_004ADBB8 *o);

extern "C" void func_0047D488(Obj_004ADBB8 *arg0) {
    Inner_004ADBB8 *s0 = *arg0->pp58;
    if (func_0047EE40((struct func_0047EE40_arg0 *)s0) != 0) {
        VEntry1 *e = (VEntry1 *)(arg0->vt + 0x78);
        e->fn((char *)arg0 + e->delta, s0);
        func_0047CE70((s32)arg0, s0);
        func_0047C9A8(s0);
        s0->f98 = 0;
        VEntry0 *e2 = (VEntry0 *)(s0->vt + 0x48);
        e2->fn((char *)s0 + e2->delta);
    }
}
