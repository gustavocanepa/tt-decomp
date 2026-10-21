#include "types.h"

extern "C" s32 func_004C0430(void);

extern "C" s32 func_003FE180(void) {
    return (u32)(func_004C0430() - 1) < 2U;
}
