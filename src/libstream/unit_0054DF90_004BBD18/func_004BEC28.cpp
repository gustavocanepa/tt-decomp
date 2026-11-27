#include "types.h"

extern "C" void func_004BEA30(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern char D_00776D80[];

extern "C" void func_004BEC28(s32 arg0, s32 arg1, s32 arg2) {
    func_004BEA30(D_00776D80, 7, arg0, arg1, arg2);
}
