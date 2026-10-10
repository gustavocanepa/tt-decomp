#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0050E1C8(s32);                         /* extern */

struct func_003C8610_arg0 {
    char pad0[0xC];
    s32 unkC;
};

void func_003C8610(struct func_003C8610_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unkC;
    if (temp_v0 != 0) {
        func_0050E1C8(temp_v0);
        arg0->unkC = 0;
    }
}
