#include "types.h"

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_002F0550(s32 arg0);

extern "C" s32 func_002E4C98(Obj *arg0)
{
    return func_002F0550(arg0->unk4);
}
