#include "types.h"

struct Obj {
    s32 unk0;
    s32 unk4;
};

extern "C" s32 func_001A3A70(Obj *arg0) {
    return (arg0->unk4 - arg0->unk0) + 0x8006;
}
