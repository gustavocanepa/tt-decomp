#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417C08_arg0 {
    char pad0[0xFC];
    f32 unkFC;
};

f32 func_00417C08(struct func_00417C08_arg0 *arg0) {
    return arg0->unkFC;
}
