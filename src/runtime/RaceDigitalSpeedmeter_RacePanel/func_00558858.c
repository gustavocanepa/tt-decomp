#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00558858_arg0 {
    char pad0[0x1F];
    s8 unk1F;
};

void func_00558858(struct func_00558858_arg0 *arg0, s8 arg1) {
    arg0->unk1F = arg1;
}
