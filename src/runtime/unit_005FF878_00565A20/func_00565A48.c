#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565A48_arg0 {
    char pad0[0x4D8];
    s32 unk4D8;
};

s32 func_00565A48(struct func_00565A48_arg0 *arg0) {
    return arg0->unk4D8;
}
