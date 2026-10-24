#include "types.h"

extern "C" void func_001C1098(s32 arg0, const char *arg1, s32 arg2);

extern "C" void func_001F68D0(s32 arg0, s32 arg1) {
    func_001C1098(arg0, "%d", arg1);
}
