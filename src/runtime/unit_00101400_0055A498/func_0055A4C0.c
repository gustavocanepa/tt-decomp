#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0055A4C0_arg0 {
    char pad0[0xDE4];
    s32 unkDE4;
};

void func_0055A4C0(struct func_0055A4C0_arg0 *arg0, s32 arg1) {
    arg0->unkDE4 = arg1;
}
