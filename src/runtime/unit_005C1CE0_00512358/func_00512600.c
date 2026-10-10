#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00512600_arg0 {
    char pad0[0x304];
    s32 unk304;
};

s32 func_00512600(struct func_00512600_arg0 *arg0) {
    return arg0->unk304;
}
