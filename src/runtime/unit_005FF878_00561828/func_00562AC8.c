#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562AC8_arg0 {
    char pad0[0x1154];
    s32 unk1154;
};

void func_00562AC8(struct func_00562AC8_arg0 *arg0, s32 arg1) {
    arg0->unk1154 = arg1;
}
