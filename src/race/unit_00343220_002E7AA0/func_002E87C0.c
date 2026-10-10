#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002E7AE0(void *, s32);             /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005C9270[];
struct func_002E87C0_arg0 {
    char pad0[0x6C];
    s32 unk6C;
};

void func_002E87C0(void *arg0, s32 arg1) {
    ((struct func_002E87C0_arg0 *)arg0)->unk6C = (s32)D_005C9270;
    func_002E7AE0(arg0 + 8, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
