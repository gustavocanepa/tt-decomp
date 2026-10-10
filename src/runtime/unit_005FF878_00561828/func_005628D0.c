#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005628D0_arg0 {
    char pad0[0x10E8];
    s32 unk10E8;
};

s32 func_005628D0(struct func_005628D0_arg0 *arg0) {
    return arg0->unk10E8;
}
