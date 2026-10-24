#include "types.h"

struct VEntry_003BCBD0 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, void *);
};

struct Obj_003BCBD0 {
    char pad0[0x64];
    VEntry_003BCBD0 *vtbl;
};

extern "C" int func_0033CA70(int arg0);

extern "C" int func_00374200(struct Obj_003BCBD0 *arg0, void *arg1) {
    VEntry_003BCBD0 *e = &arg0->vtbl[98];
    s32 r = e->fn((char *)arg0 + e->delta, arg1);

    return func_0033CA70(r);
}
