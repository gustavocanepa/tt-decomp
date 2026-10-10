#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0053C470_arg0 {
    char pad0[0x1B4];
    s32 unk1B4;
};

void func_0053C470(struct func_0053C470_arg0 *arg0, s32 arg1) {
    arg0->unk1B4 = arg1;
}
