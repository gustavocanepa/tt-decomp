#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E6A58_arg0 {
    char pad0[0x8];
    f32 unk8;
};

f32 func_002E6A58(struct func_002E6A58_arg0 *arg0) {
    return arg0->unk8;
}
