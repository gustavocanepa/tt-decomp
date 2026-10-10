#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002A10B8_arg0 {
    char pad0[0x18];
    s32 unk18;
};

s32 func_002A10B8(struct func_002A10B8_arg0 *arg0) {
    return arg0->unk18;
}
