#include "types.h"

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_00418C48(s32 arg0);

extern "C" s32 func_005668B8(Obj *arg0)
{
    return func_00418C48(arg0->unk4);
}
