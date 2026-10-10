#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0053D650_arg0 {
    char pad0[0x13C];
    s32 unk13C;
};

void func_0053D650(struct func_0053D650_arg0 *arg0, s32 arg1) {
    arg0->unk13C = arg1;
}
