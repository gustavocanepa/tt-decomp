#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417DF8_arg0 {
    char pad0[0x1D4];
    f32 unk1D4;
};

f32 func_00417DF8(struct func_00417DF8_arg0 *arg0) {
    return arg0->unk1D4;
}
