#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001B9288_arg0 {
    char pad0[0xD0];
    s32 unkD0;
};

s32 func_001B9288(struct func_001B9288_arg0 *arg0) {
    return arg0->unkD0;
}
