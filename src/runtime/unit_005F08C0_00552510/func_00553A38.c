#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00553A38_arg0 {
    char pad0[0x188];
    s32 unk188;
};

s32 func_00553A38(struct func_00553A38_arg0 *arg0) {
    return arg0->unk188;
}
