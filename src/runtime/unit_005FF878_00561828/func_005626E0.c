#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005626E0_arg0 {
    char pad0[0x88];
    s32 unk88;
};

s32 func_005626E0(struct func_005626E0_arg0 *arg0) {
    return arg0->unk88;
}
