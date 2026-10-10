#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002E4D98();                                /* extern */
s32 func_00300588(s32);                             /* extern */
s32 func_00301300(s32);                             /* extern */

s32 func_00393A08(s32 arg0) {
    if ((func_002E4D98() != 1) && (func_00300588(arg0) != 0)) {
        return func_00301300(arg0);
    }
    return 0;
}
