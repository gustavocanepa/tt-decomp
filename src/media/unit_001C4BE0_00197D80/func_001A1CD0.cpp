#include "types.h"

struct Obj1D1880 {
    char pad[4];
    s32 unk4;
};

extern "C" s32 func_004B99D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" s32 func_001A1CD0(Obj1D1880 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_004B99D8(arg0->unk4, arg1, arg2, arg4, arg3);
}
