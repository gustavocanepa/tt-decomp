#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562258_arg0 {
    char pad0[0x8238];
    s32 unk8238;
};

s32 func_00562258(struct func_00562258_arg0 *arg0) {
    return arg0->unk8238;
}
