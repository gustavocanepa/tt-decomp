#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005623D0_arg0 {
    char pad0[0x12];
    u8 unk12;
};

u8 func_005623D0(struct func_005623D0_arg0 *arg0) {
    return arg0->unk12;
}
