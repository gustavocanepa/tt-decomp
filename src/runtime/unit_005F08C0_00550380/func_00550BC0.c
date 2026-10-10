#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00550BC0_arg0 {
    char pad0[0x3277C];
    s32 unk3277C;
};

void func_00550BC0(struct func_00550BC0_arg0 *arg0) {
    arg0->unk3277C = 1;
}
