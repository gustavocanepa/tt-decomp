#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00567988_arg0 {
    char pad0[0x304];
    s32 unk304;
};

void *func_00567988(void *arg0) {
    return arg0 + ((1 - ((struct func_00567988_arg0 *)arg0)->unk304) * 0x180) + 4;
}
