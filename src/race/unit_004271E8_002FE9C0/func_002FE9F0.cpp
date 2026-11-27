#include "types.h"

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_002FE9D8(s32 arg0);

extern "C" s32 func_002FE9F0(Obj *arg0)
{
    return func_002FE9D8(arg0->unk10);
}
