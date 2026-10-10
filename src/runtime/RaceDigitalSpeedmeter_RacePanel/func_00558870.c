#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00558870_arg0 {
    char pad0[0x22];
    s8 unk22;
};

void func_00558870(struct func_00558870_arg0 *arg0, s8 arg1) {
    arg0->unk22 = arg1;
}
