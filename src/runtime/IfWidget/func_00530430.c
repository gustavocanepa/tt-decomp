#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0022F7C8(s32);                             /* extern */

struct func_00530430_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_00530430(struct func_00530430_arg0 *arg0, s32 *arg1) {
    return func_0022F7C8(*arg1) == arg0->unk4;
}
