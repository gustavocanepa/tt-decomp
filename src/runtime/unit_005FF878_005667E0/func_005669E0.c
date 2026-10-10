#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0042F4C0(s32 *, s32);              /* extern */
s32 func_0050E1A8(s32 *);                       /* extern */
s32 func_0040BC48(s32, s32);                /* extern */

extern char D_005D9A00[];
void func_005669E0(s32 *arg0, s32 arg1) {
    *arg0 = (s32)D_005D9A00;
    func_0040BC48(arg0 + 2, 2);
    func_0042F4C0(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
