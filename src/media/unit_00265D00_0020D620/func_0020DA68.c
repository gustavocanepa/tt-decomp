#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0020DA68_arg0 {
    char pad0[0xAC];
    s32 unkAC;
};

s32 func_0020DA68(struct func_0020DA68_arg0 *arg0) {
    return ((s32) arg0->unkAC >> 0x15) & 1;
}
