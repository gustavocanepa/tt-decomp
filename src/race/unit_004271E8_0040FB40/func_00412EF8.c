#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00412FE8();                            /* extern */
s32 func_004AE9F0(void *, s32);             /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D9878[];
struct func_00412EF8_arg0 {
    char pad0[0x40];
    s32 unk40;
};

void func_00412EF8(void *arg0, s32 arg1) {
    ((struct func_00412EF8_arg0 *)arg0)->unk40 = (s32)D_005D9878;
    func_00412FE8();
    func_004AE9F0(arg0 + 0x10, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
