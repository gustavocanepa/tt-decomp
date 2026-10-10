#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00541850_arg0 {
    char pad0[0x134];
    s32 unk134;
};

void func_00541850(struct func_00541850_arg0 *arg0, s32 arg1) {
    arg0->unk134 = arg1;
}
