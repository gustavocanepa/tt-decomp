#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005513D0_arg0 {
    char pad0[0xD00C];
    f32 unkD00C;
};

f32 func_005513D0(struct func_005513D0_arg0 *arg0) {
    return arg0->unkD00C;
}
