#include "types.h"

extern "C" s32 *func_0053DD28(s32 *arg0, s32 arg1, s32 *arg2) {
    if (arg1 != 0) {
        do {
            *arg0 = *arg2;
            arg1--;
            arg0++;
        } while (arg1 != 0);
    }
    return arg0;
}
