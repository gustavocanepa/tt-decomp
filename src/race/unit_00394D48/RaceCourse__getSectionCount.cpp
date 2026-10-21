#include "types.h"

struct S00395200 {
    char pad0[0x4];
    s32 unk4;
};

struct S00396800_ret {
    char pad0[0x54];
    u16 unk54;
};

extern "C" struct S00396800_ret *func_0034C5E8(s32 arg0);

extern "C" u16 RaceCourse__getSectionCount(struct S00395200 *arg0) {
    return func_0034C5E8(arg0->unk4)->unk54;
}
