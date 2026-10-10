#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562AC0_arg0 {
    char pad0[0x1154];
    s32 unk1154;
};

s32 func_00562AC0(struct func_00562AC0_arg0 *arg0) {
    return arg0->unk1154;
}
