#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0055A540_arg0 {
    char pad0[0x130];
    s32 unk130;
};

void func_0055A540(struct func_0055A540_arg0 *arg0, s32 arg1) {
    arg0->unk130 = arg1;
}
