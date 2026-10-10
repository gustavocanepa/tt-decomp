#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554718_arg0 {
    char pad0[0xE4C8];
    s32 unkE4C8;
};

void func_00554718(struct func_00554718_arg0 *arg0, s32 arg1) {
    arg0->unkE4C8 = arg1;
}
