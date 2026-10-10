#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005551F8_arg0 {
    char pad0[0x3544];
    s32 unk3544;
};

void func_005551F8(struct func_005551F8_arg0 *arg0, s32 arg1) {
    arg0->unk3544 = arg1;
}
