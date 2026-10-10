#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00551130_arg0 {
    char pad0[0x34];
    s32 unk34;
};

s32 func_00551130(struct func_00551130_arg0 *arg0) {
    return arg0->unk34;
}
