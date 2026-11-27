#include "types.h"

struct VEntry_D8 {
    s16 delta;
    s16 index;
    void *(*fn)(void *, void *);
};

struct VEntry_120 {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

extern "C" f32 func_00417158(void);

extern "C" f32 func_0031A850(char *arg0) {
    f32 temp_f20;
    void *obj;
    VEntry_D8 *e;
    void *r;

    temp_f20 = func_00417158();
    obj = *(void **)(arg0 + 0xA4C);
    e = (VEntry_D8 *)(*(char **)arg0 + 0xE0);
    r = e->fn(arg0 + e->delta, obj);
    if (r != 0) {
        VEntry_120 *e2 = (VEntry_120 *)(*(char **)r + 0x138);
        temp_f20 = e2->fn((char *)r + e2->delta);
    }
    return temp_f20;
}
