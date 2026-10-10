#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562D50_arg0 {
    char pad0[0x1164];
    s32 unk1164;
};

void func_00562D50(struct func_00562D50_arg0 *arg0, s32 arg1) {
    arg0->unk1164 = arg1;
}
