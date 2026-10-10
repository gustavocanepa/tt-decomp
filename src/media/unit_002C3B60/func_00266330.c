#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00266440();                            /* extern */
s32 func_0042BB68(s32, s32, void *);                /* extern */

struct func_00266330_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
};

void func_00266330(void *arg0, s32 arg1) {
    if (((struct func_00266330_arg0 *)arg0)->unk10 != 0) {
        func_00266440();
        ((struct func_00266330_arg0 *)arg0)->unk14 = func_0042BB68(((struct func_00266330_arg0 *)arg0)->unk10, arg1, arg0 + 0x18);
    }
}
