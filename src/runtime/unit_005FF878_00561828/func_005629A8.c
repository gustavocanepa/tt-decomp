#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005629A8_arg0 {
    char pad0[0x111C];
    s32 unk111C;
};

void func_005629A8(struct func_005629A8_arg0 *arg0, s32 arg1) {
    arg0->unk111C = arg1;
}
