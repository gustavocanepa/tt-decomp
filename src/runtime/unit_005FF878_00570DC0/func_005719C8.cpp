#include "types.h"

extern "C" void func_004AC860(s32 *arg0, s32 arg1, s32 arg2);

extern "C" void func_005719C8(s32 *arg0, s32 arg1) {
    func_004AC860(arg0, *arg0, arg1);
}
