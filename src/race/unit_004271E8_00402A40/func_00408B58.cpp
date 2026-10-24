#include "types.h"

struct Obj {
    char pad[0x4D8];
    s32 unk4D8;
};

extern "C" s32 func_00408B38(Obj *arg0, s32 arg1);

extern "C" s32 func_00408B58(Obj *arg0) {
    return func_00408B38(arg0, arg0->unk4D8);
}
