#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562248_arg0 {
    char pad0[0x8238];
    s32 unk8238;
};

void func_00562248(struct func_00562248_arg0 *arg0, s32 arg1) {
    arg0->unk8238 = arg1;
}
