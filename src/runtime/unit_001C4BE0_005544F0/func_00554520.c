#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554520_arg0 {
    char pad0[0xE24];
    s32 unkE24;
};

s32 func_00554520(struct func_00554520_arg0 *arg0) {
    return arg0->unkE24;
}
