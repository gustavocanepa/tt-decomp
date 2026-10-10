#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005263A0_arg0 {
    char pad0[0x54];
    f32 unk54;
};

f32 func_005263A0(struct func_005263A0_arg0 *arg0) {
    return arg0->unk54;
}
