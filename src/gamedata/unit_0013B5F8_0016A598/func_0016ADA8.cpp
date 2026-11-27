#include "types.h"

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_003F85C0(s32 arg0);

extern "C" s32 func_0016ADA8(Obj *arg0)
{
    return func_003F85C0(arg0->unk10);
}
