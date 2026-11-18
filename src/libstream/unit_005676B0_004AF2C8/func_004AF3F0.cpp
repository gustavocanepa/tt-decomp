#include "types.h"

struct Pair {
    s32 a;
    s32 b;
};

extern "C" void func_004AF420(void *self, Pair *p, s32 arg, s32 extra);

extern "C" void func_004AF3F0(void *self, s32 x, s32 y) {
    Pair p;
    p.a = 0;
    p.b = 0;
    func_004AF420(self, &p, x, y);
}
