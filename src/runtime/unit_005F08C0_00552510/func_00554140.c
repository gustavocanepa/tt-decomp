#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554140_arg0 {
    char pad0[0x2D0];
    s64 unk2D0;
};

void func_00554140(struct func_00554140_arg0 *arg0, s64 arg1) {
    arg0->unk2D0 = arg1;
}
