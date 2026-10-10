#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554460_arg0 {
    char pad0[0xD9C];
    s32 unkD9C;
};

s32 func_00554460(struct func_00554460_arg0 *arg0) {
    return arg0->unkD9C;
}
