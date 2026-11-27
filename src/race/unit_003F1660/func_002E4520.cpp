#include "types.h"

struct S { char pad[0x83]; u8 unk83; };

extern "C" u32 func_002E4520(S *arg0, s32 arg1) {
    return (u32)(arg1 * arg0->unk83) >> 7;
}
