#include "types.h"

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_003FD408(s32 arg0);

extern "C" s32 func_0051BB68(Obj *arg0)
{
    return func_003FD408(arg0->unk10);
}
