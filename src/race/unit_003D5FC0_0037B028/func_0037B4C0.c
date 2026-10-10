#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0037B4C0_arg0 {
    char pad0[0x64];
    s32 unk64;
};

s32 func_0037B4C0(struct func_0037B4C0_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk64;
    arg0->unk64 = 0;
    return temp_v0;
}
