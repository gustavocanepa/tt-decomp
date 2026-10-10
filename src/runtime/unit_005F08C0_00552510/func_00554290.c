#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554290_arg0 {
    char pad0[0xD8C];
    s32 unkD8C;
};

s32 func_00554290(struct func_00554290_arg0 *arg0) {
    return arg0->unkD8C;
}
