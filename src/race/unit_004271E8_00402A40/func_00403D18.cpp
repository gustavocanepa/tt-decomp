#include "types.h"

struct Obj {
    char pad[0x11];
    s8 unk11;
};

extern "C" s32 func_00403D18(s32 arg0, u32 arg1) {
    if (arg1 < 0xCU) {
        return ((Obj *)(arg1 + arg0))->unk11;
    }
    return -1;
}
