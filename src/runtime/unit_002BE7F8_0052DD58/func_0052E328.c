#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052E328_arg0 {
    char pad0[0x28];
    s32 unk28;
};

void func_0052E328(struct func_0052E328_arg0 *arg0, s32 arg1) {
    arg0->unk28 = arg1;
}
