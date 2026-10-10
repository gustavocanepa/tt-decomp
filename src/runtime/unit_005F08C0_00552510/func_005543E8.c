#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005543E8_arg0 {
    char pad0[0xD8C];
    u32 unkD8C;
};

s32 func_005543E8(struct func_005543E8_arg0 *arg0) {
    return (u32) arg0->unkD8C >= 2U;
}
