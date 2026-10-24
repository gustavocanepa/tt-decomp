#include "types.h"

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_003EEBE8(s32 arg0);

extern "C" s32 func_003F1710(Obj *arg0)
{
    return func_003EEBE8(arg0->unk4);
}
