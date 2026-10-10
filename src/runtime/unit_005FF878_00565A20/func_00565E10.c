#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565E10_arg0 {
    char pad0[0x99];
    u8 unk99;
};

s32 func_00565E10(struct func_00565E10_arg0 *arg0) {
    return arg0->unk99 * 0xA;
}
