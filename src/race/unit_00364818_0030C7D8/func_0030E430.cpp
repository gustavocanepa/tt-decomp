#include "types.h"

extern "C" char D_00583680[];
extern "C" s32 GtbABC_SetupGlobal(s32 arg0, char *arg1, s32 arg2, s32 arg3);

extern "C" s32 func_0030E430(s32 arg0) {
    return GtbABC_SetupGlobal(arg0, D_00583680, 4, 2);
}
