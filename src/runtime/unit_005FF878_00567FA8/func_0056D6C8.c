#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0056D6C8_arg0 {
    char pad0[0xC];
    s32 unkC;
};

u8 func_0056D6C8(struct func_0056D6C8_arg0 *arg0, s32 arg1) {
    return *(s32 *)(arg0->unkC + arg1);
}
