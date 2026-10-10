#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002668E8(s32);                             /* extern */
s32 func_00269380();                                /* extern */
s32 func_0020B4C8(s32, s32);                    /* extern */

struct func_00269BF8_arg0 {
    char pad0[0x10];
    s32 unk10;
};

s32 func_00269BF8(s32 arg0) {
    if (func_00269380() == 0) {
        func_0020B4C8(((struct func_00269BF8_arg0 *)arg0)->unk10, func_002668E8(arg0));
    }
}
