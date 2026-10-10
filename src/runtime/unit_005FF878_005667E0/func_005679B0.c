#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005679B0_arg0 {
    char pad0[0x304];
    s32 unk304;
};

void *func_005679B0(void *arg0) {
    return arg0 + ((1 - ((struct func_005679B0_arg0 *)arg0)->unk304) * 0x180) + 4;
}
