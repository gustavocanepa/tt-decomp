#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0048A018(s32, s32, s32, s32);              /* extern */

struct func_0028DA10_arg0 {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0x4];
    s32 unk20;
};

s32 func_0028DA10(struct func_0028DA10_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = arg0->unk20;
    if (temp_v0 >= 0) {
        return func_0048A018(arg0->unk18, temp_v0, arg1, arg2);
    }
    return 0;
}
