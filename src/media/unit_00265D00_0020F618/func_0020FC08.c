#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0020FC08_arg0 {
    char pad0[0xAC];
    u32 unkAC;
};

s32 func_0020FC08(struct func_0020FC08_arg0 *arg0) {
    return ((u32) arg0->unkAC >> 0x17) & 0xF;
}
