#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E6A78_arg0 {
    char pad0[0x120];
    f32 unk120;
};

f32 func_002E6A78(struct func_002E6A78_arg0 *arg0) {
    return arg0->unk120;
}
