#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005623C8_arg0 {
    char pad0[0x11];
    s8 unk11;
};

void func_005623C8(struct func_005623C8_arg0 *arg0, s8 arg1) {
    arg0->unk11 = arg1;
}
