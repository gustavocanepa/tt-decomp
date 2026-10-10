#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005623B8_arg0 {
    char pad0[0x10];
    s8 unk10;
};

void func_005623B8(struct func_005623B8_arg0 *arg0, s8 arg1) {
    arg0->unk10 = arg1;
}
