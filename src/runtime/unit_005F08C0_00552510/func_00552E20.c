#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00552E20_arg0 {
    char pad0[0xA4C];
    s32 unkA4C;
};

s32 func_00552E20(struct func_00552E20_arg0 *arg0) {
    return arg0->unkA4C;
}
