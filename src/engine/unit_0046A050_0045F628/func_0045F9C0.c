#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0045F9C0_arg0 {
    char pad0[0xA0];
    s32 unkA0;
    char padA4[0x8];
    s32 unkAC;
};

void func_0045F9C0(struct func_0045F9C0_arg0 *arg0) {
    arg0->unkAC = (s32) (arg0->unkA0 + 1);
}
