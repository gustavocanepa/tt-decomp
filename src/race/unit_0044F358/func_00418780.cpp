#include "types.h"

extern "C" void func_00418618(s32 arg0, s32 arg1);
extern "C" s32 func_004172F0(void);

extern "C" void func_00418780(s32 arg0) {
    s32 v0 = func_004172F0();
    if (v0 != 0) {
        func_00418618(v0, arg0);
    }
}
