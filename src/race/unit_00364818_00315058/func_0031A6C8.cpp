#include "types.h"

struct VEntry_00371CA8 {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

struct Obj_00371CA8 {
    VEntry_00371CA8 *vtbl;
};

extern "C" f32 func_0031A6C8(Obj_00371CA8 *arg0) {
    VEntry_00371CA8 *e = &arg0->vtbl[15];
    f32 v = e->fn((char *)arg0 + e->delta);

    return v * 0x1.8p4f / 0x1.F4p9f;
}
