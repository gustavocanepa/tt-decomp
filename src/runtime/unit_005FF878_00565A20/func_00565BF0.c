#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565BF0_arg0 {
    char pad0[0x50];
    u8 unk50;
};

u8 func_00565BF0(struct func_00565BF0_arg0 *arg0) {
    return arg0->unk50;
}
