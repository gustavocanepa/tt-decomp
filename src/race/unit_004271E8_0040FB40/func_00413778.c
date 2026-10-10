#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00413560(void *, void *);              /* extern */
s32 func_004F6678(void *, s32, s32);        /* extern */

struct func_00413778_arg0 {
    char pad0[0x1C];
    s32 unk1C;
};

void func_00413778(void *arg0) {
    s32 temp_v0;

    temp_v0 = ((struct func_00413778_arg0 *)arg0)->unk1C;
    if (temp_v0 != 0) {
        func_004F6678(arg0 + temp_v0 + 0x14, 0, 8 - temp_v0);
        func_00413560(arg0, arg0 + 0x14);
        ((struct func_00413778_arg0 *)arg0)->unk1C = 0;
    }
}
