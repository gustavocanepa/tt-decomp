#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00522B20_arg0 {
    char pad0[0x8A0];
    f32 unk8A0;
};

f32 func_00522B20(struct func_00522B20_arg0 *arg0) {
    return arg0->unk8A0;
}
