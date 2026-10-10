#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554528_arg0 {
    char pad0[0xE28];
    s32 unkE28;
};

void func_00554528(struct func_00554528_arg0 *arg0, s32 arg1) {
    arg0->unkE28 = arg1;
}
