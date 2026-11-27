#include "types.h"

extern "C" s32 exception__structor_0(s32 arg0);
extern "C" void func_002CE060(s32 arg0);

extern "C" s32 func_00372D30(void) {
    s32 temp_v0 = exception__structor_0(0x3C);
    func_002CE060(temp_v0);
    return temp_v0;
}
