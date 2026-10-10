#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00320FE0_arg0 {
    char pad0[0xD00];
    s32 unkD00;
};

s32 func_00320FE0(struct func_00320FE0_arg0 *arg0) {
    return arg0->unkD00;
}
