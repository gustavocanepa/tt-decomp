#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00418610_arg0 {
    char pad0[0x33C];
    s32 unk33C;
};

s32 func_00418610(struct func_00418610_arg0 *arg0) {
    return arg0->unk33C;
}
