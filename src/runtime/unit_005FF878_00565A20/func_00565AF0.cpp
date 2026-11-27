#include "types.h"

struct Obj {
    char pad0[0x1E8];
    s32 unk1E8;
};

extern "C" s64 func_00411D78(s32 arg0);

extern "C" s64 func_00565AF0(Obj *arg0) {
    return func_00411D78(arg0->unk1E8);
}
