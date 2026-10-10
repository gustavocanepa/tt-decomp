#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005623D8_arg0 {
    char pad0[0x12];
    s8 unk12;
};

void func_005623D8(struct func_005623D8_arg0 *arg0, s8 arg1) {
    arg0->unk12 = arg1;
}
