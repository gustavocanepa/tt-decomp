#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E5D40_arg0 {
    char pad0[0x5B8];
    f32 unk5B8;
};

f32 func_002E5D40(struct func_002E5D40_arg0 *arg0) {
    return arg0->unk5B8;
}
