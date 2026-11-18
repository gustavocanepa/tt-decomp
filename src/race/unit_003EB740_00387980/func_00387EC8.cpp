#include "types.h"

struct Obj16 {
    char pad[0x10];
};

struct In {
    s32 f0;
    float f4;
};

struct Out {
    s32 f0;
    float v[9];
    s32 f28;
    float f2C;
};

struct F9 {
    float v[9];
};

extern "C" void func_003EEC90(void *o);
extern "C" void func_003EECA0(void *o, int a, int b);
extern "C" int func_003EF148(void *o, void *out, int a, int b, float f0, float f1);
extern "C" int func_003EF708(void *o, void *out, int a, int b, float f0, float f1);

extern "C" void func_00387EC8(In *in, void *arg1, void *arg2, Out *out) {
    Obj16 o;
    F9 tmp;
    float tmp2;
    if (arg1 == 0 || in->f0 < 0) {
        out->f0 = 0;
        out->f28 = 0;
        return;
    }
    func_003EEC90(&o);
    func_003EECA0(&o, 0, (int)arg1);
    if (func_003EF148(&o, &tmp, in->f0, 0, in->f4, 0.0f) == 0) {
        out->f0 = 0;
    } else {
        out->f0 = 1;
        out->v[0] = tmp.v[0];
        out->v[1] = tmp.v[1];
        out->v[2] = tmp.v[2];
        out->v[3] = tmp.v[3];
        out->v[4] = tmp.v[4];
        out->v[5] = tmp.v[5];
        out->v[6] = tmp.v[6];
        out->v[7] = tmp.v[7];
        out->v[8] = tmp.v[8];
    }
    if (func_003EF708(&o, &tmp2, in->f0, 0, in->f4, 0.0f) == 0) {
        out->f28 = 0;
        return;
    }
    out->f28 = 1;
    out->f2C = tmp2;
}
