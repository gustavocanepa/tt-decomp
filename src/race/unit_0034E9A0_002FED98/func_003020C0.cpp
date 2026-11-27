#include "types.h"

extern "C" s32 func_00301F68(void);
extern "C" signed char D_005834A8[];

extern "C" s32 func_003020C0(void) {
    return D_005834A8[func_00301F68()] == 2;
}
