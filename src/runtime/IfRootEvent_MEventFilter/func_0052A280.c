#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0029B488(s32, s32);                /* extern */
s32 func_0050E1A8(s32 *);                       /* extern */

extern char D_005B14B0[];
extern char D_005B1788[];
void func_0052A280(s32 *arg0, s32 arg1) {
    *arg0 = (s32)D_005B14B0;
    func_0029B488(arg0 + 1, 2);
    *arg0 = (s32)D_005B1788;
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
