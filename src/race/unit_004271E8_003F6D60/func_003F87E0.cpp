#include "types.h"

extern "C" s32 func_003F8810(s32 arg0, s32 arg1);
extern "C" s32 func_00410340(s32 arg0);

extern "C" s32 func_003F87E0(s32 arg0, s32 arg1) {
    return func_003F8810(arg0, func_00410340(arg1));
}
