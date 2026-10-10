#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005633C8_arg0 {
    char pad0[0x6];
    s8 unk6;
};

void func_005633C8(struct func_005633C8_arg0 *arg0, s8 arg1) {
    arg0->unk6 = arg1;
}
