#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003BCFE0_arg0 {
    char pad0[0xE0];
    f32 unkE0;
};

f32 func_003BCFE0(struct func_003BCFE0_arg0 *arg0) {
    return arg0->unkE0;
}
