#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E6A70_arg0 {
    char pad0[0x11C];
    f32 unk11C;
};

f32 func_002E6A70(struct func_002E6A70_arg0 *arg0) {
    return arg0->unk11C;
}
