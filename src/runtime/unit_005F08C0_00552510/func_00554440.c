#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554440_arg0 {
    char pad0[0xDF4];
    f32 unkDF4;
};

f32 func_00554440(struct func_00554440_arg0 *arg0) {
    return arg0->unkDF4;
}
