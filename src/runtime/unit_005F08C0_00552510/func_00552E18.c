#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00552E18_arg0 {
    char pad0[0xA48];
    s32 unkA48;
};

s32 func_00552E18(struct func_00552E18_arg0 *arg0) {
    return arg0->unkA48;
}
