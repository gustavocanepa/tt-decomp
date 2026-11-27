#include "types.h"

struct S { char pad[0x1C]; u8 unk1C; };

extern "C" s32 func_0042FD80(S *arg0) {
    return arg0->unk1C == 4;
}
