#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005623C0_arg0 {
    char pad0[0x11];
    u8 unk11;
};

u8 func_005623C0(struct func_005623C0_arg0 *arg0) {
    return arg0->unk11;
}
