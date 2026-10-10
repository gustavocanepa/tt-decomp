#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00555758_arg0 {
    char pad0[0x180];
    s32 unk180;
};

s32 func_00555758(struct func_00555758_arg0 *arg0) {
    return arg0->unk180;
}
