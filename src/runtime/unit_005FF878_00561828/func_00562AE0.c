#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562AE0_arg0 {
    char pad0[0x1150];
    s32 unk1150;
};

s32 func_00562AE0(struct func_00562AE0_arg0 *arg0) {
    return arg0->unk1150;
}
