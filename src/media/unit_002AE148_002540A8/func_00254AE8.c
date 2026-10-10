#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0020CF10();                            /* extern */
void *func_0022F7C8(s32);                           /* extern */

struct func_00254AE8_temp_v0 {
    char pad0[0x174];
    s32 unk174;
};

s32 func_00254AE8(s32 arg0, s32 arg1, s32 arg2) {
    struct func_00254AE8_temp_v0 *temp_v0;

    func_0020CF10();
    temp_v0 = func_0022F7C8(arg2);
    if (temp_v0 == arg0) {
        temp_v0->unk174 = 1;
    }
    return 1;
}
