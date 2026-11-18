#include "types.h"

struct Obj {
    char pad[0x4];
    u16 unk4;
};

extern "C" Obj *func_00418AB8(s32 arg0, s32 arg1);

extern "C" u16 func_00418AE8(s32 arg0) {
    return func_00418AB8(arg0, 0)->unk4;
}
