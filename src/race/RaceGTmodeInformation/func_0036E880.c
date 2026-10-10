#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00370300(void *, s32);             /* extern */
s32 func_0040BC48(s32, s32);                /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D25A0[];
struct func_0036E880_arg0 {
    char pad0[0x134];
    s32 unk134;
};

void func_0036E880(void *arg0, s32 arg1) {
    ((struct func_0036E880_arg0 *)arg0)->unk134 = (s32)D_005D25A0;
    func_0040BC48(arg0 + 0x138, 2);
    func_00370300(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
