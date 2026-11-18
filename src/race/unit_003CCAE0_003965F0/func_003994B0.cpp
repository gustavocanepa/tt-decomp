#include "types.h"

extern "C" s32 func_00399458(void *self, s32 which);

extern "C" s32 func_003994B0(void *self) {
    if (func_00399458(self, 0)) {
        if (func_00399458(self, 1)) {
            return 0;
        }
    }
    return 1;
}
