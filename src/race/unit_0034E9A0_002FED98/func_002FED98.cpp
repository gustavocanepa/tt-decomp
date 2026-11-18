#include "types.h"

struct Obj0035A458 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_002FEBC0(s32 arg0);

extern "C" s32 func_002FED98(struct Obj0035A458 *arg0) {
    return func_002FEBC0(arg0->unk10) != 0;
}
