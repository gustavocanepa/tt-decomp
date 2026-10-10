#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565CE0_arg0 {
    char pad0[0x6E];
    u8 unk6E;
};

u8 func_00565CE0(struct func_00565CE0_arg0 *arg0) {
    return arg0->unk6E;
}
