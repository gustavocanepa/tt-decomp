#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00542860_arg0 {
    char pad0[0x88];
    f32 unk88;
};

f32 func_00542860(struct func_00542860_arg0 *arg0) {
    return arg0->unk88;
}
