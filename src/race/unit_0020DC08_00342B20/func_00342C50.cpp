#include "types.h"

struct Obj_0038E228 {
    char pad0[0x1C];
    char *inner;
};

struct VE0_0038E228 {
    s16 delta;
    s16 index;
    f32 (*fn)(void *self);
};

struct VE1_0038E228 {
    s16 delta;
    s16 index;
    f32 (*fn)(void *self, f32 x);
};

static inline f32 call0_0038E228(Obj_0038E228 *self, int off) {
    char *o = self->inner;
    VE0_0038E228 *e = (VE0_0038E228 *)(*(char **)o + off);
    return e->fn(o + e->delta);
}

static inline f32 call1_0038E228(Obj_0038E228 *self, int off, f32 f) {
    char *o = self->inner;
    VE1_0038E228 *e = (VE1_0038E228 *)(*(char **)o + off);
    return e->fn(o + e->delta, f);
}

extern "C" f32 func_00342C50(Obj_0038E228 *self, f32 fparg) {
    if (call0_0038E228(self, 0xD0) == 0.0f) {
        if (call1_0038E228(self, 0xD8, fparg) == 0.0f) {
            if (call1_0038E228(self, 0xE0, fparg) == 0.0f)
                return 0.5f;
        }
    }
    return call1_0038E228(self, 0xD8, fparg);
}
