#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554488_arg0 {
    char pad0[0xE18];
    s32 unkE18;
};

void func_00554488(struct func_00554488_arg0 *arg0, s32 arg1) {
    arg0->unkE18 = arg1;
}
