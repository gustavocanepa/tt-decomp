#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00558390_arg0 {
    char pad0[0x48];
    s8 unk48;
};

void func_00558390(struct func_00558390_arg0 *arg0, s8 arg1) {
    arg0->unk48 = arg1;
}
