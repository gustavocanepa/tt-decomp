#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005423C8_arg0 {
    char pad0[0x340];
    s32 unk340;
};

s32 func_005423C8(struct func_005423C8_arg0 *arg0) {
    return arg0->unk340;
}
