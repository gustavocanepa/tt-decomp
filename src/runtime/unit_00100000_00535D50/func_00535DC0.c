#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00535DC0_arg0 {
    char pad0[0x20];
    u16 unk20;
};

u16 func_00535DC0(struct func_00535DC0_arg0 *arg0) {
    return arg0->unk20;
}
