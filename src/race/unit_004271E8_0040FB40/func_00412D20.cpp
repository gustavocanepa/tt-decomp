#include "types.h"

extern "C" s32 func_0040F5F8(s32 arg0, char *arg1);
extern "C" void func_00412D60(s32 arg0, char *arg1);

extern "C" void func_00412D20(s32 arg0, s32 arg1) {
    char buf[0x20];
    if (func_0040F5F8(arg1, buf)) {
        return func_00412D60(arg0, buf);
    }
}
