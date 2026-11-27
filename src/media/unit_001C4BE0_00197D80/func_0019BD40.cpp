#include "types.h"

struct VEntry001CC8F8 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj001CC8F8 {
    VEntry001CC8F8 *vtbl;
};

extern "C" s32 func_0019BD40(struct Obj001CC8F8 *arg0) {
    VEntry001CC8F8 *e = &arg0->vtbl[10];

    return e->fn((char *)arg0 + e->delta) == 0;
}
