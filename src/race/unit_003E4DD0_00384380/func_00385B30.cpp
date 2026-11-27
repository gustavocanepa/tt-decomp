#include "types.h"

struct S { char pad[4]; s32 unk4; };

extern "C" s32 func_00385B30(S *arg0) {
    return arg0->unk4 != 0;
}
