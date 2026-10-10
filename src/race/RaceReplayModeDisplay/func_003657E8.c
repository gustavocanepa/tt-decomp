#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003657E8_arg0 {
    char pad0[0x104];
    f32 unk104;
};

void func_003657E8(struct func_003657E8_arg0 *arg0, s32 arg1) {
    arg0->unk104 = (f32) arg1;
}
