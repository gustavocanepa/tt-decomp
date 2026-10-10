#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003ACD28_arg0 {
    char pad0[0x158];
    f32 unk158;
};

f32 func_003ACD28(struct func_003ACD28_arg0 *arg0) {
    return arg0->unk158;
}
