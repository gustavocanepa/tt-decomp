#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00566590_arg0 {
    char pad0[0x5C];
    f32 unk5C;
};

f32 func_00566590(struct func_00566590_arg0 *arg0) {
    return arg0->unk5C;
}
