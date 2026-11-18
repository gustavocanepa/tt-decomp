#include "types.h"

struct Obj {
    char pad0[0x10D8];
    s32 unk10D8;
};

extern "C" s32 func_003F79D0(s32 arg0);

extern "C" s32 func_003FD128(Obj *arg0)
{
    return func_003F79D0(arg0->unk10D8);
}
