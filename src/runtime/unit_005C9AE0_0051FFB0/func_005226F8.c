#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005226F8_arg0 {
    char pad0[0x140B4];
    s32 unk140B4;
};

void func_005226F8(struct func_005226F8_arg0 *arg0, s32 arg1) {
    arg0->unk140B4 = arg1;
}
