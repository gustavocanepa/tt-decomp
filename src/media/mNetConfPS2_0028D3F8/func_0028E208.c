#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0020E160(s32);                             /* extern */
s32 func_0020E1A0(s32, s32);                /* extern */

struct func_0028E208_arg0 {
    char pad0[0xDC];
    s32 unkDC;
};

s32 func_0028E208(struct func_0028E208_arg0 *arg0, s32 arg1) {
    if (arg0->unkDC != 0) {
        if (func_0020E160(arg1) == 0) {
            func_0020E1A0(arg1, 1);
        }
        if (func_0020E160(arg1) == 3) {
            return func_0020E1A0(arg1, 2);
        }
    } else {
        if (func_0020E160(arg1) == 1) {
            func_0020E1A0(arg1, 0);
        }
        if (func_0020E160(arg1) == 2) {
            func_0020E1A0(arg1, 3);
        }
    }
}
