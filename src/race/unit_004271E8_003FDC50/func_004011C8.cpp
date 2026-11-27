#include "types.h"

struct VEntry43 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VObj43 {
    VEntry43 *vtbl;
};

struct Arg43 {
    s32 magic;
    s32 a;
    s32 b;
};

extern "C" s32 func_00400CA0(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_004011C8(void *arg0, void *arg1) {
    Arg43 *p = (Arg43 *)arg1;
    VObj43 *o = (VObj43 *)arg0;
    VEntry43 *e;
    s32 r;
    s32 neg;

    if (p->magic == 0xFF60BAD3 && func_00400CA0((s32)p + 0x10, -p->a, p->b) != 0) {
        neg = -p->a;
        e = &o->vtbl[2];
        r = e->fn((char *)o + e->delta);
        if (neg == r - 0x10) {
            return 1;
        }
    }
    return 0;
}
