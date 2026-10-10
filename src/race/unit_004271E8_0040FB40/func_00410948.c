#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00410948_arg0 {
    char pad0[0x1A];
    u8 unk1A;
};

u8 func_00410948(struct func_00410948_arg0 *arg0) {
    return arg0->unk1A;
}
