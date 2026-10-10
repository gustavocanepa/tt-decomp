#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F8A90_arg0 {
    char pad0[0x5F4];
    f32 unk5F4;
};

f32 func_002F8A90(struct func_002F8A90_arg0 *arg0) {
    return arg0->unk5F4;
}
