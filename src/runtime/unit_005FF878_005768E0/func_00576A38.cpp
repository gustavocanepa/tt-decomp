#include "types.h"

struct Obj {
    char pad[0x38];
    s32 unk38;
};

extern "C" s32 func_00576A38(Obj *arg0) {
    s32 v = arg0->unk38;
    typedef unsigned int u32;
    return (((u32)~v >> 31) == 0) ? -1 : v;
}
