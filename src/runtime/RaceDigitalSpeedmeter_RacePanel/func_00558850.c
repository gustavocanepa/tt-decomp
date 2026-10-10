#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00558850_arg0 {
    char pad0[0x1E];
    s8 unk1E;
};

void func_00558850(struct func_00558850_arg0 *arg0, s8 arg1) {
    arg0->unk1E = arg1;
}
