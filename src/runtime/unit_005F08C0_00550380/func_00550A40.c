#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00550A40_arg0 {
    char pad0[0x447A0];
    s32 unk447A0;
};

void func_00550A40(struct func_00550A40_arg0 *arg0, s32 arg1) {
    arg0->unk447A0 = arg1;
}
