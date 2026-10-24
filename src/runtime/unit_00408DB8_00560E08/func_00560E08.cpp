#include "types.h"

extern "C" f32 func_00560E08(char *arg0, s32 arg1) {
    arg0 = arg0 + arg1 * 4;
    return *(f32 *)(arg0 + 0x8);
}
