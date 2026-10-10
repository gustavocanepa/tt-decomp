#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002A77A8();                            /* extern */
s32 func_005447E0(s32, s32);                    /* extern */

struct func_00294D58_arg0 {
    char pad0[0x20];
    s32 unk20;
};

void *func_00294D58(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v1;

    if (arg0 != arg1) {
        func_002A77A8();
        temp_v1 = arg1 + 0x10;
        temp_v0 = arg0 + 0x10;
        if (temp_v0 != temp_v1) {
            func_005447E0(temp_v0, temp_v1);
        }
        ((struct func_00294D58_arg0 *)arg0)->unk20 = 0;
    }
    return arg0;
}
