#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00261D90_arg0 {
    char pad0[0x368];
    s32 unk368;
};

s32 func_00261D90(struct func_00261D90_arg0 *arg0) {
    return ((s32) arg0->unk368 >> 4) & 1;
}
