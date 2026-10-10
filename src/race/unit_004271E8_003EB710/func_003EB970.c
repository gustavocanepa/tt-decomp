#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003EB970_arg0 {
    char pad0[0xD8];
    s32 unkD8;
};

s32 func_003EB970(struct func_003EB970_arg0 *arg0) {
    return arg0->unkD8;
}
