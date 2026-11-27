#include "types.h"

struct S {
    char pad0[0xB0];
    s32 unkB0;
};

extern "C" void func_0050E1A8(S *arg0);
extern char D_005D7408;

extern "C" void func_003ED188(S *arg0, s32 arg1) {
    arg1 = arg1 & 1;
    arg0->unkB0 = (s32)&D_005D7408;
    if (arg1) {
        func_0050E1A8(arg0);
        return;
    }
}
