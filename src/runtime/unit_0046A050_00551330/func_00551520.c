#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00551520_arg0 {
    char pad0[0xE3EC];
    s32 unkE3EC;
};

s32 func_00551520(struct func_00551520_arg0 *arg0) {
    return arg0->unkE3EC;
}
