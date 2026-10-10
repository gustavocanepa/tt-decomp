#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005356C0_arg0 {
    char pad0[0x60];
    s32 unk60;
};

s32 func_005356C0(struct func_005356C0_arg0 *arg0) {
    return arg0->unk60;
}
