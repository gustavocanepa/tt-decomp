#include "types.h"

struct Obj {
    char pad[4];
    s32 unk4;
};

extern "C" s32 func_002E62F8(s32 arg0, s8 arg1);

extern "C" s32 func_0037B8F0(Obj *arg0, s32 arg1) {
    char *p = (char *)arg0 + arg1;
    return func_002E62F8(arg0->unk4, *(s8 *)(p + 0xC));
}
