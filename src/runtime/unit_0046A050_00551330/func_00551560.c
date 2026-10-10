#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00551560_arg0 {
    char pad0[0xE3F4];
    s32 unkE3F4;
};

s32 func_00551560(struct func_00551560_arg0 *arg0) {
    return arg0->unkE3F4;
}
