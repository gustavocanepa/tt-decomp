#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002A42F8();                            /* extern */
s32 func_002C1050(s32);                         /* extern */
s32 func_0050E1A8(s32 *);                       /* extern */

void func_002BF0B0(s32 *arg0, s32 arg1) {
    if (*arg0 != 0) {
        func_002A42F8();
        func_002C1050(*arg0);
        *arg0 = 0;
    }
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
