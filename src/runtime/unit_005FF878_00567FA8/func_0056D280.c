#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0056D280_arg0 {
    char pad0[0x8DC];
    s32 unk8DC;
};

void func_0056D280(struct func_0056D280_arg0 *arg0, s32 arg1) {
    arg0->unk8DC = arg1;
}
