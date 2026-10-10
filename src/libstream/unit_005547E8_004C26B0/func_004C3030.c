#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004C9F30(s32 *, s32);              /* extern */
s32 func_004AE9F0(s32, s32);                /* extern */
s32 func_0050E1A8(s32 *);                       /* extern */

extern char D_005DB220[];
void func_004C3030(s32 *arg0, s32 arg1) {
    *arg0 = (s32)D_005DB220;
    func_004AE9F0(arg0 + 1, 2);
    func_004C9F30(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
