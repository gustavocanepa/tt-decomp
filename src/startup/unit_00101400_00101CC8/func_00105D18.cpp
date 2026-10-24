#include "types.h"

extern "C" void func_00105D50(s32 arg0);
extern "C" void func_00105860(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_00105D18(s32 arg0) {
    s32 s0 = arg0;
    func_00105D50(arg0);
    func_00105860(s0, 0x200, 0x1C0);
}
