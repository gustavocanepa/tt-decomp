#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0047E9C0(void *, s32);             /* extern */
s32 func_0047F608(s32, s32);                /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DA6F0[];
struct func_0047EEF8_arg0 {
    char pad0[0xA8];
    s32 unkA8;
};

void func_0047EEF8(void *arg0, s32 arg1) {
    ((struct func_0047EEF8_arg0 *)arg0)->unkA8 = (s32)D_005DA6F0;
    func_0047F608(arg0 + 0xB0, 2);
    func_0047E9C0(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
