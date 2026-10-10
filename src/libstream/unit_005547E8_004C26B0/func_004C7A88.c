#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004C6F78(s32);                             /* extern */
s32 func_004C82A0(void *, s32);             /* extern */

struct func_004C7A88_temp_s0 {
    char pad0[0x8];
    s32 unk8;
    char padC[0x3C];
    s32 unk48;
};

void func_004C7A88(void **arg0) {
    struct func_004C7A88_temp_s0 *temp_s0;
    void *temp_v0;

    temp_v0 = *arg0;
    if (temp_v0 != NULL) {
        func_004C82A0(temp_v0, 6);
        temp_s0 = *arg0;
        temp_s0->unk48 = func_004C6F78(temp_s0->unk8);
    }
}
