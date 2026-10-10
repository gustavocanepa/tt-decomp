#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005599C0_arg0 {
    char pad0[0x1170];
    s8 unk1170;
};

s32 func_005599C0(struct func_005599C0_arg0 *arg0) {
    return arg0->unk1170 != 0;
}
