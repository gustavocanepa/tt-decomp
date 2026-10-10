#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562278_arg0 {
    char pad0[0x8228];
    s32 unk8228;
};

s32 func_00562278(struct func_00562278_arg0 *arg0) {
    return arg0->unk8228;
}
