#include "types.h"

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_00315458(s32 arg0);

extern "C" s32 func_00315530(Obj *arg0)
{
    return func_00315458(arg0->unk10);
}
