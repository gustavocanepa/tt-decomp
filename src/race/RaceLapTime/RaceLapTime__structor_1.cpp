#include "types.h"

struct S {
    char pad0[0xFB4];
    s32 unkFB4;
};

extern "C" void func_0050E1A8(s32 arg0);
extern char D_005D2748;

extern "C" void RaceLapTime__structor_1(S *arg0, s32 arg1)
{
    arg1 = arg1 & 1;
    arg0->unkFB4 = (s32)&D_005D2748;
    if (arg1)
    {
        func_0050E1A8((s32)arg0);
        return;
    }
}
