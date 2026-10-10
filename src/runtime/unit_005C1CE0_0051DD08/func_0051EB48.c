#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0051EB48_arg0 {
    char pad0[0xBC];
    s32 unkBC;
};

void func_0051EB48(struct func_0051EB48_arg0 *arg0, s32 arg1) {
    arg0->unkBC = arg1;
}
