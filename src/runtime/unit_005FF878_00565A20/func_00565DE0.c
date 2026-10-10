#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565DE0_arg0 {
    char pad0[0x38];
    s16 unk38;
};

s16 func_00565DE0(struct func_00565DE0_arg0 *arg0) {
    return arg0->unk38;
}
