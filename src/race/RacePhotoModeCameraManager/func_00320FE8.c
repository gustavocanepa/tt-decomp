#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00320FE8_arg0 {
    char pad0[0xD04];
    s32 unkD04;
};

s32 func_00320FE8(struct func_00320FE8_arg0 *arg0) {
    return arg0->unkD04;
}
