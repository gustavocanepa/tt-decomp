#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004448E0_arg0 {
    char pad0[0x38];
    f32 unk38;
};

f32 func_004448E0(struct func_004448E0_arg0 *arg0) {
    return arg0->unk38;
}
