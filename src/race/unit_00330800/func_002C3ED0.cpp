#include "types.h"

extern "C" s32 func_002C3ED0(s32 arg0, s32 arg1) {
loop_0:
    if (arg1 != 0) {
        s32 t = arg0 % arg1;
        arg0 = arg1;
        arg1 = t;
        goto loop_0;
    }
    return arg0;
}
