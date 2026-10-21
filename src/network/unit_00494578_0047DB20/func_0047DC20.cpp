#include "types.h"

struct Pair {
    s32 a;
    s32 b;
};

extern "C" void func_0047DD30(void *self, s32 x, Pair *p, s32 y, s32 z);

extern "C" void *func_0047DC20(void *self, s32 x, s32 y, s32 z) {
    Pair p;
    p.a = 0;
    p.b = 0;
    func_0047DD30(self, x, &p, y, z);
    return self;
}
