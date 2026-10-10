#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00284F70_arg0 {
    char pad0[0x70];
    f32 unk70;
};

f32 func_00284F70(struct func_00284F70_arg0 *arg0) {
    return 0x1.0000000000000p+0f / arg0->unk70;
}
