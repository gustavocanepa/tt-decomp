#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0056D288_arg0 {
    char pad0[0x8A8];
    s32 unk8A8;
};

void func_0056D288(struct func_0056D288_arg0 *arg0, s32 arg1) {
    arg0->unk8A8 = arg1;
}
