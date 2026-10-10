#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00457D78(void *, s32);                     /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D7420[];
struct func_003EE7D0_arg0 {
    char pad0[0x11D0];
    s32 unk11D0;
};

void func_003EE7D0(struct func_003EE7D0_arg0 *arg0, s32 arg1) {
    arg0->unk11D0 = (s32)D_005D7420;
    func_00457D78(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
