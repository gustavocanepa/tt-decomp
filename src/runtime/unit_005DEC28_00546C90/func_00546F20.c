#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002C0FE8(s32);                         /* extern */
s32 func_002C1050(s32);                         /* extern */

struct func_00546F20_arg0 {
    char pad0[0xB4];
    s32 unkB4;
};

void func_00546F20(void *arg0, s32 *arg1) {
    s32 temp_s0;
    s32 temp_v0;

    if ((arg0 + 0xB4) != arg1) {
        temp_s0 = *arg1;
        if (temp_s0 != 0) {
            func_002C0FE8(temp_s0);
        }
        temp_v0 = ((struct func_00546F20_arg0 *)arg0)->unkB4;
        if (temp_v0 != 0) {
            func_002C1050(temp_v0);
        }
        ((struct func_00546F20_arg0 *)arg0)->unkB4 = temp_s0;
    }
}
