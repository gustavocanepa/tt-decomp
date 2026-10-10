#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00566A88_arg0 {
    char pad0[0x198];
    s64 unk198;
};

void func_00566A88(struct func_00566A88_arg0 *arg0, s64 arg1) {
    arg0->unk198 = arg1;
}
