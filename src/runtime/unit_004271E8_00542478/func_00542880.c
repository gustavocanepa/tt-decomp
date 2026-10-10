#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00542880_arg0 {
    char pad0[0x90];
    s32 unk90;
};

s32 func_00542880(struct func_00542880_arg0 *arg0) {
    return arg0->unk90;
}
