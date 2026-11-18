#include "types.h"

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_003FDAE8(s32 arg0);

extern "C" s32 func_0051B6D0(Obj *arg0)
{
    return func_003FDAE8(arg0->unk10);
}
