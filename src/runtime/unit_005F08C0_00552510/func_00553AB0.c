#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00553AB0_arg0 {
    char pad0[0x1E8];
    f32 unk1E8;
};

f32 func_00553AB0(struct func_00553AB0_arg0 *arg0) {
    return arg0->unk1E8;
}
