#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005532F8_arg0 {
    char pad0[0xE8];
    s32 unkE8;
};

void func_005532F8(struct func_005532F8_arg0 *arg0, s32 arg1) {
    arg0->unkE8 = arg1;
}
