#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00556D08_arg0 {
    char pad0[0x6C];
    s32 unk6C;
};

void func_00556D08(struct func_00556D08_arg0 *arg0, s32 arg1) {
    arg0->unk6C = arg1;
}
