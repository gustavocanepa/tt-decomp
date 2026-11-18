#include "types.h"

struct Mtx { f32 m[16]; };

extern "C" void func_00101C28(Mtx *o) {
    o->m[0] = 1.0f;
    o->m[1] = 0.0f;
    o->m[2] = 0.0f;
    o->m[3] = 0.0f;
    o->m[4] = 0.0f;
    o->m[5] = 1.0f;
    o->m[6] = 0.0f;
    o->m[7] = 0.0f;
    o->m[8] = 0.0f;
    o->m[9] = 0.0f;
    o->m[10] = 1.0f;
    o->m[11] = 0.0f;
    o->m[12] = 0.0f;
    o->m[13] = 0.0f;
    o->m[14] = 0.0f;
    o->m[15] = 1.0f;
}
