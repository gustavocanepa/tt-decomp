#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00552BE8_arg0 {
    char pad0[0xB4];
    f32 unkB4;
};

f32 func_00552BE8(struct func_00552BE8_arg0 *arg0) {
    return arg0->unkB4;
}
