#include "types.h"

struct S { char pad[0x12]; u8 unk12; };

extern "C" s32 func_0039F070(S *arg0) {
    return arg0->unk12 == 2;
}
