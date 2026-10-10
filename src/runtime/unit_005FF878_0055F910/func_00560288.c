#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00560288_arg0 {
    char pad0[0x1D4];
    s32 unk1D4;
};

void func_00560288(struct func_00560288_arg0 *arg0, s32 arg1) {
    arg0->unk1D4 = arg1;
}
