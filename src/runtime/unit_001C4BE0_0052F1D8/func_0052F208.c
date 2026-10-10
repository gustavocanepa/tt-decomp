#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052F208_arg0 {
    char pad0[0x110];
    s32 unk110;
};

void func_0052F208(struct func_0052F208_arg0 *arg0, s32 arg1) {
    arg0->unk110 = arg1;
}
