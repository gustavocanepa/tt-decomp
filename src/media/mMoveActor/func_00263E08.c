#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001B3928(void *);                          /* extern */
s32 func_001D9DE0();                                /* extern */
s32 func_001DADF8(void *, s32);                 /* extern */
s32 func_00263B98(void *, void *, f32);         /* extern */

struct func_00263E08_arg0 {
    char pad0[0x4C];
    s32 unk4C;
    char pad50[0x20];
    f32 unk70;
    char pad74[0x18];
    s32 unk8C;
};

void func_00263E08(void *arg0, s32 arg1) {
    if (func_001D9DE0() != 0) {
        func_001DADF8(arg0, arg1);
        ((struct func_00263E08_arg0 *)arg0)->unk4C = func_001B3928(arg0);
        if (((struct func_00263E08_arg0 *)arg0)->unk8C != 0) {
            func_00263B98(arg0, arg0 + 0x50, 0x1.0000000000000p+0f);
            return;
        }
        func_00263B98(arg0, arg0 + 0x60, ((struct func_00263E08_arg0 *)arg0)->unk70);
    }
}
