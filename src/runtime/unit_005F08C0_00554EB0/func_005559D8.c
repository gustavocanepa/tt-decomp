#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005559D8_arg0 {
    char pad0[0xA4];
    s32 unkA4;
};

s32 func_005559D8(struct func_005559D8_arg0 *arg0) {
    return arg0->unkA4;
}
