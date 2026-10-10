#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0022F7C8(s32);                             /* extern */

struct func_005418F8_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_005418F8(struct func_005418F8_arg0 *arg0, s32 *arg1) {
    return func_0022F7C8(*arg1) == arg0->unk4;
}
