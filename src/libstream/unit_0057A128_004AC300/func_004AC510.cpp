#include "types.h"

struct Range {
    char pad0[4];
    s32 lo;
    s32 hi;
};

extern "C" void func_004AC488(Range *r);

extern "C" void func_004AC510(Range *arg0, s32 arg1) {
    s32 next = arg1 + 1;
    s32 lt;

    arg0->lo = arg1;
    lt = arg1 < arg0->hi;
    if (lt == 0) {
        arg0->hi = next;
    }
    func_004AC488(arg0);
}
