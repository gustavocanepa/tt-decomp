#include "types.h"

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_002E5CF8(s32 arg0);

extern "C" s32 func_0037BB10(Obj *arg0)
{
    return func_002E5CF8(arg0->unk4);
}
