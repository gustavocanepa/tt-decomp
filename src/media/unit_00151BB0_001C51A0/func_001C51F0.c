#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001C51F0_arg0 {
    char pad0[0x20];
    s32 unk20;
};

s32 func_001C51F0(struct func_001C51F0_arg0 *arg0) {
    return arg0->unk20;
}
