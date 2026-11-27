#include "types.h"

extern "C" s32 DynamicsConductor__GetCountDown(s32 arg0, s32 arg1);

extern "C" s32 func_002F0550(s32 arg0) {
    return DynamicsConductor__GetCountDown(arg0, -1) > 0;
}
