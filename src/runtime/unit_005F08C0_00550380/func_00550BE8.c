#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00550BE8_arg0 {
    char pad0[0x3277C];
    s32 unk3277C;
};

s32 func_00550BE8(struct func_00550BE8_arg0 *arg0) {
    return arg0->unk3277C;
}
