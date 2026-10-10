#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00528B48_arg0 {
    char pad0[0x18];
    f32 unk18;
};

f32 func_00528B48(struct func_00528B48_arg0 *arg0) {
    return arg0->unk18;
}
