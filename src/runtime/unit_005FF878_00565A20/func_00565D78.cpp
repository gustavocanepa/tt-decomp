#include "types.h"

struct Obj {
    char pad0[0x92];
    u8 unk92;
};

extern "C" s32 func_00565D78(Obj *arg0) {
    return arg0->unk92 * 10;
}
