#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562D40_arg0 {
    char pad0[0x1160];
    s32 unk1160;
};

void func_00562D40(struct func_00562D40_arg0 *arg0, s32 arg1) {
    arg0->unk1160 = arg1;
}
