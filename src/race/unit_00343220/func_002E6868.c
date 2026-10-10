#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E6868_arg0 {
    char pad0[0x678];
    f32 unk678;
};

f32 func_002E6868(struct func_002E6868_arg0 *arg0) {
    return arg0->unk678;
}
