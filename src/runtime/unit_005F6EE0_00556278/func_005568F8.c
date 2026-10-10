#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005568F8_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_005568F8(struct func_005568F8_arg0 *arg0, s32 arg1) {
    arg0->unk8 = arg1;
}
