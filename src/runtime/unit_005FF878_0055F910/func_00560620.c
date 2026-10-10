#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00560620_arg0 {
    char pad0[0x904];
    s32 unk904;
};

void func_00560620(struct func_00560620_arg0 *arg0, s32 arg1) {
    arg0->unk904 = arg1;
}
