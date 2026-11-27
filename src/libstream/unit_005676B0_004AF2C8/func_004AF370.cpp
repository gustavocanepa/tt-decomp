#include "types.h"

extern "C" void func_004AF398(void *arg0, s32 arg1);

struct Pair {
    s32 a;
    s32 b;
};

extern "C" void func_004AF370(s32 arg0) {
    Pair local;
    local.a = 0;
    local.b = 0;
    func_004AF398(&local, arg0);
}
