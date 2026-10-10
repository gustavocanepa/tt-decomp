#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005629D0_arg0 {
    char pad0[0x1128];
    s32 unk1128;
};

s32 func_005629D0(struct func_005629D0_arg0 *arg0) {
    return arg0->unk1128;
}
