#include "types.h"

extern "C" s32 func_003F7B10(void);

extern "C" s32 func_00561D90(void) {
    return ~func_003F7B10() != 0;
}
