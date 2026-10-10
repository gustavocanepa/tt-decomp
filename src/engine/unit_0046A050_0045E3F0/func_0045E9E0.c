#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00460868(s32);                         /* extern */

struct func_0045E9E0_arg0 {
    char pad0[0xC];
    s32 unkC;
};

void func_0045E9E0(struct func_0045E9E0_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unkC;
    if (temp_v0 != 0) {
        func_00460868(temp_v0);
    }
    arg0->unkC = 0;
}
