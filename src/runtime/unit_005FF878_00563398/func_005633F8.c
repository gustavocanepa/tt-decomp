#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005633F8_arg0 {
    char pad0[0x8];
    s8 unk8;
};

void func_005633F8(struct func_005633F8_arg0 *arg0, s8 arg1) {
    arg0->unk8 = arg1;
}
