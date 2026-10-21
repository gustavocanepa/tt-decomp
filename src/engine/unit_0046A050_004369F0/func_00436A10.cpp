#include "types.h"

extern "C" s32 *func_004369F0(void);

extern "C" s32 func_00436A10(void) {
    return *func_004369F0();
}
