#include "types.h"

s32 func_00406A50(s32, s32, s32);                   /* extern */
s32 func_00412278(s32);                             /* extern */
s32 func_004122C8(s32);                             /* extern */

s32 func_00406A88(s32 arg0, s32 arg1, s32 arg2) {
    if (func_004122C8(arg1) == 0) {
        return 1;
    }
    if ((func_00412278(arg1) == 0) < arg2) {
        return func_00406A50(arg0, arg1, arg2 - 1);
    }
    return 1;
}
