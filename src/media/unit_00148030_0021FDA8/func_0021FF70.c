#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001D9DE0();                                /* extern */
s32 func_001DAE00(void *, s32);                 /* extern */

struct func_0021FF70_arg0 {
    char pad0[0x4C];
    s32 unk4C;
};

void func_0021FF70(struct func_0021FF70_arg0 *arg0, s32 arg1) {
    if (func_001D9DE0() != 0) {
        func_001DAE00(arg0, arg1);
        arg0->unk4C = 0;
    }
}
