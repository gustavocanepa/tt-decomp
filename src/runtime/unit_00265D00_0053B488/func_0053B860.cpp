#include "types.h"

extern "C" void func_004C99F0(s32 arg0, s32 arg1);

extern "C" void func_0053B860(char *arg0, char *arg1) {
    func_004C99F0((s32)(arg1 + 0x10), (s32)(arg0 + 0x18));
}
