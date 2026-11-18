#include "types.h"

struct S { char pad[0x30]; u8 unk30; };

extern "C" s32 func_002E6BF8(S *arg0) {
    return arg0->unk30 == 7;
}
