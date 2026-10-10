#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005544A8_arg0 {
    char pad0[0xDA0];
    s32 unkDA0;
};

void func_005544A8(struct func_005544A8_arg0 *arg0, s32 arg1) {
    arg0->unkDA0 = arg1;
}
