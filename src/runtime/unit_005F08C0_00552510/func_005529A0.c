#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005529A0_arg0 {
    char pad0[0x20A20];
    s32 unk20A20;
};

s32 func_005529A0(struct func_005529A0_arg0 *arg0) {
    return arg0->unk20A20;
}
