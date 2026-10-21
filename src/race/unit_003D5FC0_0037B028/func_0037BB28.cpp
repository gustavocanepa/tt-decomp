#include "types.h"

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_002E5CB8(s32 arg0);

extern "C" s32 func_0037BB28(Obj *arg0)
{
    return func_002E5CB8(arg0->unk4);
}
