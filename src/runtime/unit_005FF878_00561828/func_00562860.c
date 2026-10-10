#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562860_arg0 {
    char pad0[0x10CC];
    s32 unk10CC;
};

s32 func_00562860(struct func_00562860_arg0 *arg0) {
    return arg0->unk10CC;
}
