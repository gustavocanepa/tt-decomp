#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002C0FE8(s32);                         /* extern */
s32 func_002C1050(s32);                         /* extern */

struct func_00250208_arg0 {
    char pad0[0xD4];
    s32 unkD4;
};

void func_00250208(void *arg0, s32 *arg1) {
    s32 temp_s0;
    s32 temp_v0;

    if ((arg0 + 0xD4) != arg1) {
        temp_s0 = *arg1;
        if (temp_s0 != 0) {
            func_002C0FE8(temp_s0);
        }
        temp_v0 = ((struct func_00250208_arg0 *)arg0)->unkD4;
        if (temp_v0 != 0) {
            func_002C1050(temp_v0);
        }
        ((struct func_00250208_arg0 *)arg0)->unkD4 = temp_s0;
    }
}
