#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565D10_arg0 {
    char pad0[0x18];
    u16 unk18;
};

u16 func_00565D10(struct func_00565D10_arg0 *arg0) {
    return arg0->unk18;
}
