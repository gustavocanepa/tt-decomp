#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052C9F8_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_0052C9F8(struct func_0052C9F8_arg0 *arg0, s32 arg1) {
    arg0->unk10 = arg1;
}
