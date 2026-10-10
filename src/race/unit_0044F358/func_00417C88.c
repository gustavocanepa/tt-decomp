#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417C88_arg0 {
    char pad0[0x11C];
    f32 unk11C;
};

f32 func_00417C88(struct func_00417C88_arg0 *arg0) {
    return arg0->unk11C;
}
