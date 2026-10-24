#include "types.h"

extern "C" s32 RaceEventQueue__get(void *arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" s32 func_0055AE58(char *arg0, s32 arg1, s32 arg2) {
    return RaceEventQueue__get(arg0 + 0xF4, arg1, arg2, 0);
}
