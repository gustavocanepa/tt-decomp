#include "types.h"

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_003FDA88(s32 arg0);

extern "C" s32 func_0051B448(Obj *arg0)
{
    return func_003FDA88(arg0->unk10);
}
