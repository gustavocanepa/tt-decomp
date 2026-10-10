#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0035F428_arg0 {
    char pad0[0x150];
    s32 unk150;
};

void func_0035F428(struct func_0035F428_arg0 *arg0, s32 arg1) {
    arg0->unk150 = arg1;
}
