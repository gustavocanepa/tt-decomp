#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00542018_arg0 {
    char pad0[0x6C];
    f32 unk6C;
};

f32 func_00542018(struct func_00542018_arg0 *arg0) {
    return arg0->unk6C;
}
