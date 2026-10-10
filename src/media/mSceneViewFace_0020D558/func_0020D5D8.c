#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0020D5D8_arg0 {
    char pad0[0xAC];
    s32 unkAC;
};

s32 func_0020D5D8(struct func_0020D5D8_arg0 *arg0) {
    return ((s32) arg0->unkAC >> 0x11) & 1;
}
