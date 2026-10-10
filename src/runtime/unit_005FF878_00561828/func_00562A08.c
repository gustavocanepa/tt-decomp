#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562A08_arg0 {
    char pad0[0x1134];
    s32 unk1134;
};

void func_00562A08(struct func_00562A08_arg0 *arg0, s32 arg1) {
    arg0->unk1134 = arg1;
}
