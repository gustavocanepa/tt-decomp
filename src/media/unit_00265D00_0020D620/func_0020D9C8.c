#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0020D9C8_arg0 {
    char pad0[0xAC];
    s32 unkAC;
};

u32 func_0020D9C8(struct func_0020D9C8_arg0 *arg0) {
    return (u32) (arg0->unkAC & 0xF) >> 3;
}
