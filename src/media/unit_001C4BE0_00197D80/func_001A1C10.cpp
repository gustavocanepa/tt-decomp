#include "types.h"

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_004B8C80(s32 arg0);

extern "C" s32 func_001A1C10(Obj *arg0)
{
    return func_004B8C80(arg0->unk4);
}
