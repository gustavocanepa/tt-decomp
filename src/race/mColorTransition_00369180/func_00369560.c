#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00344410(s32);                         /* extern */

struct func_00369560_arg0 {
    char pad0[0x4840];
    s32 *unk4840;
};

s32 func_00369560(void *arg0) {
    s32 *temp_v0;

    temp_v0 = ((struct func_00369560_arg0 *)arg0)->unk4840;
    if (temp_v0 != NULL) {
        *temp_v0 = arg0 + 0x4850;
        func_00344410(arg0 + 0x12C0);
    }
}
