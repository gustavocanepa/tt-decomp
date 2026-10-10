#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00524A88_arg0 {
    char pad0[0xC0];
    s32 unkC0;
};

s32 func_00524A88(struct func_00524A88_arg0 *arg0) {
    return arg0->unkC0;
}
