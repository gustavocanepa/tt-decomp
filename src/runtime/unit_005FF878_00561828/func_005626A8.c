#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005626A8_arg0 {
    char pad0[0x84];
    s32 unk84;
};

void func_005626A8(struct func_005626A8_arg0 *arg0, s32 arg1) {
    arg0->unk84 = arg1;
}
