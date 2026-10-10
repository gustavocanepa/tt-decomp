#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003EE7D0(void *, s32);             /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D73F0[];
struct func_003ECA48_arg0 {
    char pad0[0x1DE4];
    s32 unk1DE4;
};

void func_003ECA48(void *arg0, s32 arg1) {
    ((struct func_003ECA48_arg0 *)arg0)->unk1DE4 = (s32)D_005D73F0;
    func_003EE7D0(arg0 + 0xBD8, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
