#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00566598_arg0 {
    char pad0[0x60];
    f32 unk60;
};

f32 func_00566598(struct func_00566598_arg0 *arg0) {
    return arg0->unk60;
}
