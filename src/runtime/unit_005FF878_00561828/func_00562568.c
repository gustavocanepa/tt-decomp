#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562568_arg0 {
    char pad0[0x64];
    s32 unk64;
};

void func_00562568(struct func_00562568_arg0 *arg0, s32 arg1) {
    arg0->unk64 = arg1;
}
