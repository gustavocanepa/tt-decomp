#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00545D18_arg0 {
    char pad0[0x104];
    s32 unk104;
};

s32 func_00545D18(struct func_00545D18_arg0 *arg0) {
    return arg0->unk104;
}
