#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00240940_arg0 {
    char pad0[0x1A8];
    f32 unk1A8;
};

f32 func_00240940(struct func_00240940_arg0 *arg0) {
    return arg0->unk1A8 * 0x1.e000000000000p+5f;
}
