#include "types.h"

struct Obj {
    char pad0[8];
    s32 unk8;
};

extern "C" s32 func_00418C48(s32 arg0);

extern "C" s32 func_005668E8(Obj *arg0)
{
    return func_00418C48(arg0->unk8);
}
