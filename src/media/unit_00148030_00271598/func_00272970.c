#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00272970_arg0 {
    char pad0[0x8C];
    f32 unk8C;
};

f32 func_00272970(struct func_00272970_arg0 *arg0) {
    return arg0->unk8C;
}
