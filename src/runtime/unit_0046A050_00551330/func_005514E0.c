#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005514E0_arg0 {
    char pad0[0xE3E8];
    s32 unkE3E8;
};

s32 func_005514E0(struct func_005514E0_arg0 *arg0) {
    return arg0->unkE3E8;
}
