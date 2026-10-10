#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562DD0_arg0 {
    char pad0[0x1180];
    s32 unk1180;
};

void func_00562DD0(struct func_00562DD0_arg0 *arg0, s32 arg1) {
    arg0->unk1180 = arg1;
}
