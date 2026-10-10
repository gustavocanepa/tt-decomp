#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562958_arg0 {
    char pad0[0x1108];
    s32 unk1108;
};

void func_00562958(struct func_00562958_arg0 *arg0, s32 arg1) {
    arg0->unk1108 = arg1;
}
