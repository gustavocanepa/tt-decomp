#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005356F0_arg0 {
    char pad0[0x6C];
    f32 unk6C;
};

f32 func_005356F0(struct func_005356F0_arg0 *arg0) {
    return arg0->unk6C;
}
