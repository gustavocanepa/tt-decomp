#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004447B0_arg0 {
    char pad0[0x3C];
    f32 unk3C;
};

f32 func_004447B0(struct func_004447B0_arg0 *arg0) {
    return arg0->unk3C;
}
