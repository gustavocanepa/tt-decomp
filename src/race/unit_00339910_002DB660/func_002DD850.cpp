#include "types.h"

struct Key {
    float v[17];
};

struct Obj {
    int unk0;
    Key keys[2];
    int current;
};

extern "C" void func_002DD6C8(float *out, s32 n, const float *a, const float *b, float t);

extern "C" float func_002DD850(Obj *o, float t) {
    float o1[4];
    float o2[4];
    float sum;
    float r;

    func_002DD6C8(o1, 3, o->keys[1 - o->current].v, o->keys[o->current].v, t);
    func_002DD6C8(o2, 3, o->keys[1 - o->current].v + 3, o->keys[o->current].v + 3, t);

    float d0 = o2[0] - o1[0];
    float d1 = o2[1] - o1[1];
    float d2 = o2[2] - o1[2];
    sum = d0 * d0 + d1 * d1 + d2 * d2;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(sum));
    return r;
}
