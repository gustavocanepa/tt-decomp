#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003FB500(void *, s32);                 /* extern */

struct func_003FBBA8_arg0 {
    char pad0[0x8210];
    s32 unk8210;
};

s32 func_003FBBA8(void *arg0) {
    s32 temp_v0;

    temp_v0 = ((struct func_003FBBA8_arg0 *)arg0)->unk8210;
    if (temp_v0 >= 0) {
        func_003FB500(arg0 + (temp_v0 << 5) + 8, arg0 + 0x7D08);
    }
}
