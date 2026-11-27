#include "types.h"

struct Obj {
    char pad[0x1D];
    s8 unk1D;
};

extern "C" s32 func_00403D60(s32 arg0, u32 arg1) {
    if (arg1 < 0x10U) {
        return ((Obj *)(arg1 + arg0))->unk1D;
    }
    return -1;
}
