#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005599F0_arg0 {
    char pad0[0x1173];
    s8 unk1173;
};

s32 func_005599F0(struct func_005599F0_arg0 *arg0) {
    return arg0->unk1173 != 0;
}
