#include "types.h"

extern char D_00585680;
extern char D_005D8DC8;

struct func_003FEC08_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" void func_003FEC08(struct func_003FEC08_arg0 *arg0) {
    s32 hi = (s32)&D_005D8DC8;
    s32 lo = (s32)&D_00585680;
    arg0->unk0 = lo;
    arg0->unkC = hi;
    arg0->unk4 = lo;
    arg0->unk8 = lo;
}
