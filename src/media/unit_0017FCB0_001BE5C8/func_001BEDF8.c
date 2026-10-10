#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001B3928(s32);                             /* extern */
s32 func_001BEBA0(s32, s32);                    /* extern */
s32 func_001BEC80(s32, s32);                /* extern */
s32 func_001BED60(s32);                         /* extern */
s32 func_001D9DE0();                                /* extern */
s32 func_001DADF8(s32, s32);                    /* extern */

s32 func_001BEDF8(s32 arg0, s32 arg1) {
    if (func_001D9DE0() != 0) {
        func_001DADF8(arg0, arg1);
        func_001BEBA0(arg0, func_001B3928(arg0));
        func_001BEC80(arg0, 1);
        func_001BED60(arg0);
        func_001BEC80(arg0, 0);
    }
}
