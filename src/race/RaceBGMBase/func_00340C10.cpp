#include "types.h"

struct Obj {
    char pad[0x4];
    u32 unk4;
};

extern "C" s32 func_00340B40(Obj *arg0, s32 arg1);

extern "C" s32 func_00340C10(Obj *arg0) {
    return func_00340B40(arg0, arg0->unk4 != 0);
}
