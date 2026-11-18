#include "types.h"

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_003FD9C8(s32 arg0);

extern "C" s32 func_0051BAB8(Obj *arg0)
{
    return func_003FD9C8(arg0->unk10);
}
