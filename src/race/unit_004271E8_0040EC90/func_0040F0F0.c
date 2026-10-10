#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0040F0F0_arg0 {
    char pad0[0xA8];
    s64 unkA8;
};

s64 func_0040F0F0(struct func_0040F0F0_arg0 *arg0) {
    return arg0->unkA8;
}
