#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00552BF0_arg0 {
    char pad0[0xB8];
    f32 unkB8;
};

f32 func_00552BF0(struct func_00552BF0_arg0 *arg0) {
    return arg0->unkB8;
}
