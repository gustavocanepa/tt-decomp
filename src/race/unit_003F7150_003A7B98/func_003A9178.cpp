#include "types.h"

struct Vec4 {
    f32 x, y, z, w;
};

struct Obj {
    Vec4 v[6];
};

extern "C" s32 func_003A9178(Obj *self) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (self->v[i].w > 0.0f) {
            return 0;
        }
    }
    return 1;
}
