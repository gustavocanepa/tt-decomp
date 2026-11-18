#include "types.h"

struct Pair {
    s32 unk0;
    s32 unk4;
};

extern "C" s32 func_0019C308(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" s32 func_0019E648(s32 arg0, s32 arg1, struct Pair *arg2, s32 arg3) {
    return func_0019C308(arg0, arg1, arg2->unk0, arg2->unk4, arg3) == 0;
}
