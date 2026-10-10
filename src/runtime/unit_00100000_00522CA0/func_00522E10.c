#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00522E10_arg0 {
    char pad0[0x44];
    s32 unk44;
};

s32 func_00522E10(struct func_00522E10_arg0 *arg0) {
    return arg0->unk44;
}
