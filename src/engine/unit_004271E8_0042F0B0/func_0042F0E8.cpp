#include "types.h"

extern "C" void func_0042F140(s32 arg0, s32 arg1, void *arg2, s32 arg3);

struct Pair {
    s32 a;
    s32 b;
};

extern "C" void func_0042F0E8(s32 arg0, s32 arg1) {
    Pair local;
    local.a = 0;
    local.b = 0;
    func_0042F140(arg0, arg1, &local, 1);
}
