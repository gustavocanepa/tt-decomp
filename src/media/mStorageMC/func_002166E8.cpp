#include "types.h"

struct Obj002768A8 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_004BA550(s32 arg0);

extern "C" s32 func_002166E8(struct Obj002768A8 *arg0) {
    return func_004BA550(arg0->unk10 - 1);
}
