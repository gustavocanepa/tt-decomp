#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */

struct func_0040EF20_arg0 {
    char pad0[0xB0];
    s32 unkB0;
};

void func_0040EF20(struct func_0040EF20_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unkB0;
    if (temp_v0 != 0) {
        func_004A45D0(temp_v0);
        arg0->unkB0 = 0;
    }
}
