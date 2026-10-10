#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0048D0B8_arg0 {
    char pad0[0x10];
    s32 (*unk10)(s32, s32);
};

void func_0048D0B8(struct func_0048D0B8_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk10(arg1, arg2);
}
