#include "types.h"

struct Obj {
    char pad[0x1F8];
    s32 unk1F8;
    s32 unk1FC;
};

extern "C" s32 func_0046F558(void) {
    Obj *p = (Obj *)0x70002000;
    return p->unk1FC - p->unk1F8;
}
