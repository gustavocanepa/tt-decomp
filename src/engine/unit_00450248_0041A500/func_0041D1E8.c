#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0041D1E8_arg0 {
    char pad0[0x5E8];
    s32 unk5E8;
};

void func_0041D1E8(struct func_0041D1E8_arg0 *arg0, s32 arg1) {
    arg0->unk5E8 = arg1;
}
