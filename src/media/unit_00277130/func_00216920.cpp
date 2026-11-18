#include "types.h"

extern "C" void func_004BA678(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_00216920(s32 *arg0, s32 arg1) {
    func_004BA678(0, arg1, *arg0);
}
