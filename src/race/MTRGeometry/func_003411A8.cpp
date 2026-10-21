#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

struct Obj {
    VEntry *vtbl;
};

extern "C" f32 func_003411A8(struct Obj *arg0) {
    VEntry *e = &arg0->vtbl[41];

    return -e->fn((char *)arg0 + e->delta);
}
