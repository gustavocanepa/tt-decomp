#include "types.h"

struct Obj0060D650 {
    char pad7C[0x7C];
    s32 unk7C;
    s32 unk80;
};

extern "C" s32 func_00488BF8(Obj0060D650 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" s32 func_00570EF0(Obj0060D650 *arg0, s32 arg1, s32 arg2) {
    return func_00488BF8(arg0, arg0->unk7C, arg0->unk80, arg1, arg2);
}
