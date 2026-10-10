#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005385F8_arg0 {
    char pad0[0x38];
    s32 unk38;
};

s32 func_005385F8(struct func_005385F8_arg0 *arg0) {
    return arg0->unk38;
}
