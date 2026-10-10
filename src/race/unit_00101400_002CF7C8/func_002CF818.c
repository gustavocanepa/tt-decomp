#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0033C7F0();                                /* extern */

struct func_002CF818_arg0 {
    char pad0[0xE44];
    s32 (*unkE44)(s32, s32);
    s32 unkE48;
};

s32 func_002CF818(struct func_002CF818_arg0 *arg0) {
    s32 (*temp_v0_2)(s32, s32);
    s32 temp_a0;
    s32 temp_v0;

    temp_v0 = func_0033C7F0();
    temp_v0_2 = arg0->unkE44;
    temp_a0 = temp_v0;
    if (temp_v0_2 != NULL) {
        temp_v0_2(temp_a0, arg0->unkE48);
    }
    return temp_v0;
}
