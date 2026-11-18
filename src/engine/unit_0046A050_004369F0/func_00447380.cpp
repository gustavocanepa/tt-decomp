#include "types.h"

struct Obj {
    char pad0[0x60];
    s32 unk60;
};

extern "C" s32 func_0043B610(s32 arg0);

extern "C" s32 func_00447380(Obj *arg0)
{
    return func_0043B610(arg0->unk60);
}
