#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002C0FE8(s32);                         /* extern */
s32 func_002C1050(s32);                         /* extern */

struct hStaticValue__virtual_08_arg0 {
    char pad0[0xC];
    s32 unkC;
};

void hStaticValue__virtual_08(void *arg0, s32 *arg1) {
    s32 temp_s0;
    s32 temp_v0;

    if (arg1 != (arg0 + 0xC)) {
        temp_s0 = ((struct hStaticValue__virtual_08_arg0 *)arg0)->unkC;
        if (temp_s0 != 0) {
            func_002C0FE8(temp_s0);
        }
        temp_v0 = *arg1;
        if (temp_v0 != 0) {
            func_002C1050(temp_v0);
        }
        *arg1 = temp_s0;
    }
}
