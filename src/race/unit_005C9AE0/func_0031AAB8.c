#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0031AAB8_arg0 {
    char pad0[0xA4C];
    s32 unkA4C;
};

void func_0031AAB8(struct func_0031AAB8_arg0 *arg0, s32 arg1) {
    arg0->unkA4C = arg1;
}
