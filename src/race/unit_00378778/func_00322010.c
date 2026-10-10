#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00322010_arg0 {
    char pad0[0x154];
    s32 unk154;
};

s32 func_00322010(struct func_00322010_arg0 *arg0) {
    return arg0->unk154;
}
