#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0020FBD0_arg0 {
    char pad0[0xAC];
    s32 unkAC;
};

s32 func_0020FBD0(struct func_0020FBD0_arg0 *arg0) {
    return ((s32) arg0->unkAC >> 0x16) & 1;
}
