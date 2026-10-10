#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005459A0_arg0 {
    char pad0[0xD4];
    s32 unkD4;
};

s32 func_005459A0(struct func_005459A0_arg0 *arg0) {
    return arg0->unkD4;
}
