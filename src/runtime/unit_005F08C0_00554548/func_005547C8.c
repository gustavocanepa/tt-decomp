#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005547C8_arg0 {
    char pad0[0xE4CC];
    s32 unkE4CC;
};

s32 func_005547C8(struct func_005547C8_arg0 *arg0) {
    return arg0->unkE4CC;
}
