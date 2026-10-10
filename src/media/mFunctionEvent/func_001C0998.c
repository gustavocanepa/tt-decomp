#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002C0FE8(s32);                         /* extern */
s32 func_002C1050(s32);                         /* extern */

struct func_001C0998_arg0 {
    char pad0[0x20];
    s32 unk20;
};

void func_001C0998(void *arg0, s32 *arg1) {
    s32 temp_s0;
    s32 temp_v0;

    if ((arg0 + 0x20) != arg1) {
        temp_s0 = *arg1;
        if (temp_s0 != 0) {
            func_002C0FE8(temp_s0);
        }
        temp_v0 = ((struct func_001C0998_arg0 *)arg0)->unk20;
        if (temp_v0 != 0) {
            func_002C1050(temp_v0);
        }
        ((struct func_001C0998_arg0 *)arg0)->unk20 = temp_s0;
    }
}
