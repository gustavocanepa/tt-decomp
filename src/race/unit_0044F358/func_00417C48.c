#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417C48_arg0 {
    char pad0[0x10C];
    f32 unk10C;
};

f32 func_00417C48(struct func_00417C48_arg0 *arg0) {
    return arg0->unk10C;
}
