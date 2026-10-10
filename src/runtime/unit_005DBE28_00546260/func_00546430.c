#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00546430_arg0 {
    char pad0[0x120];
    s32 unk120;
};

s32 func_00546430(struct func_00546430_arg0 *arg0) {
    return arg0->unk120;
}
