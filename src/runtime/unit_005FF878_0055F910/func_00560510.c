#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00560510_arg0 {
    char pad0[0x1DE0];
    s32 unk1DE0;
};

void func_00560510(struct func_00560510_arg0 *arg0, s32 arg1) {
    arg0->unk1DE0 = arg1;
}
