#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565E48_arg0 {
    char pad0[0x7D];
    u8 unk7D;
};

u8 func_00565E48(struct func_00565E48_arg0 *arg0) {
    return arg0->unk7D;
}
