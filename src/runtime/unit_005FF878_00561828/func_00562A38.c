#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562A38_arg0 {
    char pad0[0x1140];
    s32 unk1140;
};

void func_00562A38(struct func_00562A38_arg0 *arg0, s32 arg1) {
    arg0->unk1140 = arg1;
}
