#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565D58_arg0 {
    char pad0[0x46];
    u8 unk46;
};

u8 func_00565D58(struct func_00565D58_arg0 *arg0) {
    return arg0->unk46;
}
