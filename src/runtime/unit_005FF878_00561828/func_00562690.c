#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562690_arg0 {
    char pad0[0x80];
    s32 unk80;
};

s32 func_00562690(struct func_00562690_arg0 *arg0) {
    return arg0->unk80;
}
