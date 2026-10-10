#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00558868_arg0 {
    char pad0[0x21];
    s8 unk21;
};

void func_00558868(struct func_00558868_arg0 *arg0, s8 arg1) {
    arg0->unk21 = arg1;
}
