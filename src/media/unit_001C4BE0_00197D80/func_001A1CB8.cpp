#include "types.h"

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_004B8BF8(s32 arg0);

extern "C" s32 func_001A1CB8(Obj *arg0)
{
    return func_004B8BF8(arg0->unk4);
}
