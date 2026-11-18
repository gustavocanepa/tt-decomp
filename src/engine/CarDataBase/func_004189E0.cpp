#include "types.h"

struct S {
    char pad0[0xC];
    s32 unkC;
};

extern "C" void func_0050E1A8(S *arg0);
extern char D_005D99E8;

extern "C" void func_004189E0(S *arg0, s32 arg1)
{
    arg1 = arg1 & 1;
    arg0->unkC = (s32)&D_005D99E8;
    if (arg1)
    {
        func_0050E1A8(arg0);
        return;
    }
}
