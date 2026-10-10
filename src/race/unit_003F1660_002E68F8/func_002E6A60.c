#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E6A60_arg0 {
    char pad0[0x48];
    f32 unk48;
};

f32 func_002E6A60(struct func_002E6A60_arg0 *arg0) {
    return arg0->unk48;
}
