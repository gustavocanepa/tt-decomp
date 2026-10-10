#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005590E8_arg0 {
    char pad0[0x150];
    s32 unk150;
};

void func_005590E8(struct func_005590E8_arg0 *arg0, s32 arg1) {
    arg0->unk150 = arg1;
}
