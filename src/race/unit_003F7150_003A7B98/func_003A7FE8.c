#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0030E928(s32);                             /* extern */

struct func_003A7FE8_arg0 {
    char pad0[0x18];
    s32 unk18;
};

s32 func_003A7FE8(struct func_003A7FE8_arg0 *arg0) {
    return func_0030E928(arg0->unk18) >= 3;
}
