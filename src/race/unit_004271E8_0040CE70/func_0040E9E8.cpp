#include "types.h"

struct Obj {
    char pad[0xF0];
    u64 unkF0;
} __attribute__((aligned(8)));

extern "C" s32 func_0040E9E8(Obj *arg0) {
    return ~arg0->unkF0 == 0;
}
