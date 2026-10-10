#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005629E8_arg0 {
    char pad0[0x112C];
    s32 unk112C;
};

void func_005629E8(struct func_005629E8_arg0 *arg0, s32 arg1) {
    arg0->unk112C = arg1;
}
