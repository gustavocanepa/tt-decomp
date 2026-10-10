#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00321050_arg0 {
    char pad0[0xF68];
    f32 unkF68;
};

f32 func_00321050(struct func_00321050_arg0 *arg0) {
    return arg0->unkF68;
}
