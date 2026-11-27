#include "types.h"

struct Obj {
    char pad[8];
    s32 unk8;
};

extern "C" u8 func_0036E768(Obj *arg0, s32 arg1) {
    u8 r = *((u8 *)arg0 + 9);
    if (arg1 != 0) {
        arg0->unk8 = arg0->unk8 & 0xFFFF00FF;
    }
    return r;
}
