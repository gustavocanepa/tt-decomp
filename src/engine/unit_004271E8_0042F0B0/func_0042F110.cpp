#include "types.h"

struct Pair {
    s32 a;
    s32 b;
};

extern "C" void func_0042F140(void *self, Pair *p, s32 arg, s32 n);

extern "C" void func_0042F110(void *self, s32 arg) {
    Pair p;
    p.a = 0;
    p.b = 0;
    func_0042F140(self, &p, arg, 1);
}
