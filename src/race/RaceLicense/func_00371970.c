#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00371970_arg0 {
    char pad0[0xD8C];
    u32 unkD8C;
};

s32 func_00371970(struct func_00371970_arg0 *arg0) {
    return (u32) arg0->unkD8C < 2U;
}
