#include "types.h"
struct VEntry { short delta; short index; float (*fn)(void *); };
struct VObj { char pad0[4]; char *vtbl; };
static inline float vcall(char *o) {
    VEntry *e = (VEntry *)(((VObj *)o)->vtbl + 0x70);
    return e->fn(o + e->delta);
}
extern "C" void func_001FB238(void *);
extern "C" void func_001FBAF0(s32, float, float);
extern "C" void func_001FB1E0(void *, s32);

struct Arg {
    s32 a;
    s32 b;
};

extern "C" void func_001FB430(s32 *arg0, void *arg1, s32 arg2, Arg *arg3) {
    s32 buf[4];
    if (arg2 == 2) {
        func_001FB238(buf);
        s32 s0 = buf[0];
        float f = vcall((char *)arg3->a);
        float g = vcall((char *)arg3->b);
        func_001FBAF0(s0, f, g);
        func_001FB1E0(buf, 2);
    }
}
