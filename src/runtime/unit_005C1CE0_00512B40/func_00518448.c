#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00518448_arg0 {
    char pad0[0x17C];
    s32 unk17C;
};

void func_00518448(struct func_00518448_arg0 *arg0, s32 arg1) {
    arg0->unk17C = arg1;
}
