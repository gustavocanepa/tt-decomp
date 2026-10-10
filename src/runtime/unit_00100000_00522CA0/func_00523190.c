#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00523190_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_00523190(struct func_00523190_arg0 *arg0, s32 arg1) {
    arg0->unk4 = arg1;
}
