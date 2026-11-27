#include "types.h"

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_002E6A80(s32 arg0);

extern "C" s32 func_002E68E0(Obj *arg0)
{
    return func_002E6A80(arg0->unk10);
}
