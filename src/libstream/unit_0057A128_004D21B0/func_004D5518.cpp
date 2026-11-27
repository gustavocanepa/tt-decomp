#include "types.h"

struct Obj { char pad[0x14]; u8 unk14; };

extern "C" s32 func_004D5518(Obj *arg0, Obj *arg1) {
    return arg0->unk14 - arg1->unk14;
}
