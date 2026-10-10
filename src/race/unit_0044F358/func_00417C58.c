#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417C58_arg0 {
    char pad0[0x110];
    f32 unk110;
};

f32 func_00417C58(struct func_00417C58_arg0 *arg0) {
    return arg0->unk110;
}
