#include "types.h"

extern "C" s32 func_003F93B8();
extern "C" void GranTurismo4__GetTimeString(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_003F93F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    GranTurismo4__GetTimeString(func_003F93B8(), arg2, arg3);
}
