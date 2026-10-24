#include "types.h"

extern "C" s32 *func_001AF2E0(void);

extern "C" s32 func_005221D0(void) {
    return *func_001AF2E0();
}
