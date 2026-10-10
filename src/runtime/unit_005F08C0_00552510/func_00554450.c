#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554450_arg0 {
    char pad0[0xD98];
    s32 unkD98;
};

void func_00554450(struct func_00554450_arg0 *arg0, s32 arg1) {
    arg0->unkD98 = arg1;
}
