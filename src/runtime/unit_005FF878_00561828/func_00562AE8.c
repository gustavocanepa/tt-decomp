#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562AE8_arg0 {
    char pad0[0x1150];
    s32 unk1150;
};

void func_00562AE8(struct func_00562AE8_arg0 *arg0, s32 arg1) {
    arg0->unk1150 = arg1;
}
