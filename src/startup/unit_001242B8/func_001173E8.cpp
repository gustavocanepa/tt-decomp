#include "types.h"

struct Obj {
    char pad[0x458];
    s32 unk364;
};

extern "C" s32 D_00579774;

extern "C" s32 func_001173E8(s32 arg0, s32 arg1) {
    return ((Obj *)(D_00579774 + arg1 * 4))->unk364;
}
