#include "types.h"

struct Obj { char pad[0x18]; u32 unk18; };

extern "C" void func_004C26B0(Obj *arg0) {
    arg0->unk18 = arg0->unk18 | 1;
}
